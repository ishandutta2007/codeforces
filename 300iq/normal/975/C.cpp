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
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector <ll> pref(n);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        pref[i] = s;
    }
    ll delta = 0;
    while (q--)
    {
        ll k;
        cin >> k;
        delta += k;
        int l = -1, r = n;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            if (pref[m] > delta)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        l = r;
        if (l == n)
        {
            l = 0;
            delta = 0;
        }
        cout << n - l << '\n';
    }
}