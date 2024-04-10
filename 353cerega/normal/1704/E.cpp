//#pragma GCC optimize("Ofast")
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


vector<vector<ll>> g;
vector<ll> was, q;

void dfs (ll u) {
    was[u] = 1;
    for (ll v: g[u])
    {
        if (was[v]==0) dfs(v);
    }
    q.push_back(u);
}



void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    g.clear();
    g.resize(n);
    was.clear();
    was.resize(n);
    q.clear();
    for (ll i=0;i<m;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    for (ll i=0;i<n;i++)
    {
        if (was[i]==0) dfs(i);
    }
    reverse(q.begin(),q.end());
    vector<ll> p(n);
    for (ll i=0;i<n;i++)
    {
        p[q[i]] = i;
    }
    vector<ll> d(n);
    vector<vector<ll>> dp(n,vector<ll>(n));
    dp[n-1][0] = 1;
    ll INF = 1100;
    for (ll i=n-1;i>=0;i--)
    {
        ll u = q[i];
        ll x = a[u];
        for (ll v: g[u])
        {
            ll v2 = p[v];
            for (ll j=0;j+1<n;j++)
            {
                dp[i][j+1] += dp[v2][j];
            }
        }
        for (ll j=0;j<n;j++)
        {
            dp[i][j] = min(dp[i][j],INF);
            d[j] += x*dp[i][j];
            d[j] = min(d[j],INF);
        }
    }
    vector<ll> a2(n);
    for (ll i=0;i<n;i++) a2[i] = a[i];
    for (ll W=0;W<=INF+5;W++)
    {
        vector<ll> w;
        for (ll i=0;i<n;i++) if (a2[i]>0) w.push_back(i);
        if (w.size()==0)
        {
            cout << W << "\n";
            return;
        }
        for (ll x: w)
        {
            a2[x]--;
            for (ll v: g[x]) a2[v]++;
        }
    }
    ll A = 0;
    ll S = 0;
    for (ll i=0;i<n;i++)
    {
        S += d[i];
        if (S==0) A++;
        else S--;
    }
    for (ll i=0;i<n;i++)
    {
        ll u = q[i];
        for (ll v: g[u])
        {
            a[v] = (a[v]+a[u])%mod;
        }
    }
    A = (A+a[q[n-1]])%mod;
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}