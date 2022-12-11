#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
using namespace std;

const int MAX_NB_TYPES = 10 * 1000;
const int INFINI = 1000 * 1000 * 1000;

struct Pack
{
    int nombre, valeur;
    Pack(int _nombre = 0, int _valeur = 0)
    {
        nombre = _nombre;
        valeur = _valeur;
    }
};

bool operator < (const Pack &a, const Pack &b)
{
    if(a.nombre * a.valeur == b.nombre * b.valeur)
        return a.nombre < b.nombre;
    return a.nombre * a.valeur < b.nombre * b.valeur;
}

int nbTypes, maxNombre;
int valeurs[MAX_NB_TYPES];
set<Pack> packs;

int main()
{
    cin >> nbTypes >> maxNombre;

    for(int iType = 0;iType < nbTypes;iType++)
    {
        cin >> valeurs[iType];

        for(int iPack = 1;iPack <= maxNombre;iPack++)
            packs.insert(Pack(iPack, valeurs[iType]));
    }

    int nbPayements = 0;
    cin >> nbPayements;

    for(int iPayement = 0;iPayement < nbPayements;iPayement++)
    {
        int valeur;
        cin >> valeur;

        int mini = INFINI;
        for(int iType = 0;iType < nbTypes;iType++)
        {
            for(int iNombre = 0;iNombre <= maxNombre;iNombre++)
            {
                int reste = valeur - iNombre * valeurs[iType];

                if(reste == 0)
                    mini = min(mini, iNombre);
                else
                {
                    set<Pack>::iterator suppose = packs.lower_bound(Pack(1, reste));

                    if(suppose != packs.end() && suppose->nombre * suppose->valeur == reste)
                        mini = min(mini, iNombre + suppose->nombre);
                }
            }
        }

        if(mini > maxNombre)
            cout << -1 << endl;
        else
            cout << mini << endl;
    }

    return 0;
}