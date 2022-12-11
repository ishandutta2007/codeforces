#include <iostream>
#include <algorithm>
using namespace std;

int nombre;
int valeurs[4];

void lireEntree()
{
    cin >> nombre;
    for(int iNombre = 0;iNombre < nombre;iNombre++)
        cin >> valeurs[iNombre];
}

int main()
{
    lireEntree();
    if(nombre == 0)
    {
        cout << "YES" << endl;
        cout << 1 << endl  << 1 << endl << 3 << endl << 3 << endl;
        return 0;
    }

    int vals[4], nvals[4];
    for(vals[0] = 1;vals[0] <= 10000;vals[0]++)
        for(vals[1] = vals[0];vals[1] <= 10000;vals[1]++)
        {
            nvals[0] = vals[0];
            nvals[1] = vals[1];
            nvals[2] = 4 * vals[0] - vals[1];
            nvals[3] = 3 * vals[0];
            if(nvals[1] > nvals[2] || nvals[2] > nvals[3])
                continue;
            if(nvals[3] - nvals[0] != (nvals[1] + nvals[2]) / 2. || nvals[3] - nvals[0] != (nvals[0] + nvals[1] + nvals[2] + nvals[3]) / 4.)
                continue;
            int bon = 0;
            for(int iNombre = 0;iNombre < nombre;iNombre++)
                for(int iVal = 0;iVal < 4;iVal++)
                    if(valeurs[iNombre] == nvals[iVal])
                    {
                        nvals[iVal] = -1;
                        iVal = 4;
                        bon++;
                    }
            if(bon == nombre)
            {
                cout << "YES" << endl;
                for(int iVal = 0;iVal < 4;iVal++)
                    if(nvals[iVal] != -1)
                        cout << nvals[iVal] << endl;
                return 0;
            }
        }
    cout << "NO" << endl;
    return 0;
}