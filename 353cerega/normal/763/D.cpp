//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#include <random>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
const ll mod2 = 998244353;

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
    if (a>=mod) a -= mod;
    //a %= mod;
    return a;
}

ll sub(ll a, ll b)
{
    a += mod-b;
    a %= mod;
    return a;
}

inline ll mul(ll a, ll b, ll M)
{
    if (a*b<M) return a*b;
    else return a*b%M;
}

inline ll pew(ll a, ll b, ll M)
{
    ll res = 1;
    while (b)
    {
        if (b&1LL) res = mul(res,a,M);
        a = mul(a,a,M);
        b >>= 1LL;
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
    sz[v] = 1;
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
vector<vector<ll>> val, valP;

ll A = 0, A2 = 0, Q = 0;

map<pair<ll,ll>,ll> C;

void add(pair<ll,ll> x)
{
    C[x]++;
    if (C[x]==1) Q++;
}

void err(pair<ll,ll> x)
{
    C[x]--;
    if (C[x]==0) Q--;
}

void dfs0(ll u, ll p)
{
    val[u][0] = val[u][1] = 1;
    for (ll v: g[u])
    {
        if (v==p) continue;
        dfs0(v,u);

        val[u][0] = (val[u][0]+valP[v][0])%mod;
        val[u][1] = (val[u][1]+valP[v][1])%mod2;
    }
    if (u!=0) add({val[u][0],val[u][1]});
    valP[u][0] = pew(3,val[u][0],mod);
    valP[u][1] = pew(3,val[u][1],mod2);
}

void dfs(ll u, ll p, ll H0, ll H1)
{
    if (Q>A)
    {
        A = Q;
        A2 = u;
    }
    pair<ll,ll> W = {(val[u][0]+H0)%mod,(val[u][1]+H1)%mod2};
    for (ll v: g[u])
    {
        if (v==p) continue;
        pair<ll,ll> W2 = W;
        W2.X -= valP[v][0];
        W2.Y -= valP[v][1];
        if (W2.X<0) W2.X += mod;
        if (W2.Y<0) W2.Y += mod2;
        add(W2);
        err({val[v][0],val[v][1]});
        ll H20 = pew(3,W2.X,mod);
        ll H21 = pew(3,W2.Y,mod2);
        dfs(v,u,H20,H21);
        err(W2);
        add({val[v][0],val[v][1]});
    }
}

void solve()
{
    ll n;
    cin >> n;
    g.resize(n);
    for (ll i=1;i<n;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    val.resize(n,vector<ll>(2));
    valP.resize(n,vector<ll>(2));
    dfs0(0,-1);
    dfs(0,-1,0,0);
    cout << A2+1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}