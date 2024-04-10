#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = int;
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




void solve()
{
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<ll> c(26);
    for (ll i=0;i<n;i++)
    {
        c[s[i]-'a']++;
        c[t[i]-'a']--;
    }
    for (ll j=0;j<26;j++)
    {
        if (c[j]!=0)
        {
            cout << -1 << "\n";
            return;
        }
    }
    vector<ll> mn(n,-1);
    for (ll i=0;i<n;i++)
    {
        c[s[i]-'a']--;
        if (i>0) mn[i] = mn[i-1];
        while (true)
        {
            ll ok = 1;
            for (ll j=0;j<26;j++)
            {
                if (c[j]<0) ok = 0;
            }
            if (ok==1) break;
            mn[i]++;
            c[t[mn[i]]-'a']++;
        }
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    for (ll i=0;i<=n;i++)
    {
        for (ll j=0;j<=n;j++)
        {
            if (i<n and j>=mn[i] and j<n and s[i]==t[j]) dp[i+1][j+1] = dp[i][j]+1;
            if (i<n) dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            if (j<n) dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
        }
    }
    cout << n-dp[n][n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}