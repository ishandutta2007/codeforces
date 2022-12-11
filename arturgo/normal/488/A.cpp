#include <iostream>
#include <algorithm>
using namespace std;

long long nombre;

void lireEntree()
{
    cin >> nombre;
}

bool contient8(long long nb)
{
    while(nb != 0)
    {
        if(nb % 10 == 8)
            return true;
        nb /= 10;
    }
    return false;
}

int main()
{
    lireEntree();
    
    for(int iDessus = 1;iDessus <= 20;iDessus++)
        if(contient8(abs(nombre + iDessus)))
        {
            cout << iDessus << endl;
            return 0;
        }
    return 0;
}