#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
//const ll mod = 998244353;
ll mod = 998244353;

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
    return __int128(a)*__int128(b)%mod;
    /*if (a*b<mod) return a*b;
    else return a*b%mod;*/
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
    if (n<=2)
    {
        cout << 0 << "\n";
        return;
    }
    vector<pair<ll,ll>> A;
    vector<ll> L;
    vector<ll> pr, d(n+1);
    for (ll i=2;i<=n;i++)
    {
        if (d[i]==0)
        {
            d[i] = n;
            pr.push_back(i);
        }
        for (ll j=0;j<pr.size() and pr[j]<=d[i] and pr[j]*i<=n;j++)
        {
            d[pr[j]*i] = pr[j];
        }
    }
    vector<ll> was(n+1);
    for (ll i=pr.size()-1;i>=0;i--)
    {
        ll x = pr[i];
        vector<ll> c;
        for (ll j=x;j<=n;j+=x)
        {
            if (was[j]==1) continue;
            c.push_back(j);
            was[j] = 1;
        }
        if (c.size()>=2) swap(c[0],c[1]);
        while (c.size()>=2)
        {
            ll sz = c.size();
            A.push_back({c[sz-1],c[sz-2]});
            c.pop_back();
            c.pop_back();
        }
        if (c.size()==1) was[c[0]] = 0;
    }
    cout << A.size() << "\n";
    for (ll i=0;i<A.size();i++) cout << A[i].X << " " << A[i].Y << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    //cin >> T;
    T = 1;
    while (T--) solve();
}