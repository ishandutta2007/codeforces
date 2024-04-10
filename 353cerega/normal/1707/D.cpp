//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

ll mod = 1000000007;
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


ll n;

vector<vector<ll>> g;
vector<vector<ll>> dp;

void dfs(ll u, ll p)
{
    vector<ll> vs;
    for (ll v: g[u])
    {
        if (v==p) continue;
        vs.push_back(v);
        dfs(v,u);
    }
    ll sz = vs.size();
    vector<vector<ll>> pr(sz+1,vector<ll>(n-1));
    vector<vector<ll>> suf(sz+1,vector<ll>(n-1));
    for (ll i=0;i+1<n;i++)
    {
        pr[0][i] = 1;
        suf[sz][i] = 1;
    }
    for (ll i=0;i<sz;i++)
    {
        ll S = 0;
        for (ll j=1;j<n;j++)
        {
            S = (S+dp[vs[i]][j])%mod;
            pr[i+1][j-1] = S;
        }
    }
    for (ll i=sz-1;i>=0;i--)
    {
        for (ll j=0;j+1<n;j++)
        {
            suf[i][j] = suf[i+1][j]*pr[i+1][j]%mod;
        }
    }
    for (ll i=1;i<=sz;i++)
    {
        for (ll j=0;j+1<n;j++)
        {
            pr[i][j] = pr[i-1][j]*pr[i][j]%mod;
        }
    }
    for (ll j=0;j+1<n;j++)
    {
        dp[u][j+1] = pr[sz][j];
    }
    if (u==0) return;
    for (ll i=0;i<sz;i++)
    {
        ll S = 0;
        for (ll j=0;j+1<n;j++)
        {
            dp[u][j+1] = (dp[u][j+1]+dp[vs[i]][j+1]*S)%mod;
            S = (S+pr[i][j]*suf[i+1][j])%mod;
        }
    }
}


void solve()
{
    cin >> n >> mod;
    g.resize(n);
    for (ll i=1;i<n;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp.resize(n,vector<ll>(n));
    dfs(0,-1);
    vector<ll> f(n+1), f2(n+1);
    f[0] = f2[0] = 1;
    for (ll i=1;i<=n;i++)
    {
        f[i] = f[i-1]*i%mod;
        f2[i] = pew(f[i],mod-2);
    }
    for (ll i=1;i<n;i++)
    {
        for (ll j=i+1;j<n;j++)
        {
            dp[0][j] = (dp[0][j]+mod*mod-f[j]*f2[i]%mod*f2[j-i]%mod*dp[0][i])%mod;
        }
    }
    for (ll i=1;i<n;i++) cout << dp[0][i] << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}