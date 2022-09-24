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


ll t[1200000], t2[1200000], del[1200000];

void build(ll v, ll tl, ll tr, ll val)
{
    t[v] = tr-tl+1;
    t2[v] = val;
    del[v] = -1;
    if (tl==tr) return;
    ll tm = (tl+tr)/2;
    build(v*2,tl,tm,val);
    build(v*2+1,tm+1,tr,val);
}

void upd(ll v, ll tl, ll tr, ll p)
{
    t[v]--;
    if (tl==tr) return;
    ll tm = (tl+tr)/2;
    if (p<=tm) upd(v,tl,tm,p);
    else upd(v,tm+1,tr,p);
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r) return t[v];
    ll tm = (tl+tr)/2;
    ll x = 0;
    if (l<=tm) x += get(v,tl,tm,l,r);
    if (r>tm) x += get(v,tm+1,tr,l,r);
    return x;
}

void push(ll v)
{
    if (del[v]!=-1)
    {
        t2[v*2] = t2[v*2+1] = del[v*2] = del[v*2+1] = del[v];
        del[v] = -1;
    }
}

void upd2(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (tl>=l and tr<=r)
    {
        t2[v] = del[v] = val;
        return;
    }
    ll tm = (tl+tr)/2;
    push(v);
    if (l<=tm) upd2(v*2,tl,tm,l,r,val);
    if (r>tm) upd2(v*2+1,tm+1,tr,l,r,val);
    t2[v] = t2[v*2];
}

ll get2(ll v, ll tl, ll tr, ll val)
{
    if (t2[v]>val) return tl;
    if (tl==tr) return tl+1;
    ll tm = (tl+tr)/2;
    push(v);
    if (t2[v*2+1]<=val) return get2(v*2+1,tm+1,tr,val);
    else return get2(v*2,tl,tm,val);
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    set<ll> lft;
    n++;
    for (ll i=1;i<=n;i++)
    {
        lft.insert(i);
    }
    build(1,1,n,n);
    while (q--)
    {
        ll T;
        cin >> T;
        if (T==0)
        {
            ll L, R, x;
            cin >> L >> R >> x;
            if (x==0)
            {
                while (true)
                {
                    auto it = lft.lower_bound(L);
                    if (it!=lft.end() and *it<=R)
                    {
                        upd(1,1,n,*it);
                        lft.erase(it);
                    } else break;
                }
                continue;
            }
            ll st = get2(1,1,n,R);
            if (st>L) continue;
            upd2(1,1,n,st,L,R);
            continue;
        }
        ll x;
        cin >> x;
        if (lft.count(x)==0)
        {
            cout << "NO\n";
            continue;
        }
        auto it = lft.lower_bound(x+1);
        ll R = (*it)-1;
        ll st = get2(1,1,n,R);
        st--;
        if (st>0)
        {
            it = lft.lower_bound(st);
            if (x==*it)
            {
                cout << "YES\n";
                continue;
            }
        }
        cout << "N/A\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    //cin >> T;
    T = 1;
    while (T--) solve();
}