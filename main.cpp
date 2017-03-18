// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;


//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{
   ofstream out(nombre_archivo.c_str(),ios::in);
    if(!out.is_open())
            {
                out.open(nombre_archivo.c_str());
            }
    out.seekp(14*posicion,ios::beg);
            out.write((char*)&mascota->edad,4);
            out.write(mascota->nombre.c_str(),10);
            out.close();
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{
    Mascota *m = new Mascota(-1,"");
    ifstream in(nombre_archivo.c_str());
    in.seekg(14*posicion,ios::beg);
            in.read((char*)&m->edad,4);
            char temp[10];
        in.read(temp,10);
        m->nombre = temp;
            in.close();
    return m;
}

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
     in.seekg(0,ios::end);
    int tamano_archivo = in.tellg();
   // cout<<tamano_archivo<<endl;
    in.close();
    vector<Mascota*>respuesta;
    for(int i = 0; i<tamano_archivo/14; i++){
         //Mascota *m =leer(nombre_archivo,i);
        respuesta.push_back(leer(nombre_archivo,i));
        //cout<<respuesta.size()<<endl;

    }
    return respuesta;

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
