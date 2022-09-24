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
vector<ll> a, L, R, bad, bad2, h, obr;
vector<vector<ll>> up;
ll T = 0;
ll K = 20;
set<pair<ll,ll>> kek;


void dfs(ll u, ll p, ll H)
{
    L[u] = T++;
    obr[L[u]] = u;
    h[u] = H;
    up[u][0] = p;
    for (ll i=1;i<K;i++)
    {
        if (up[u][i-1]==-1) up[u][i] = -1;
        else up[u][i] = up[up[u][i-1]][i-1];
    }
    for (ll v: g[u])
    {
        if (v==p) continue;
        dfs(v,u,H+1);
    }
    kek.insert({a[u],L[u]});
    R[u] = T-1;
}

ll A = 0;

void dfs2(ll u, ll p, ll W)
{
    if (bad2[u]==1) return;
    W -= bad[u];
    if (W==0) A++;
    for (ll v: g[u])
    {
        if (v==p) continue;
        dfs2(v,u,W);
    }
}

ll get(ll u, ll v)
{
    for (ll j=K-1;j>=0;j--)
    {
        if (h[v]+(1LL<<j)<h[u]) u = up[u][j];
    }
    return u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    a.resize(n);
    g.resize(n);
    bad.resize(n);
    bad2.resize(n);
    L.resize(n);
    R.resize(n);
    h.resize(n);
    obr.resize(n);
    up.resize(n,vector<ll>(K));
    for (ll i=0;i<n;i++) cin >> a[i];
    for (ll i=1;i<n;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,-1,0);
    ll C = 0;
    for (ll i=0;i<n;i++)
    {
        auto it = kek.lower_bound({a[i],L[i]+1});
        if (it!=kek.end() and it->X==a[i] and it->Y<=R[i])
        {
            ll v = get(obr[it->Y],i);
            if (bad[v]==0)
            {
                bad[v] = 1;
                C++;
            }
        }
        it = kek.lower_bound({a[i],R[i]+1});
        it--;
        if (it->Y>L[i])
        {
            ll v = get(obr[it->Y],i);
            if (bad[v]==0)
            {
                bad[v] = 1;
                C++;
            }
        }
        it = kek.lower_bound({a[i],0});
        if (it->Y<L[i])
        {
            bad2[i] = 1;
        }
        it = kek.lower_bound({a[i],R[i]+1});
        if (it!=kek.end() and it->X==a[i])
        {
            bad2[i] = 1;
        }
    }
    dfs2(0,-1,C);
    cout << A << endl;
}