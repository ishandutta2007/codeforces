#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
//const ll mod = 998244353;
const ll mod = 1051131;

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


int a[1<<25];

void solve()
{
    ll n, T, s;
    cin >> n >> T >> s;
    ll N = (1LL<<n);
    for (ll i=0;i<s;i++) cin >> a[i];
    for (ll i=s;i<N;i++) a[i] = (a[i-s]*101+10007)%mod;
    ll n2 = 2*n+2;
    vector<vector<ll>> A(n2,vector<ll>(n2)), C(n2,vector<ll>(n2));
    for (ll i=0;i<n2;i++)
    {
        C[i][i] = 1;
        ll w = i/2;
        for (ll p=0;p<n;p++)
        {
            if (p<w) A[i][p*2+1] += N/2;
            if (p==w) A[i][i^1] += N/2;
            if (p>w) A[i][i] += N/2;
        }
        A[i][i] += 1;
        for (ll j=0;j<n2;j++) A[i][j] %= mod;
    }
    while (true)
    {
        if (T&1)
        {
            vector<vector<ll>> A2(n2,vector<ll>(n2));
            for (ll i=0;i<n2;i++)
            {
                for (ll j=0;j<n2;j++)
                {
                    for (ll k=0;k<n2;k++)
                    {
                        A2[i][j] = (A2[i][j]+A[i][k]*C[k][j])%mod;
                    }
                }
            }
            C = A2;
        }
        T /= 2;
        if (T==0) break;
        {
            vector<vector<ll>> A2(n2,vector<ll>(n2));
            for (ll i=0;i<n2;i++)
            {
                for (ll j=0;j<n2;j++)
                {
                    for (ll k=0;k<n2;k++)
                    {
                        A2[i][j] = (A2[i][j]+A[i][k]*A[k][j])%mod;
                    }
                }
            }
            A = A2;
        }
    }
    vector<ll> nxt(n2);
    for (ll i=0;i<n2;i++)
    {
        nxt[i] = C[n*2][i];
    }
    vector<ll> p2(n+1);
    p2[0] = 1;
    for (ll i=1;i<=n;i++)
    {
        p2[i] = p2[i-1]*(mod+1)/2%mod;
    }
    vector<vector<int>> ans(n+1);
    ans[0].resize(1);
    for (ll k=n;k>=1;k--)
    {
        ans[k].resize(1LL<<k);
        for (ll i=0;i<(1LL<<k);i++)
        {
            ll x = a[i]*nxt[k*2-2]*p2[n-k];
            if (k==n) x += nxt[2*n]*a[i];
            x += a[i^(1LL<<(k-1))]*nxt[k*2-1]*p2[n-k];
            //x += ans[k-1][i&((1LL<<(k-1))-1)];
            ans[k][i] = x%mod;
        }
        for (ll i=0;i<(1LL<<(k-1));i++)
        {
            a[i] = (a[i]+a[i+(1LL<<(k-1))])%mod;
        }
    }
    for (ll k=1;k<=n;k++)
    {
        for (ll i=0;i<(1LL<<k);i++)
        {
            ans[k][i] = (ans[k][i]+ans[k-1][i&((1LL<<(k-1))-1)])%mod;
        }
    }
    ll W = 0;
    for (ll i=0;i<N;i++)
    {
        W ^= ans[n][i];
    }
    cout << W << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}