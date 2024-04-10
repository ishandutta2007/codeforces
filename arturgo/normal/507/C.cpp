#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

long long prof, iSortie;

long long va(long long a)
{
    return ((a > 0)?(a):(-a));
}

long long doitVisiter(bool Pleft, long long debut, long long fin)
{
    if(debut == fin && debut == iSortie)
        return 0;
    if(debut > iSortie || fin < iSortie)
        return -(2 * (fin - debut) + 1);
    long long milieu = (debut + fin) / 2;

    long long r1, r2;

    if(Pleft)
    {
        r1 = doitVisiter(false, debut, milieu);
        r2 = doitVisiter(true, milieu + 1, fin);
    }
    else
    {
        r1 = doitVisiter(true, milieu + 1, fin);
        r2 = doitVisiter(false, debut, milieu);
    }

    if(r1 < 0)
        return va(r1) + va(r2) + 1;
    return va(r1) + 1;
}

int main()
{
    cin >> prof >> iSortie;
    long long fin = 1;
    for(int iProf = 0;iProf < prof;iProf++)
        fin *= 2;
    cout << doitVisiter(true, 1, fin) << endl;
    return 0;
}