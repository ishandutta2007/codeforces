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
    sz[v] = 1;
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
    vector<pair<ll,ll>> a(n);
    for (ll i=0;i<n;i++) cin >> a[i].X >> a[i].Y;
    sort(a.begin(),a.end());
    vector<ll> d(n);
    for (ll i=0;i<n;i++) d[i] = abs(a[i].X);
    ll A = 0;
    {
        ll mn = mod*mod;
        ll mx = -mod*mod;
        for (ll i=0;i<n;i++)
        {
            mn = min(mn,a[i].Y);
            mx = max(mx,a[i].Y);
        }
        A = (mx-mn)*(mx-mn);
    }
    ll L = -1, R = A;
    while (R-L>1)
    {
        ll M = (L+R)/2;
        ll L2 = 0, R2 = mod*2;
        while (R2-L2>1)
        {
            ll M2 = (L2+R2)/2;
            if (M2*M2>M) R2 = M2;
            else L2 = M2;
        }
        ll MM = L2;
        ll j = 0;
        vector<vector<ll>> dp(4,vector<ll>(n+1));
        dp[0][0] = dp[2][n] = mod;
        dp[1][0] = dp[3][n] = -mod;
        for (ll i=0;i<n;i++)
        {
            dp[0][i+1] = min(dp[0][i],a[i].Y);
            dp[1][i+1] = max(dp[1][i],a[i].Y);
        }
        for (ll i=n-1;i>=0;i--)
        {
            dp[2][i] = min(dp[2][i+1],a[i].Y);
            dp[3][i] = max(dp[3][i+1],a[i].Y);
        }
        ll F = 0;
        for (ll i=0;i<n;i++)
        {
            if (a[i].X<0) continue;
            while (d[j]>d[i] or a[i].X-a[j].X>MM)
            {
                j++;
            }
            while (j>0 and d[j-1]<=d[i] and a[i].X-a[j-1].X<=MM)
            {
                j--;
            }
            ll mn = min(dp[0][j],dp[2][i+1]);
            ll mx = max(dp[1][j],dp[3][i+1]);
            if (mx<mn)
            {
                F = 1;
                R = M;
                break;
            }
            if (mx-mn>MM) continue;
            if (mx*mx+a[i].X*a[i].X>M) continue;
            if (mn*mn+a[i].X*a[i].X>M) continue;
            F = 1;
            R = M;
            break;
        }
        if (F==1) continue;
        j = n-1;
        for (ll i=n-1;i>=0;i--)
        {
            if (a[i].X>=0) continue;
            while (d[j]>d[i] or a[j].X-a[i].X>MM)
            {
                j--;
            }
            while (j+1<n and d[j+1]<d[i] and a[j+1].X-a[i].X<=MM)
            {
                j++;
            }
            ll mn = min(dp[2][j+1],dp[0][i]);
            ll mx = max(dp[3][j+1],dp[1][i]);
            if (mx<mn)
            {
                F = 1;
                R = M;
                break;
            }
            if (mx-mn>MM) continue;
            if (mx*mx+a[i].X*a[i].X>M) continue;
            if (mn*mn+a[i].X*a[i].X>M) continue;
            F = 1;
            R = M;
            break;
        }
        if (F==1) continue;
        L = M;
    }
    cout << R << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    cin.tie(0);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}