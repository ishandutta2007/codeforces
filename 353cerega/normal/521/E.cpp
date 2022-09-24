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

vector<vector<pair<int,int>>> g;
vector<int> tin, up;
map<pair<int,int>,int> col;
vector<int> was;
int T = 0;
int C = 0;

void dfs0(int u)
{
    was[u] = 1;
    tin[u] = T;
    up[u] = tin[u];
    T++;
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i].Y;
        if (was[v]==1)
        {
            up[u] = min(up[u],tin[v]);
            continue;
        }
        dfs0(v);
        up[u] = min(up[u],up[v]);
    }
}

void dfs1(int u, int c, int p)
{
    was[u] = 1;
    for (int i=0;i<g[u].size();i++)
    {
        int v = g[u][i].Y;
        if (v==p)
        {
            g[u][i].X = col[{u,v}];
            continue;
        }
        if (was[v]==1)
        {
            if (col.count({u,v})==0)
            {
                col[{u,v}] = c;
                col[{v,u}] = c;
            }
            g[u][i].X = col[{u,v}];
            continue;
        }
        if (up[v]>=tin[u])
        {
            C++;
            if (col.count({u,v})==0)
            {
                col[{u,v}] = C;
                col[{v,u}] = C;
            }
            g[u][i].X = col[{u,v}];
            dfs1(v,C,u);
        }
        else
        {
            if (col.count({u,v})==0)
            {
                col[{u,v}] = c;
                col[{v,u}] = c;
            }
            g[u][i].X = col[{u,v}];
            dfs1(v,c,u);
        }
    }
}

vector<int> ans;
vector<int> ans2;

int dfs2(int u, int c, int st, int p)
{
    was[u] = 1;
    ans.push_back(u);
    for (int i=0;i<g[u].size();i++)
    {
        if (g[u][i].X!=c) continue;
        int v = g[u][i].Y;
        if (was[v]==2) continue;
        if (v==p) continue;
        if (v==st) return 1;
        if (was[v]==1 and v!=st) continue;
        if (dfs2(v,c,st,u))
        {
            return 1;
        }
    }
    was[u] = 2;
    ans.pop_back();
    return 0;
}

int dfs3(int u, int c, int st)
{
    was[u] = 3;
    ans2.push_back(u);
    for (int i=0;i<g[u].size();i++)
    {
        if (g[u][i].X!=c) continue;
        int v = g[u][i].Y;
        if (was[v]==3) continue;
        if (was[v]==1 and (u!=st or (v!=ans[1] and v!=ans.back())))
        {
            ans2.push_back(v);
            return 1;
        }
        if (was[v]==1) continue;
        if (dfs3(v,c,st))
        {
            return 1;
        }
    }
    ans2.pop_back();
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    tin.resize(n);
    up.resize(n);
    was.resize(n);
    for (int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back({-1,b});
        g[b].push_back({-1,a});
    }
    for (int i=0;i<n;i++)
    {
        if (was[i]==0) dfs0(i);
    }
    for (int i=0;i<n;i++) was[i] = 0;
    for (int i=0;i<n;i++)
    {
        if (was[i]==0)
        {
            dfs1(i,C,-1);
        }
    }
    for (int i=0;i<n;i++)
    {
        sort(g[i].begin(),g[i].end());
    }
    C++;
    for (int i=0;i<n;i++) was[i] = 0;
    vector<int> v3(C,-1);
    for (int i=0;i<n;i++)
    {
        int cnt = 0;
        for (int j=0;j<g[i].size();j++)
        {
            int c = g[i][j].X;
            if (j==0 or c!=g[i][j-1].X)
            {
                cnt = 1;
            }
            else cnt++;
            if (cnt>=3) {
                cout << "YES" << endl;
                dfs2(i,c,i,-1);
                dfs3(i,c,i);
                vector<vector<int>> A(3);
                A[2] = ans2;
                for (int k=0;k<ans.size();k++)
                {
                    A[0].push_back(ans[k]);
                    if (ans[k]==A[2].back())
                    {
                        A[1].push_back(ans[0]);
                        for (int k2=ans.size()-1;k2>=k;k2--) A[1].push_back(ans[k2]);
                        break;
                    }
                }
                for (int x=0;x<3;x++)
                {
                    cout << A[x].size();
                    for (int k=0;k<A[x].size();k++) cout << " " << A[x][k]+1;
                    cout << endl;
                }
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}