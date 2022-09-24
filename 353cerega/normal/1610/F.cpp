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


vector<set<pair<ll,pair<ll,ll>>>> g, g2;
vector<ll> d, d2, col, inv, F;
ll M;

void add_e(ll u, ll v)
{
    g[u].insert({v,{M,1}});
    g[v].insert({u,{M,-1}});
    col.push_back(-1);
    inv.push_back(0);
    F.push_back(0);
    M++;
}

void del(ll u)
{
    pair<ll,pair<ll,ll>> e1, e2;
    {
        auto it = g[u].begin();
        e1 = *it;
        g[u].erase(e1);
        it = g[u].begin();
        e2 = *it;
        g[u].erase(e2);
        d[u] -= 2;
    }
    ll v1 = e1.X;
    ll v2 = e2.X;
    g[v1].erase({u,{e1.Y.X,e1.Y.Y*-1}});
    g[v2].erase({u,{e2.Y.X,e2.Y.Y*-1}});
    if (v1==v2)
    {
        d[v1]--;
        d[v2]--;
        if (e1.Y.Y!=e2.Y.Y)
        {
            F[e1.Y.X] = 1;
            F[e2.Y.X] = 1;
        } else
        {
            F[e1.Y.X] = 1;
            F[e2.Y.X] = -1;
        }
        return;
    }
    col[e1.Y.X] = M;
    col[e2.Y.X] = M;
    if (e1.Y.Y==1) inv[e1.Y.X] = 1;
    if (e2.Y.Y==-1) inv[e2.Y.X] = 1;
    add_e(v1,v2);
}

void add_e2(ll u, ll v)
{
    g2[u].insert({v,{M,1}});
    g2[v].insert({u,{M,-1}});
    col.push_back(-1);
    inv.push_back(0);
    F.push_back(0);
    M++;
}

void del2(ll u)
{
    pair<ll,pair<ll,ll>> e1, e2;
    {
        auto it = g2[u].begin();
        e1 = *it;
        g2[u].erase(e1);
        it = g2[u].begin();
        e2 = *it;
        g2[u].erase(e2);
        d2[u] -= 2;
    }
    ll v1 = e1.X;
    ll v2 = e2.X;
    g2[v1].erase({u,{e1.Y.X,e1.Y.Y*-1}});
    g2[v2].erase({u,{e2.Y.X,e2.Y.Y*-1}});
    if (v1==v2)
    {
        d2[v1]--;
        d2[v2]--;
        if (e1.Y.Y!=e2.Y.Y)
        {
            F[e1.Y.X] = 1;
            F[e2.Y.X] = 1;
        } else
        {
            F[e1.Y.X] = 1;
            F[e2.Y.X] = -1;
        }
        return;
    }
    col[e1.Y.X] = M;
    col[e2.Y.X] = M;
    if (e1.Y.Y==1) inv[e1.Y.X] = 1;
    if (e2.Y.Y==-1) inv[e2.Y.X] = 1;
    add_e2(v1,v2);
}

vector<ll> was, W;

void dfs(ll u)
{
    was[u] = 1;
    if (g[u].size()!=0)
    {
        pair<ll,pair<ll,ll>> e1;
        auto it = g[u].begin();
        e1 = *it;
        g[u].erase(e1);
        ll v = e1.X;
        g[v].erase({u,{e1.Y.X,e1.Y.Y*-1}});
        ll T = 1;
        if (W[u]==-2) T = -1;
        W[u] -= T;
        W[v] += T;
        F[e1.Y.X] = T*e1.Y.Y;
        if (was[v]==0) dfs(v);
    }
    if (g2[u].size()!=0)
    {
        pair<ll,pair<ll,ll>> e1;
        auto it = g2[u].begin();
        e1 = *it;
        g2[u].erase(e1);
        ll v = e1.X;
        g2[v].erase({u,{e1.Y.X,e1.Y.Y*-1}});
        ll T = 1;
        if (W[u]==-1) T = -1;
        W[u] -= T*2;
        W[v] += T*2;
        F[e1.Y.X] = T*e1.Y.Y;
        if (was[v]==0) dfs(v);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    M = m;
    vector<vector<ll>> e(m);
    col.resize(m,-1);
    F.resize(m);
    inv.resize(m,0);
    g.resize(n);
    g2.resize(n);
    d.resize(n);
    d2.resize(n);
    for (ll i=0;i<m;i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        if (c==1)
        {
            d[u]++;
            d[v]++;
            g[u].insert({v,{i,1}});
            g[v].insert({u,{i,-1}});
        }
        else
        {
            d2[u]++;
            d2[v]++;
            g2[u].insert({v,{i,1}});
            g2[v].insert({u,{i,-1}});
        }
        e[i] = {u,v,c};
    }
    for (ll i=0;i<n;i++)
    {
        while (d[i]>=2) del(i);
        while (d2[i]>=2) del2(i);
    }
    was.resize(n);
    W.resize(n);
    for (ll i=0;i<n;i++)
    {
        if (was[i]==0) dfs(i);
    }
    ll k = 0;
    for (ll i=0;i<n;i++)
    {
        if (W[i]==-1 or W[i]==1) k++;
    }
    cout << k << endl;
    vector<vector<pair<ll,ll>>> G(M);
    vector<ll> q;
    for (ll j=0;j<M;j++)
    {
        if (col[j]!=-1) G[col[j]].push_back({j,inv[j]});
        else q.push_back(j);
    }
    for (ll z=0;z<q.size();z++)
    {
        ll p = q[z];
        for (ll i=0;i<G[p].size();i++)
        {
            ll v = G[p][i].X;
            ll c = F[p];
            if (G[p][i].Y==1) c *= -1;
            F[v] = c;
            q.push_back(v);
        }
    }
    for (ll i=0;i<m;i++)
    {
        if (F[i]==-1) cout << 2;
        else cout << 1;
    }
}