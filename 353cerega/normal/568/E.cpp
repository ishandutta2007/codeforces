//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = int;
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

inline ll mul(ll a, ll b, ll M)
{
    if (a*b<M) return a*b;
    else return a*b%M;
}

inline ll pew(ll a, ll b, ll M)
{
    ll res = 1;
    while (b)
    {
        if (b&1LL) res = mul(res,a,M);
        a = mul(a,a,M);
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
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    ll m;
    cin >> m;
    vector<ll> b(m);
    for (ll i=0;i<m;i++) cin >> b[i];
    multiset<ll> lft;
    for (ll i=0;i<m;i++) lft.insert(b[i]);
    sort(b.begin(),b.end());
    b.resize(unique(b.begin(),b.end())-b.begin());
    m = b.size();
    vector<ll> dp(n+1,mod);
    dp[0] = -mod;
    vector<ll> C(n);
    for (ll i=0;i<n;i++)
    {
        if (a[i]!=-1)
        {
            ll p = lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
            C[i] = p;
            dp[p] = a[i];
            continue;
        }
        C[i] = -1;
        ll j = 0;
        for (ll l=0;j<m and l<=n;l++)
        {
            if (b[j]>dp[l]) continue;
            ll x = b[j];
            while (j<m and b[j]<=dp[l]) j++;
            dp[l] = x;
        }
    }
    ll sz = 0;
    ll mx = 0;
    for (ll i=n;i>=0;i--)
    {
        if (dp[i]<mod)
        {
            sz = i;
            mx = dp[i]+1;
            break;
        }
    }
    ll R = lower_bound(b.begin(),b.end(),mx)-b.begin();
    ll k = 0;
    vector<ll> pos;
    for (ll i=n-1;i>=0;i--)
    {
        if (C[i]==-1)
        {
            k++;
            pos.push_back(i);
            if (k<=R and k==sz)
            {
                for (ll w=0;w<k;w++)
                {
                    lft.erase(lft.find(b[R-w-1]));
                    a[pos[w]] = b[R-w-1];
                }
                break;
            }
            continue;
        }
        if (a[i]>=mx) continue;
        ll p = upper_bound(b.begin(),b.end(),a[i])-b.begin();
        if (p<R-k) p = R-k;
        if (C[i]+R-p<sz) continue;
        k = R-p;
        for (ll w=0;w<k;w++)
        {
            lft.erase(lft.find(b[R-w-1]));
            a[pos[w]] = b[R-w-1];
        }
        pos.clear();
        mx = a[i];
        sz = C[i]-1;
        R = lower_bound(b.begin(),b.end(),mx)-b.begin();
        k = 0;
    }
    for (ll i=0;i<n;i++)
    {
        if (a[i]==-1)
        {
            a[i] = *lft.begin();
            lft.erase(lft.find(a[i]));
        }
        cout << a[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}