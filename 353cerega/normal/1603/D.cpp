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

ll mx = 100100;
ll K = 20;
vector<ll> phi, f;
vector<vector<ll>> dp;
ll M = 300;

void rec(ll l, ll r, ll L, ll R, ll k)
{
    ll m = (l+r)/2;
    ll bst = L;
    ll C = 1;
    ll D = 0;
    ll P = min(R,m);
    while (m/(C+1)>=P and C<300)
    {
        D += f[C]*(m/C-m/(C+1));
        C++;
    }
    ll Z = D;
    if (C<300) Z += (m/C-P)*f[C];
    else
    {
        for (ll Q=P+1;m/Q>=C;Q++) Z += f[m/Q];
    }
    for (ll p=min(R,m);p>=L;p--)
    {
        if (dp[k][m]>dp[k-1][p]+Z)
        {
            bst = p;
            dp[k][m] = dp[k-1][p]+Z;
        }
        if (p>L) Z += f[m/p];
    }
    if (m!=l) rec(l,m-1,L,bst,k);
    if (m!=r) rec(m+1,r,bst,R,k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    phi.resize(mx+1);
    vector<ll> d(mx+1), pr;
    for (ll i=2;i<=mx;i++)
    {
        if (d[i]==0)
        {
            phi[i] = i-1;
            d[i] = i;
            pr.push_back(i);
        }
        for (ll j=0;j<pr.size() and pr[j]<=d[i] and i*pr[j]<=mx;j++)
        {
            d[i*pr[j]] = pr[j];
            phi[i*pr[j]] = phi[i]*pr[j];
            if (pr[j]!=d[i])
            {
                phi[i*pr[j]] = phi[i*pr[j]]/pr[j]*(pr[j]-1);
            }
        }
    }
    f.resize(mx+1);
    f[0] = 0;
    for (ll i=1;i<=mx;i++)
    {
        f[i] = f[i-1]+phi[i];
    }
    dp.resize(K,vector<ll>(mx+1,mod*mod));
    dp[0][0] = 0;
    for (ll q=1;q<K;q++)
    {
        rec(0,mx,0,mx,q);
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll n, k;
        cin >> n >> k;
        if (k>=K) cout << n << "\n";
        else cout << dp[k][n]+n << "\n";
    }
}