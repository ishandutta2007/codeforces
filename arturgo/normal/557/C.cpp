#include <iostream>
#include <algorithm>
using namespace std;

const int INFINI = 1000 * 1000 * 1000;

struct Pied
{
    int taille, energie;
    Pied(int _taille = 0, int _energie = 0)
    {
        taille = _taille;
        energie = _energie;
    }
};

bool operator < (const Pied &a, const Pied &b)
{
    return a.taille < b.taille;
}

int tailles[100 * 1000], energie[100 * 1000];
Pied pieds[100 * 1000];

int minis[201];

int main()
{
    int nbPieds;
    cin >> nbPieds;
    
    for(int iPied = 0;iPied < nbPieds;iPied++)
        cin >> tailles[iPied];
    
    int somme = 0;
    for(int iPied = 0;iPied < nbPieds;iPied++)
    {
        cin >> energie[iPied];
        pieds[iPied] = Pied(tailles[iPied], energie[iPied]);
        somme += energie[iPied];
    }
    
    sort(pieds, pieds + nbPieds);
    
    int mini = INFINI;

    int iFin = 0;
    for(int iDebut = 0;iDebut < nbPieds;)
    {
        while(pieds[iDebut].taille == pieds[iFin].taille)
        {
            somme -= pieds[iFin].energie;
            iFin++;
        }
        
        int sommeMinis = 0;
        int nbMinis = nbPieds - (2 * (iFin - iDebut) - 1) - (nbPieds - iFin);
        for(int iEnergie = 0;nbMinis > 0 && iEnergie <= 200;iEnergie++)
        {
            int prise = min(nbMinis, minis[iEnergie]);
            sommeMinis += iEnergie * prise;
            nbMinis -= prise;
        }
        
        if(nbMinis <= 0)
            mini = min(mini, somme + sommeMinis);
        
        for(int iEnleve = iDebut;iEnleve < iFin;iEnleve++)
            minis[pieds[iEnleve].energie]++;

        iDebut = iFin;
    }

    cout << mini << endl;
    return 0;
}