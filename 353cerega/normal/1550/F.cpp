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

//ll t[3200000];
//ll del[1200000];

/*void build(int n)
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

/*void update (int v, int tl, int tr, int p, ll val) {
    t[v] += val;
    if (tl==tr) return;
    int tm = (tl+tr)/2;
    //if (del[v]!=0) push(v);
    if (p<=tm) update(2*v,tl,tm,p,val);
    else update(2*v+1,tm+1,tr,p,val);
}

ll get (int v, int tl, int tr, int l, int r) {
    if (tl==l and tr==r) return t[v];
    int tm = (tl+tr)/2;
    //push(v);
    if (r<=tm) return get(2*v,tl,tm,l,r);
    if (l>tm) return get(2*v+1,tm+1,tr,l,r);
    return get(2*v,tl,tm,l,tm)+get(2*v+1,tm+1,tr,tm+1,r);
}*/

set<int> lul;
set<int> lft;
set<pair<int,int>> kek;

void upd(int u)
{
    auto it = lft.lower_bound(u);
    if (it!=lft.end()) kek.insert({*it-u,*it});
    if (it!=lft.begin())
    {
        it--;
        kek.insert({u-*it,*it});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, q, s, d;
    cin >> n >> q >> s >> d;
    s--;
    vector<int> a(n);
    int mx = 1000000;
    vector<int> obr(mx+1,-1);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        obr[a[i]] = i;
    }
    for (int i=0;i<n;i++)
    {
        if (i!=s) lft.insert(a[i]);
    }
    lul.insert(a[s]-d);
    upd(a[s]-d);
    lul.insert(a[s]+d);
    upd(a[s]+d);
    vector<pair<pair<int,int>,int>> ord(q);
    for (int i=0;i<q;i++)
    {
        cin >> ord[i].X.Y >> ord[i].X.X;
        ord[i].X.Y--;
        ord[i].Y = i;
    }
    sort(ord.begin(),ord.end());
    vector<int> ans(q);
    for (int z=0;z<q;z++)
    {
        int k = ord[z].X.X;
        while (kek.size()>0 and kek.begin()->X<=k)
        {
            int p = kek.begin()->Y;
            kek.erase(kek.begin());
            if (lft.count(p)==0) continue;
            lft.erase(p);
            lul.insert(p-d);
            upd(p-d);
            lul.insert(p+d);
            upd(p+d);
            auto it = lul.lower_bound(p);
            if (it!=lul.end()) upd(*it);
            if (it!=lul.begin())
            {
                it--;
                upd(*it);
            }
        }
        if (lft.count(a[ord[z].X.Y])==0) ans[ord[z].Y] = 1;
        else ans[ord[z].Y] = 0;
    }
    for (int i=0;i<q;i++)
    {
        if (ans[i]==1) cout << "Yes\n";
        else cout << "No\n";
    }
}