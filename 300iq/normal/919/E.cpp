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

inline int add(int a, int b, int mod)
{
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

inline int mul(int a, int b, int mod)
{
    return (a * (ll) b) % mod;
}

inline int bin(int a, int n, int mod)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            a = mul(a, a, mod);
            n /= 2;
        }
        else
        {
            res = mul(res, a, mod);
            n--;
        }
    }
    return res;
}

ll big_mul(ll a, ll b, ll mod)
{
    ll res = 0;
    while (b)
    {
        if (b % 2 == 0)
        {
            a = (a + a) % mod;
            b /= 2;
        }
        else
        {
            res = (res + a) % mod;
            b--;
        }
    }
    return res;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, p;
    ll X;
    cin >> a >> b >> p >> X;
    ll ans = 0;
    for (int i = 0; i < p - 1; i++)
    {
        int cur = bin(a, i, p);
        int mn = mul(bin(cur, p - 2, p), b, p);
        int x = bin(p - 1, p - 2, p);
        ll big_mod = (p - 1) * (ll) p;
        ll kek = big_mul(big_mul(p - 1, x, big_mod), mn, big_mod);
        kek = (kek + i * (ll) p) % big_mod;
        ll p = X - kek;
        if (p >= 0)
            ans += p / big_mod;
        if (p >= 0 && kek != 0) ans++;
    }
    cout << ans << '\n';
}