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
    return __int128(a)*__int128(b)%mod;
    /*if (a*b<mod) return a*b;
    else return a*b%mod;*/
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





ll n, m;

ll calc3(ll R)
{
    ll x = R*(R+1)/2%mod;
    return x*x%mod;
}

ll p6 = pew(6,mod-2);

ll calc2(ll R)
{
    return R*(R+1)%mod*(R*2+1)%mod*p6%mod;
}

ll calc1(ll R)
{
    return R*(R+1)/2%mod;
}


ll mx = 1000100;
vector<vector<ll>> pr;

void prec()
{
    vector<ll> dp(mx+1);
    pr.resize(mx+1,vector<ll>(3));
    vector<ll> d(mx+1), P, phi(mx+1);
    phi[1] = 1;
    for (ll i=2;i<=mx;i++)
    {
        if (d[i]==0)
        {
            d[i] = i;
            phi[i] = i-1;
            P.push_back(i);
        }
        for (ll j=0;j<P.size() and P[j]*i<=mx and P[j]<=d[i];j++)
        {
            d[P[j]*i] = P[j];
            if (P[j]==d[i]) phi[P[j]*i] = phi[i]*P[j];
            else phi[P[j]*i] = phi[i]*(P[j]-1);
        }
    }
    for (ll L=1;L<=mx;L++)
    {
        ll A = L*L*L%mod;
        A += 2*calc2(L);
        A -= 2*calc1(L)*L%mod;
        A -= 2*L*L%mod;
        A %= mod;
        if (A<0) A += mod;
        dp[L] = A;
    }
    for (ll x=1;x<=mx;x++)
    {
        for (ll L=x;L<=mx;L+=x)
        {
            dp[L] += 2*phi[L/x]*x%mod;
            dp[L] += mod;
            dp[L] %= mod;
        }
    }
    for (ll L=1;L<=mx;L++)
    {
        pr[L][0] = (pr[L-1][0]+dp[L])%mod;
        pr[L][1] = (pr[L-1][1]+dp[L]*L)%mod;
        pr[L][2] = (pr[L-1][2]+dp[L]*L%mod*L)%mod;
    }
}

void solve()
{
    cin >> n >> m;
    if (n>m) swap(n,m);
    ll A = pr[n][0]*(n+1)%mod*(m+1)%mod+pr[n][2];
    A -= pr[n][1]*(n+m+2);
    A %= mod;
    if (A<0) A += mod;
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    prec();
    ll T;
    cin >> T;
    while (T--) solve();
}