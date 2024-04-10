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

ll K = 20;
vector<vector<ll>> g;
vector<pair<ll,ll>> Q, Q2;
vector<ll> h, L, R;
vector<vector<ll>> up;

ll T = 0;

void dfs(ll u, ll p, ll H)
{
    up[0][u] = p;
    h[u] = H;
    L[u] = T;
    T++;
    for (ll v: g[u])
    {
        dfs(v,u,H+1);
    }
    R[u] = T-1;
}

ll check(ll u, ll v)
{
    if (h[u]==h[v]) return -1;
    for (ll j=K-1;j>=0;j--)
    {
        if (h[u]>=h[v]+1+(1<<j)) u = up[j][u];
    }
    if (up[0][u]!=v) return -1;
    return u;
}


ll t[1200000];

void build()
{
    for (ll i=0;i<1200000;i++) t[i] = 0;
}

void upd(ll v, ll tl, ll tr, ll p, ll val)
{
    t[v] += val;
    if (tl==tr) return;
    ll tm = (tl+tr)/2;
    if (tm>=p) upd(v*2,tl,tm,p,val);
    else upd(v*2+1,tm+1,tr,p,val);
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r) return t[v];
    ll tm = (tl+tr)/2;
    ll S = 0;
    if (tm>=l) S +=  get(v*2,tl,tm,l,r);
    if (tm<r) S += get(v*2+1,tm+1,tr,l,r);
    return S;
}

bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    return h[a.Y]>h[b.Y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    for (ll i=1;i<n;i++)
    {
        ll p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }
    up.resize(K,vector<ll>(n));
    L.resize(n);
    R.resize(n);
    h.resize(n);
    dfs(0,-1,0);
    for (ll j=1;j<K;j++)
    {
        for (ll i=0;i<n;i++)
        {
            if (up[j-1][i]==-1) up[j][i] = -1;
            else up[j][i] = up[j-1][up[j-1][i]];
        }
    }
    for (ll i=0;i<m;i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        if (h[a]<h[b]) swap(a,b);
        if (up[0][a]==b)
        {
            cout << -1 << endl;
            return 0;
        }
        ll z = check(a,b);
        if (z!=-1) Q.push_back({a,z});
        else Q2.push_back({a,b});
    }
    build();
    sort(Q.begin(),Q.end(),cmp);
    ll A = 0;
    for (ll z=0;z<Q.size();z++)
    {
        ll a = Q[z].X;
        ll b = Q[z].Y;
        if (get(1,0,n-1,L[a],R[a])!=get(1,0,n-1,L[b],R[b])) continue;
        A++;
        upd(1,0,n-1,L[b],1);
    }
    for (ll z=0;z<Q2.size();z++)
    {
        ll a = Q2[z].X;
        ll b = Q2[z].Y;
        if (get(1,0,n-1,L[a],R[a])+get(1,0,n-1,L[b],R[b])!=get(1,0,n-1,0,n-1)) continue;
        A++;
        break;
    }
    cout << A << endl;
}