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

const int root = 106061068;
const int root_1 = 474649464;
const int root_pw = 1<<14;


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




int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll mx = 300000;
    vector<ll> f(mx+1), f2(mx+1);
    f[0] = f2[0] = 1;
    for (ll i=1;i<=mx;i++)
    {
        f[i] = f[i-1]*i%mod;
        f2[i] = pew(f[i],mod-2);
    }
    ll sz = root_pw;
    vector<int> a(sz), b(sz);
    a[0] = 1;
    ll L = 0, R = 0;
    for (ll i=0;i<n;i++)
    {
        ll A, B;
        cin >> A >> B;
        for (ll j=0;j<sz;j++) b[j] = 0;
        ll mn = L+B-R;
        if (mn<0) mn = 0;
        ll x = min(R+A-L,A+B);
        for (ll j=mn;j<=x;j++)
        {
            b[j-mn] = f[A+B]*f2[j]%mod*f2[A+B-j]%mod;
        }
        fft(a,false);
        fft(b,false);
        for (ll j=0;j<sz;j++)
        {
            a[j] = (a[j]*1LL*b[j])%mod;
        }
        fft(a,true);
        L = L+B-mn;
        R = R+A-mn;
        if (L>0)
        {
            for (ll j=0;j+L<sz;j++)
            {
                a[j] = a[j+L];
            }
            R = R-L;
            L = 0;
        }
        for (ll j=R+1;j<sz;j++) a[j] = 0;
    }
    ll S = 0;
    for (ll i=0;i<sz;i++) S = (S+a[i])%mod;
    cout << S << endl;
}