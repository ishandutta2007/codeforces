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

ll t[2200000];

void build()
{
    for (ll i=0;i<2200000;i++) t[i] = 0;
}

void upd(ll v, ll tl, ll tr, ll p, ll d)
{
    t[v] = (t[v]+d)%mod;
    if (tl==tr) return;
    ll tm = (tl+tr)/2;
    if (p<=tm) upd(v*2,tl,tm,p,d);
    else upd(v*2+1,tm+1,tr,p,d);
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r) return t[v];
    ll tm = (tl+tr)/2;
    ll x = 0;
    if (l<=tm) x += get(v*2,tl,tm,l,r);
    if (r>tm) x += get(v*2+1,tm+1,tr,l,r);
    x %= mod;
    return x;
}

bool cmp(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b)
{
    return a.X.Y<b.X.Y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<pair<pair<ll,ll>,ll>> a(n);
    for (ll i=0;i<n;i++) cin >> a[i].X.X >> a[i].X.Y;
    ll k;
    cin >> k;
    for (ll i=0;i<k;i++)
    {
        ll x;
        cin >> x;
        x--;
        a[x].Y = 1;
    }
    sort(a.begin(),a.end(),cmp);
    vector<ll> dp(n);
    build();
    vector<pair<ll,ll>> p;
    for (ll i=0;i<n;i++)
    {
        if (a[i].Y==1) p.push_back({a[i].X.X,i});
    }
    vector<ll> pr(n+1);
    for (ll i=0;i<n;i++)
    {
        ll x = get(1,0,2*n,a[i].X.X,2*n);
        dp[i] = (x+1)%mod;
        upd(1,0,2*n,a[i].X.X,dp[i]);
        pr[i+1] = (pr[i]+dp[i])%mod;
    }
    sort(p.begin(),p.end());
    {
        vector<pair<ll,ll>> q;
        for (ll i=0;i<p.size();i++)
        {
            while (q.size()>0)
            {
                if (a[q.back().Y].X.Y<a[p[i].Y].X.Y) q.pop_back();
                else break;
            }
            q.push_back(p[i]);
        }
        p = q;
    }
    ll S = 0;
    vector<pair<pair<ll,ll>,ll>> b(n);
    for (ll i=0;i<n;i++)
    {
        b[i] = a[i];
        b[i].Y = i;
    }
    sort(b.begin(),b.end());
    build();
    for (ll i=0;i<n;i++)
    {
        upd(1,0,2*n,b[i].X.Y,dp[b[i].Y]);

    }
    ll d = 0;
    ll j = 0;
    for (ll i=0;i<p.size();i++)
    {
        S += get(1,0,2*n,d,a[p[i].Y].X.Y)+mod-dp[p[i].Y]+1;
        S %= mod;
        d = a[p[i].Y].X.X;
        while (j<n and b[j].X.X<=d)
        {
            upd(1,0,2*n,b[j].X.Y,mod-dp[b[j].Y]);
            j++;
        }
    }
    cout << S << endl;
}