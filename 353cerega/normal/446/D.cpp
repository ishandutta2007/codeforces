#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
//const ll mod = 998244353;
const ll mod = 1000000009;

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
    sz[v] = 1;
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
    k -= 2;
    vector<vector<ld>> g(n,vector<ld>(n));
    vector<ll> p, p2(n,-1), d(n);
    for (ll i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        if (x==1)
        {
            p2[i] = p.size();
            p.push_back(i);
        }
    }
    for (ll i=0;i<m;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u][v] += 1;
        g[v][u] += 1;
        d[u]++, d[v]++;
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<n;j++) g[i][j] /= d[i];
    }
    vector<ll> was(n);
    for (ll j=1;j<n;j++)
    {
        if (p2[j]!=-1) continue;
        was[j] = 1;
        ld Q = 1.0/(1.0-g[j][j]);
        for (ll i=0;i<n;i++) g[j][i] *= Q;
        for (ll i=0;i<n;i++)
        {
            if (was[i]==1) continue;
            for (ll i2=0;i2<n;i2++)
            {
                if (was[i2]==1) continue;
                g[i][i2] += g[i][j]*g[j][i2];
            }
            g[i][j] = 0;
        }
    }
    vector<ld> st(n);
    st[0] = 1;
    if (p2[0]==-1)
    {
        st[0] = 0;
        was[0] = 1;
        ld Q = 1.0/(1.0-g[0][0]);
        for (ll i=0;i<n;i++)
        {
            g[0][i] *= Q;
            st[i] = g[0][i];
        }
        for (ll i=0;i<n;i++)
        {
            if (was[i]==1) continue;
            for (ll i2=0;i2<n;i2++)
            {
                if (was[i2]==1) continue;
                g[i][i2] += g[i][0]*g[0][i2];
            }
            g[i][0] = 0;
        }
    }
    ll sz = p.size();
    vector<vector<ld>> A(sz,vector<ld>(sz)), C(sz,vector<ld>(sz));
    vector<ld> val(sz);
    for (ll i=0;i<sz;i++)
    {
        C[i][i] = 1;
        val[i] = st[p[i]];
        for (ll j=0;j<sz;j++)
        {
            A[i][j] = g[p[i]][p[j]];
        }
    }
    while (k>0)
    {
        if (k&1)
        {
            vector<vector<ld>> T(sz,vector<ld>(sz));
            for (ll i=0;i<sz;i++)
            {
                for (ll j=0;j<sz;j++)
                {
                    for (ll w=0;w<sz;w++)
                    {
                        T[i][w] += A[i][j]*C[j][w];
                    }
                }
            }
            C = T;
        }
        k >>= 1;
        if (k==0) break;
        {
            vector<vector<ld>> T(sz,vector<ld>(sz));
            for (ll i=0;i<sz;i++)
            {
                for (ll j=0;j<sz;j++)
                {
                    for (ll w=0;w<sz;w++)
                    {
                        T[i][w] += A[i][j]*A[j][w];
                    }
                }
            }
            A = T;
        }
    }
    ld ans = 0;
    for (ll i=0;i<sz;i++) ans += C[i][sz-1]*val[i];
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(20);
    //freopen("input.txt","r",stdin);
    cin.tie(0);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}