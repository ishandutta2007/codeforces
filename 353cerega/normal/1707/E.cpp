//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

ll mod = 1000000007;
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


vector<ll> len;
int K = 20;
int mn[20][20][110000];
int mx[20][20][110000];

ll n;

void calc()
{
    ll L, R;
    cin >> L >> R;
    L--;
    if (L==0 and R==n)
    {
        cout << 0 << "\n";
        return;
    }
    ll b = len[R-L];
    if (min(mn[K-1][b][L],mn[K-1][b][R-(1<<b)])!=0)
    {
        cout << -1 << "\n";
        return;
    }
    if (max(mx[K-1][b][L],mx[K-1][b][R-(1<<b)])!=n-1)
    {
        cout << -1 << "\n";
        return;
    }
    ll A = 1;
    for (ll j=K-1;j>=0;j--)
    {
        ll F = 0;
        b = len[R-L];
        if (min(mn[j][b][L],mn[j][b][R-(1<<b)])!=0) F = 1;
        if (max(mx[j][b][L],mx[j][b][R-(1<<b)])!=n-1) F = 1;
        if (F==1)
        {
            ll L2 = min(mn[j][b][L],mn[j][b][R-(1<<b)]);
            ll R2 = max(mx[j][b][L],mx[j][b][R-(1<<b)])+1;
            L = L2, R = R2;
            A += (1<<j);
        }
    }
    cout << A << "\n";
}

void solve()
{
    ll q;
    cin >> n >> q;
    vector<ll> a(n);
    len.resize(1<<K);
    for (ll b=0;b<K;b++)
    {
        for (ll i=(1<<b);i<(1<<(b+1));i++) len[i] = b;
    }
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
        mn[0][0][i] = mx[0][0][i] = a[i];
        if (i!=0)
        {
            mn[0][1][i-1] = min(a[i],a[i-1]);
            mx[0][1][i-1] = max(a[i],a[i-1]);
        }
    }
    for (ll j=2;j<K;j++)
    {
        for (ll i=0;i+(1<<j)<=n;i++)
        {
            mn[0][j][i] = min(mn[0][j-1][i],mn[0][j-1][i+(1<<(j-1))]);
            mx[0][j][i] = max(mx[0][j-1][i],mx[0][j-1][i+(1<<(j-1))]);
        }
    }
    for (ll b=1;b<K;b++)
    {
        for (ll i=0;i<n;i++)
        {
            mn[b][0][i] = mx[b][0][i] = mn[b-1][0][mn[b-1][0][i]];
            if (i+1!=n)
            {
                ll L = mn[b-1][1][i];
                ll R = mx[b-1][1][i];
                R++;
                ll j = len[R-L];
                mn[b][1][i] = min(mn[b-1][j][L],mn[b-1][j][R-(1<<j)]);
                mx[b][1][i] = max(mx[b-1][j][L],mx[b-1][j][R-(1<<j)]);
            }
        }
        for (ll j=2;j<K;j++)
        {
            for (ll i=0;i+(1<<j)<=n;i++)
            {
                mn[b][j][i] = min(min(mn[b][j-1][i],mn[b][j-1][i+(1<<(j-1))]),mn[b][j-1][i+(1<<(j-2))]);
                mx[b][j][i] = max(max(mx[b][j-1][i],mx[b][j-1][i+(1<<(j-1))]),mx[b][j-1][i+(1<<(j-2))]);
            }
        }
    }
    while (q--) calc();
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}