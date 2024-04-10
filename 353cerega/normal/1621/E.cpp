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



void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    while (n>m)
    {
        a.pop_back();
        n--;
    }
    reverse(a.begin(),a.end());
    vector<pair<ll,ll>> ord(m);
    vector<vector<ll>> g(m);
    vector<ll> S(m);
    for (ll i=0;i<m;i++)
    {
        ll sz;
        cin >> sz;
        for (ll j=0;j<sz;j++)
        {
            ll x;
            cin >> x;
            S[i] += x;
            g[i].push_back(x);
        }
        ll R = S[i]/sz;
        if (S[i]%sz!=0) R++;
        ord[i] = {R,i};
    }
    sort(ord.begin(),ord.end());
    ll mx = m;
    ll bad = 0;
    for (ll i=0;i<m;i++)
    {
        if (i+1<m and ord[i].X>a[i+1])
        {
            bad = 1;
        }
        if (ord[i].X>a[i])
        {
            if (mx==m) mx = i+1;
        }
    }
    if (bad==1)
    {
        for (ll i=0;i<m;i++)
        {
            ll sz = g[i].size();
            for (ll j=0;j<sz;j++) cout << "0";
        }
        cout << "\n";
        return;
    }
    vector<ll> suf(m+1);
    suf[m] = m;
    for (ll i=m-1;i>0;i--)
    {
        if (suf[i+1]==-1 or ord[i].X>a[i])
        {
            suf[i] = -1;
            continue;
        }
        if (ord[i].X<=a[i-1]) suf[i] = suf[i+1];
        else suf[i] = i;
    }
    for (ll i=0;i<m;i++)
    {
        ll p = ord[i].Y;
        ll sz = g[p].size();
        for (ll j=0;j<sz;j++)
        {
            ll Q = S[p]-g[p][j];
            ll R = Q/(sz-1);
            if (Q%(sz-1)!=0) R++;
            ll pos = min(mx,suf[i+1])-1;
            if (pos<0 or a[pos]<R) g[p][j] = 0;
            else g[p][j] = 1;
        }
    }
    for (ll i=0;i<m;i++)
    {
        for (ll j=0;j<g[i].size();j++) cout << g[i][j];
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}