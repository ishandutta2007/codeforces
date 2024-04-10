#pragma GCC optimize("Ofast")
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


ll n;
vector<vector<ll>> g, D, D2;

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b)
{
    vector<vector<ll>> c(n,vector<ll>(n));
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<n;j++)
        {
            for (ll z=0;z<n;z++)
            {
                c[i][z] = (c[i][z]+a[i][j]*b[j][z])%mod;
            }
        }
    }
    return c;
}

vector<vector<ll>> sum(vector<vector<ll>> a, vector<vector<ll>> b)
{
    vector<vector<ll>> c(n,vector<ll>(n));
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<n;j++)
        {
            c[i][j] = (a[i][j]+b[i][j])%mod;
        }
    }
    return c;
}

vector<vector<vector<ll>>> calc(ll k)
{
    if (k<=1)
    {
        vector<vector<vector<ll>>> Q(2,vector<vector<ll>>(n,vector<ll>(n)));
        for (ll i=0;i<n;i++) Q[0][i][i] = 1;
        if (k==1) swap(Q[0],Q[1]);
        return Q;
    }
    ll k2 = k/2;
    vector<vector<vector<ll>>> P = calc(k2);
    vector<vector<vector<ll>>> A(4,vector<vector<ll>>(n,vector<ll>(n)));
    for (ll i=0;i<2;i++)
    {
        for (ll j=0;j<2;j++)
        {
            A[k-k2*2+i+j] = sum(A[k-k2*2+i+j],mul(P[i],P[j]));
        }
    }
    for (ll i=3;i>=2;i--)
    {
        A[i-1] = sum(A[i-1],mul(A[i],g));
        A[i-2] = sum(A[i-2],mul(A[i],D2));
        A.pop_back();
    }
    return A;
}

void solve()
{
    ll m, k;
    cin >> n >> m >> k;
    g.resize(n,vector<ll>(n));
    D.resize(n,vector<ll>(n));
    D2.resize(n,vector<ll>(n));
    for (ll i=0;i<m;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u][v] = g[v][u] = 1;
        D[u][u]++;
        D[v][v]++;
        D2[u][u]--;
        D2[v][v]--;
    }
    for (ll i=0;i<n;i++)
    {
        D2[i][i]++;
        if (D2[i][i]<0) D2[i][i] += mod;
    }
    vector<vector<vector<ll>>> Q = calc(k-1);
    vector<vector<ll>> M2 = mul(g,g);
    for (ll i=0;i<n;i++)
    {
        M2[i][i] -= D[i][i];
        if (M2[i][i]<0) M2[i][i] += mod;
    }
    vector<vector<ll>> A = mul(g,Q[0]);
    A = sum(A,mul(M2,Q[1]));
    ll ans = 0;
    for (ll i=0;i<n;i++) ans = (ans+A[i][i])%mod;
    cout << ans << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    //cin >> T;
    T = 1;
    while (T--) solve();
}