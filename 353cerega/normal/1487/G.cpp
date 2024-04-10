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
    ll n;
    cin >> n;
    vector<ll> a(26);
    for (ll i=0;i<26;i++)
    {
        cin >> a[i];
        a[i]++;
    }
    vector<vector<ll>> A(n+1,vector<ll>(n+1));
    {
        vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(9)));
        vector<vector<vector<ll>>> dp2(n+1,vector<vector<ll>>(n+1,vector<ll>(9)));
        for (ll i=0;i<3;i++)
        {
            for (ll j=0;j<3;j++)
            {
                ll x = 0, y = 0, C = 1;
                if (i==0) x++;
                if (i==1) y++;
                if (i==2) C *= 24;
                if (j==0) x++;
                if (j==1) y++;
                if (j==2) C *= 24;
                dp[x][y][i*3+j] = C;
            }
        }
        for (ll i=2;i<n;i++)
        {
            for (ll x=0;x<=i;x++)
            {
                for (ll y=0;y<=i;y++)
                {
                    for (ll p=0;p<9;p++)
                    {
                        dp2[x][y][p] = 0;
                    }
                }
            }
            for (ll x=0;x<=i;x++)
            {
                for (ll y=0;y<=i;y++)
                {
                    for (ll p=0;p<9;p++)
                    {
                        for (ll k=0;k<3;k++)
                        {
                            ll dx = 0, dy = 0, C = 1;
                            if (k==0) dx++;
                            if (k==1) dy++;
                            if (k==2) C *= 24;
                            if (k==p/3) C--;
                            if (dp[x][y][p]==0 or C==0) continue;
                            ll p2 = p%3*3+k;
                            dp2[x+dx][y+dy][p2] = (dp2[x+dx][y+dy][p2]+dp[x][y][p]*C)%mod;
                        }
                    }
                }
            }
            swap(dp,dp2);
        }
        for (ll i=n;i>=0;i--)
        {
            for (ll j=n;j>=0;j--)
            {
                for (ll k=0;k<9;k++)
                {
                    A[i][j] = (A[i][j]+dp[i][j][k])%mod;
                }
                if (j<n) A[i][j] = (A[i][j]+A[i][j+1])%mod;
            }
        }
        for (ll i=n-1;i>=0;i--)
        {
            for (ll j=n;j>=0;j--)
            {
                A[i][j] = (A[i][j]+A[i+1][j])%mod;
            }
        }
    }
    ll ans = 26*26;
    for (ll i=0;i<n-2;i++)
    {
        ans = (ans*25)%mod;
    }
    for (ll i=0;i<26;i++)
    {
        for (ll j=i+1;j<26;j++)
        {
            if (a[i]>n or a[j]>n) continue;
            ans = (ans+A[a[i]][a[j]])%mod;
        }
    }
    vector<ll> B(n+1);
    {
        vector<vector<ll>> dp(n+1,vector<ll>(4)), dp2(n+1,vector<ll>(4));
        for (ll i=0;i<2;i++)
        {
            for (ll j=0;j<2;j++)
            {
                ll x = 0, C = 1;
                if (i==0) x++;
                if (i==1) C *= 25;
                if (j==0) x++;
                if (j==1) C *= 25;
                dp[x][i*2+j] = C;
            }
        }
        for (ll i=2;i<n;i++)
        {
            for (ll x=0;x<=i;x++)
            {
                for (ll p=0;p<4;p++)
                {
                    dp2[x][p] = 0;
                }
            }
            for (ll x=0;x<=i;x++)
            {
                for (ll p=0;p<4;p++)
                {
                    for (ll k=0;k<2;k++)
                    {
                        ll dx = 0, C = 1;
                        if (k==0) dx++;
                        if (k==1) C *= 25;
                        if (k==p/2) C--;
                        if (dp[x][p]==0 or C==0) continue;
                        ll p2 = p%2*2+k;
                        dp2[x+dx][p2] = (dp2[x+dx][p2]+dp[x][p]*C)%mod;
                    }
                }
            }
            swap(dp,dp2);
        }
        for (ll i=n;i>=0;i--)
        {
            for (ll k=0;k<4;k++)
            {
                B[i] = (B[i]+dp[i][k])%mod;
            }
            if (i<n) B[i] = (B[i]+B[i+1])%mod;
        }
    }
    for (ll i=0;i<26;i++)
    {
        if (a[i]>n) continue;
        ans = (ans+mod-B[a[i]])%mod;
    }
    cout << ans << endl;
}