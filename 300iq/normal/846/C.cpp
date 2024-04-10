
/*
    !  !!!
   
   
   
   
   
   
   
   
   
   
   
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    vector <ll> pref(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        pref[i] = s;
    }
    ll best = -1e18;
    int A = 0, B = 0, C = 0;
    for (int d1 = 0; d1 <= n; d1++)
    {
        int x0 = 0;
        ll bst = -1e18;
        for (int d0 = 0; d0 <= d1; d0++)
        {
            ll cost = 0;
            if (d0) cost += 2 * pref[d0 - 1];
            if (d1) cost -= pref[d1 - 1];
            if (cost > bst) x0 = d0, bst = cost;
        }
        ll kek = bst;
        int x2 = 0;
        bst = -1e18;
        for (int d2 = d1; d2 <= n; d2++)
        {
            ll cost = 0;
            if (d2) cost += 2 * pref[d2 - 1];
            if (d1) cost -= pref[d1 - 1];
            cost -= pref[n - 1];
            if (cost > bst) x2 = d2, bst = cost;
        }
        kek += bst;
        if (kek > best)
        {
            A = x0, B = d1, C = x2;
            best = kek;
        }
    }
    printf("%d %d %d\n", A, B, C);
}