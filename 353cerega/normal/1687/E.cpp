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

/*
set<pair<ll,ll>> kek;

void add(ll L, ll R)
{
    auto it = kek.lower_bound({L+1,-1});
    if (it!=kek.begin())
    {
        it--;
        if (it->Y>=R) return;
    }
    while (true)
    {
        it = kek.lower_bound({L,-1});
        if (it!=kek.end() and it->Y<=R) kek.erase(it);
        else break;
    }
    kek.insert({L,R});
}*/


vector<ll> a;
vector<vector<ll>> ans;
ll n;

void add(ll F, ll p)
{
    vector<ll> cur;
    ll G = 0;
    for (ll i=0;i<n;i++)
    {
        if (i==p) continue;
        ll G2 = gcd(G,a[i]);
        if (G2!=G)
        {
            G = G2;
            cur.push_back(i);
        }
    }
    ll sz = cur.size();
    while (true)
    {
        sz = cur.size();
        ll W = 0;
        for (ll i=0;i<sz;i++)
        {
            ll Q = 0;
            for (ll j=0;j<sz;j++)
            {
                if (j==i) continue;
                Q = gcd(Q,a[cur[j]]);
            }
            if (Q==G)
            {
                vector<ll> cur2;
                for (ll j=0;j<sz;j++)
                {
                    if (j==i) continue;
                    cur2.push_back(cur[j]);
                }
                W = 1;
                cur = cur2;
                break;
            }
        }
        if (W==0) break;
    }
    sz = cur.size();
    ll sz2 = (1LL<<sz);
    for (ll m=1;m<sz2;m++)
    {
        ll F2 = F^1;
        ll C = 0;
        for (ll b=0;b<sz;b++)
        {
            if (m&(1LL<<b))
            {
                F2 ^= 1;
                C++;
            }
        }
        vector<ll> A;
        A.push_back(F2);
        A.push_back(C);
        for (ll b=0;b<sz;b++)
        {
            if (m&(1LL<<b)) A.push_back(cur[b]+1);
        }
        ans.push_back(A);
    }
}

void solve()
{
    cin >> n;
    a.resize(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
    }
    ll D = 2;
    ll G = 0;
    for (ll i=0;i<n;i++)
    {
        ll G2 = gcd(G,a[i]);
        if (G2!=G)
        {
            G = G2;
            add(0,i);
            D--;
        }
    }
    while (D>0)
    {
        D--;
        add(0,-1);
    }
    while (D<0)
    {
        D++;
        add(1,-1);
    }
    cout << ans.size() << "\n";
    for (ll i=0;i<ans.size();i++)
    {
        for (ll x: ans[i]) cout << x << " ";
        cout << "\n";
    }
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