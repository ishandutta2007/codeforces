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



void solve()
{
    ll n;
    cin >> n;
    ll mx = 2*n;
    vector<vector<ll>> C(mx+1,vector<ll>(mx+1));
    for (ll i=0;i<=mx;i++)
    {
        C[i][0] = C[i][i] = 1;
        for (ll j=1;j<i;j++)
        {
            C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    string s, t;
    cin >> s >> t;
    ll D = n;
    vector<ll> dp(mx+1), dp2(mx+1);
    dp[D] = 1;
    vector<ll> suf(n+1), suf2(n+1);
    for (ll i=n-1;i>=0;i--)
    {
        suf[i] = suf[i+1];
        suf2[i] = suf2[i+1];
        if (i%2==0)
        {
            if (s[i]=='1') suf[i]++;
            if (t[i]=='1') suf[i]--;
            if (s[i]=='?') suf2[i]++;
            if (t[i]=='?')
            {
                suf[i]--;
                suf2[i]++;
            }
        } else
        {
            if (s[i]=='1') suf[i]--;
            if (t[i]=='1') suf[i]++;
            if (t[i]=='?') suf2[i]++;
            if (s[i]=='?')
            {
                suf[i]--;
                suf2[i]++;
            }
        }
    }
    ll A = 0;
    for (ll z=0;z<n;z++)
    {
        for (ll j=0;j<=mx;j++)
        {
            dp2[j] = 0;
        }
        for (ll i=-z;i<=z;i++)
        {
            for (ll b=0;b<2;b++)
            {
                if (s[z]-'0'==1-b) continue;
                for (ll b2=0;b2<2;b2++)
                {
                    if (t[z]-'0'==1-b2) continue;
                    ll q = (b+b2)%2;
                    ll q2 = b-b2;
                    if (z%2==1) q2 *= -1;
                    
                    if (dp[i+D]==0) continue;
                    {
                        ll L = i+q2+suf[z+1];
                        L *= -1;
                        if (L>=0 and L<=suf2[z+1]) A = (A+abs(i+q2)*C[suf2[z+1]][L]%mod*dp[i+D])%mod;
                    }
                    dp2[D+i+q2] += dp[i+D];
                }
            }
        }
        swap(dp,dp2);
        for (ll i=-z-1;i<=z+1;i++)
        {
            dp[i+D] %= mod;
        }
    }
    cout << A << "\n";
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