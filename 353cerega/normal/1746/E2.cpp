//#pragma GCC optimize("Ofast")
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


ll ask(vector<ll> a)
{
    cout << "? " << a.size();
    for (ll x: a) cout << " " << x;
    cout << endl;
    string s;
    cin >> s;
    if (s=="NO") return 0;
    return 1;
}

ll fin(ll x)
{
    cout << "! " << x << endl;
    string s;
    cin >> s;
    if (s[1]==')') return 1;
    return 0;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a;
    for (ll i=1;i<=n;i++)
    {
        a.push_back(i);
    }
    vector<vector<ll>> a2(2);
    a2[1] = a;
    ll S1 = n, S0 = 0;
    while (S1+S0>2)
    {
        vector<vector<ll>> b(4);
        for (ll i=0;i<a2[0].size();i++)
        {
            if (i%2==0) b[0].push_back(a2[0][i]);
            else b[1].push_back(a2[0][i]);
        }
        ll F = 0;
        if (b[0].size()!=b[1].size())
        {
            F = 1;
        }
        for (ll i=0;i<a2[1].size();i++)
        {
            if (i%2==0) b[3].push_back(a2[1][i]);
            else
            {
                if (F==1 and i==1) b[3].push_back(a2[1][i]);
                else
                {
                    b[2].push_back(a2[1][i]);
                }
            }
        }
        vector<ll> c;
        for (ll x: b[3]) c.push_back(x);
        for (ll x: b[1]) c.push_back(x);
        ll f = ask(c);
        a2[0].clear();
        a2[1].clear();
        if (f==0)
        {
            for (ll x: b[3]) a2[0].push_back(x);
            for (ll x: b[0]) a2[1].push_back(x);
            for (ll x: b[2]) a2[1].push_back(x);
        } else
        {
            for (ll x: b[2]) a2[0].push_back(x);
            for (ll x: b[1]) a2[1].push_back(x);
            for (ll x: b[3]) a2[1].push_back(x);
        }
        S0 = a2[0].size();
        S1 = a2[1].size();
    }
    a.clear();
    for (ll x: a2[0]) a.push_back(x);
    for (ll x: a2[1]) a.push_back(x);
    if (a.size()==3)
    {
        for (ll d=0;d<100;d++)
        {
            vector<ll> b;
            for (ll i=0;i<3;i++)
            {
                if (i!=d%3) b.push_back(a[i]);
            }
            ll f = ask(b);
            if (f==1) f = ask(b);
            if (f==1)
            {
                a = b;
                break;
            }
            ll p = a[(d+1)%3];
            ll q = a[(d+2)%3];
            ll r = a[d%3];
            vector<ll> c;
            c.push_back(p);
            f = ask(c);
            a.clear();
            a.push_back(r);
            if (f==1)
            {
                a.push_back(p);
            } else
            {
                a.push_back(q);
            }
            break;
        }
    }
    for (ll x: a)
    {
        if (fin(x)) return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}