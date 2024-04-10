#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
#define X first
#define Y second

ll mod = 1000000007;

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

/*
void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        //del[v] += val;
        t[v] += val;
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


ll get (int v, int tl, int tr, int p) {
    //if (del[v]!=0 and tl!=tr) push(v,tl,tr,tm);
    if (tl==tr)
    {
        return t[v];
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (p<=tm) return t[v]+get(2*v,tl,tm,p);
    else return t[v]+get(2*v+1,tm+1,tr,p);
}*/

int INF = 10000000;
int n;

struct Node
{
    Node* L;
    Node* R;
    int mn;
    Node(int v)
    {
        L = NULL;
        R = NULL;
        mn = v;
    }
    Node()
    {
        L = NULL;
        R = NULL;
        mn = INF;
    }
};

Node* Nodes[220000];

void update2(Node* v, int tl, int tr, int y, int val) {

    v->mn = min(v->mn,val);
    if (tl==tr) return;
    int tm = (tl+tr)/2;
    if (y<=tm)
    {
        if (v->L==NULL) v->L = new Node(val);
        update2(v->L,tl,tm,y,val);
    }
    else
    {
        if (v->R==NULL) v->R = new Node(val);
        update2(v->R,tm+1,tr,y,val);
    }
}

void update (int v, int tl, int tr, int x, int y, int val) {
    Node* root = Nodes[v];
    update2(root,0,n,y,val);
    if (tl==tr) return;
    int tm = (tl+tr)/2;
    if (x<=tm) update(2*v,tl,tm,x,y,val);
    else update(2*v+1,tm+1,tr,x,y,val);
}

int get2(Node* v, int tl, int tr, int ly, int ry) {

    if (tl==ly and tr==ry)
    {
        return v->mn;
    }
    int tm = (tl+tr)/2;
    if (ry<=tm)
    {
        if (v->L==NULL) return INF;
        return get2(v->L,tl,tm,ly,ry);
    }
    if (ly>tm)
    {
        if (v->R==NULL) return INF;
        return get2(v->R,tm+1,tr,ly,ry);
    }
    int a = INF;
    if (v->L!=NULL) a = min(a,get2(v->L,tl,tm,ly,tm));
    if (v->R!=NULL) a = min(a,get2(v->R,tm+1,tr,tm+1,ry));
    return a;
}

int get (int v, int tl, int tr, int lx, int rx, int ly, int ry) {

    if (tl==lx and tr==rx)
    {
        Node* root = Nodes[v];
        return get2(root,0,n,ly,ry);
    }
    int tm = (tl+tr)/2;
    if (rx<=tm) return get(v*2,tl,tm,lx,rx,ly,ry);
    if (lx>tm) return get(v*2+1,tm+1,tr,lx,rx,ly,ry);
    return min(get(v*2,tl,tm,lx,tm,ly,ry),get(v*2+1,tm+1,tr,tm+1,rx,ly,ry));
}


int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0;i<220000;i++) Nodes[i] = new Node();
    int m;
    cin >> n >> m;
    vector<pair<int,int>> a(m);
    vector<int> ans(n);
    vector<vector<int>> add(n);
    for (int i=0;i<m;i++)
    {
        cin >> a[i].X >> a[i].Y;
        a[i].X--, a[i].Y--;
        add[a[i].Y-a[i].X].push_back(i);
    }
    for (int L=n-1;L>=0;L--)
    {
        set<pair<int,int>> cur;
        set<int> kek;
        for (int v: add[L])
        {
            int A = n-a[v].X;
            int B = a[v].Y;
            update(1,0,n,A,B,v);
        }
        cur.insert({0,n-1});
        kek.insert(get(1,0,n,0,n,0,n));
        while (kek.size()>0)
        {
            int x = *kek.begin();
            if (x>=m) break;
            kek.erase(x);
            ans[L] += a[x].Y+1-a[x].X;
            auto it = cur.lower_bound({a[x].X+1,0});
            it--;
            int A = it->X;
            int B = it->Y;
            cur.erase(it);
            if (A!=a[x].X)
            {
                cur.insert({A,a[x].X-1});
                kek.insert(get(1,0,n,0,n-A,0,a[x].X-1));
            }
            if (B!=a[x].Y)
            {
                cur.insert({a[x].Y+1,B});
                kek.insert(get(1,0,n,0,n-a[x].Y-1,0,B));
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        cout << ans[i] << "\n";
    }
}