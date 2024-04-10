#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = double;
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

vector<ll> a;
vector<vector<ll>> b;
ll t[1200000];
//ll del[1200000];

void build(int v, int tl, int tr)
{
    vector<ll> cur;
    if (tl==tr)
    {
        b[v].push_back(a[tl]);
        return;
    }
    int tm = (tr+tl)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    for (int q: b[v*2]) cur.push_back(q);
    for (int q: b[v*2+1]) cur.push_back(q);
    sort(cur.begin(),cur.end());
    for (int i=0;i<cur.size();i++)
    {
        if (i+1<cur.size() and cur[i]==cur[i+1]) continue;
        int u = cur[i];
        int cnt = 0;
        for (int j=tl;j<=tr;j++)
        {
            if (a[j]==u) cnt++;
        }
        if (cnt*5>tr-tl)
        {
            b[v].push_back(u);
        }
    }
}

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
}*/

vector<ll> lul;

void get (int v, int tl, int tr, int l, int r) {
    //if (del[v]!=0 and tl!=tr) push(v,tl,tr,tm);
    if (tl==l and tr==r)
    {
        for (int u: b[v])
        {
            lul.push_back(u);
        }
        return;
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (r<=tm)
    {
        get(2*v,tl,tm,l,r);
        return;
    }
    if (l>tm)
    {
        get(2*v+1,tm+1,tr,l,r);
        return;
    }
    get(2*v,tl,tm,l,tm);
    get(2*v+1,tm+1,tr,tm+1,r);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    a.resize(n);
    b.resize(1<<20);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    build(1,0,n-1);
    vector<set<pair<int,int>>> kek(n+1);
    vector<int> cnt(n+1);
    for (int i=0;i<n;i++)
    {
        kek[a[i]].insert({i,cnt[a[i]]});
        cnt[a[i]]++;
    }
    for (int i=0;i<q;i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        int len = (r-l+1);
        lul.clear();
        get(1,0,n-1,l,r);
        int mn = n+1;
        for (int u: lul)
        {
            auto it = kek[u].lower_bound({l,0});
            auto it2 = kek[u].lower_bound({r+1,0});
            int S;
            if (it2==kek[u].end())
            {
                S = cnt[u];
            } else S = it2->Y;
            if (it==kek[u].end())
            {
                S -= cnt[u];
            } else S -= it->Y;
            if (S*k>len)
            {
                mn = min(mn,u);
            }
        }
        if (mn==n+1)
        {
            cout << -1 << "\n";
        } else cout << mn << "\n";
    }
}