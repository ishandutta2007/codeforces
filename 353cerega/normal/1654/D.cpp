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
vector<vector<vector<pair<ll,ll>>>> g2;

ll mx = 300000;
vector<ll> d(mx+1), pr;

void prec()
{
    for (ll i=2;i<=mx;i++)
    {
        if (d[i]==0)
        {
            d[i] = i;
            pr.push_back(i);
        }
        for (ll j=0;j<pr.size() and pr[j]*i<=mx and pr[j]<=d[i];j++)
        {
            d[i*pr[j]] = pr[j];
        }
    }
}

ll S = 0;

vector<ll> C, mn;
vector<ll> obr;

void dfs(ll u, ll p, ll x)
{
    S = (S+x)%mod;
    for (ll i=0;i<g[u].size();i++)
    {
        if (g[u][i]==p) continue;
        ll x2 = x;
        for (auto w: g2[u][i])
        {
            C[w.X] += w.Y;
            mn[w.X] = min(mn[w.X],C[w.X]);
            if (w.Y>0)
            {
                for (ll z=0;z<w.Y;z++) x2 = x2*w.X%mod;
            } else
            {
                for (ll z=0;z<-w.Y;z++) x2 = x2*obr[w.X]%mod;
            }
        }
        dfs(g[u][i],u,x2);
        for (auto w: g2[u][i])
        {
            C[w.X] -= w.Y;
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    g.clear();
    g2.clear();
    g.resize(n);
    g2.resize(n);
    for (ll i=1;i<n;i++)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        ll A, B;
        cin >> A >> B;
        map<ll,ll> cnt;
        while (A>1)
        {
            cnt[d[A]]--;
            A /= d[A];
        }
        while (B>1)
        {
            cnt[d[B]]++;
            B /= d[B];
        }
        vector<pair<ll,ll>> cur;
        for (auto p: cnt)
        {
            cur.push_back(p);
        }
        g[x].push_back(y);
        g2[x].push_back(cur);
        ll sz = cur.size();
        vector<pair<ll,ll>> cur2(sz);
        for (ll z=0;z<sz;z++)
        {
            cur2[z] = {cur[z].X,-cur[z].Y};
        }
        g[y].push_back(x);
        g2[y].push_back(cur2);
    }
    S = 0;
    mn.clear();
    C.clear();
    obr.clear();
    mn.resize(n+1);
    C.resize(n+1);
    obr.resize(n+1);
    for (ll i=1;i<=n;i++) obr[i] = pew(i,mod-2);
    dfs(0,-1,1);
    for (ll z=0;z<=n;z++)
    {
        if (mn[z]==0) continue;
        for (ll q=0;q<-mn[z];q++) S = S*z%mod;
    }
    cout << S << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    prec();
    while (t--) solve();
}