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

ll J = 15, K = 30;
ll dp[15][31][20000];
ll mx[31][15][20000];

vector<ll> len;
ll n;

void build(ll j)
{
    for (ll k=0;k<=K;k++)
    {
        for (ll i=0;i<n;i++) mx[k][0][i] = dp[j][k][i];
        for (ll j2=1;j2<J;j2++)
        {
            for (ll i=0;i+(1LL<<j2)<=n;i++)
            {
                mx[k][j2][i] = max(mx[k][j2-1][i],mx[k][j2-1][i+(1LL<<(j2-1))]);
            }
        }
    }
}

ll calc(ll k, ll L, ll R)
{
    ll w = len[R-L];
    return max(mx[k][w][L],mx[k][w][R-(1LL<<w)]);
}

void solve()
{
    len.resize((1LL<<J));
    for (ll j=0;j<J;j++)
    {
        for (ll i=(1LL<<j);i<(1LL<<j)*2;i++) len[i] = j;
    }
    ll q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        a[i] += i;
        for (ll k=0;k<=K;k++) dp[0][k][i] = a[i]+k;
    }
    for (ll j=1;j<J;j++)
    {
        build(j-1);
        for (ll k=0;k<=K;k++)
        {
            for (ll i=0;i<n;i++) dp[j][k][i] = i;
        }
        for (ll k=0;k<=K;k++)
        {
            for (ll k2=0;k2+k<=K;k2++)
            {
                for (ll i=0;i<n;i++)
                {
                    if (dp[j-1][k][i]>=n)
                    {
                        dp[j][k+k2][i] = dp[j-1][k][i];
                        continue;
                    }
                    ll x = calc(k2,i,dp[j-1][k][i]+1);
                    dp[j][k+k2][i] = max(dp[j][k+k2][i],x);
                }
            }
        }
    }
    vector<ll> ans(q);
    vector<ll> l(q), r(q), req(q);
    vector<vector<ll>> x(q,vector<ll>(K+1,-1));
    for (ll i=0;i<q;i++)
    {
        ll k;
        cin >> l[i] >> req[i] >> k;
        l[i]--;
        req[i]--;
        if (l[i]==req[i]) ans[i] = -1;
        for (ll j=K-k;j<=K;j++) x[i][j] = l[i];
    }
    for (ll j=J-1;j>=0;j--)
    {
        build(j);
        for (ll w=0;w<q;w++)
        {
            if (l[w]==req[w]) continue;
            ll F = 0;
            for (ll k=0;k<=K;k++)
            {
                if (x[w][k]==-1) continue;
                if (calc(K-k,l[w],x[w][k]+1)>=req[w])
                {
                    F = 1;
                    break;
                }
            }
            if (F==1) continue;
            ans[w] += (1LL<<j);
            for (ll k=K;k>=0;k--)
            {
                if (x[w][k]==-1) continue;
                for (ll k2=K-k;k2>=0;k2--)
                {
                    ll R = calc(k2,l[w],x[w][k]+1);
                    x[w][k+k2] = max(x[w][k+k2],R);
                }
            }
        }
    }
    for (ll i=0;i<q;i++) cout << ans[i]+1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    //cin >> T;
    T = 1;
    while (T--) solve();
}