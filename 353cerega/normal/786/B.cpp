#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
#define X first
#define Y second

const ll mod = 1000000007;

ll gcd(ll a, ll b)
{
    if (a==0 or b==0) return a+b;
    return gcd(b,a%b);
}


ll sum(ll a, ll b)
{
    a += b;
    a %= mod;
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
    return a*b%mod;
}

inline ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1) res = mul(res,a);
        a = mul(a,a);
        b /= 2;
    }
    return res;
}



/*const int MOD = 998244353;
const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;
const int root = 31;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/


/*void fft (vector<int> & a, bool invert) {
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


int parent[600001];
int rnk[600001];

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
}

//ll t[1200000];
//ll del[1200000];

/*void build()
{
    for (int i=0;i<1200000;i++)
    {
        t[i] = 0;
        //del[i] = 0;
    }
}*/

/*void push(int v, int tl, int tr, int tm)
{
    t[2*v].X += del[v];
    t[2*v+1].X += del[v];
    del[2*v] += del[v];
    del[2*v+1] += del[v];
    del[v] = 0;
}*/

/*void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        //del[v] += val;

        //t[v] += val*(tr-tl+1);
        return;
    }
    int tm = (tl + tr) / 2;
    //if (del[v]!=0) push(v,tl,tr,tm);
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
    t[v] = min(t[2*v],t[2*v+1]);
}*/


/*void update (int v, int tl, int tr, int pos, ll val) {
    if (tl==tr)
    {
        //del[v] += val;
        t[v] += val;
        return;
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (pos<=tm)
    {
        update(2*v,tl,tm,pos,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    else
    {
        update(2*v+1,tm+1,tr,pos,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    //update(2*v,tl,tm,l,tm,val);
    //update(2*v+1,tm+1,tr,tm+1,r,val);
    //t[v] = min(t[2*v],t[2*v+1]);
}


ll get (int v, int tl, int tr, int l, int r) {
    //if (del[v]!=0 and tl!=tr) push(v,tl,tr,tm);
    if (tl==l and tr==r)
    {
        return t[v];
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (r<=tm) return get(2*v,tl,tm,l,r);
    if (l>tm) return get(2*v+1,tm+1,tr,l,r);
    return get(2*v,tl,tm,l,tm)+get(2*v+1,tm+1,tr,tm+1,r);
}*/

vector<vector<ll>> R(1<<18);

void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        //del[v] += val;
        R[v].push_back(val);
        return;
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
    //t[v] = min(t[2*v],t[2*v+1]);
}

vector<ll> cur;
void get (int v, int tl, int tr, int pos) {
    //if (del[v]!=0 and tl!=tr) push(v,tl,tr,tm);
    for (ll x: R[v])
    {
        cur.push_back(x);
    }
    R[v].clear();
    if (tl==tr)
    {
        return;
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (pos<=tm) return get(2*v,tl,tm,pos);
    return get(2*v+1,tm+1,tr,pos);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, q, s;
    cin >> n >> q >> s;
    s--;
    vector<vector<pair<ll,ll>>> g(n);
    vector<pair<ll,ll>> L(n);
    int S = n;
    int W = 0;
    vector<pair<ll,ll>> M;
    for (int i=0;i<q;i++)
    {
        int t;
        cin >> t;
        if (t==1)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            g[u].push_back({v,w});
            continue;
        }
        ll v, l, r, w;
        cin >> v >> l >> r >> w;
        v--, l--, r--;
        if (t==2)
        {
            L.push_back({l,r});
            g.push_back({});
            g[v].push_back({S,w});
            S++;
            continue;
        }
        update(1,0,n-1,l,r,W);
        M.push_back({v,w});
        W++;
    }
    ll INF = 1000000000LL*1000000LL;
    vector<ll> d(S,INF);
    d[s] = 0;
    set<pair<ll,ll>> kek;
    set<ll> lft;
    vector<ll> was(W);
    for (int i=0;i<S;i++)
    {
        kek.insert({d[i],i});
        lft.insert(i);
    }
    while (kek.size()>0)
    {
        int p = kek.begin()->Y;
        kek.erase({d[p],p});
        lft.erase(p);
        for (pair<ll,ll> v: g[p])
        {
            if (d[v.X]>d[p]+v.Y)
            {
                kek.erase({d[v.X],v.X});
                d[v.X] = d[p]+v.Y;
                kek.insert({d[v.X],v.X});
            }
        }
        if (p>=n)
        {
            auto it = lft.lower_bound(L[p].X);
            while (it!=lft.end() and *it<=L[p].Y)
            {
                kek.erase({d[*it],*it});
                d[*it] = d[p];
                kek.insert({d[*it],*it});
                lft.erase(it);
                it = lft.lower_bound(L[p].X);
            }
        }
        if (p<n)
        {
            cur.clear();
            get(1,0,n-1,p);
            for (ll i: cur)
            {
                if (was[i]==1) continue;
                pair<ll,ll> v = M[i];
                was[i] = 1;
                if (d[v.X]>d[p]+v.Y)
                {
                    kek.erase({d[v.X],v.X});
                    d[v.X] = d[p]+v.Y;
                    kek.insert({d[v.X],v.X});
                }
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        if (d[i]==INF) cout << -1 << " ";
        else cout << d[i] << " ";
    }
}