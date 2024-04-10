#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int v, k, kol, sum, i, n, a[100000], b[100000];
    cin >> n;
    sum = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }
    k = sum / n;
    kol = 0;
    for(i = 0; i < n; i++)
    {
        if (a[i] != k)
        {
            kol++;
            b[kol] = i;
        }
    }
    if ((kol > 2) or (kol == 1))
    {
        cout << "Unrecoverable configuration.";
        return 0;
    }
    if ((kol == 2) and (a[b[1]] + a[b[2]] != 2 * k))
    {
        cout << "Unrecoverable configuration.";
        return 0;
    }
    if ((kol == 2) and (a[b[1]] > a[b[2]]))
    {
       v = (a[b[1]] - a[b[2]]) / 2;
       cout << v << " ml. from cup #" << b[2]+1 << " to cup #" << b[1]+1 << ".";

    }
    if ((kol == 2) and (a[b[1]] < a[b[2]]))
    {
       v = (a[b[2]] - a[b[1]]) / 2;
       cout << v << " ml. from cup #" << b[1]+1 << " to cup #" << b[2]+1 << ".";
    }
    if (kol == 0) cout << "Exemplary pages.";
    return 0;

}