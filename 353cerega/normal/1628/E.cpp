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


ll t[2200000], t2[2200000], F[2200000], mx[2200000], mn[2200000];

vector<ll> a, a2;

void build(ll v, ll tl, ll tr)
{
    if (tl==tr)
    {
        mx[v] = a[tl];
        mn[v] = a[tl];
        t[v] = mod;
        t2[v] = -1;
        F[v] = -1;
        return;
    }
    ll tm = (tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    mx[v] = max(mx[v*2],mx[v*2+1]);
    mn[v] = min(mn[v*2],mn[v*2+1]);
    t[v] = min(t[2*v],t[2*v+1]);
    t2[v] = max(t2[2*v],t2[2*v+1]);
}

void push(ll v)
{
    if (F[v]==0) return;
    if (F[v]==1)
    {
        F[2*v] = F[v];
        t[2*v] = mn[2*v];
        t2[2*v] = mx[2*v];
        F[2*v+1] = F[v];
        t[2*v+1] = mn[2*v+1];
        t2[2*v+1] = mx[2*v+1];
    }
    if (F[v]==-1)
    {
        F[2*v] = F[v];
        t[2*v] = mod;
        t2[2*v] = -1;
        F[2*v+1] = F[v];
        t[2*v+1] = mod;
        t2[2*v+1] = -1;
    }
    F[v] = 0;
}

void upd(ll v, ll tl, ll tr, ll l, ll r, ll f)
{
    if (tl>=l and tr<=r)
    {
        if (f==1)
        {
            F[v] = 1;
            t[v] = mn[v];
            t2[v] = mx[v];
        }
        else
        {
            F[v] = -1;
            t[v] = mod;
            t2[v] = -1;
        }
        return;
    }
    ll tm = (tl+tr)/2;
    push(v);
    if (tm>=l) upd(v*2,tl,tm,l,r,f);
    if (tm<r) upd(v*2+1,tm+1,tr,l,r,f);
    t[v] = min(t[2*v],t[2*v+1]);
    t2[v] = max(t2[2*v],t2[2*v+1]);
}

ll K = 20;


ll par[700000];


void make_set(ll v)
{
    par[v] = v;
}

ll find_set(ll v)
{
    if (par[v]==v) return v;
    return par[v] = find_set(par[v]);
}

vector<ll> dp, h;
vector<vector<ll>> g, up;
ll T = 0;
ll n;

void dfs(ll u, ll p, ll H)
{
    h[u] = H;
    up[u][0] = p;
    if (u<n)
    {
        a2[T] = u;
        a[u] = T++;
    }
    for (ll j=1;j<K;j++)
    {
        if (up[u][j-1]==-1) up[u][j] = -1;
        else up[u][j] = up[up[u][j-1]][j-1];
    }
    for (ll v: g[u]) dfs(v,u,H+1);
}

ll lca(ll u, ll v)
{
    if (h[u]<h[v]) swap(u,v);
    for (ll j=K-1;j>=0;j--) if (h[u]>=h[v]+(1LL<<j)) u = up[u][j];
    if (u==v) return u;
    for (ll j=K-1;j>=0;j--) if (up[u][j]!=up[v][j]) u = up[u][j], v = up[v][j];
    return up[u][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll q;
    cin >> n >> q;
    ll N = n*2-1;
    dp.resize(N);
    g.resize(N);
    a.resize(n);
    a2.resize(n);
    h.resize(N);
    up.resize(N,vector<ll>(K));
    vector<pair<ll,pair<ll,ll>>> e(n-1);
    for (ll i=0;i<N;i++) make_set(i);
    for (ll i=0;i+1<n;i++)
    {
        cin >> e[i].Y.X >> e[i].Y.Y >> e[i].X;
        e[i].Y.X--, e[i].Y.Y--;
    }
    sort(e.begin(),e.end());
    for (ll i=0;i<e.size();i++)
    {
        ll Q = n+i;
        dp[Q] = e[i].X;
        ll u = find_set(e[i].Y.X);
        ll v = find_set(e[i].Y.Y);
        g[Q].push_back(u);
        g[Q].push_back(v);
        par[u] = Q;
        par[v] = Q;
    }
    dfs(N-1,-1,0);
    build(1,0,n-1);
    for (ll i=0;i<q;i++)
    {
        ll w;
        cin >> w;
        if (w==1)
        {
            ll L, R;
            cin >> L >> R;
            L--, R--;
            upd(1,0,n-1,L,R,1);
            continue;
        }
        if (w==2)
        {
            ll L, R;
            cin >> L >> R;
            L--, R--;
            upd(1,0,n-1,L,R,-1);
            continue;
        }
        ll u;
        cin >> u;
        u--;
        if (t2[1]==-1)
        {
            cout << -1 << "\n";
            continue;
        }
        u = lca(u,a2[t[1]]);
        u = lca(u,a2[t2[1]]);
        if (dp[u]==0) cout << -1 << "\n";
        else cout << dp[u] << "\n";
    }
}