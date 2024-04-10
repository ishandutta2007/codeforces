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


ll t[1200000], t2[1200000], del[1200000];

void build(ll v, ll tl, ll tr)
{
    t[v] = 0;
    t2[v] = tl;
    del[v] = 0;
    if (tl==tr) return;
    ll tm = (tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
}

void push(ll v)
{
    if (del[v]!=0)
    {
        del[v*2] += del[v];
        del[v*2+1] += del[v];
        t[v*2] += del[v];
        t[v*2+1] += del[v];
        del[v] = 0;
    }
}

void add(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (tl>=l and tr<=r)
    {
        t[v] += val;
        del[v] += val;
        return;
    }
    push(v);
    ll tm = (tl+tr)/2;
    if (tm>=l) add(v*2,tl,tm,l,r,val);
    if (tm<r) add(v*2+1,tm+1,tr,l,r,val);
    if (t[v*2]>=t[v*2+1])
    {
        t[v] = t[v*2];
        t2[v] = t2[v*2];
    } else
    {
        t[v] = t[v*2+1];
        t2[v] = t2[v*2+1];
    }
}


vector<vector<ll>> g;
vector<ll> L, R, was, up, obr;
ll Q = 0;
ll n;

void dfs(ll u, ll p)
{
    L[u] = Q;
    obr[Q] = u;
    up[u] = p;
    was[u] = 0;
    Q++;
    for (ll v: g[u])
    {
        if (v==p) continue;
        dfs(v,u);
    }
    R[u] = Q-1;
    add(1,0,n-1,L[u],R[u],1);
}

void rec(ll u)
{
    if (u==-1 or was[u]==1) return;
    was[u] = 1;
    add(1,0,n-1,L[u],R[u],-1);
    rec(up[u]);
}

void solve()
{
    ll k;
    cin >> n >> k;
    build(1,0,n-1);
    g.clear();
    g.resize(n);
    L.resize(n);
    R.resize(n);
    up.resize(n);
    was.resize(n);
    obr.resize(n);
    for (ll i=1;i<n;i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    Q = 0;
    dfs(0,-1);
    ll A = n;
    ll mx = 0;
    for (ll z=1;z<=k;z++)
    {
        ll u = obr[t2[1]];
        ll W = t[1];
        A -= W;
        ll w = n-z-A;
        mx = max(mx,w*(z-A));
        rec(u);
    }
    if (A<k)
    {
        cout << mx << endl;
        return;
    }
    ll mn = mod*mod;
    for (ll z=0;z<=A;z++)
    {
        ll W = n-k-z;
        mn = min(mn,W*(k-z));
    }
    cout << mn << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    //cin >> T;
    T = 1;
    while (T--)
    {
        solve();
    }
}