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
#include <bitset>

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
    int n, r;
    ll k;
    cin >> n >> r >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector <ll> val(n);
    ll vl = -1, vr = 2e18;
    while (vl < vr - 1)
    {
        ll vm = (vl + vr) / 2;
        ll cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < r)
            {
                cur += a[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            val[i] = a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (i + r < n)
            {
                cur += val[i + r];
            }
            ll need = max(0ll, vm - cur);
            val[min(n - 1, i + r)] += need;
            if (val[min(n - 1, i + r)] - a[min(n - 1, i + r)] > k)
            {
                break;
            }
            cur += need;
            if (i - r >= 0)
            {
                cur -= val[i - r];
            }
        }
        ll s = 0;
        for (int i = 0; i < n; i++)
        {
            s += val[i] - a[i];
            if (s > k) break;
        }
        if (s <= k)
        {
            vl = vm;
        }
        else
        {
            vr = vm;
        }
    }
    cout << vl << '\n';
}