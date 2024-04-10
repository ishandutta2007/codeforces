#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
#define X first
#define Y second

const ll mod = 998244353;

ll gcd(ll a, ll b)
{
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
const int root = 31;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/


/*void fft (vector<int> & a, bool invert) {
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


int parent[600001];
int rnk[600001];

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

//ll t[1200000];
//ll del[1200000];

/*void build()
{
    for (int i=0;i<1200000;i++)
    {
        t[i] = 0;
        //del[i] = 0;
    }
}*/

/*void push(int v, int tl, int tr, int tm)
{
    t[2*v].X += del[v];
    t[2*v+1].X += del[v];
    del[2*v] += del[v];
    del[2*v+1] += del[v];
    del[v] = 0;
}*/

/*void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        //del[v] += val;

        //t[v] += val*(tr-tl+1);
        return;
    }
    int tm = (tl + tr) / 2;
    //if (del[v]!=0) push(v,tl,tr,tm);
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
    t[v] = min(t[2*v],t[2*v+1]);
}*/

/*
void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        //del[v] += val;
        t[v] += val;
        return;
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
    //t[v] = min(t[2*v],t[2*v+1]);
}


ll get (int v, int tl, int tr, int p) {
    //if (del[v]!=0 and tl!=tr) push(v,tl,tr,tm);
    if (tl==tr)
    {
        return t[v];
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (p<=tm) return t[v]+get(2*v,tl,tm,p);
    else return t[v]+get(2*v+1,tm+1,tr,p);
}*/

vector<vector<pair<ll,ll>>> g;
vector<ll> a, b, h, was;
vector<pair<ll,ll>> s, up;

void dfs0(int u, int x)
{
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i].X;
        if (h[v]!=-1) continue;
        h[v] = h[u]+1;
        up[v] = {u,g[u][i].Y};
        dfs0(v,g[u][i].Y);
    }
    if (x!=-1)
    {
        ll w = a[u];
        a[s[x].X] -= w;
        a[s[x].Y] -= w;
        b[x] += w;
    }
}

int dfs2(int u)
{
    was[u] = 1;
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i].X;
        if (h[v]%2!=h[u]%2) continue;
        int x = g[u][i].Y;
        ll L = a[u]/2;
        a[s[x].X] -= L;
        a[s[x].Y] -= L;
        b[x] += L;
        while (u!=v)
        {
            L *= -1;
            x = up[v].Y;
            a[s[x].X] -= L;
            a[s[x].Y] -= L;
            b[x] += L;
            v = up[v].X;
        }
        return 1;
    }
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i].X;
        if (was[v]==1) continue;
        int x = g[u][i].Y;
        ll L = a[u];
        a[s[x].X] -= L;
        a[s[x].Y] -= L;
        b[x] += L;
        if (dfs2(v)) return 1;
        a[s[x].X] += L;
        a[s[x].Y] += L;
        b[x] -= L;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    a.resize(n);
    g.resize(n);
    h.resize(n,-1);
    up.resize(n);
    was.resize(n);
    b.resize(m);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        s.push_back({u,v});
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    h[0] = 0;
    dfs0(0,-1);
    if (a[0]==0)
    {
        cout << "YES\n";
        for (int i=0;i<m;i++)
        {
            cout << b[i] << "\n";
        }
        return 0;
    }
    int ok = dfs2(0);
    if (ok==1)
    {
        cout << "YES\n";
        for (int i=0;i<m;i++)
        {
            cout << b[i] << "\n";
        }
        return 0;
    }
    cout << "NO\n";
}