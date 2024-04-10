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

const int root = 805775211;
const int root_1 = 46809892;
const int root_pw = 1<<19;


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
}


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


void mul(vector<int> &a, vector<int> &b)
{
    ll sz = a.size()+b.size()-1;
    ll S = 1;
    while (S<sz) S *= 2;
    a.resize(S);
    b.resize(S);
    fft(a,false);
    fft(b,false);
    for (ll i=0;i<S;i++) a[i] = a[i]*1LL*b[i]%mod;
    fft(a,true);
    a.resize(sz);
}

vector<ll> a;
vector<ll> pr, suf;
ll A = 0;

void rec(ll L, ll R)
{
    if (L+1==R) return;
    ll M = (L+R)/2;
    vector<int> a0(M-L), b0(R-M), a1(M-L), b1(R-M);
    for (ll i=L;i<M;i++)
    {
        a0[i-L] = pr[i];
        a1[i-L] = pr[i]*(mod-i)%mod;
    }
    for (ll i=M;i<R;i++) b0[i-M] = b1[i-M] = suf[i];
    mul(a0,b0);
    mul(a1,b1);
    ll A0 = A;
    for (ll i=0;i<a0.size();i++)
    {
        ll p = i+L+M;
        if (p%2!=0) continue;
        p /= 2;
        A = (A+a[p]*p%mod*a0[i])%mod;
        A = (A+a[p]*a1[i])%mod;
    }
    rec(L,M);
    rec(M,R);
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    a.resize(2*n);
    for (ll i=0;i<n;i++) cin >> a[i];
    vector<ll> was(n);
    for (ll i=0;i<m;i++)
    {
        ll p;
        cin >> p;
        p--;
        was[p] = 1;
    }
    ll x = 1;
    pr.resize(2*n);
    for (ll i=0;i<n;i++)
    {
        if (was[i]==0) continue;
        pr[i] = x;
        x = x*2%mod;
    }
    suf.resize(2*n,1);
    x = 1;
    for (ll i=n-1;i>=0;i--)
    {
        if (was[i]==1) x = x*2%mod;
        suf[i] = x;
    }
    rec(0,2*n);
    for (ll i=0;i*2<n;i++)
    {
        swap(a[i],a[n-1-i]);
        swap(was[i],was[n-1-i]);
    }
    pr.clear();
    pr.resize(2*n);
    suf.clear();
    suf.resize(2*n,1);
    x = 1;
    for (ll i=0;i<n;i++)
    {
        if (was[i]==0) continue;
        pr[i] = x;
        x = x*2%mod;
    }
    x = 1;
    for (ll i=n-1;i>=0;i--)
    {
        suf[i] = x;
        if (was[i]==1) x = x*2%mod;
    }
    rec(0,2*n);
    A = A*pew((pew(2,m)-1),mod-2)%mod;
    cout << A << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    //cin >> T;
    T = 1;
    while (T--) solve();
}