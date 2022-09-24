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


vector<ll> ans;
vector<vector<ll>> g, g2;
vector<set<ll>> W, gr;
vector<ll> num2, num, up;
set<pair<ll,ll>> lul;
ll C = 0;

void merge2(ll A, ll B)
{
    A = num2[A];
    B = num2[B];
    ll szA = g2[A].size()+W[A].size();
    ll szB = g2[B].size()+W[B].size();
    if (szA<szB) swap(A,B);
    for (ll x: W[B])
    {
        if (W[A].count(x))
        {
            ans[x] = C;
            W[A].erase(x);
        } else W[A].insert(x);
    }
    W[B].clear();
    for (ll x: g2[B])
    {
        num2[x] = A;
        g2[A].push_back(x);
    }
    gr[up[B]].erase(B);
    g2[B].clear();
}

void merge1(ll A, ll B)
{
    vector<pair<ll,ll>> add;
    for (ll B2: gr[B])
    {
        vector<ll> cur;
        for (ll A2: gr[A])
        {
            ll F = 0;
            for (ll x: g2[B2])
            {
                for (ll y: g2[A2])
                {
                    if (lul.count({x,y})) continue;
                    F = 1;
                    break;
                }
                if (F==1) break;
            }
            if (F==1) cur.push_back(A2);
        }
        while (cur.size()>1)
        {
            ll u = cur.back();
            cur.pop_back();
            ll v = cur.back();
            merge2(u,v);
        }
        if (cur.size()==1) add.push_back({B2,cur[0]});
    }
    for (auto x: add) merge2(x.X,x.Y);
    for (ll B2: gr[B])
    {
        up[B2] = A;
        gr[A].insert(B2);
    }
    gr[B].clear();
    for (ll x: g[B])
    {
        num[x] = A;
        g[A].push_back(x);
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<pair<ll,ll>,pair<ll,ll>>> e(m);
    vector<pair<ll,ll>> Q(m);
    ans.clear();
    g.clear();
    g2.clear();
    W.clear();
    gr.clear();
    num.clear();
    num2.clear();
    up.clear();
    lul.clear();
    ans.resize(m);
    g.resize(n);
    g2.resize(n);
    W.resize(n);
    gr.resize(n);
    num.resize(n);
    num2.resize(n);
    up.resize(n);
    for (ll i=0;i<m;i++)
    {
        cin >> e[i].Y.X >> e[i].Y.Y >> e[i].X.X;
        e[i].X.Y = i;
        e[i].Y.X--, e[i].Y.Y--;
        Q[i] = e[i].Y;
        lul.insert(Q[i]);
        lul.insert({e[i].Y.Y,e[i].Y.X});
        W[e[i].Y.X].insert(i);
        W[e[i].Y.Y].insert(i);
    }
    sort(e.begin(),e.end());
    for (ll i=0;i<n;i++)
    {
        g[i].push_back(i);
        num[i] = i;
        gr[i].insert(i);
        g2[i].push_back(i);
        num2[i] = i;
        up[i] = i;
    }
    for (ll i=0;i<m;i++)
    {
        ll u = e[i].Y.X;
        ll v = e[i].Y.Y;
        C = e[i].X.X;
        if (num[u]==num[v]) continue;
        ll A = num[u];
        ll B = num[v];
        if (g[A].size()<g[B].size()) swap(A,B);
        merge1(A,B);
    }
    for (ll i=0;i<m;i++) cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) solve();
}