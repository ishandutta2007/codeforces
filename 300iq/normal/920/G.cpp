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

int sign(int x)
{
    return (x % 2 == 0 ? 1 : -1);
}

vector <int> a;

int ans(int lim)
{
    int cnt = (int) a.size();
    int ret = 0;
    for (int mask = 0; mask < (1 << cnt); mask++)
    {
        int cur = 1;
        for (int i = 0; i < cnt; i++)
        {
            if ((mask >> i) & 1)
            {
                cur *= a[i];
            }
        }
        ret += (lim / cur) * sign(__builtin_popcount(mask));
    }
    return ret;
}

void prec(int x)
{
    a.clear();
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            a.push_back(i);
            while (x % i == 0)
            {
                x /= i;
            }
        }
    }
    if (x != 1)
    {
        a.push_back(x);
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int x, p, k;
        cin >> x >> p >> k;
        prec(p);
        k += ans(x);
        int l = 0, r = 1e9 + 7;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            if (ans(m) >= k)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        cout << r << '\n';
    }
}