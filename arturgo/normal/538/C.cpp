#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int taille, connus;
    cin >> taille >> connus;

    int curD, curH;
    int derD, derH;

    bool possible = true;
    int maxDiff = 0;

    cin >> curD >> curH;
    maxDiff = max(maxDiff, curH + curD - 1);
    for(int iConnu = 1;iConnu < connus;iConnu++)
    {
        derD = curD;
        derH = curH;

        cin >> curD >> curH;
        if(abs(curD - derD) < abs(curH - derH))
            possible = false;
        else
            maxDiff = max(maxDiff, max(curH, derH) + (abs(curD - derD) - abs(curH - derH)) / 2);
    }
    derD = curD;
    derH = curH;
    maxDiff = max(maxDiff, derH + taille - derD);

    if(possible)
        cout << maxDiff << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}