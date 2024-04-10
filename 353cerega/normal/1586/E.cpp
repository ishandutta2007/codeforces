#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = double;

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
const int root = 31;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/


/*void fft (vector<int> & a, bool invert) {
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
}

vector<vector<ll>> g;
ll k = 20;
vector<vector<ll>> up;
vector<ll> h;

void dfs(ll u, ll p, ll H)
{
    up[u][0] = p;
    h[u] = H;
    for (ll v: g[u])
    {
        if (up[v][0]!=-2) continue;
        dfs(v,u,H+1);
    }
}

ll lca(ll a, ll b)
{
    ll j = k-1;
    if (h[a]<h[b]) swap(a,b);
    while (h[a]>h[b])
    {
        if (h[a]>=(1<<j)+h[b]) a = up[a][j];
        j--;
    }
    if (a==b) return a;
    j = k-1;
    while (j>=0)
    {
        if (up[a][j]!=up[b][j])
        {
            a = up[a][j], b = up[b][j];
        }
        j--;
    }
    a = up[a][0];
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    h.resize(n);
    up.resize(n,vector<ll>(k,-2));
    for (ll i=0;i<m;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,-1,0);
    for (ll d=0;d+1<k;d++)
    {
        for (ll i=0;i<n;i++)
        {
            if (up[i][d]==-1) up[i][d+1] = -1;
            else up[i][d+1] = up[up[i][d]][d];
        }
    }
    ll q;
    cin >> q;
    vector<ll> cnt(n);
    vector<pair<ll,ll>> a(q);
    for (ll i=0;i<q;i++)
    {
        cin >> a[i].X >> a[i].Y;
        a[i].X--, a[i].Y--;
        cnt[a[i].X]++;
        cnt[a[i].Y]++;
    }
    ll S = 0;
    for (ll i=0;i<n;i++)
    {
        if (cnt[i]%2==1) S++;
    }
    if (S>0)
    {
        cout << "NO\n";
        cout << S/2;
        return 0;
    }
    cout << "YES\n";
    for (ll i=0;i<q;i++)
    {
        ll A = a[i].X;
        ll B = a[i].Y;
        ll C = lca(A,B);
        vector<ll> kek, kek2;
        while (A!=C)
        {
            kek.push_back(A);
            A = up[A][0];
        }
        kek.push_back(C);
        while (B!=C)
        {
            kek2.push_back(B);
            B = up[B][0];
        }
        reverse(kek2.begin(),kek2.end());
        for (ll x: kek2) kek.push_back(x);
        cout << kek.size() << "\n";
        for (ll x: kek) cout << x+1 << " ";
        cout << "\n";
    }
}