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

inline ll mul(ll a, ll b)
{
    if (a*b<mod) return a*b;
    else return a*b%mod;
}

inline ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1LL) res = mul(res,a);
        a = mul(a,a);
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


vector<vector<ll>> g, G;
vector<ll> was, sz, mx, q, h, prv;
vector<vector<ll>> d, C, col, M;
ll K = 19;

void dfs0(ll u, ll p)
{
    mx[u] = 0;
    sz[u] = 1;
    q.push_back(u);
    for (ll v: g[u])
    {
        if (v==p or was[v]==1) continue;
        dfs0(v,u);
        sz[u] += sz[v];
        mx[u] = max(mx[u],sz[v]);
    }
}

void dfs1(ll u, ll p, ll D, ll H)
{
    d[H][u] = D;
    C[H][u] = D;
    for (ll v: g[u])
    {
        if (v==p or was[v]==1) continue;
        col[H][v] = col[H][u];
        dfs1(v,u,D+1,H);
        C[H][u] = max(C[H][v],C[H][u]);
    }
}

ll dfs(ll u, ll H)
{
    q.clear();
    dfs0(u,-1);
    ll S = q.size();
    ll mn = mod;
    ll u2 = u;
    for (ll x: q)
    {
        mx[x] = max(mx[x],S-sz[x]);
        if (mn>mx[x])
        {
            mn = mx[x];
            u = x;
        }
    }
    prv[u] = u2;
    h[u] = H;
    col[H][u] = u;
    dfs1(u,-1,0,H);
    was[u] = 1;
    for (ll v: g[u])
    {
        if (was[v]==1) continue;
        if (M[u][2]<C[H][v])
        {
            M[u][2] = C[H][v];
            for (ll j=1;j>=0;j--) if (M[u][j]<M[u][j+1]) swap(M[u][j],M[u][j+1]);
        }
    }
    for (ll v: g[u])
    {
        if (was[v]==1) continue;
        ll v2 = dfs(v,H+1);
        G[u].push_back(v2);
    }
    return u;
}

ll calc1(ll R, ll H, ll u, ll D)
{
    ll R2 = col[H+1][u];
    if (R2==-1) return M[R][0]+D;
    ll u2 = prv[R2];
    ll S = M[R][0];
    if (C[H][u2]==S) S = M[R][1];
    return max(S+D+d[H][u],calc1(R2,H+1,u,D));
}

ll calc2(ll R, ll H, ll u, ll v, ll D1, ll D2)
{
    if (u==v) return calc1(R,H,u,min(D1,D2));
    ll DD1 = d[H][u]+D1;
    ll DD2 = d[H][v]+D2;
    if (DD1>DD2)
    {
        swap(u,v);
        swap(D1,D2);
        swap(DD1,DD2);
    }
    ll uR2 = col[H+1][u];
    ll vR2 = col[H+1][v];
    if (vR2==-1) return calc1(R,H,u,D1);
    ll v2 = prv[vR2];
    ll S = 0;
    if (uR2==-1)
    {
        S = M[R][0];
        if (C[H][v2]==S) S = M[R][1];
        S = max(S+D1,calc2(vR2,H+1,v2,v,DD1+1,D2));
        return S;
    }
    ll u2 = prv[uR2];
    if (u2==v2)
    {
        S = M[R][0];
        if (C[H][v2]==S) S = M[R][1];
        S = max(S+DD1,calc2(vR2,H+1,u,v,D1,D2));
        return S;
    }
    ll p0 = 0;
    ll F1 = 0;
    if (M[R][p0]==C[H][v2])
    {
        p0++;
        F1 = 1;
    }
    if (M[R][p0]==C[H][u2]) p0++;
    if (F1==0 and M[R][p0]==C[H][v2]) p0++;
    S = DD1+M[R][p0];
    S = max(S,calc1(uR2,H+1,u,D1));
    S = max(S,calc2(vR2,H+1,v2,v,DD1+1,D2));
    return S;
}

void solve()
{
    ll n;
    cin >> n;
    g.resize(n), G.resize(n);
    was.resize(n);
    sz.resize(n), mx.resize(n);
    d.resize(K,vector<ll>(n));
    C.resize(K,vector<ll>(n));
    col.resize(K,vector<ll>(n,-1));
    M.resize(n,vector<ll>(3));
    h.resize(n);
    prv.resize(n);
    for (ll i=1;i<n;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll m;
    cin >> m;
    ll R = dfs(0,0);
    for (ll i=0;i<m;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        cout << calc2(R,0,u,v,0,0) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    cin.tie(0);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}