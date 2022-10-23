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
const int N = 1 << 20;
const int mod = 1e9 + 7;

void fwht(ll f[], int n)
{
    for (int b = 0; b < n; ++b)
        for (int i = 0; i < (1 << n); i += (1 << (b + 1)))
            for (int j = 0; j < (1 << b); ++j)
            {
                int u = f[i + j];
                int v = f[i + j + (1 << b)];
                f[i + j] = (u + v) % mod;
                f[i + j + (1 << b)] = (u - v + mod) % mod;
            }
}

int n;
ll f[N], g[N], mark[N];
int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < (1 << n); ++i) mark[i] = f[i] = s[i] - '0';
    for (int i = 0; i < (1 << n); ++i) g[i] = 1 << (n - __builtin_popcount(i));
    fwht(f, n);
    fwht(g, n);
    for (int i = 0; i < (1 << n); ++i) f[i] = f[i] * g[i] % mod;
    fwht(f, n);
    ll res = 0;
    for (int i = 0; i < (1 << n); ++i) res = (res + mark[i] * f[i]) % mod;
    for (int i = 0; i < n; ++i) res = res * ((mod + 1) / 2) % mod;
    cout << res * 3 % mod;
    return 0;
}