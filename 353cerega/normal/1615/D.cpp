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

vector<vector<pair<ll,ll>>> g;
vector<vector<ll>> gr;
vector<ll> num, col;
vector<vector<ll>> ans;

void dfs(ll u, ll p)
{
    for (ll i=0;i<g[u].size();i++)
    {
        ll v = g[u][i].X;
        if (v==p) continue;
        dfs(v,u);
        if (g[u][i].Y!=-1) continue;
        if (num[v]==num[u])
        {
            if (col[u]==col[v])
            {
                ans.push_back({u,v,0});
            }
            else ans.push_back({u,v,1});
            continue;
        }
        ans.push_back({u,v,0});
        ll C = (col[u]+col[v])%2;
        ll a = u;
        ll b = v;
        a = num[a];
        b = num[b];
        if (gr[a].size()<gr[b].size()) swap(a,b);
        for (ll x: gr[b])
        {
            num[x] = a;
            gr[a].push_back(x);
            col[x] = (col[x]+C)%2;
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n);
    gr.clear();
    num.clear();
    col.clear();
    gr.resize(n);
    num.resize(n);
    col.resize(n);
    for (ll i=0;i<n;i++)
    {
        num[i] = i;
        gr[i].push_back(i);
    }
    ans.clear();
    for (ll i=1;i<n;i++)
    {
        ll a, b, v;
        cin >> a >> b >> v;
        a--, b--;
        g[a].push_back({b,v});
        g[b].push_back({a,v});
        if (v!=-1)
        {
            ans.push_back({a,b,v});
            ll C = 0;
            for (ll z=0;z<30;z++)
            {
                if (v&(1LL<<z)) C = 1-C;
            }
            C += col[a];
            C += col[b];
            C %= 2;
            a = num[a];
            b = num[b];
            if (gr[a].size()<gr[b].size()) swap(a,b);
            for (ll x: gr[b])
            {
                num[x] = a;
                gr[a].push_back(x);
                col[x] = (col[x]+C)%2;
            }
        }
    }
    ll F = 0;
    for (ll i=0;i<m;i++)
    {
        ll a, b, C;
        cin >> a >> b >> C;
        a--, b--;
        C += col[a];
        C += col[b];
        a = num[a];
        b = num[b];
        C %= 2;
        if (a==b and C==1)
        {
            F = 1;
            continue;
        }
        if (a==b) continue;
        if (gr[a].size()<gr[b].size()) swap(a,b);
        for (ll x: gr[b])
        {
            num[x] = a;
            gr[a].push_back(x);
            col[x] = (col[x]+C)%2;
        }
    }
    if (F==1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    dfs(0,-1);
    for (ll i=0;i<ans.size();i++)
    {
        cout << ans[i][0]+1 << " " << ans[i][1]+1 << " " << ans[i][2] << "\n";
    }
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