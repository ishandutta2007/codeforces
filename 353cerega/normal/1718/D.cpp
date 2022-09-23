//#pragma GCC optimize("Ofast")
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

vector<vector<ll>> g, mx;
vector<ll> a, b, len, M;

ll get(ll L, ll R)
{
    ll w = len[R-L];
    if (b[mx[w][L]]>b[mx[w][R-(1LL<<w)]]) return mx[w][L];
    return mx[w][R-(1LL<<w)];
}

void rec(ll L, ll R, ll p)
{
    ll p2 = get(L,R+1);
    if (p!=-1) g[p].push_back(p2);
    if (p2!=L) rec(L,p2-1,p2);
    if (p2!=R) rec(p2+1,R,p2);
}

ll F = 0;

vector<pair<ll,ll>> x;

void dfs0(ll u, ll W)
{
    M[u] = 0;
    if (a[u]!=0)
    {
        M[u] = a[u];
        W = a[u];
    }
    for (ll v: g[u])
    {
        dfs0(v,W);
        if (a[u]!=0 and M[v]>=a[u]) F = 1;
        M[u] = max(M[u],M[v]);
    }
    if (a[u]==0)
    {
        x.push_back({M[u]+1,W});
    }
}


void solve()
{
    ll n, q;
    cin >> n >> q;
    b.resize(n);
    a.resize(n);
    g.clear();
    g.resize(n);
    M.resize(n);
    ll K = 20;
    mx.clear();
    mx.resize(K,vector<ll>(n));
    for (ll i=0;i<n;i++)
    {
        cin >> b[i];
        mx[0][i] = i;
    }
    for (ll j=1;j<K;j++)
    {
        for (ll i=0;i+(1LL<<j)<=n;i++)
        {
            if (b[mx[j-1][i]]>b[mx[j-1][i+(1LL<<(j-1))]]) mx[j][i] = mx[j-1][i];
            else mx[j][i] = mx[j-1][i+(1LL<<(j-1))];
        }
    }
    ll R = get(0,n);
    rec(0,n-1,-1);
    F = 0;
    ll D = 0;
    set<ll> kek;
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        if (a[i]==0) D++;
        else
        {
            if (kek.count(a[i])) F = 1;
            kek.insert(a[i]);
        }
    }
    vector<ll> val(D-1);
    for (ll i=0;i<D-1;i++) cin >> val[i];
    sort(val.begin(),val.end());
    for (ll i=0;i<D-1;i++)
    {
        if (kek.count(val[i])) F = 1;
        kek.insert(val[i]);
    }
    x.clear();
    ll INF = 1000001;
    dfs0(R,INF);
    vector<ll> Q(q);
    for (ll i=0;i<q;i++) cin >> Q[i];
    for (ll i=0;i<D-1;i++) x.push_back({val[i],INF+1});
    sort(x.begin(),x.end());
    vector<vector<ll>> A;
    multiset<pair<ll,ll>> kek2;
    ll L1 = 0, R1 = 0;
    for (ll i=0;i<x.size();i++)
    {
        ll w = x[i].X;
        while (kek2.size()>0 and kek2.begin()->X<=w)
        {
            L1 = kek2.begin()->Y;
            R1 = kek2.begin()->X;
            kek2.erase(kek2.begin());
        }
        if (x[i].Y!=INF+1)
        {
            kek2.insert({x[i].Y,x[i].X});
        }
        else
        {
            if (kek2.size()==0)
            {
                F = 1;
                break;
            }
            ll L2 = kek2.begin()->Y;
            ll R2 = kek2.begin()->X;
            kek2.erase(kek2.begin());
            A.push_back({w,L2,R2});
        }
    }
    if (kek2.size()!=0)
    {
        L1 = kek2.begin()->Y;
        R1 = kek2.begin()->X;
    }
    if (F==1)
    {
        for (ll i=0;i<q;i++) cout << "NO\n";
        return;
    }
    set<pair<ll,ll>> kek3;
    for (ll i=0;i<A.size();i++) kek3.insert({A[i][0],i});
    while (true)
    {
        auto it = kek3.lower_bound({L1,0});
        if (it==kek3.end() or it->X>=R1) break;
        ll p = it->Y;
        kek3.erase(it);
        L1 = min(L1,A[p][1]);
        R1 = max(R1,A[p][2]);
    }
    for (ll i=0;i<q;i++)
    {
        if (Q[i]>=L1 and Q[i]<R1) cout << "YES\n";
        else cout << "NO\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    len.resize(1<<20);
    for (ll k=0;k<20;k++)
    {
        for (ll i=(1LL<<k);i<2*(1LL<<k);i++) len[i] = k;
    }
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}