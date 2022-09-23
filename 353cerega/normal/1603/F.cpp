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

ll p2[10000100], pn2[10000100], dp[10000100];

void solve2(ll n, ll k)
{
    ll A = 1;
    if (k<n)
    {
        cout << 0 << "\n";
        return;
    }
    p2[0] = 1;
    for (ll i=1;i<=k;i++) p2[i] = p2[i-1]*2%mod;
    for (ll i=0;i<n;i++)
    {
        A = (A*(p2[k]-p2[i]+mod))%mod;
    }
    cout << A << "\n";
}


void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    if (x==0)
    {
        solve2(n,k);
        return;
    }
    ll A = 1;
    p2[0] = 1;
    if (n>=k) pn2[0] = pew(2,n-k);
    else pn2[0] = pew(2,mod-1-(k-n)%(mod-1));
    for (ll i=1;i<=k;i++)
    {
        p2[i] = p2[i-1]*2%mod;
        pn2[i] = pn2[i-1]*2%mod;
    }
    ll Q = p2[k]-1;
    dp[0] = 1;
    for (ll i=1;i<min(k,n+1);i++)
    {
        Q = Q*(p2[i]-1)%mod;
        dp[i] = dp[i-1]*p2[i-1]%mod*(pn2[k-i+1]-1)%mod*(p2[k-i+1]-1)%mod;
    }
    Q = pew(Q,mod-2);
    for (ll i=min(k,n+1)-1;i>=1;i--)
    {
        A = (A+dp[i]*Q%mod*(p2[k]-p2[i]))%mod;
        Q = Q*(p2[i]-1)%mod;
    }
    /*for (ll i=1;i<min(k,n);i++)
    {
        C = C*pew(p2[i]-1,mod-2)%mod*p2[i-1]%mod*(p2[n-i+1]-1)%mod*(p2[k-i+1]-1)%mod;
        A = (A+C*(p2[k]-p2[i])%mod*pew(p2[k]-1,mod-2))%mod;
    }*/
    if (A<0) A += mod;
    cout << A << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    cin >> T;
    while (T--) solve();
}