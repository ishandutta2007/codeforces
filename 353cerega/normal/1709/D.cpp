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

ll K = 20;
vector<vector<ll>> mn;
vector<ll> len;

ll get(ll L, ll R)
{
    ll b = len[R-L];
    return min(mn[b][L],mn[b][R-(1<<b)]);
}

void solve()
{
    ll m, n;
    cin >> m >> n;
    vector<ll> a(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        a[i] = m-a[i];
    }
    mn.resize(K,vector<ll>(n));
    len.resize(1<<K);
    for (ll j=0;j<K;j++)
    {
        for (ll x=(1<<j);x<(1<<(j+1));x++) len[x] = j;
    }
    for (ll i=0;i<n;i++) mn[0][i] = a[i];
    for (ll j=1;j<K;j++)
    {
        for (ll i=0;i+(1LL<<j)<=n;i++) mn[j][i] = min(mn[j-1][i],mn[j-1][i+(1<<(j-1))]);
    }
    ll q;
    cin >> q;
    vector<vector<ll>> Q(q,vector<ll>(5));
    vector<pair<pair<ll,ll>,ll>> ord;
    ll W = 200;
    for (ll i=0;i<q;i++)
    {
        for (ll j=0;j<5;j++) cin >> Q[i][j];
        swap(Q[i][0],Q[i][1]);
        swap(Q[i][2],Q[i][3]);
        swap(Q[i][1],Q[i][2]);
        Q[i][0]--, Q[i][1]--;
        if (Q[i][1]<Q[i][0]) swap(Q[i][0],Q[i][1]);
        ord.push_back({{Q[i][0]/W,Q[i][1]},i});
    }
    sort(ord.begin(),ord.end());
    vector<ll> ans(q);
    ll L = 0, R = 0;
    set<pair<ll,ll>> cur;
    for (int j=0;j<ord.size();j++)
    {
        ll p = ord[j].Y;
        ll L2 = Q[p][0];
        ll R2 = Q[p][1]+1;
        ll x = get(L2,R2);
        ll w = Q[p][4];
        if (Q[p][0]%w!=Q[p][1]%w or Q[p][2]%w!=Q[p][3]%w) ans[p] = 1;
        Q[p][2] = m-Q[p][2];
        Q[p][2] %= w;
        if (Q[p][2]>=x) ans[p] = 1;
    }
    for (ll i=0;i<q;i++)
    {
        if (ans[i]==0) cout << "YES\n";
        else cout << "NO\n";
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