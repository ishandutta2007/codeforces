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
    sz[v] = 1;
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


set<ll> cur;

void add(ll N)
{
    for (ll j=2;j*j<=N;j++)
    {
        if (N%j==0)
        {
            cur.insert(j);
            while (N%j==0) N /= j;
        }
    }
    if (N>1) cur.insert(N);
}

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    add(a[0]);
    add(a[0]-1);
    add(a[0]+1);
    add(a[n-1]);
    add(a[n-1]-1);
    add(a[n-1]+1);
    ll A = (n-1)*x;
    for (ll p: cur)
    {
        vector<ll> suf(n+1,mod*mod);
        suf[n] = 0;
        ll S = 0;
        for (ll i=n-1;i>=0;i--)
        {
            ll q = a[i]%p;
            if (q>1 and q<p-1) S = mod*mod;
            S -= x;
            if (q!=0) S += y;
            suf[i] = min(suf[i+1],S);
        }
        S = 0;
        A = min(A,suf[0]+n*x);
        for (ll i=0;i<n;i++)
        {
            ll q = a[i]%p;
            if (q>1 and q<p-1) break;
            S -= x;
            if (q!=0) S += y;
            A = min(A,suf[i+1]+S+n*x);
        }
    }
    cout << A << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    cin.tie(0);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}