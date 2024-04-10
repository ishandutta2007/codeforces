#include <iostream>
using namespace std;

const int MAX_B = 10000;
const int MODULO = 1000000007;

long long factoModInv[MAX_B + 1];
long long factoMod[MAX_B + 1];
int nbBalles[1000];

long long inverse(long long a)
{
    long long lignes[3][2] = {{MODULO, 0}, {a, 1}};

    int iLigne = 1;
    while(lignes[iLigne % 3][0] != 1)
    {
        iLigne++;
        lignes[iLigne % 3][0] = lignes[(iLigne + 1) % 3][0] % lignes[(iLigne + 2) % 3][0];
        lignes[iLigne % 3][1] = (((lignes[(iLigne + 1) % 3][1] - (int)(lignes[(iLigne + 1) % 3][0] / lignes[(iLigne + 2) % 3][0]) * lignes[(iLigne + 2) % 3][1]) % MODULO) + MODULO) % MODULO;
    }
    return lignes[iLigne % 3][1];
}

void init()
{
    factoMod[0] = 1;
    for(int iFact = 1;iFact <= MAX_B;iFact++)
        factoMod[iFact] = (factoMod[iFact - 1] * iFact) % MODULO;

    for(int iFact = 0;iFact <= MAX_B;iFact++)
        factoModInv[iFact] = inverse(factoMod[iFact]);
}

long long coeffBin(int a, int b)
{
    long long res = (factoMod[b] * factoModInv[a]) % MODULO;
    res = (res * factoModInv[b - a]) % MODULO;
    return res;
}

int main()
{
    init();
    int nbCouleurs;
    cin >> nbCouleurs;
    
    long long int nbCombis = 1;
    int somme = 0;
    for(int iCouleur = 0;iCouleur < nbCouleurs;iCouleur++)
    {
        cin >> nbBalles[iCouleur];
        nbCombis = (nbCombis * coeffBin(somme, somme + nbBalles[iCouleur] - 1)) % MODULO;
        somme += nbBalles[iCouleur];
    }
    
    cout << nbCombis << endl;
    return 0;
}