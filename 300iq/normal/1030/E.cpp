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
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[i] = __builtin_popcountll(x);
    }
    int bad = 0;
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        int mx = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            mx = max(mx, a[j]);
            if (sum > 300) break;
            if (sum - mx < mx && sum % 2 == 0)
            {
                bad++;
            }
        }
    }
    int pref = 0;
    int z0 = 1, z1 = 0;
    for (int i = 0; i < n; i++)
    {
        pref ^= (a[i] % 2);
        if (pref) z1++;
        else z0++;
    }
    cout << z0 * (ll) (z0 - 1) / 2 + z1 * (ll) (z1 - 1) / 2 - bad << '\n';
}