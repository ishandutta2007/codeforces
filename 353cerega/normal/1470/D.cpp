#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
#define X first
#define Y second

ll mod = 998244353;

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

/*
typedef complex<double> base;
long double PI = acos(-1);
const ll root = 31;
const ll root_pw = 1<<23;
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
    if (n == 1)  return;

    vector<base> a0 (n/2),  a1 (n/2);
    for (int i=0, j=0; i<n; i+=2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft (a0, invert);
    fft (a1, invert);

    double ang = 2*PI/n * (invert ? -1 : 1);
    base w (1),  wn (cos(ang), sin(ang));
    for (int i=0; i<n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert)
            a[i] /= 2,  a[i+n/2] /= 2;
        w *= wn;
    }
}
*/
int parent[600001];
int rnk[600001];
int suk[600001];

void make_set (int v) {
    parent[v] = v;
    rnk[v] = 0;
    suk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b and (suk[a]*suk[b]==0)) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
        suk[a] += suk[b];
    }
}

/*
ll t[4200000];
ll del[4200000];

void build()
{
    for (int i=0;i<4200000;i++)
    {
        t[i] = 0;
        del[i] = 0;
    }
}

void push(int v, int tl, int tr, int tm)
{
    t[2*v] += del[v]*(tm-tl+1);
    t[2*v+1] += del[v]*(tr-tm);
    del[2*v] += del[v];
    del[2*v+1] += del[v];
    del[v] = 0;
}

void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        del[v] += val;
        t[v] += val*(tr-tl+1);
        return;
    }
    int tm = (tl + tr) / 2;
    if (del[v]!=0) push(v,tl,tr,tm);
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
}

ll get (int v, int tl, int tr, int l, int r) {
    int tm = (tl + tr) / 2;
    if (del[v]>0 and tl!=tr) push(v,tl,tr,tm);
    if (tl==l and tr==r)
        return t[v];
    if (r<=tm) return get(2*v,tl,tm,l,r);
    if (l>tm) return get(2*v+1,tm+1,tr,l,r);
    return get(2*v,tl,tm,l,tm)+get(2*v+1,tm+1,tr,tm+1,r);
}*/

/*
ll base = 1000000000;

vector<ll> mul(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<a.size();i++)
    {
        for (int j=0;j<b.size();j++)
        {
            res[i+j] += a[i]*b[j];
        }
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}

vector<ll> sum(vector<ll> a, vector<ll> b)
{
    if (a.size()<b.size())
    {
        swap(a,b);
    }
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]+b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}

vector<ll> sub(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]-b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]<0)
        {
            res[i+1]--;
            res[i] += base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}
*/


vector<vector<ll>> g;
vector<ll> used;
vector<ll> pos;
void dfs(ll u)
{
    if (used[u]==1) return;
    used[u] = 1;
    for (int i=0;i<g[u].size();i++)
    {
        dfs(g[u][i]);
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n);
    used.clear();
    used.resize(n);
    for (int i=0;i<m;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for (int i=0;i<n;i++)
    {
        if (used[i]==0)
        {
            cout << "NO" << "\n";
            return;
        }
    }
    used.clear();
    used.resize(n);
    vector<ll> ans;
    ans.push_back(0);
    used[0] = 1;
    pos.clear();
    pos.resize(n);
    vector<ll> kek;
    ll lft = n-1;
    for (int i=0;i<g[0].size();i++)
    {
        if (used[g[0][i]]==0)
        {
            used[g[0][i]] = 1;
            kek.push_back(g[0][i]);
            lft--;
        }
    }
    ll q = 0;
    while (lft>0)
    {
        ll cur = kek[q];
        q++;
        for (;pos[cur]<g[cur].size();pos[cur]++)
        {
            ll nxt = g[cur][pos[cur]];
            if (used[nxt]==0)
            {
                used[nxt] = 1;
                lft--;
                ans.push_back(nxt);
                for (int j=0;j<g[nxt].size();j++)
                {
                    if (used[g[nxt][j]]==0)
                    {
                        used[g[nxt][j]] = 1;
                        kek.push_back(g[nxt][j]);
                        lft--;
                    }
                }
            }
        }
    }
    cout << "YES" << "\n";
    cout << ans.size() << "\n";
    for (int i=0;i<ans.size();i++)
    {
        cout << ans[i]+1 << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}