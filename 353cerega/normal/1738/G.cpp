//#pragma GCC optimize("Ofast")
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

const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;

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


void fin(vector<vector<ll>> a)
{
    ll n = a.size();
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<n;j++) cout << 1-a[i][j];
        cout << "\n";
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<string> s(n);
    ll D = (n-k+1)*(n-k+1);
    ll Q = 0;
    vector<vector<ll>> a(n,vector<ll>(n));
    for (ll i=0;i<n;i++)
    {
        cin >> s[i];
        for (ll j=0;j<n;j++)
        {
            a[i][j] = s[i][j]-'0';
            if (a[i][j]==1) Q++;
        }
    }
    if (Q<D)
    {
        cout << "NO\n";
        return;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    for (ll i=0;i<=n;i++)
    {
        for (ll j=0;j<=n;j++)
        {
            if (i<n and j<n and a[i][j]==0) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
            if (i<n) dp[i+1][j] = max(dp[i][j],dp[i+1][j]);
            if (j<n) dp[i][j+1] = max(dp[i][j],dp[i][j+1]);
        }
    }
    if (dp[n][n]>=k)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    ll L = Q-D;
    if (L==0)
    {
        fin(a);
        return;
    }
    vector<vector<ll>> suf(n+1,vector<ll>(n+1));
    if (dp[n][n]+1<k)
    {
        ll F = 0;
        for (ll i=n-1;i>=0 and F==0;i--)
        {
            for (ll j=n-1;j>=0 and F==0;j--)
            {
                if (a[i][j]==1) L--, a[i][j] = 0;
                if (L==0)
                {
                    fin(a);
                    return;
                }
                if (a[i][j]==0) suf[i][j] = max(suf[i][j],suf[i+1][j+1]+1);
                if (suf[i][j]+dp[i][j]==k-1)
                {
                    F = 1;
                    break;
                }
                suf[i+1][j] = max(suf[i+1][j],suf[i+1][j+1]);
                suf[i][j+1] = max(suf[i][j+1],suf[i+1][j+1]);
            }
        }
    }
    for (ll i=0;i<=n;i++)
    {
        for (ll j=0;j<=n;j++) dp[i][j] = 0;
    }
    for (ll i=n-k+1;i<n;i++)
    {
        for (ll j=0;j<k-1;j++)
        {
            if (i-j<n-k+1) continue;
            if (a[i][j]==1)
            {
                L--;
                a[i][j] = 0;
                if (L==0)
                {
                    fin(a);
                    return;
                }
            }
            if (a[j][i]==1)
            {
                L--;
                a[j][i] = 0;
                if (L==0)
                {
                    fin(a);
                    return;
                }
            }
        }
    }
    for (ll i=0;i<=n;i++)
    {
        for (ll j=0;j<=n;j++)
        {
            if (i<n and j<n and a[i][j]==0) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
            if (i<n) dp[i+1][j] = max(dp[i][j],dp[i+1][j]);
            if (j<n) dp[i][j+1] = max(dp[i][j],dp[i][j+1]);
        }
    }
    for (ll w=1;w<k;w++)
    {
        ll i = n-1;
        ll j = w-1;
        while (i>=0 and j<n)
        {
            //cout << i << " " << j << endl;
            if (a[i][j]==1)
            {
                a[i][j] = 0;
                L--;
                if (L==0)
                {
                    fin(a);
                    return;
                }
            }
            if (i==0 and j+1==n) break;
            //cout << dp[i+1][j+1] << " " << dp[i][j+1] << " " << dp[i+1][j+2] << endl;
            if (i>=n-1-j)
            {
                if (i!=0 and dp[i+1][j+1]==dp[i][j+1] and dp[i-1][j]+1==dp[i][j+1])
                {
                    i--;
                    continue;
                }
                j++;
                continue;
            }
            if (j+1<n and dp[i+1][j+1]==dp[i+1][j+2] and dp[i][j+1]+1==dp[i+1][j+2])
            {
                j++;
                continue;
            }
            i--;
        }
    }
    assert(false);
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}