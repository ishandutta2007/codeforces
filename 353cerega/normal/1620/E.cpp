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


vector<vector<ll>> g;

void solve()
{
    ll q;
    cin >> q;
    set<pair<ll,ll>> kek;
    ll S = 0;
    vector<ll> col;
    for (ll i=0;i<q;i++)
    {
        ll t, x;
        cin >> t >> x;
        if (t==1)
        {
            col.push_back(x);
            make_set(S);
            S++;
            auto it = kek.lower_bound({x,0});
            if (it!=kek.end() and it->X==x)
            {
                ll p = it->Y;
                union_sets(S-1,p);
                ll P = find_set(p);
                kek.erase(it);
                kek.insert({x,P});
            } else
            {
                kek.insert({x,S-1});
            }
            continue;
        }
        ll y;
        cin >> y;
        auto it = kek.lower_bound({x,0});
        if (it==kek.end() or it->X!=x) continue;
        ll p = it->Y;
        col[p] = y;
        kek.erase(it);
        it = kek.lower_bound({y,0});
        if (it==kek.end() or it->X!=y)
        {
            kek.insert({col[p],p});
            continue;
        }
        ll p2 = it->Y;
        union_sets(p,p2);
        p = find_set(p);
        kek.erase(it);
        kek.insert({col[p],p});
    }
    for (ll i=0;i<S;i++)
    {
        ll x = find_set(i);
        cout << col[x] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}