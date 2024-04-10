#include <iostream>
#include <string>
using namespace std;

int nbOcB[2][26];
bool estPris[400 * 1000];

int valeur(char car)
{
    if(car >= 'A' && car <= 'Z')
        return car - 'A';
    return car - 'a';
}

int casse(char car)
{
    if(car >= 'A' && car <= 'Z')
        return 1;
    return 0;
}

int main()
{
    string a, b;
    cin >> a >> b;

    for(int iCar = 0;iCar < (int)b.size();iCar++)
        nbOcB[casse(b[iCar])][valeur(b[iCar])]++;

    int nbYay = 0, nbWhoops = 0;
    for(int iCar = 0;iCar < (int)a.size();iCar++)
        if(nbOcB[casse(a[iCar])][valeur(a[iCar])] != 0)
        {
            nbOcB[casse(a[iCar])][valeur(a[iCar])]--;
            nbYay++;
            estPris[iCar] = true;
        }

    for(int iCar = 0;iCar < (int)a.size();iCar++)
        if(!estPris[iCar] && nbOcB[1 - casse(a[iCar])][valeur(a[iCar])] != 0)
        {
            nbOcB[1 - casse(a[iCar])][valeur(a[iCar])]--;
            nbWhoops++;
            estPris[iCar] = true;
        }

    cout << nbYay << " " << nbWhoops << endl;
    return 0;
}