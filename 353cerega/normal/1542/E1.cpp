//#pragma GCC optimize("Ofast")
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




int main()
{
    ios_base::sync_with_stdio(false);
    ll n, M;
    cin >> n >> M;
    vector<vector<ll>> c(n+1,vector<ll>(n+1));
    for (ll i=0;i<=n;i++)
    {
        c[i][i] = c[i][0] = 1;
        for (ll j=1;j<i;j++)
        {
            c[i][j] = (c[i-1][j]+c[i-1][j-1])%M;
        }
    }
    ll D = 70000;
    ll D2 = D*2;
    ll R = 1000;
    vector<ll> dp(D2);
    vector<ll> pr(D2+1), pr1(D2+1), pr2(D2+1);
    dp[D] = 1;
    pr2[0] = 0;
    pr1[0] = 0;
    for (ll j=0;j<D2;j++)
    {
        pr[j+1] = (pr[j]+dp[j])%M;
        pr1[j+1] = (pr1[j]+dp[j]*(j+1))%M;
        pr2[j+1] = (pr2[j]+dp[j]*(D2-j))%M;
    }
    vector<ll> f(n+1);
    f[0] = 1;
    for (ll i=1;i<=n;i++) f[i] = f[i-1]*i%M;
    ll ans = 0;
    for (ll i=0;i+1<n;i++)
    {
        for (ll j=0;j<D2;j++)
        {
            ll A = pr1[j+1];
            A -= (j-i)*pr[j+1];
            if (j>=i)
            {
                A -= pr1[j-i];
                A += pr[j-i]*(j-i);
            }
            A -= pr2[j+1];
            A += pr[j+1]*(D2-j-i-1);
            if (D2-j-1<i)
            {
                A += pr2[D2];
                A -= (D2-j-i-1)*pr[D2];
            }
            else
            {
                A += pr2[j+1+i];
                A -= (D2-j-i-1)*pr[j+1+i];
            }
            A %= M;
            if (A<0) A += M;
            dp[j] = A;
        }
        for (ll j=0;j<R;j++)
        {
            dp[R] = (dp[R]+dp[j])%M;
            dp[j] = 0;
        }
        for (ll j=0;j<D2;j++)
        {
            pr[j+1] = (pr[j]+dp[j])%M;
            pr1[j+1] = (pr1[j]+dp[j]*(j+1))%M;
            pr2[j+1] = (pr2[j]+dp[j]*(D2-j))%M;
        }
        for (ll q=1;q<=i+1;q++)
        {
            ans = (ans+pr[D-q]*c[n][n-i-2]%M*f[n-i-2]%M*(i+2-q))%M;
        }
    }
    cout << ans << "\n";
}