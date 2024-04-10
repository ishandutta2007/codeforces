#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = double;

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


const ll M = 400;

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m, q;
    cin >> n >> m >> q;
    ll k;
    cin >> k;
    vector<ll> was(n);
    for (ll i=0;i<k;i++)
    {
        ll x;
        cin >> x;
        x--;
        was[x] = 1;
    }
    vector<vector<pair<ll,ll>>> g(n);
    vector<ll> C(n);
    for (ll i=0;i<m;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back({v,1});
        g[v].push_back({u,1});
    }
    vector<vector<ll>> a(q);
    for (ll i=0;i<q;i++)
    {
        a[i].resize(3);
        string s;
        ll u;
        cin >> s >> a[i][1];
        a[i][1]--;
        if (s=="A" or s=="D")
        {
            cin >> a[i][2];
            a[i][2]--;
        }
        if (s=="O") a[i][0] = 0;
        if (s=="F") a[i][0] = 1;
        if (s=="A") a[i][0] = 2;
        if (s=="D") a[i][0] = 3;
        if (s=="C") a[i][0] = 4, C[a[i][1]]++;
    }
    vector<vector<pair<ll,ll>>> g2(n);
    vector<ll> ans(n);
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<g[i].size();j++)
        {
            ll v = g[i][j].X;
            if (C[v]>=M)
            {
                g2[i].push_back({g[i][j]});
                if (was[i]==1) ans[v]++;
            }
        }
    }
    for (ll i=0;i<q;i++)
    {
        if (a[i][0]==0)
        {
            ll u = a[i][1];
            was[u] = 1;
            for (ll j=0;j<g2[u].size();j++)
            {
                ll v = g2[u][j].X;
                ll c = g2[u][j].Y;
                ans[v] += c;
            }
            continue;
        }
        if (a[i][0]==1)
        {
            ll u = a[i][1];
            was[u] = 0;
            for (ll j=0;j<g2[u].size();j++)
            {
                ll v = g2[u][j].X;
                ll c = g2[u][j].Y;
                ans[v] -= c;
            }
            continue;
        }
        if (a[i][0]==2)
        {
            ll u = a[i][1];
            ll v = a[i][2];
            g[u].push_back({v,1});
            g[v].push_back({u,1});
            if (C[v]>=M)
            {
                ans[v] += was[u];
                g2[u].push_back({v,1});
            }
            if (C[u]>=M)
            {
                ans[u] += was[v];
                g2[v].push_back({u,1});
            }
            continue;
        }
        if (a[i][0]==3)
        {
            ll u = a[i][1];
            ll v = a[i][2];
            g[u].push_back({v,-1});
            g[v].push_back({u,-1});
            if (C[v]>=M)
            {
                ans[v] -= was[u];
                g2[u].push_back({v,-1});
            }
            if (C[u]>=M)
            {
                ans[u] -= was[v];
                g2[v].push_back({u,-1});
            }
            continue;
        }
        if (a[i][0]==4)
        {
            ll u = a[i][1];
            if (C[u]>=M)
            {
                cout << ans[u] << "\n";
                continue;
            }
            ll x = 0;
            for (ll j=0;j<g[u].size();j++)
            {
                ll v = g[u][j].X;
                ll c = g[u][j].Y;
                x += c*was[v];
            }
            cout << x << "\n";
        }
    }
}