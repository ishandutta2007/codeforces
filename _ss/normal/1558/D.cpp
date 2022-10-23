#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 4e5 + 10, MX = 2e5;
const ll mod = 998244353;
int bit[N];

void add(int x, int v)
{
    for (int i = x; i <= MX; i += (i & -i)) bit[i] += v;
}

int find_pos(int v)
{
    v--;
    int pos = 0;
    for (int i = (1 << 17); i; i >>= 1)
        if ((pos | i) <= MX && bit[pos | i] <= v) pos |= i, v -= bit[pos];
    return pos + 1;
}

ll fact[N], inv[N], ifact[N];

void precal(int n)
{
    inv[1] = ifact[0] = ifact[1] = fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        inv[i] = mod - mod / i * inv[mod % i] % mod;
        ifact[i] = ifact[i - 1] * inv[i] % mod;
        fact[i] = fact[i - 1] * i % mod;
    }
}

ll C(int t, int h) { return fact[h] * ifact[t] % mod * ifact[h - t] % mod; }

int x[N], y[N], n, m;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    precal(4e5);
    for (int i = 1; i <= MX; ++i) add(i, 1);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) cin >> x[i] >> y[i];
        map<int, int> a;
        for (int i = m; i; --i)
        {
            int pos = find_pos(y[i]);
            add(pos, -1);
            a[pos] = x[i];
        }
        for (pii p : a) add(p.fi, 1);
        for (pii p : a)
            if (a.count(p.fi + 1) && a[p.fi + 1] > p.se) m--;
        cout << C(n, 2 * n - 1 - m) << "\n";
    }
    return 0;
}