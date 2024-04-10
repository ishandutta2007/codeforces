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


vector<vector<ll>> g, g2;
vector<ll> nxt;
vector<vector<ll>> was, was2;


void dfs(ll u, ll c)
{
    was[u][c] = 1;
    for (ll v: g[u-1])
    {
        if (nxt[u]<v-1) continue;
        if (was[v][1-c]==1) continue;
        dfs(v,1-c);
    }
}

void dfs2(ll u, ll c)
{
    was2[u][c] = 1;
    for (ll v: g2[u+1])
    {
        if (nxt[v+1]<u) continue;
        if (was2[v][1-c]==1) continue;
        dfs2(v,1-c);
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    n += 2;
    nxt.resize(n);
    was.clear();
    was.resize(n,vector<ll>(2));
    was2.clear();
    was2.resize(n,vector<ll>(2));
    for (ll i=0;i<n;i++) nxt[i] = i;
    g.clear();
    g2.clear();
    g.resize(n);
    g2.resize(n);
    nxt[0] = 1;
    nxt[n-2] = n-1;
    for (ll j=2;j<n;j++)
    {
        g[0].push_back(j);
        g2[j].push_back(0);
    }
    for (ll j=0;j+2<n;j++)
    {
        g[j].push_back(n-1);
        g2[n-1].push_back(j);
    }
    for (ll i=0;i<m;i++)
    {
        ll a, b;
        cin >> a >> b;
        if (b==a+1) nxt[a] = b;
        else
        {
            g[a].push_back(b);
            g2[b].push_back(a);
        }
    }
    for (ll i=n-1;i>=0;i--)
    {
        nxt[i] = nxt[nxt[i]];
    }
    if (nxt[0]==n-1)
    {
        cout << (n-2)*(n-3)/2 << "\n";
        return;
    }
    ll a = nxt[0];
    dfs(a+1,0);
    dfs2(a,0);
    vector<ll> C(4), C2(4);
    for (ll i=0;i<n;i++)
    {
        if (nxt[i]==n-1)
        {
            ll b = 0;
            if (was[i][0]==1) b += 1;
            if (was[i][1]==1) b += 2;
            C[b]++;
        }
        if (nxt[0]>=i)
        {
            ll b = 0;
            if (was2[i][0]==1) b += 1;
            if (was2[i][1]==1) b += 2;
            C2[b]++;
        }
    }
    ll A = C[3]*(C2[1]+C2[2]+C2[3])+C[1]*(C2[3]+C2[1])+C[2]*(C2[3]+C2[2]);
    if (nxt[a+1]==n-1) A--;
    cout << A << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}