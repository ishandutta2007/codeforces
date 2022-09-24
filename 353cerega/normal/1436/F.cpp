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



int main()
{
    ios_base::sync_with_stdio(false);
    ll n = 100000;
    vector<ll> d(n+1), pr, f(n+1);
    f[1] = 1;
    for (ll i=2;i<=n;i++)
    {
        if (d[i]==0)
        {
            d[i] = i;
            f[i] = -1;
            pr.push_back(i);
        }
        for (ll j=0;j<pr.size() and pr[j]<=d[i] and pr[j]*i<=n;j++)
        {
            d[i*pr[j]] = pr[j];
            if (d[i]==pr[j]) f[i*pr[j]] = 0;
            else f[i*pr[j]] = -f[i];
        }
    }
    ll m;
    cin >> m;
    vector<ll> c(n+1), c2(n+1,1);
    for (ll i=0;i<m;i++)
    {
        ll p, x;
        cin >> p >> x;
        c[p] = x;
        c2[p] = pew(2,c[p]);
    }
    ll A = 0;
    ll p2 = pew(2,mod-2);
    for (ll z=1;z<=n;z++)
    {
        if (f[z]==0) continue;
        ll S = 0;
        ll S2 = 0;
        ll Q = 1;
        for (ll i=z;i<=n;i+=z)
        {
            Q = (Q*c2[i])%mod;
            S2 = (S2+i*i%mod*c[i]%mod*p2)%mod;
            S = (S+i*c[i]%mod*p2)%mod;
        }
        for (ll i=z;i<=n;i+=z)
        {
            ll cS = (S-i*p2)%mod;
            ll cS2 = (S2-i*i%mod*p2)%mod;
            A = (A+f[z]*cS*i%mod*c[i]%mod*Q%mod*p2)%mod;
            A = (A+f[z]*cS*cS%mod*Q%mod*p2%mod*c[i])%mod;
            A = (A+f[z]*cS2*p2%mod*Q%mod*p2%mod*c[i])%mod;
        }
    }
    if (A<0) A += mod;
    cout << A << endl;
}