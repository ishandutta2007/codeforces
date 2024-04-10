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


vector<vector<int>> g;
vector<int> was, d;
vector<int> g2;
int C = -1;
int n;

void dfs(int u)
{
    was[u] = 1;
    if (u==C)
    {
        for (int i=0;i<n;i++)
        {
            if (g2[i]==1 and was[i]==0) dfs(i);
        }
    } else
    {
        for (int v: g[u])
        {
            if (was[v]==1) continue;
            if (C==v and g2[u]==0) continue;
            dfs(v);
        }
    }
}

vector<int> pt;
vector<vector<int>> R;
vector<int> ord;



int main()
{
    ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    g.resize(n);
    g2.resize(n);
    d.resize(n);
    was.resize(n);
    int cnt2 = 0;
    R.resize(n,vector<int>(n));
    for (int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        d[a]++;
        d[b]++;
        R[a][b] = 1;
        R[b][a] = 1;
    }

    for (int i=0;i<n;i++) if (d[i]%2==1) cnt2++;
    for (int i=0;i<n;i++)
    {
        C = i;
        for (int j=0;j<n;j++) was[j] = 0;
        for (int j=0;j<n;j++) g2[j] = 0;
        int cur = cnt2;
        int W = 0;
        for (int v: g[i])
        {
            if (d[v]%2==1)
            {
                cur--;
            }
            else
            {
                g2[v] = 1;
                W++;
            }
        }
        if (cur>2) continue;
        dfs(i);
        int V = -1;
        for (int j=0;j<n;j++)
        {
            if (was[j]==0)
            {
                if (d[j]==1 and g[j][0]==i) continue;
                V = j;
            }
        }
        if (d[i]%2==1) cur--;
        if (W%2==1) cur++;
        if (V!=-1 and cur==2) continue;
        if (cur==2 and W%2==0) continue;
        int q = i;
        if (V!=-1)
        {
            if (cur==2) continue;
            for (int v: g[i])
            {
                if (d[v]%2==1 and d[v]>1 and was[v]==0)
                {
                    g2[v] = 1;
                    q = v;
                    break;
                }
            }
            if (q==-1) continue;
            for (int j=0;j<n;j++) was[j] = 0;
            dfs(i);
            V = -1;
            for (int j=0;j<n;j++)
            {
                if (was[j]==0)
                {
                    if (d[j]==1 and g[j][0]==i) continue;
                    V = j;
                }
            }
            if (V!=-1) continue;
        }
        pt.resize(n);
        for (int j=0;j<n;j++)
        {
            pt[j] = 0;
        }
        for (int v: g[i])
        {
            if (g2[v]==0)
            {
                d[v]--;
                R[i][v] = R[v][i] = 0;
            }
        }
        q = i;
        for (int j=0;j<n;j++)
        {
            if (d[j]%2==1 and j!=i) q = j;
        }
        stack<int> st;
        st.push(q);
        vector<int> ans;
        while (!st.empty())
        {
            int v = st.top();
            int x;
            for (x=0; x<n; ++x)
                if (R[v][x])
                    break;
            if (x==n)
            {
                ans.push_back(v);
                st.pop();
            }
            else
            {
                --R[v][x];
                --R[x][v];
                st.push(x);
            }
        }
        if (ans.back()!=i) reverse(ans.begin(),ans.end());
        ans.push_back(-2);
        for (int v: g[i])
        {
            if (g2[v]==0)
            {
                ans.push_back(v);
                ans.push_back(i);
            }
        }
        cout << ans.size() << endl;
        for (int j=0;j<ans.size();j++)
        {
            cout << ans[j]+1 << " ";
        }
        return 0;
    }
    cout << 0 << endl;
}