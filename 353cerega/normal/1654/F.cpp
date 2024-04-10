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




void solve()
{
    ll n;
    cin >> n;
    ll L = (1LL<<n);
    string s;
    cin >> s;
    vector<ll> ord;
    vector<ll> val(L);
    ll sz = 26;
    {
        vector<vector<ll>> cur(sz);
        for (ll i=0;i<L;i++)
        {
            val[i] = s[i]-'a';
            cur[val[i]].push_back(i);
        }
        for (ll z=0;z<sz;z++)
        {
            for (ll i=0;i<cur[z].size();i++) ord.push_back(cur[z][i]);
        }
    }
    for (ll b=0;b<n;b++)
    {
        vector<vector<pair<ll,ll>>> g(sz);
        for (ll i=0;i<ord.size();i++)
        {
            ll p = ord[i];
            ll x = val[p];
            ll p2 = p^(1LL<<b);
            ll x2 = val[p2];
            g[x2].push_back({x,p2});
        }
        ll sz2 = 0;
        ord.clear();
        for (ll z=0;z<sz;z++)
        {
            for (ll q=0;q<g[z].size();q++)
            {
                if (q==0 or g[z][q].X!=g[z][q-1].X) sz2++;
                ll p = g[z][q].Y;
                val[p] = sz2-1;
                ord.push_back(p);
            }
        }
        sz = sz2;
    }
    ll st = ord[0];
    for (ll i=0;i<L;i++)
    {
        cout << s[st^i];
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    t = 1;
    while (t--) solve();
}