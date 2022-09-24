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

inline ll pew(ll a, ll b, ll MOD)
{
    ll res = 1;
    while (b)
    {
        //if (b&1) res = mul(res,a);
        //a = mul(a,a);
        if (b&1) res = res*a%MOD;
        a = a*a%MOD;
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
}

//ll t[3200000];
//ll del[1200000];

/*
void build(int n)
{
    for (int i=0;i<=4*n;i++)
    {
        t[i] = 0;
        //del[i] = 0;
    }
}*/

/*void push(int v)
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

/*
void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        t[v] = (t[v]+val)%mod;
        return;
    }
    int tm = (tl+tr)/2;
    //if (del[v]!=0) push(v);
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
}

ll get (int v, int tl, int tr, int p) {
    if (tl==tr) return t[v];
    int tm = (tl+tr)/2;
    //push(v);
    if (p<=tm) return t[v]+get(2*v,tl,tm,p);
    else return t[v]+get(2*v+1,tm+1,tr,p);

}
*/

ll INF = mod*mod;
ll ans = INF;
ll n;

vector<set<pair<ll,ll>>> kek;
set<pair<ll,pair<ll,ll>>> A;
set<pair<ll,ll>> mn;
vector<ll> val;

void calc()
{
    ans = mn.begin()->X;
    vector<pair<ll,pair<ll,ll>>> a;
    ll T = 7;
    auto it = A.begin();
    while (T>0 and it!=A.end())
    {
        T--;
        a.push_back(*it);
        it++;
    }
    for (ll i=0;i<a.size();i++)
    {
        for (ll j=i+1;j<a.size();j++)
        {
            if (a[i].Y.X==a[j].Y.X or a[i].Y.X==a[j].Y.Y or a[i].Y.Y==a[j].Y.X or a[i].Y.Y==a[j].Y.Y) continue;
            ans = min(ans,a[i].X+a[j].X);
        }
    }
}

ll check(ll u, ll v, ll w)
{
   auto it = kek[u].begin();
   ll T = 3;
    while (T>0 and it!=kek[u].end())
    {
        T--;
        if (it->X==w and it->Y==v) return 1;
        if (T>0) it++;
    }
    return 0;
}

void upd(ll u)
{
    ll T = 3;
    auto it = kek[u].begin();
    ll S = 0;
    val[u] = INF;
    while (T>0 and it!=kek[u].end())
    {
        T--;
        pair<ll,ll> cur = {u,it->Y};
        if (cur.X>cur.Y) swap(cur.X,cur.Y);
        if (check(it->Y,u,it->X))
        {
            A.insert({it->X,cur});
        }
        S += it->X;
        if (T>0) it++;
    }
    if (T==0)
    {
        it++;
        if (it!=kek[u].end())
        {
            pair<ll,ll> cur = {u,it->Y};
            if (cur.X>cur.Y) swap(cur.X,cur.Y);
            A.erase({it->X,cur});
        }
    }
    if (T==0) val[u] = S;
}





int main()
{
    ios_base::sync_with_stdio(false);
    ll m;
    cin >> n >> m;
    kek.resize(n);
    val.resize(n,INF);
    map<pair<ll,ll>,ll> lul;
    for (ll i=0;i<n;i++) mn.insert({val[i],i});
    for (ll i=0;i<m;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        if (u>v) swap(u,v);
        ll w;
        cin >> w;
        lul[{u,v}] = w;
        kek[u].insert({w,v});
        kek[v].insert({w,u});
        mn.erase({val[u],u});
        mn.erase({val[v],v});
        upd(u);
        upd(v);
        mn.insert({val[u],u});
        mn.insert({val[v],v});
        calc();
    }
    cout << ans << "\n";
    ll q;
    cin >> q;
    for (ll i=0;i<q;i++)
    {
        ll t, u, v;
        cin >> t >> u >> v;
        u--, v--;
        if (u>v) swap(u,v);
        ll w;
        if (t==0)
        {
            w = lul[{u,v}];
            kek[u].erase({w,v});
            kek[v].erase({w,u});
            A.erase({w,{u,v}});
        } else
        {
            cin >> w;
            lul[{u,v}] = w;
            kek[u].insert({w,v});
            kek[v].insert({w,u});
        }
        mn.erase({val[u],u});
        mn.erase({val[v],v});
        upd(u);
        upd(v);
        mn.insert({val[u],u});
        mn.insert({val[v],v});
        calc();
        cout << ans << "\n";
    }
}