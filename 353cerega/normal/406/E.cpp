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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(2);
    {
        set<ll> val;
        val.insert(0);
        val.insert(n);
        for (ll i=0;i<m;i++)
        {
            ll b, L;
            cin >> b >> L;
            a[b].push_back(L);
            val.insert(L);
        }
        map<ll,ll> num;
        ll S = 0;
        for (ll x: val)
        {
            num[x] = S++;
        }
        n = S;
        for (ll b=0;b<2;b++)
        {
            for (ll i=0;i<a[b].size();i++) a[b][i] = num[a[b][i]];
        }
    }
    vector<vector<ll>> D(2,vector<ll>(n));
    sort(a[0].begin(),a[0].end());
    sort(a[1].begin(),a[1].end());
    for (ll b=0;b<2;b++)
    {
        if (a[b].size()==0)
        {
            ll x = a[1-b].back();
            ll R = 0;
            while (a[1-b].size()>0 and a[1-b].back()==x)
            {
                a[1-b].pop_back();
                R++;
            }
            if (a[1-b].size()==0)
            {
                cout << R*(R-1)*(R-2)/6 << "\n";
                return;
            }
            ll L = 0;
            while (a[1-b].size()>L and a[1-b][L]==a[1-b][0])
            {
                L++;
            }
            cout << L*R*(m-L-R)+L*(L-1)/2*R+R*(R-1)/2*L << "\n";
            return;
        }
    }
    for (ll b=0;b<2;b++)
    {
        if (a[b].back()<=a[1-b][0])
        {
            ll x = a[b].back();
            ll R = 0;
            while (a[b].size()>0 and a[b].back()==x)
            {
                a[b].pop_back();
                R++;
            }
            ll L = 0;
            while (a[1-b].size()>L and a[1-b][L]==a[1-b][0])
            {
                L++;
            }
            cout << L*R*(m-L-R)+L*(L-1)/2*R+R*(R-1)/2*L << "\n";
            return;
        }
    }
    vector<vector<ll>> pr(2,vector<ll>(n));
    vector<ll> sz(2);
    for (ll b=0;b<2;b++)
    {
        sz[b] = a[b].size();
        for (ll x: a[b]) pr[b][x]++;
        for (ll i=1;i<n;i++) pr[b][i] += pr[b][i-1];
    }
    ll A = 0;
    for (ll b=0;b<2;b++)
    {
        for (ll x: a[1-b])
        {
            ll C1 = pr[b][x-1];
            ll C0 = pr[b][x]-pr[b][x-1];
            ll C2 = sz[b]-C0-C1;
            A += C1*C0+C2*C0+C1*C2+C0*(C0-1)/2;
        }
    }
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}