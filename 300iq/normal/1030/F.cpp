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

const int N = 2e5 + 7;
const int M = 1e9 + 7;

ll f_w[N];
ll f_aw[N];

void inc_w(int x, int y)
{   
    for (; x < N; x = (x | (x + 1)))
    {
        f_w[x] += y;
    }
}

void inc_aw(int x, ll y)
{   
    y %= M;
    if (y < 0) y += M;
    for (; x < N; x = (x | (x + 1)))
    {
        f_aw[x] += y;
        if (f_aw[x] >= M)
        {
            f_aw[x] -= M;
        }
    }
}

ll get_w(int x)
{
    ll res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
    {
        res += f_w[x];
    }
    return res;
}

int get_aw(int x)
{
    int res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
    {
        res += f_aw[x];
        if (res >= M) res -= M;
    }
    return res;
}

ll get_w(int l, int r)
{
    return get_w(r) - get_w(l - 1);
}

int get_aw(int l, int r)
{
    int res = get_aw(r);
    res -= get_aw(l - 1);
    if (res < 0) res += M;
    return res;
}

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
        a[i] -= i;
    }
    vector <int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        inc_w(i, w[i]);
        inc_aw(i, a[i] * (ll) w[i]);
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x < 0)
        {
            x = -x;
            x--;
            inc_w(x, -w[x]);
            inc_aw(x, -(a[x] * (ll) w[x]));
            w[x] = y;
            inc_w(x, w[x]);
            inc_aw(x, (a[x] * (ll) w[x]));
        }
        else
        {
            x--, y--;
            ll sum = get_w(x, y);
            ll need = sum / 2 + get_w(x - 1);
            int l = x - 1, r = y;
            while (l < r - 1)
            {
                int m = (l + r) / 2;
                if (get_w(m) <= need)
                {
                    l = m;
                }
                else
                {
                    r = m;
                }
            }
            int p = l + 1;
            ll ans = -get_aw(x, p) + get_aw(p + 1, y);
            if (ans < 0) ans += M;
            ans += (get_w(x, p) % M * (ll) a[p]) % M;
            if (ans >= M) ans -= M;
            ans -= (get_w(p + 1, y) % M * (ll) a[p]) % M;
            if (ans < 0) ans += M;
            cout << ans << '\n';
        }
    }
}