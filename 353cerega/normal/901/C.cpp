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
vector<ll> tin, up, was;
ll T = 0;

void dfs0(int u, int p)
{
    T++;
    tin[u] = T;
    up[u] = tin[u];
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i].X;
        if (v==p) continue;
        if (tin[v]!=0)
        {
            up[u] = min(up[u],tin[v]);
            continue;
        }
        dfs0(v,u);
        up[u] = min(up[u],up[v]);
    }
}
vector<vector<ll>> bad;
void dfs2(int u)
{
    was[u] = 1;
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i].X;
        if (tin[u]<up[v])
        {
            g[u][i].Y = 0;
            bad[v].push_back(u);
        }
        if (was[v]==0) dfs2(v);
    }
}

int mx = -1;
void dfs3(int u)
{
    mx = max(u,mx);
    was[u] = 1;
    for (int i=0;i<g[u].size();i++)
    {
        if (g[u][i].Y==0) continue;
        int v = g[u][i].X;
        if (was[v]==0) dfs3(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    up.resize(n);
    tin.resize(n);
    was.resize(n);
    bad.resize(n);
    for (int i=0;i<m;i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back({v,1});
        g[v].push_back({u,1});
    }
    for (int i=0;i<n;i++)
    {
        if (tin[i]==0) dfs0(i,-1);
    }
    for (int i=0;i<n;i++)
    {
        if (was[i]==0) dfs2(i);
    }
    for (int i=0;i<n;i++)
    {
        sort(bad[i].begin(),bad[i].end());
        sort(g[i].begin(),g[i].end());
        int x = 0;
        for (int j=0;j<g[i].size();j++)
        {
            if (x<bad[i].size() and bad[i][x]==g[i][j].X)
            {
                g[i][j].Y = 0;
                x++;
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        was[i] = 0;
    }
    vector<pair<ll,ll>> keks, kek;
    for (int i=0;i<n;i++)
    {
        if (was[i]==1) continue;
        mx = -1;
        dfs3(i);
        if (mx!=i) keks.push_back({i,mx});
    }
    sort(keks.begin(),keks.end());
    for (int i=0;i<keks.size();i++)
    {
        ll L = keks[i].X;
        ll R = keks[i].Y;
        while (kek.size()>0 and kek.back().Y>=R) kek.pop_back();
        kek.push_back({L,R});
    }
    int p = 0;
    vector<ll> pref(n+1);

    for (int i=0;i<n;i++)
    {
        ll cur = 0;
        if (p==kek.size())
        {
            cur = n-i;
        } else cur = kek[p].Y-i;
        pref[i+1] = pref[i]+cur;
        while (p<kek.size() and kek[p].X==i) p++;
    }
    ll q;
    cin >> q;
    for (int z=0;z<q;z++)
    {
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        ll L = -1;
        ll R = kek.size();
        while (R-L>1)
        {
            ll M = (R+L)/2;
            if (kek[M].Y<=B) L = M;
            else R = M;
        }
        p = L;
        if (p==-1) L = A;
        else L = max(A,kek[p].X+1);
        ll val = pref[L]-pref[A];
        ll len = B-L+1;
        val += len*(len+1)/2;
        cout << val << "\n";
    }
}