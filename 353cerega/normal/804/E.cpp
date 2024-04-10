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

vector<int> p, a;
vector<vector<int>> w;
vector<pair<int,int>> ans;
int L;

void add(int x, int y)
{
    if (w[x][y]==1)
    {
        return;
    }
    L--;
    int v = a[x];
    int u = a[y];
    swap(a[x],a[y]);
    swap(p[u],p[v]);
    w[x][y] = 1;
    w[y][x] = 1;
    if (x>y) swap(x,y);
    ans.push_back({x,y});
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n*(n-1)/2%2!=0)
    {
        cout << "NO" << endl;
        return 0;
    }
    mt19937 gen(time(0));
    uniform_int_distribution<int> uid(0,1);
    cout << "YES" << endl;
    while (true) {
        p.clear();
        a.clear();
        w.clear();
        ans.clear();
        p.resize(n + 1);
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            a[i] = i;
            p[i] = i;
        }
        w.resize(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            w[i][i] = 1;
        }
        vector<int> ok(n + 1);
        L = n * (n - 1) / 2;
        int S = 0;
        while (L > 0) {
            if (S == 0) {
                for (int j = 1; j <= n; j++) {
                    if (ok[j] == 0) {
                        S = j;
                        break;
                    }
                }
            }
            ok[S] = 1;
            int F = p[S];
            vector<int> g;
            for (int i = 1; i <= n; i++) {
                if (w[S][i] == 0) g.push_back(i);
            }
            reverse(g.begin(), g.end());
            if (F == S) {
                add(S, g[0]);
                add(g[0], g.back());
                for (int i = 1; i < g.size(); i++) {
                    add(S, g[i]);
                }
                int d = uid(gen);
                if (d == 0) S = g.back();
                else S = g[0];
                continue;
            }
            int nxt = 0;
            if (F != g.back()) {
                add(F, g.back());
                nxt = g.back();
            }
            for (int i = 0; i < g.size(); i++) {
                add(S, g[i]);
            }
            S = nxt;
        }
        int z = 1;
        for (int i = 1; i <= n; i++) if (a[i] != i) z = 0;
        if (z == 1) break;
    }
    for (int i=0;i<ans.size();i++)
    {
        cout << ans[i].X << " " << ans[i].Y << "\n";
    }
}