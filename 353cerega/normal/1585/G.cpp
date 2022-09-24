//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = int;
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


const ll mx = 3000000;
vector<ll> S, F, sz, nxt(3000000), val(3000000);
vector<vector<ll>> g;
vector<set<ll>> kek;
vector<ll> dp;
ll C = 0;

ll add(ll l, ll r, ll v)
{
    val[C] = v;
    if (l!=-1) nxt[l] = C;
    if (r!=-1) nxt[C] = r;
    return C++;
}

void dfs(ll u)
{
    dp[u] = 0;
    if (g[u].size()==0)
    {
        dp[u] = 1;
        ll x = add(-1,-1,0);
        S[u] = x;
        F[u] = x;
        sz[u] = 1;
        kek[u].insert(0);
        return;
    }
    ll Q = 0;
    if (g[u].size()==1)
    {
        for (ll v: g[u])
        {
            dfs(v);
            Q ^= dp[v];
            S[u] = S[v];
            F[u] = F[v];
            sz[u] = sz[v];
            swap(kek[u],kek[v]);
            dp[u] = dp[v];
        }
        ll x = add(-1,S[u],Q);
        S[u] = x;
        sz[u]++;
        kek[u].insert(Q);
        while (kek[u].count(dp[u])!=0) dp[u]++;
        return;
    }
    ll mn = mod;
    for (ll i=0;i<g[u].size();i++)
    {
        ll v = g[u][i];
        dfs(v);
        mn = min(mn,sz[v]);
        Q ^= dp[v];
    }
    sz[u] = mn;
    F[u] = -1;
    for (ll j=0;j<mn;j++)
    {
        F[u] = add(F[u],-1,0);
        if (j==0) S[u] = F[u];
    }
    for (ll v: g[u])
    {
        ll p = S[u];
        ll p2 = S[v];
        for (ll z=0;z<mn;z++)
        {
            val[p] ^= val[p2];
            p = nxt[p];
            p2 = nxt[p2];
        }
    }
    ll x = add(-1,S[u],Q);
    S[u] = x;
    sz[u]++;
    ll p = S[u];
    for (ll z=0;z<sz[u];z++)
    {
        kek[u].insert(val[p]);
        p = nxt[p];
    }
    while (kek[u].count(dp[u])!=0) dp[u]++;
}

void solve()
{
    ll n;
    cin >> n;
    g.clear();
    g.resize(n);
    dp.clear();
    dp.resize(n);
    kek.clear();
    kek.resize(n);
    S.clear();
    S.resize(n);
    F.clear();
    F.resize(n);
    sz.clear();
    sz.resize(n);
    vector<ll> R;
    for (ll i=0;i<n;i++)
    {
        ll p;
        cin >> p;
        p--;
        if (p==-1) R.push_back(i);
        else g[p].push_back(i);
    }
    ll A = 0;
    for (ll i=0;i<R.size();i++)
    {
        dfs(R[i]);
        A ^= dp[R[i]];
    }
    if (A==0) cout << "NO\n";
    else cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}