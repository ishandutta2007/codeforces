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


ll dp[4][2010][2010];

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll s, t;
    cin >> s >> t;
    s--, t--;
    vector<vector<pair<ll,ll>>> g(n);
    vector<ll> a(n+1);
    for (ll i=0;i<n;i++) cin >> a[i];
    for (ll i=0;i<m;i++)
    {
        ll u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        g[u].push_back({v,d});
        g[v].push_back({u,d});
    }
    vector<ll> d(n+1,mod*mod), d2(n+1,mod*mod);
    {
        d[s] = 0;
        set<pair<ll,ll>> kek;
        for (ll i=0;i<n;i++) kek.insert({d[i],i});
        while (kek.size()>0)
        {
            ll u = kek.begin()->Y;
            kek.erase({d[u],u});
            for (ll i=0;i<g[u].size();i++)
            {
                ll v = g[u][i].X;
                ll D = g[u][i].Y+d[u];
                if (d[v]>D)
                {
                    kek.erase({d[v],v});
                    d[v] = D;
                    kek.insert({d[v],v});
                }
            }
        }
    }
    {
        d2[t] = 0;
        set<pair<ll,ll>> kek;
        for (ll i=0;i<n;i++) kek.insert({d2[i],i});
        while (kek.size()>0)
        {
            ll u = kek.begin()->Y;
            kek.erase({d2[u],u});
            for (ll i=0;i<g[u].size();i++)
            {
                ll v = g[u][i].X;
                ll D = g[u][i].Y+d2[u];
                if (d2[v]>D)
                {
                    kek.erase({d2[v],v});
                    d2[v] = D;
                    kek.insert({d2[v],v});
                }
            }
        }
    }
    vector<pair<ll,ll>> ord, ord2;
    ord.push_back({mod*mod,n});
    ord2.push_back({mod*mod,n});
    for (ll i=0;i<n;i++)
    {
        ord.push_back({d[i],i});
        ord2.push_back({d2[i],i});
    }
    sort(ord.begin(),ord.end());
    sort(ord2.begin(),ord2.end());
    for (ll i=0;i<=n;i++)
    {
        for (ll j=0;j<=n;j++)
        {
            dp[0][i][j] = dp[1][i][j] = -mod*mod;
            dp[2][i][j] = dp[3][i][j] = mod*mod;
            if (i==n or j==n) dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = dp[3][i][j] = 0;
        }
    }
    for (ll i=n;i>=0;i--)
    {
        for (ll j=n;j>=0;j--)
        {
            if (i==0 or ord[i].X!=ord[i-1].X)
            {
                if (j==0 or ord2[j].X!=ord2[j-1].X)
                {
                    if (dp[2][i][j]<mod*mod/2) dp[1][i][j] = max(dp[1][i][j],dp[2][i][j]);
                    if (dp[0][i][j]>-mod*mod/2) dp[3][i][j] = min(dp[0][i][j],dp[3][i][j]);
                }
            }
            if (i>0)
            {
                if (d2[ord[i-1].Y]<ord2[j].X)
                {
                    dp[0][i-1][j] = max(dp[0][i-1][j],dp[0][i][j]);
                    dp[1][i-1][j] = max(dp[1][i-1][j],dp[1][i][j]);
                } else
                {
                    ll x = a[ord[i-1].Y];
                    dp[0][i-1][j] = max(dp[0][i-1][j],max(dp[0][i][j],dp[1][i][j])+x);
                }
            }
            if (j>0)
            {
                if (d[ord2[j-1].Y]<ord[i].X)
                {
                    dp[2][i][j-1] = min(dp[2][i][j-1],dp[2][i][j]);
                    dp[3][i][j-1] = min(dp[3][i][j-1],dp[3][i][j]);
                } else
                {
                    ll x = a[ord2[j-1].Y];
                    dp[2][i][j-1] = min(dp[2][i][j-1],min(dp[2][i][j],dp[3][i][j])-x);
                }
            }
        }
    }
    if (dp[0][0][0]<0) cout << "Cry\n";
    if (dp[0][0][0]==0) cout << "Flowers\n";
    if (dp[0][0][0]>0) cout << "Break a heart\n";
}



int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}