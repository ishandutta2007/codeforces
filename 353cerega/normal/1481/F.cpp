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


vector<vector<ll>> g;
vector<ll> h, c, c2;
ll n, k;

ll mx = 0;

void dfs(ll u, ll H)
{
    c[H]++;
    h[u] = H;
    mx = max(mx,H+1);
    if (g[u].size()==0) c2[H]++;
    for (ll v: g[u])
    {
        dfs(v,H+1);
    }
}

const ll M = 300;

ll solve()
{
    vector<ll> C(M+1);
    for (ll i=0;i<n;i++)
    {
        if (c[i]<=M) C[c[i]]++;
    }
    vector<ll> dp(n+1);
    vector<ll> prv(n+1);
    dp[0] = 1;
    for (ll D=1;D<=M;D++)
    {
        ll Q = C[D];
        if (Q==0) continue;
        for (ll i=0;i+D<=n;i++)
        {
            if (dp[i]==0 or dp[i+D]==1) continue;
            if (prv[i]==i-D*Q) continue;
            dp[i+D] = 1;
            if (i-prv[i]>=D) prv[i+D] = prv[i];
            else prv[i+D] = i;
        }
        for (ll i=0;i<=n;i++)
        {
            if (dp[i]==1 and i-prv[i]>D) prv[i] = i-D;
        }
    }
    for (ll z=0;z<n;z++)
    {
        ll D = c[z];
        if (D<=M) continue;
        for (ll i=n-D;i>=0;i--)
        {
            if (dp[i]==0 or dp[i+D]==1) continue;
            dp[i+D] = 1;
            prv[i+D] = i;
        }
    }
    if (dp[k]==0) return 0;
    cout << mx << "\n";
    set<pair<ll,ll>> kek;
    vector<ll> col(n);
    for (ll i=0;i<n;i++)
    {
        kek.insert({c[i],i});
    }
    ll x = k;
    while (x>0)
    {
        ll D = x-prv[x];
        x = prv[x];
        auto it = kek.lower_bound({D,0});
        col[it->Y] = 1;
        kek.erase(it);
    }
    for (ll i=0;i<n;i++)
    {
        if (col[h[i]]==1) cout << "a";
        else cout << "b";
    }
    return 1;
}

void solve2()
{
    cout << mx+1 << "\n";
    ll p = -1;
    mx = -1;
    for (ll i=0;i<n;i++)
    {
        if (c2[i]>mx)
        {
            mx = c2[i];
            p = i;
        }
    }
    c[p] -= c2[p];
    vector<ll> C(M+1);
    for (ll i=0;i<n;i++)
    {
        if (c[i]<=M) C[c[i]]++;
    }
    vector<ll> dp(n+1);
    vector<ll> prv(n+1);
    dp[0] = 1;
    for (ll D=1;D<=M;D++)
    {
        ll Q = C[D];
        if (Q==0) continue;
        for (ll i=0;i+D<=n;i++)
        {
            if (dp[i]==0 or dp[i+D]==1) continue;
            if (prv[i]==i-D*Q) continue;
            dp[i+D] = 1;
            if (i-prv[i]>=D) prv[i+D] = prv[i];
            else prv[i+D] = i;
        }
        for (ll i=0;i<=n;i++)
        {
            if (dp[i]==1 and i-prv[i]>D) prv[i] = i-D;
        }
    }
    for (ll z=0;z<n;z++)
    {
        ll D = c[z];
        if (D<=M) continue;
        for (ll i=n-D;i>=0;i--)
        {
            if (dp[i]==0 or dp[i+D]==1) continue;
            dp[i+D] = 1;
            prv[i+D] = i;
        }
    }
    for (ll q=max(0LL,k-mx);q<=k;q++)
    {
        if (dp[q]==0) continue;
        set<pair<ll,ll>> kek;
        vector<ll> col(n);
        for (ll i=0;i<n;i++)
        {
            kek.insert({c[i],i});
        }
        k -= q;
        ll x = q;
        while (x>0)
        {
            ll D = x-prv[x];
            x = prv[x];
            auto it = kek.lower_bound({D,0});
            col[it->Y] = 1;
            kek.erase(it);
        }
        for (ll i=0;i<n;i++)
        {
            if (h[i]!=p or g[i].size()>0)
            {
                if (col[h[i]]==1) cout << "a";
                else cout << "b";
                continue;
            }
            if (k>0)
            {
                k--;
                cout << "a";
            }
            else cout << "b";
        }
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    g.resize(n);
    for (ll i=1;i<n;i++)
    {
        ll p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    h.resize(n);
    c.resize(n);
    c2.resize(n);
    dfs(0,0);
    if (solve())
    {
        return 0;
    }
    solve2();
}