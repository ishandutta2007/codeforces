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



int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> p3(n+1);
    p3[0] = 1;
    for (int i=1;i<=n;i++) p3[i] = p3[i-1]*3;
    vector<ll> S(3);
    vector<vector<ll>> val(n,vector<ll>(3));
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<3;j++)
        {
            cin >> val[i][j];
            S[j] += val[i][j];
        }
    }
    pair<ll,ll> T = {S[1]-S[0],S[2]-S[0]};
    int m = (n+1)/2;
    int m2 = n-m;
    vector<pair<ll,ll>> R(p3[m]);
    vector<ll> V(p3[m]);
    unordered_map<ll,ll> R2;
    vector<ll> V2(p3[m2]);
    for (int msk=0;msk<p3[m];msk++)
    {
        pair<ll,ll> cur = {0,0};
        for (int i=0;i<m;i++)
        {
            int p = msk/p3[i]%3;
            if (p==0)
            {
                cur.X -= val[i][p];
                cur.Y -= val[i][p];
                V[msk] -= val[i][p];
            }
            if (p==1) cur.X += val[i][p];
            if (p==2) cur.Y += val[i][p];
        }
        R[msk] = cur;
    }
    for (int msk=0;msk<p3[m2];msk++)
    {
        pair<ll,ll> cur = {0,0};
        for (int i=0;i<m2;i++)
        {
            int j = i+m;
            int p = msk/p3[i]%3;
            if (p==0)
            {
                cur.X -= val[j][p];
                cur.Y -= val[j][p];
                V2[msk] -= val[j][p];
            }
            if (p==1) cur.X += val[j][p];
            if (p==2) cur.Y += val[j][p];
        }
        if (R2.count({cur.X*mod+cur.Y})==0)
        {
            R2[{cur.X*mod+cur.Y}] = msk;
            continue;
        }
        ll prv = R2[{cur.X*mod+cur.Y}];
        if (V2[prv]<V2[msk]) R2[{cur.X*mod+cur.Y}] = msk;
    }
    ll INF = 1000000000LL*1000000000LL;
    ll bst = -INF;
    pair<ll,ll> A = {-1,-1};
    for (ll i=0;i<p3[m];i++)
    {
        pair<ll,ll> cur = T;
        cur.X -= R[i].X;
        cur.Y -= R[i].Y;
        if (R2.count({cur.X*mod+cur.Y})!=0)
        {
            ll j = R2[{cur.X*mod+cur.Y}];
            ll x = V[i]+V2[j];
            if (x<=bst) continue;
            A = {i,j};
            bst = x;
        }
    }

    if (bst==-INF)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int b=0;b<m;b++)
    {
        int p = A.X/p3[b]%3;
        if (p==0) cout << "MW\n";
        if (p==1) cout << "LW\n";
        if (p==2) cout << "LM\n";
    }
    for (int b=0;b<m2;b++)
    {
        int p = A.Y/p3[b]%3;
        if (p==0) cout << "MW\n";
        if (p==1) cout << "LW\n";
        if (p==2) cout << "LM\n";
    }
}