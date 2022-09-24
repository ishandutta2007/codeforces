#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
const ll mod = 998244353;

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


vector<ll> val, uval, cur, col, h;
vector<vector<ll>> G;
vector<vector<ll>> mx, up;

vector<vector<pair<ll,ll>>> g;
ll K = 20;



ll mxlca(ll u, ll v)
{
    if (h[u]<h[v]) swap(u,v);
    ll A = 0;
    for (ll j=K-1;j>=0;j--)
    {
        if (h[v]+(1LL<<j)<=h[u])
        {
            A = max(A,mx[u][j]);
            u = up[u][j];
        }
    }
    if (u==v) return A;
    for (ll j=K-1;j>=0;j--)
    {
        if (up[u][j]!=up[v][j])
        {
            A = max(A,mx[u][j]);
            A = max(A,mx[v][j]);
            u = up[u][j];
            v = up[v][j];
        }
    }
    A = max(A,mx[u][0]);
    A = max(A,mx[v][0]);
    return A;
}

pair<ll,ll> calc(ll u)
{
    ll C = col[u];
    ll p = uval[C];
    ll A = max(mxlca(p,u),cur[C]);
    return {val[C],A};
}

void dfs(ll u, ll p, ll H, ll C)
{
    h[u] = H;
    up[u][0] = p;
    mx[u][0] = C;
    for (ll j=1;j<K;j++)
    {
        if ((1LL<<j)<=h[u])
        {
            up[u][j] = up[up[u][j-1]][j-1];
            mx[u][j] = max(mx[u][j-1],mx[up[u][j-1]][j-1]);
        } else up[u][j] = -1;
    }
    for (ll i=0;i<g[u].size();i++)
    {
        ll v = g[u][i].X;
        ll C2 = g[u][i].Y;
        if (v==p) continue;
        dfs(v,u,H+1,C2);
    }
}

void merge(ll u, ll v, ll c)
{
    ll Cu = col[u];
    ll Cv = col[v];
    if (G[Cu].size()<G[Cv].size())
    {
        swap(Cu,Cv);
        swap(u,v);
    }
    g[u].push_back({v,c});
    g[v].push_back({u,c});
    for (ll x: G[Cv])
    {
        col[x] = Cu;
        G[Cu].push_back(x);
    }
    G[Cv].clear();
    dfs(v,u,h[u]+1,c);
    if (val[Cu]>val[Cv]) return;
    if (val[Cv]>val[Cu])
    {
        val[Cu] = val[Cv];
        uval[Cu] = uval[Cv];
        cur[Cu] = cur[Cv];
        return;
    }
    cur[Cu] = max(cur[Cu],cur[Cv]);
    cur[Cu] = max(cur[Cu],mxlca(uval[Cu],uval[Cv]));
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    val.resize(n);
    uval.resize(n);
    g.resize(n);
    G.resize(n);
    col.resize(n);
    cur.resize(n);
    up.resize(n,vector<ll>(20,-1));
    h.resize(n);
    mx.resize(n,vector<ll>(20));
    for (ll i=0;i<n;i++)
    {
        cin >> val[i];
        uval[i] = i;
        cur[i] = 0;
        col[i] = i;
        G[i].push_back(i);
    }
    vector<vector<ll>> e(n-1,vector<ll>(4));
    vector<pair<ll,ll>> ord;
    for (ll i=0;i<n-1;i++)
    {
        for (ll j=0;j<4;j++) cin >> e[i][j];
        e[i][0]--, e[i][1]--;
        ord.push_back({e[i][2],i});
    }
    vector<vector<ll>> Q(q,vector<ll>(2));
    for (ll i=0;i<q;i++)
    {
        for (ll j=0;j<2;j++) cin >> Q[i][j];
        Q[i][1]--;
        ord.push_back({Q[i][0],i-q});
    }
    sort(ord.begin(),ord.end());
    reverse(ord.begin(),ord.end());
    vector<pair<ll,ll>> ans(q);
    for (ll i=0;i<ord.size();i++)
    {
        if (ord[i].Y<0)
        {
            ord[i].Y += q;
            ans[ord[i].Y] = calc(Q[ord[i].Y][1]);
            continue;
        }
        ll u = e[ord[i].Y][0];
        ll v = e[ord[i].Y][1];
        ll c = e[ord[i].Y][3];
        merge(u,v,c);
    }
    for (ll i=0;i<q;i++) cout << ans[i].X << " " << ans[i].Y << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}