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

const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;

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
}



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

vector<pair<ll,ll>> t[1200000];

vector<vector<pair<ll,ll>>> x;

void build(ll v, ll tl, ll tr)
{
    if (tl+1==tr)
    {
        for (auto w: x[tl]) t[v].push_back(w);
        return;
    }
    ll tm = (tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm,tr);
    vector<pair<ll,ll>> a;
    vector<pair<ll,ll>> C0 = t[2*v];
    vector<pair<ll,ll>> C1 = t[2*v+1];
    if (C0.size()==0 or C1.size()==0) return;
    ll i = 0, j = 0;
    while (i<C0.size() and j<C1.size())
    {
        if (C0[i].Y<=C1[j].X)
        {
            i++;
            continue;
        }
        if (C1[j].Y<=C0[i].X)
        {
            j++;
            continue;
        }
        t[v].push_back({max(C0[i].X,C1[j].X),min(C0[i].Y,C1[j].Y)});
        if (C0[i].Y<=C1[j].Y) i++;
        else j++;
    }
}

bool check(ll v, ll p)
{
    if (t[v].size()==0) return false;
    ll L = 0, R = t[v].size();
    if (t[v][0].X>p) return false;
    while (R-L>1)
    {
        ll M = (L+R)/2;
        if (t[v][M].X<=p) L = M;
        else R = M;
    }
    return t[v][L].Y > p;
}

ll get(ll v, ll tl, ll tr, ll p, ll val)
{
    if (tl+1==tr)
    {
        if (!check(v,val)) return tl;
        return tr;
    }
    ll tm = (tl+tr)/2;
    if (p<=tl)
    {
        if (check(v*2,val)) return get(v*2+1,tm,tr,p,val);
        else return get(v*2,tl,tm,p,val);
    }
    if (tm<=p) return get(v*2+1,tm,tr,p,val);
    ll q = get(v*2,tl,tm,p,val);
    if (q!=tm) return q;
    return get(v*2+1,tm,tr,p,val);
}

void solve()
{
    ll n, W;
    cin >> n >> W;
    vector<ll> P(n);
    vector<ll> a(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        cin >> P[i];
    }
    vector<ll> d(n);
    ll S = 0;
    ll A = 0;
    P[0] = (W-P[0])%W;
    for (ll i=1;i<n;i++)
    {
        cin >> d[i];
        A += d[i];
        S = (S+d[i])%W;
        P[i] = (-S-P[i]+2*W)%W;
    }
    x.resize(n);
    for (ll i=0;i<n;i++)
    {
        ll L = P[i];
        ll R = L+a[i];
        if (L<0) L += W;
        if (R>W) R -= W;
        if (L<=R) x[i].push_back({L,R});
        else
        {
            x[i].push_back({0,R});
            x[i].push_back({L,W});
        }
    }
    build(1,0,n);
    vector<ll> nxt(n);
    for (ll i=n-1;i>=0;i--)
    {
        nxt[i] = get(1,0,n,i,P[i]);
    }
    vector<ll> dp(n+1,mod*mod);
    dp[n] = 0;
    for (ll i=n-1;i>=0;i--)
    {
        dp[i] = dp[nxt[i]];
        if (nxt[i]==n) continue;
        dp[i] += (P[nxt[i]]-P[i]+W)%W;
    }
    if (nxt[0]==n)
    {
        cout << A << "\n";
        return;
    }
    ll ans = dp[0];
    vector<ll> trash;
    for (ll i=0;i<n;i++)
    {
        ll st = P[i];
        ll s = get(1,0,n,0,st);
        if (dp[s]==n) ans = min(ans,dp[s]);
        else ans = min(ans,dp[s]+(P[s]-st+W)%W);
        st = (P[i]+a[i]-1)%W;
        s = get(1,0,n,0,st);
        if (s==n) ans = min(ans,dp[s]);
        else ans = min(ans,dp[s]+(P[s]-st+W)%W);
    }
    cout << A+ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}