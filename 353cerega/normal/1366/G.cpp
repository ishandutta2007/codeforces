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


int dp[10001][10001];

int main()
{
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    ll m = s.length();
    ll n = t.length();
    for (ll i=0;i<=m;i++)
    {
        for (ll j=0;j<=n;j++) dp[i][j] = mod;
    }
    dp[0][0] = 0;
    vector<pair<ll,ll>> ord;
    ll b = 0;
    vector<ll> nxt(m,-1);
    for (ll i=0;i<=m;i++)
    {
        ord.push_back({b,i});
        if (i==m) continue;
        if (s[i]=='.') b--;
        else b++;
    }
    sort(ord.begin(),ord.end());
    for (ll i=0;i<ord.size();i++)
    {
        if (i+1<ord.size() and ord[i].X==ord[i+1].X)
        {
            nxt[ord[i].Y] = ord[i+1].Y;
        }
    }
    for (ll i=0;i<m;i++)
    {
        for (ll j=0;j<=n;j++) dp[i+1][j] = min(dp[i+1][j],dp[i][j]+1);
        if (s[i]=='.')
        {
            for (ll j=1;j<=n;j++) dp[i+1][j-1] = min(dp[i+1][j-1],dp[i][j]);
            continue;
        }
        for (ll j=0;j<n;j++)
        {
            if (s[i]==t[j])
            {
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]);
            }
        }
        if (nxt[i]==-1) continue;
        for (ll j=0;j<=n;j++)
        {
            dp[nxt[i]][j] = min(dp[nxt[i]][j],dp[i][j]);
        }
    }
    cout << dp[m][n] << endl;
}