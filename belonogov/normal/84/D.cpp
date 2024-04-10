#include <iostream>
#include <cstdio>

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <sstream>


using namespace std;

#define forn(i, n) for(i = 0; i < n; i++)
typedef long long ll;
struct Tstruct
{
        int k, i;
};
bool rez(Tstruct a, Tstruct b)
{
        return a.k < b.k;
}
bool rez2(Tstruct a, Tstruct b)
{
        return a.i < b.i;
}


Tstruct a[100000];


int main()
{
     int n, i;
    ll k, k0;
    cin >> n >> k;
    forn(i, n)
    {
        cin >> a[i].k;
        a[i].i = i;
    }

    sort(a, a + n, rez);
    k0 = 0;
    i = 0;
    while (k - ((n - i) * (a[i].k - k0)) >= 0)
    {
        k = k - ((n - i) * (a[i].k - k0));
        k0 = a[i].k;
        i++;
        if ((i == n) && (k == 0)) return 0;
        if ((i == n) && (k > 0))
        {
            cout << -1;
            return 0;
        }
    }

    k0 = k0 + k / n;
    k = k % (n - i);
    int j;
    sort(a + i, a + n, rez2);
    for(j = (i + k); j < n; j++)
        if (a[j].k - k0 > 0)
            cout << a[j].i + 1 << " ";

    for(j = i; j < k + i; j++)
        if (a[j].k - k0 > 1)
            cout << a[j].i + 1 << " ";


    return 0;
}