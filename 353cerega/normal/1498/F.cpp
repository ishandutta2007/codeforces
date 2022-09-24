#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a==0 or b==0) return a+b;
    return gcd(b,a%b);
}


ll sum(ll a, ll b)
{
    a += b;
    a %= mod;
    return a;
}

ll sub(ll a, ll b)
{
    a += mod-b;
    a %= mod;
    return a;
}

inline ll mul(ll a, ll b)
{
    if (a*b<mod) return a*b;
    return a*b%mod;
}

inline ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1) res = mul(res,a);
        a = mul(a,a);
        b /= 2;
    }
    return res;
}



/*const int MOD = 998244353;
const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;
const int root = 30;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/

/*
void fft (vector<int> & a, bool invert) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = pew(n, mod-2);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}*/

/*
int parent[1200001];
int rnk[1200001];


void make_set (int v) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets (int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}*/

vector<vector<ll>> g;
vector<vector<ll>> dp, dp2;
vector<ll> a;
ll k;

void dfs(ll u, ll p)
{
    for (ll v: g[u])
    {
        if (v==p) continue;
        dfs(v,u);
        for (ll i=0;i<k;i++)
        {
            dp[u][(i+1)%k] ^= dp[v][i];
        }
    }
    dp[u][0] ^= a[u];
}

void dfs2(ll u, ll p)
{
    for (ll v: g[u])
    {
        if (v==p) continue;
        dp2[v] = dp[v];
        for (ll i=0;i<k;i++)
        {
            dp2[v][(i+1)%k] ^= dp2[u][i]^dp[v][(i+k-1)%k];
        }
        dfs2(v,u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n >> k;
    k *= 2;
    g.resize(n);
    a.resize(n);
    dp.resize(n,vector<ll>(k));
    dp2.resize(n,vector<ll>(k));
    for (ll i=1;i<n;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (ll i=0;i<n;i++) cin >> a[i];
    dfs(0,-1);
    dp2[0] = dp[0];
    dfs2(0,-1);
    for (ll i=0;i<n;i++)
    {
        ll S = 0;
        for (ll j=k/2;j<k;j++)
        {
            S ^= dp2[i][j];
        }
        if (S==0) cout << 0 << " ";
        else cout << 1 << " ";
    }
}