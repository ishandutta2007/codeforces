#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
//const ll mod = 998244353;
ll mod = 998244353;

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
    return __int128(a)*__int128(b)%mod;
    /*if (a*b<mod) return a*b;
    else return a*b%mod;*/
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



void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll,ll>>> g(n);
    vector<pair<ll,ll>> g2;
    vector<vector<pair<ll,ll>>> G(n);
    for (ll i=0;i<m;i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
        G[u].push_back({v,c});
        G[v].push_back({u,c});
    }
    for (ll i=0;i<k;i++)
    {
        ll v = 0;
        ll u, c;
        cin >> u >> c;
        u--;
        G[u].push_back({v,c});
        G[v].push_back({u,c});
        g2.push_back({c,u});
    }
    sort(g2.begin(),g2.end());
    vector<ll> d(n,mod*mod);
    d[0] = 0;
    set<pair<ll,ll>> kek;
    for (ll i=0;i<n;i++) kek.insert({d[i],i});
    while (kek.size()>0)
    {
        ll u = kek.begin()->Y;
        kek.erase({d[u],u});
        for (ll i=0;i<G[u].size();i++)
        {
            ll v = G[u][i].X;
            ll c = d[u]+G[u][i].Y;
            if (c>=d[v]) continue;
            kek.erase({d[v],v});
            d[v] = c;
            kek.insert({d[v],v});
        }
    }
    ll A = 0;
    vector<ll> mn(n,mod*mod);
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<g[i].size();j++)
        {
            mn[i] = min(mn[i],d[g[i][j].X]+g[i][j].Y);
        }
    }
    for (ll i=0;i<g2.size();i++)
    {
        ll u = g2[i].Y;
        if (mn[u]==d[u])
        {
            A++;
            continue;
        }
        mn[u] = d[u];
    }
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    //cin >> T;
    T = 1;
    while (T--) solve();
}