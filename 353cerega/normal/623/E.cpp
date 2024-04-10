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


vector<ll> mul(vector<ll> &a, vector<ll> &b)
{
    ll n = a.size();
    vector<ll> A(n+n-1);
    if (n<10)
    {
        for (ll i=0;i<n;i++)
        {
            for (ll j=0;j<n;j++) A[i+j] = (A[i+j]+a[i]*b[j])%mod;
        }
        return A;
    }
    ll n1 = n/2;
    ll n2 = n-n/2;
    vector<ll> a1(n1), a2(n2), b1(n1), b2(n2);
    for (ll i=0;i<n1;i++) a1[i] = a[i], b1[i] = b[i];
    for (ll i=0;i<n2;i++) a2[i] = a[i+n1], b2[i] = b[i+n1];
    vector<ll> r1 = mul(a1,b1);
    vector<ll> r2 = mul(a2,b2);
    for (ll i=0;i<n1;i++)
    {
        a2[i] = (a2[i]+a[i])%mod;
        b2[i] = (b2[i]+b[i])%mod;
    }
    vector<ll> r = mul(a2,b2);
    for (ll i=0;i<n1+n1-1;i++)
    {
        A[i] += r1[i];
        A[i+n1] += mod-r1[i];
    }
    for (ll i=0;i<n2+n2-1;i++)
    {
        A[i+n1+n1] += r2[i];
        A[i+n1] += mod-r2[i];
        A[i+n1] += r[i];
    }
    for (ll i=0;i<n+n-1;i++) A[i] %= mod;
    return A;
}

ll k;
vector<ll> E;

vector<ll> mul2(vector<ll> C, ll W)
{
    vector<ll> E2(k+1);
    ll p2 = pew(2,W);
    ll w = 1;
    for (ll i=0;i<=k;i++)
    {
        E2[i] = E[i]*w%mod;
        w = w*p2%mod;
    }
    vector<ll> x = mul(E2,C);
    x.resize(k+1);
    return x;
}



void solve()
{
    ll n;
    cin >> n >> k;
    if (n>k)
    {
        cout << 0 << "\n";
        return;
    }
    vector<ll> f(k+1), f2(k+1);
    f[0] = f2[0] = 1;
    for (ll i=1;i<=k;i++)
    {
        f[i] = f[i-1]*i%mod;
        f2[i] = pew(f[i],mod-2);
    }
    E.resize(k+1);
    for (ll i=1;i<=k;i++) E[i] = f2[i];
    vector<ll> C(k+1);
    C[0] = 1;
    ll W = 0;
    ll Q = 1;
    while (n>0)
    {
        if (n&Q)
        {
            C = mul2(C,W);
            n -= Q;
            W += Q;
        }
        if (n==0) break;
        E = mul2(E,Q);
        Q *= 2;
    }
    ll A = 0;
    for (ll i=1;i<=k;i++)
    {
        A = (A+C[i]*f[k]%mod*f2[k-i])%mod;
    }
    cout << A << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    cout.precision(20);
    cin.tie(0);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}