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


ll t[1200000], del[1200000];

void build(ll n)
{
    for (ll i=0;i<4*n+100;i++) t[i] = -1, del[i] = -1;
}

void push(ll v)
{
    if (del[v]==-1) return;
    t[2*v] = del[2*v] = t[2*v+1] = del[2*v+1] = del[v];
    del[v] = -1;
}

void upd(ll v, ll tl, ll tr, ll l, ll r, ll x)
{
    if (tl>=l and tr<=r)
    {
        t[v] = x;
        del[v] = x;
        return;
    }
    ll tm = (tl+tr)/2;
    push(v);
    if (tm>=l) upd(v*2,tl,tm,l,r,x);
    if (tm<r) upd(v*2+1,tm+1,tr,l,r,x);
    t[v] = max(t[2*v],t[2*v+1]);
}

ll get(ll v, ll tl, ll tr, ll p)
{
    if (tl==tr) return t[v];
    ll tm = (tl+tr)/2;
    push(v);
    if (tm>=p) return get(v*2,tl,tm,p);
    else return get(v*2+1,tm+1,tr,p);
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    ll S = -1;
    {
        vector<pair<ll,ll>> ord(n);
        for (ll i=0;i<n;i++) ord[i] = {a[i],i};
        sort(ord.begin(),ord.end());
        for (ll i=0;i<ord.size();i++)
        {
            if (i==0 or ord[i].X!=ord[i-1].X) S++;
            a[ord[i].Y] = S;
        }
        S++;
    }
    build(n);
    vector<pair<ll,ll>> Q(m);
    for (ll i=0;i<m;i++)
    {
        cin >> Q[i].Y >> Q[i].X;
        Q[i].Y--, Q[i].X--;
    }
    sort(Q.begin(),Q.end());
    for (ll i=0;i<m;i++)
    {
        upd(1,0,n-1,Q[i].Y,Q[i].X,Q[i].X);
    }
    vector<ll> mx(n);
    for (ll i=0;i<n;i++)
    {
        mx[i] = max(i,get(1,0,n-1,i));
    }
    vector<vector<ll>> g(S);
    vector<ll> pos(n);
    for (ll i=0;i<n;i++)
    {
        pos[i] = g[a[i]].size();
        g[a[i]].push_back(i);
    }
    ll mnL = n;
    ll mnR = -1;
    vector<pair<ll,ll>> kek;
    for (ll i=0;i<n;i++)
    {
        ll x = a[i];
        ll L = 0, R = g[x].size();
        while (R-L>1)
        {
            ll M = (L+R)/2;
            if (g[x][M]<=mx[i]) L = M;
            else R = M;
        }
        if (g[x][L]==i) continue;
        ll b = pos[i];
        mnL = min(mnL,g[x][b+1]);
        mnR = max(mnR,g[x][L-1]);
        kek.push_back({g[x][b],g[x][L]});
    }
    if (kek.size()==0)
    {
        cout << 0 << "\n";
        return;
    }
    {
        vector<pair<ll,ll>> kek2;
        for (ll i=0;i<kek.size();i++)
        {
            if (kek[i].X>=mnL or kek[i].Y<=mnR) continue;
            kek2.push_back(kek[i]);
        }
        kek = kek2;
    }
    sort(kek.begin(),kek.end());
    ll R = mnR;
    ll A = n;
    for (ll i=0;i<kek.size();i++)
    {
        ll L = kek[i].X;
        A = min(A,R-min(L,mnL)+1);
        R = max(R,kek[i].Y);
    }
    A = min(A,R-mnL+1);
    ll L = mnL;
    for (ll i=0;i<kek.size();i++)
    {
        swap(kek[i].X,kek[i].Y);
    }
    sort(kek.begin(),kek.end());
    reverse(kek.begin(),kek.end());
    for (ll i=0;i<kek.size();i++)
    {
        R = kek[i].X;
        A = min(A,max(R,mnR)-L+1);
        L = min(L,kek[i].Y);
    }
    A = min(A,mnR-L+1);
    A = max(A,0LL);
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    //T = 1;
    cin >> T;
    while (T--) solve();
}