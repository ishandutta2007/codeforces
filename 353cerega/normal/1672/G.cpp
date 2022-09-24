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


vector<vector<ll>> g;
vector<ll> was, val;
ll S = 0, Q = 0, D = 0;

void dfs(ll u)
{
    was[u] = 1;
    Q ^= val[u];
    S += g[u].size();
    D++;
    for (ll v: g[u])
    {
        if (was[v]==1) continue;
        dfs(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n,vector<ll>(m));
    for (ll i=0;i<n;i++)
    {
        string s;
        cin >> s;
        for (ll j=0;j<m;j++)
        {
            if (s[j]=='?') a[i][j] = -1;
            else a[i][j] = s[j]-'0';
        }
    }
    if (n==1)
    {
        ll F0 = 1, F1 = 1;
        for (ll j=0;j<m;j++)
        {
            if (a[0][j]==0) F1 = 0;
            if (a[0][j]==1) F0 = 0;
        }
        cout << F1+F0 << "\n";
        return 0;
    }
    if (m==1)
    {
        ll F0 = 1, F1 = 1;
        for (ll j=0;j<n;j++)
        {
            if (a[j][0]==0) F1 = 0;
            if (a[j][0]==1) F0 = 0;
        }
        cout << F1+F0 << "\n";
        return 0;
    }
    if (n%2==0 and m%2==0)
    {
        ll A = 1;
        for (ll i=0;i<n;i++)
        {
            for (ll j=0;j<m;j++)
            {
                if (a[i][j]==-1) A = A*2%mod;
            }
        }
        cout << A << "\n";
        return 0;
    }
    if (m%2==0)
    {
        vector<vector<ll>> b(m,vector<ll>(n));
        for (ll i=0;i<n;i++)
        {
            for (ll j=0;j<m;j++) b[j][i] = a[i][j];
        }
        swap(a,b);
        swap(n,m);
    }
    if (n%2==0)
    {
        ll C0 = 1, C1 = 1;
        for (ll i=0;i<n;i++)
        {
            ll x0 = 1, x1 = 0;
            for (ll j=0;j<m;j++)
            {
                if (a[i][j]==0) continue;
                if (a[i][j]==1)
                {
                    swap(x0,x1);
                    continue;
                }
                S = (x0+x1)%mod;
                x0 = x1 = S;
            }
            C0 = C0*x0%mod;
            C1 = C1*x1%mod;
        }
        cout << (C0+C1)%mod << endl;
        return 0;
    }
    ll N = n+m;
    val.resize(N);
    g.resize(N);
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            if (a[i][j]==-1)
            {
                g[i].push_back(j+n);
                g[j+n].push_back(i);
            }
            if (a[i][j]==1) val[i] ^= 1, val[j+n] ^= 1;
        }
    }
    was.resize(N);
    vector<ll> dp(2,1);
    for (ll i=0;i<N;i++)
    {
        if (was[i]==1) continue;
        S = 0;
        Q = 0;
        D = 0;
        dfs(i);
        S /= 2;
        ll R = S-D+1;
        ll w = 1;
        for (ll z=0;z<R;z++) w = w*2%mod;
        if (D%2==0)
        {
            if (Q==0)
            {
                dp[0] = (dp[0]*w)%mod;
                dp[1] = (dp[1]*w)%mod;
            }
            else dp[0] = dp[1] = 0;
        } else
        {
            dp[Q] = (dp[Q]*w)%mod;
            dp[1-Q] = 0;
        }
    }
    cout << (dp[0]+dp[1])%mod << "\n";
}