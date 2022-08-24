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
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int M = 998244353;

ll lim[10];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lim[2] = 2e9;
    lim[3] = 2e6;
    lim[4] = 1e5;
    vector <pair <ll, int> > p;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1) continue;
        pair <ll, int> ret = {-1, -1};
        for (int t = 4; t >= 2; t--)
        {
            ll l = 0, r = a[i] + 1;
            while (l < r - 1)
            {
                ll m = (l + r) / 2;
                ll x = 1;
                for (int it = 0; it < t; it++)
                {
                    if (m > a[i] / x)
                    {
                        x = a[i] + 1;
                        break;
                    }
                    x *= m;
                }
                if (x <= a[i])
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            ll x = 1;
            for (int it = 0; it < t; it++) x *= l;
            if (x == a[i])
            {
                ret = {l, t};
                break;
            }
        }
        if (ret.first == -1)
        {
            ret = {a[i], -1};
        }
        p.push_back(ret);
    }
    map <ll, int> add_p;
    map <ll, int> add_pq;
    for (int i = 0; i < (int) p.size(); i++)
    {
        if (p[i].second == -1)
        {
            ll div = 0;
            for (int j = 0; j < (int) p.size(); j++)
            {
                ll g = __gcd(p[i].first, p[j].first);
                if (1 < g && g < p[i].first)
                {
                    div = g;
                    break;
                }
            }
            if (div != 0)
            {
                add_p[div]++;
                add_p[p[i].first / div]++;
            }
            else
            {
                add_pq[p[i].first]++;
            }
        }
        else
        {
            add_p[p[i].first] += p[i].second;
        }
    }
    ll res = 1;
    for (auto c : add_p)
    {
        res = (res * (c.second + 1)) % M;
    }
    for (auto c : add_pq)
    {
        res = (res * (c.second + 1)) % M;
        res = (res * (c.second + 1)) % M;
    }
    cout << res << '\n';
}