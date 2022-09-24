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

/*void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl>=l and tr<=r)
    {
        del[v] += val;
        t[v] += val;
        return;
    }
    int tm = (tl+tr)/2;
    //if (del[v]!=0) push(v);
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
    t[v] = t[2*v]+t[2*v+1];
}*/


/*pair<ll,ll> get (int v, int tl, int tr, int p) {
    if (tl==tr) return t[v];
    int tm = (tl+tr)/2;
    //push(v);
    if (p<=tm) return t[v]+get(2*v,tl,tm,p);
    else return t[v]+get(2*v+1,tm+1,tr,p);
}*/

vector<vector<int>> g, gr;

vector<char> used;
vector<int> order, cur;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    cur.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i=0;i<n;i++)
    {
        cin >> s[i];
    }
    g.resize(n*m);
    gr.resize(n*m);
    int ok = 0;
    vector<ll> prv(m,-1);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (s[i][j]=='.') continue;
            ok = 1;
            if (i+1<n and s[i+1][j]!='.')
            {
                g[i*m+j].push_back((i+1)*m+j);
                gr[i*m+j].push_back((i+1)*m+j);
                g[(i+1)*m+j].push_back(i*m+j);
                gr[(i+1)*m+j].push_back(i*m+j);
            }
            if (j+1<m and s[i][j+1]!='.')
            {
                g[i*m+j].push_back(i*m+j+1);
                g[i*m+j+1].push_back(i*m+j);
                gr[i*m+j].push_back(i*m+j+1);
                gr[i*m+j+1].push_back(i*m+j);
            }
        }
    }
    for (int i=n-1;i>=0;i--)
    {
        for (int j=0;j<m;j++)
        {
            if (s[i][j]=='.') continue;
            if (j>0 and prv[j-1]!=-1)
            {
                g[i*m+j].push_back(prv[j-1]*m+j-1);
                gr[prv[j-1]*m+j-1].push_back(i*m+j);
            }
            if (j+1<m and prv[j+1]!=-1)
            {
                g[i*m+j].push_back(prv[j+1]*m+j+1);
                gr[prv[j+1]*m+j+1].push_back(i*m+j);
            }
            if (prv[j]!=-1)
            {
                g[i*m+j].push_back(prv[j]*m+j);
                gr[prv[j]*m+j].push_back(i*m+j);
            }
            prv[j] = i;
        }
    }
    if (ok==0)
    {
        cout << 0 << endl;
        return 0;
    }
    int N = n;
    n = m*n;
    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1(i);
    used.assign (n, false);
    vector<int> col(n);
    int S = 0;
    for (int i=0;i<n;i++) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2(v);
            for (int u: cur)
            {
                col[u] = S;
            }
            S++;
            cur.clear();
        }
    }
    vector<int> kek(S,1);
    ll ans = S;
    for (int i=0;i<n;i++)
    {
        for (int j: g[i])
        {
            if (col[i]!=col[j])
            {
                if (kek[col[j]]==1)
                {
                    kek[col[j]] = 0;
                    ans--;
                }
            }
        }
    }
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (s[i][j]=='.')
            {
                if (kek[col[i*m+j]]==1)
                {
                    kek[col[i*m+j]] = 0;
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
}