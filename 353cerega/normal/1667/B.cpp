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

vector<set<pair<ll,ll>>> kek;

ll calc(ll p, ll v)
{
    auto it = kek[0].lower_bound({v,mod*mod});
    ll A = -mod;
    if (it!=kek[0].end())
    {
        A = max(A,it->Y-p);
    }
    it = kek[1].lower_bound({v,-mod*mod});
    if (it!=kek[1].end()) A = max(A,it->Y);
    it = kek[2].lower_bound({-v,mod*mod});
    if (it!=kek[2].end()) A = max(A,it->Y+p);
    return A;
}

void recalc(ll i, ll p, ll v)
{
    ll V = v+i;
    auto it = kek[0].lower_bound({p,-mod*mod});
    if (it==kek[0].end() or it->Y<V)
    {
        while (true)
        {
            it = kek[0].lower_bound({p,mod*mod});
            if (it==kek[0].begin()) break;
            it--;
            if (it->Y>V) break;
            kek[0].erase(it);
        }
        kek[0].insert({p,V});
    }
    V = v;
    it = kek[1].lower_bound({p,mod*mod});
    if (it==kek[1].end() or it->Y<V)
    {
        while (true)
        {
            it = kek[1].lower_bound({p,mod*mod});
            if (it==kek[1].begin()) break;
            it--;
            if (it->Y>V) break;
            kek[1].erase(it);
        }
        kek[1].insert({p,V});
    }
    V = v-i;
    it = kek[2].lower_bound({-p,mod*mod});
    if (it==kek[2].end() or it->Y<V)
    {
        while (true)
        {
            it = kek[2].lower_bound({-p,mod*mod});
            if (it==kek[2].begin()) break;
            it--;
            if (it->Y>V) break;
            kek[2].erase(it);
        }
        kek[2].insert({-p,V});
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), pr(n+1);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        pr[i+1] = pr[i]+a[i];
    }
    kek.clear();
    kek.resize(3);
    vector<ll> dp(n+1);
    for (ll i=n;i>=0;i--)
    {
        if (i!=n) dp[i] = calc(i,pr[i]);
        recalc(i,pr[i],dp[i]);
    }
    cout << dp[0] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    cin >> T;
    while (T--) solve();
}