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
}

ll t[2400000];

void build()
{
    for (ll i=0;i<2400000;i++) t[i] = 0;
}

void upd(ll v, ll tl, ll tr, ll p)
{
    t[v]++;
    if (tl==tr) return;
    ll tm = (tl+tr)/2;
    if (tm>=p) upd(v*2,tl,tm,p);
    else upd(v*2+1,tm+1,tr,p);
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r) return t[v];
    ll tm = (tl+tr)/2;
    ll x = 0;
    if (l<=tm) x += get(v*2,tl,tm,l,r);
    if (r>tm) x += get(v*2+1,tm+1,tr,l,r);
    return x;
}

vector<ll> L, R, L2, h, val;
ll T = 0, T2 = 0;
ll K = 20;

vector<vector<ll>> up;

ll lca(ll u, ll v)
{
    if (h[u]<h[v]) swap(u,v);
    for (ll j=K-1;j>=0;j--)
    {
        if (h[u]-(1LL<<j)>=h[v]) u = up[u][j];
    }
    if (u==v) return u;
    for (ll j=K-1;j>=0;j--)
    {
        if (up[u][j]!=up[v][j]) u = up[u][j], v = up[v][j];
    }
    return up[u][0];
}

vector<vector<pair<ll,ll>>> g;


void dfs(ll u, ll p, ll H, ll x)
{
    h[u] = H;
    L[u] = T++;
    val[u] = x;
    up[u][0] = p;
    for (ll j=1;j<K;j++)
    {
        if (up[u][j-1]==-1) up[u][j] = -1;
        else up[u][j] = up[up[u][j-1]][j-1];
    }
    for (ll i=0;i<g[u].size();i++)
    {
        ll v = g[u][i].X;
        if (v==p) continue;
        ll x2 = x^g[u][i].Y;
        dfs(v,u,H+1,x2);
    }
    R[u] = T-1;
    L2[u] = T2++;
}

ll n;

void rec(ll u, ll c)
{
    while (u!=c)
    {
        upd(2,0,n-1,L[u]);
        upd(3,0,n-1,L2[u]);
        u = up[u][0];
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll q;
    cin >> n >> q;
    g.resize(n);
    for (ll i=0;i<n;i++) make_set(i);
    vector<vector<ll>> Q;
    vector<ll> ans(q);
    for (ll i=0;i<q;i++)
    {
        ll u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        if (find_set(u)!=find_set(v))
        {
            ans[i] = 1;
            g[u].push_back({v,x});
            g[v].push_back({u,x});
            union_sets(u,v);
            continue;
        }
        Q.push_back({u,v,x,i});
    }
    L.resize(n,-1);
    L2.resize(n,-1);
    R.resize(n);
    val.resize(n);
    h.resize(n);
    up.resize(n,vector<ll>(K));
    for (ll i=0;i<n;i++)
    {
        if (L[i]==-1) dfs(i,-1,0,0);
    }
    build();
    for (ll z=0;z<Q.size();z++)
    {
        ll u = Q[z][0];
        ll v = Q[z][1];
        ll x = Q[z][2];
        ll p = Q[z][3];
        ll c = lca(u,v);
        ll S = get(2,0,n-1,0,R[u])+get(2,0,n-1,0,R[v]);
        S -= 2*get(2,0,n-1,0,R[c]);
        if (L2[u]!=0) S -= get(3,0,n-1,0,L2[u]-1);
        if (L2[v]!=0) S -= get(3,0,n-1,0,L2[v]-1);
        if (L2[c]!=0) S += 2*get(3,0,n-1,0,L2[c]-1);
        if (S!=0 or (x^val[u]^val[v])!=1)
        {
            ans[p] = 0;
            continue;
        }
        ans[p] = 1;
        rec(u,c);
        rec(v,c);
    }
    for (ll i=0;i<q;i++)
    {
        if (ans[i]==1) cout << "YES\n";
        else cout << "NO\n";
    }
}