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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n,vector<ll>(n,-1));
    for (ll i=0;i<m;i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        g[a][b] = w;
    }
    vector<ll> q;
    {
        vector<ll> was(n);
        ll L = n;
        while (L>0)
        {
            for (ll i=0;i<n;i++)
            {
                if (was[i]==1) continue;
                ll bad = 0;
                for (ll j=0;j<n;j++)
                {
                    if (was[j]==1 or g[j][i]==-1) continue;
                    bad = 1;
                }
                if (bad==0)
                {
                    q.push_back(i);
                    was[i] = 1;
                    L--;
                }
            }
        }
        reverse(q.begin(),q.end());
    }
    ll n2 = (1LL<<n);
    vector<vector<ll>> ok(n2,vector<ll>(n));
    vector<ll> D(n2);
    for (ll M=0;M<n2;M++)
    {
        for (ll i=0;i<n;i++)
        {
            if (M&(1LL<<i)) continue;
            ll bad = 0;
            for (ll j=0;j<n;j++)
            {
                if (M&(1LL<<j)) continue;
                if (g[j][i]!=-1) bad = 1;
            }
            if (bad==0) ok[M][i] = 1;
        }
        for (ll i=0;i<n;i++)
        {
            if ((M&(1LL<<i))==0) continue;
            for (ll j=0;j<n;j++)
            {
                if (M&(1LL<<j)) continue;
                if (g[i][j]!=-1) D[M] += g[i][j];
            }
        }
    }
    vector<ll> prv(n2);
    vector<ll> dp(n2,mod*mod);
    dp[0] = 0;
    vector<ll> prv2(n2), dp2(n2);
    for (ll z=0;z<n;z++)
    {
        for (ll M=0;M<n2;M++)
        {
            prv2[M] = M;
            dp2[M] = dp[M];
        }
        for (ll p=0;p<n;p++)
        {
            ll i = q[p];
            for (ll M=0;M<n2;M++)
            {
                if (ok[M][i]==0) continue;
                if (dp2[M+(1LL<<i)]>dp[prv2[M]])
                {
                    dp2[M+(1LL<<i)] = dp[prv2[M]];
                    prv2[M+(1LL<<i)] = prv2[M];
                }
            }
        }
        for (ll M=0;M<n2;M++)
        {
            ll S = dp2[M]+D[M];
            if (S<dp[M])
            {
                dp[M] = S;
                prv[M] = prv2[M];
            }
        }
    }
    vector<ll> A(n);
    {
        ll M = n2-1;
        ll C = 0;
        while (M>0)
        {
            ll M2 = prv[M];
            for (ll i=0;i<n;i++)
            {
                if (M2&(1LL<<i)) continue;
                if ((M&(1LL<<i))==0) continue;
                A[i] = C;
            }
            M = M2;
            C++;
        }
    }
    for (ll i=0;i<n;i++) cout << A[i] << " ";
}