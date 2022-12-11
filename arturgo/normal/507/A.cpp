#include <algorithm>
#include <iostream>
using namespace std;

int inss[200];
int ids[200];

bool comp(const int &a, const int &b)
{
    return inss[a] < inss[b];
}

int main()
{
    int nbI, nbD;
    cin >> nbI >> nbD;

    for(int iIns = 0;iIns < nbI;iIns++)
    {
        cin >> inss[iIns];
        ids[iIns] = iIns;
    }

    sort(ids, ids + nbI, comp);

    int sum = 0, nb = 0;
    while(nb < nbI && sum + inss[ids[nb]] <= nbD)
    {
        sum += inss[ids[nb]];
        nb++;
    }

    cout << nb << endl;
    for(int iIns = 0;iIns < nb;iIns++)
        cout << ids[iIns] + 1 << " ";
    return 0;
}