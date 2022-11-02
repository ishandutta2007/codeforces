#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double

const int maxn = 2e5 + 9;
int p[maxn];
int k[maxn];
int b[maxn];
int n, q, ans;
int mod = 998244353;

int binpow(int x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x % mod;
    int z = binpow(x, y / 2);
    z = (z * z) % mod;
    if (y % 2)
        z = (z * x) % mod;
    return z;
}

int divv(int x, int y)
{
    return (binpow(y, mod - 2) * x) % mod;
}

void add(int l, int r, int t)
{
    int cur = divv(1, p[l]);
    int xx = (cur - b[l] + mod) % mod;
    xx = divv(xx, k[l]);
    xx = (k[r] * xx + b[r]) % mod;
//    cout << l << " " << r << "   " << xx << "\n";
    ans = ((ans + xx * t) % mod + mod) % mod;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i] = divv(p[i], 100);
    }
    k[0] = 1;
    b[0] = 0;
    for (int i = 1; i < n; i++)
    {
//        int cur = (1 - p[i] + mod) % mod;
//        cur = (cur * cur) % mod;
//        cur = divv(p[i], cur);
        int cur = divv(1, p[i]);
        k[i] = (k[i - 1] * cur) % mod;
        b[i] = ((b[i - 1] + 1) * cur) % mod;
        //cout << k[i] << " " << b[i] << "\n";
    }
    add(0, n - 1, 1);
    set<int> kek;
    kek.insert(0);
    kek.insert(n);
    for (int j = 0; j < q; j++)
    {
        int x;
        cin >> x;
        x--;
        auto u = kek.find(x);
        if (u != kek.end())
        {
            u--;
            int l = (*u);
            u++; u++;
            int r = (*u);
            add(l, x - 1, -1);
            add(x, r - 1, -1);
            add(l, r - 1, 1);
            kek.erase(x);
        }
        else
        {
            u = kek.lower_bound(x);
            int r = (*u);
            u--;
            int l = (*u);
            add(l, r - 1, -1);
            add(l, x - 1, 1);
            add(x, r - 1, 1);
            kek.insert(x);
        }
        cout << ans << "\n";
    }
}