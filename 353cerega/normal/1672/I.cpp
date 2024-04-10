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



ll t[2200000];
pair<ll,ll> t2[1200000];
pair<ll,ll> t3[1200000];
ll del[2200000];
pair<ll,ll> t4[2200000];


void build()
{
    for (ll i=0;i<2200000;i++) t[i] = 0, del[i] = 0, t4[i] = {mod,-1};
    for (ll i=0;i<1200000;i++) t2[i] = {mod,-1}, t3[i] = {-1,-1};
}

void upd(ll v, ll tl, ll tr, ll p)
{
    t[v]++;
    if (tl==tr) return;
    ll tm = (tl+tr)/2;
    if (tm>=p) upd(v*2,tl,tm,p);
    else upd(v*2+1,tm+1,tr,p);
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r) return t[v];
    ll tm = (tl+tr)/2;
    ll x = 0;
    if (tm>=l) x += get(v*2,tl,tm,l,r);
    if (tm<r) x += get(v*2+1,tm+1,tr,l,r);
    return x;
}

void upd2(ll v, ll tl, ll tr, ll p, ll val)
{
    if (tl==tr)
    {
        t2[v] = {val,p};
        if (val==mod) t2[v].Y = -1;
        return;
    }
    ll tm = (tl+tr)/2;
    if (tm>=p) upd2(v*2,tl,tm,p,val);
    else upd2(v*2+1,tm+1,tr,p,val);
    t2[v] = min(t2[2*v],t2[2*v+1]);
}

void upd3(ll v, ll tl, ll tr, ll p, ll val)
{
    if (tl==tr)
    {
        t3[v] = {val,p};
        if (val==-1) t3[v].Y = -1;
        return;
    }
    ll tm = (tl+tr)/2;
    if (tm>=p) upd3(v*2,tl,tm,p,val);
    else upd3(v*2+1,tm+1,tr,p,val);
    t3[v] = max(t3[2*v],t3[2*v+1]);
}

pair<ll,ll> get2(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r) return t2[v];
    ll tm = (tl+tr)/2;
    pair<ll,ll> x = {mod,-1};
    if (tm>=l) x = min(x,get2(v*2,tl,tm,l,r));
    if (tm<r) x = min(x,get2(v*2+1,tm+1,tr,l,r));
    return x;
}

pair<ll,ll> get3(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r) return t3[v];
    ll tm = (tl+tr)/2;
    pair<ll,ll> x = {-1,-1};
    if (tm>=l) x = max(x,get3(v*2,tl,tm,l,r));
    if (tm<r) x = max(x,get3(v*2+1,tm+1,tr,l,r));
    return x;
}

void push(ll v)
{
    if (del[v]==0) return;
    del[v*2] += del[v];
    del[v*2+1] += del[v];
    t4[v*2].X += del[v];
    t4[v*2+1].X += del[v];
    del[v] = 0;
}

void upd0(ll v, ll tl, ll tr, ll p, ll val)
{
    if (tl==tr)
    {
        t4[v] = {val,p};
        return;
    }
    push(v);
    ll tm = (tl+tr)/2;
    if (tm>=p) upd0(v*2,tl,tm,p,val);
    else upd0(v*2+1,tm+1,tr,p,val);
    t4[v] = min(t4[v*2],t4[v*2+1]);
}

void add0(ll v, ll tl, ll tr, ll l, ll r, ll d)
{
    if (tl>=l and tr<=r)
    {
        del[v] += d;
        t4[v].X += d;
        return;
    }
    push(v);
    ll tm = (tl+tr)/2;
    if (tm>=l) add0(v*2,tl,tm,l,r,d);
    if (tm<r) add0(v*2+1,tm+1,tr,l,r,d);
    t4[v] = min(t4[v*2],t4[v*2+1]);
}


set<ll> L, R;
set<pair<ll,ll>> L2, R2;

ll n;
vector<ll> a;

ll calc(ll p)
{
    ll W = a[p]-p;
    W += get(2,0,n-1,0,p);
    W -= get(3,0,n-1,0,a[p]);
    return abs(W);
}

void addL(ll p)
{
    //cout << "ADDL " << p << endl;
    L.insert(p);
    L2.insert({a[p],p});
    upd2(1,0,n-1,p,mod);
    ll W = calc(p);
    upd0(2,0,n-1,p,W);
}

void recalcL(ll l, ll r)
{
    if (r<l) return;
    pair<ll,ll> x = get2(1,0,n-1,l,r);
    if (x.Y==-1) return;
    auto it = L.lower_bound(x.Y);
    if (it==L.end() or a[*it]>x.X)
    {
        addL(x.Y);
        recalcL(l,x.Y-1);
        recalcL(x.Y+1,r);
    }
}

void addR(ll p)
{
    //cout << "ADDR " << p << endl;
    R.insert(p);
    R2.insert({a[p],p});
    upd3(1,0,n-1,p,-1);
    ll W = calc(p);
    upd0(3,0,n-1,p,W);
}

void recalcR(ll l, ll r)
{
    if (r<l) return;
    pair<ll,ll> x = get3(1,0,n-1,l,r);
    if (x.Y==-1) return;
    auto it = R.lower_bound(x.Y);
    if (it!=R.begin())
    {
        it--;
        if (a[*it]>x.X) return;
    }
    addR(x.Y);
    recalcR(l,x.Y-1);
    recalcR(x.Y+1,r);
}

void rec(ll p)
{
    {
        auto it = L.lower_bound(p);
        if (it!=L.end()) add0(2,0,n-1,*it,n-1,1);
    }
    {
        auto it = R.lower_bound(p);
        if (it!=R.end()) add0(3,0,n-1,*it,n-1,-1);
    }
    {
        auto it = L2.lower_bound({a[p],-1});
        if (it!=L2.end()) add0(2,0,n-1,it->Y,n-1,-1);
    }
    {
        auto it = R2.lower_bound({a[p],-1});
        if (it!=R2.end()) add0(3,0,n-1,it->Y,n-1,1);
    }
}

void errL(ll p)
{
    //cout << "ErrL " << p << endl;
    upd0(2,0,n-1,p,mod);
    upd(2,0,n-1,p);
    upd(3,0,n-1,a[p]);
    L.erase(p);
    L2.erase({a[p],p});
    rec(p);
    {
        auto it = L.lower_bound(p);
        ll st = 0;
        if (it!=L.begin())
        {
            it--;
            st = *it;
        }
        recalcL(st,p);
    }
}

void errR(ll p)
{
    //cout << "ErrR " << p << endl;
    upd0(3,0,n-1,p,mod);
    upd(2,0,n-1,p);
    upd(3,0,n-1,a[p]);
    R.erase(p);
    R2.erase({a[p],p});
    rec(p);
    {
        auto it = R.lower_bound(p);
        ll f = n-1;
        if (it!=R.end()) f = *it;
        recalcR(p,f);
    }
}


void solve()
{
    cin >> n;
    a.resize(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        a[i]--;
    }
    build();
    ll A = 0;
    for (ll i=0;i<n;i++)
    {
        if (a[i]>=i) upd2(1,0,n-1,i,a[i]);
        else upd3(1,0,n-1,i,a[i]);
    }
    recalcL(0,n-1);
    recalcR(0,n-1);
    for (ll z=0;z<n;z++)
    {
        pair<ll,ll> Q1 = t4[2];
        pair<ll,ll> Q2 = t4[3];
        if (Q1.X<=Q2.X)
        {
            A = max(A,Q1.X);
            errL(Q1.Y);
        }
        else
        {
            A = max(A,Q2.X);
            errR(Q2.Y);
        }
    }
    cout << A << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}