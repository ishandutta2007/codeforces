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


ll t[4400000];

void build(ll n)
{
    for (ll i=0;i<4*n+20;i++) t[i] = 0;
}

const ll mx = 1001000;
vector<vector<ll>> g(mx);
vector<ll> a(mx);
vector<vector<pair<pair<ll,ll>,ll>>> Q(mx);
vector<ll> C(mx), ans(mx);
set<pair<ll,ll>> kek;


void add(ll v, ll tl, ll tr, ll p, ll val)
{
    t[v] += val;
    if (tl==tr) return;
    ll tm = (tl+tr)/2;
    if (p<=tm) add(v*2,tl,tm,p,val);
    else add(v*2+1,tm+1,tr,p,val);
}

ll k;
ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl==tr)
    {
        if (t[v]>=k)
        {
            k = 0;
            return tl;
        }
        k -= t[v];
        return -1;
    }
    ll tm = (tl+tr)/2;
    if (tl>=l and tr<=r)
    {
        if (t[v]<k)
        {
            k -= t[v];
            return -1;
        }
        if (t[2*v]>=k) return get(v*2,tl,tm,l,r);
        else
        {
            k -= t[2*v];
            return get(v*2+1,tm+1,tr,l,r);
        }
    }
    if (tm>=l)
    {
        ll x = get(v*2,tl,tm,l,r);
        if (x!=-1) return x;
    }
    if (tm<r) return get(v*2+1,tm+1,tr,l,r);
    return -1;
}

ll n;

void dfs(ll u)
{
    ll z = a[u];
    add(1,0,n,C[z],-1);
    kek.erase({C[z],z});
    C[z]++;
    add(1,0,n,C[z],1);
    kek.insert({C[z],z});
    for (ll i=0;i<Q[u].size();i++)
    {
        ll L = Q[u][i].X.X;
        k = Q[u][i].X.Y;
        ll p = Q[u][i].Y;
        ll x = get(1,0,n,L,n);
        if (x==-1)
        {
            ans[p] = -1;
            continue;
        }
        auto it = kek.lower_bound({x,0});
        ans[p] = it->Y+1;
    }
    for (ll v: g[u])
    {
        dfs(v);
    }
    add(1,0,n,C[z],-1);
    kek.erase({C[z],z});
    C[z]--;
    add(1,0,n,C[z],1);
    kek.insert({C[z],z});
}

void solve()
{
    ll q;
    cin >> n >> q;
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (ll i=1;i<n;i++)
    {
        ll p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }

    for (ll i=0;i<q;i++)
    {
        ll u, L, z;
        cin >> u >> L >> z;
        u--;
        Q[u].push_back({{L,z},i});
    }
    kek.clear();
    dfs(0);
    for (ll i=0;i<q;i++) cout << ans[i] << " ";
    for (ll i=0;i<=n;i++)
    {
        g[i].clear();
        Q[i].clear();
        C[i] = 0;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}