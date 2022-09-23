//#pragma GCC optimize("Ofast")
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
    if (a>=mod) a -= mod;
    //a %= mod;
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
    else return a*b%mod;
}

inline ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1LL) res = mul(res,a);
        a = mul(a,a);
        b >>= 1LL;
    }
    return res;
}



/*const int MOD = 998244353;
const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;
const int root = 30;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/

/*
void fft (vector<int> & a, bool invert) {
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


/*
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
}*/




void solve()
{
    int n;
    cin >> n;
    vector<vector<string>> s(n,vector<string>(n));
    vector<vector<vector<int>>> nxt(n,vector<vector<int>>(n));
    for (ll i=0;i<n;i++)
    {
        for (ll j=i+1;j<n;j++)
        {
            cin >> s[i][j];
            for (ll k=0;k<n;k++)
            {
                if (s[i][j][k]=='1')
                {
                    nxt[i][k].push_back(j);
                    nxt[j][k].push_back(i);
                }
            }
        }
    }
    for (int st=1;st<n;st++)
    {
        vector<pair<int,int>> g;
        g.push_back({0,st});
        g.push_back({st,0});
        vector<ll> was(n);
        was[0] = was[st] = 1;
        ll F = 0;
        for (int w=0;w<g.size();w++)
        {
            for (int v: nxt[g[w].X][g[w].Y])
            {
                if (was[v]==1)
                {
                    F = 1;
                    break;
                }
                was[v] = 1;
                g.push_back({g[w].Y,v});
            }
            if (F==1) break;
        }
        for (int i=0;i<n;i++)
        {
            if (was[i]==0) F = 1;
        }
        if (F==1) continue;
        vector<vector<int>> G(n);
        for (ll i=1;i<g.size();i++)
        {
            int u = g[i].X;
            int v = g[i].Y;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for (ll i=0;i<n;i++)
        {
            vector<int> d(n,-1);
            d[i] = 0;
            vector<int> q;
            q.push_back(i);
            for (int w=0;w<q.size();w++)
            {
                int u = q[w];
                for (int v: G[u])
                {
                    if (d[v]!=-1) continue;
                    d[v] = d[u]+1;
                    q.push_back(v);
                }
            }
            for (int j=0;j<n and F==0;j++)
            {
                for (int j2=j+1;j2<n;j2++)
                {
                    if (s[j][j2][i]=='1' and d[j]!=d[j2])
                    {
                        F = 1;
                        break;
                    }
                    if (s[j][j2][i]=='0' and d[j]==d[j2])
                    {
                        F = 1;
                        break;
                    }
                }
            }
        }
        if (F==1) continue;
        cout << "Yes\n";
        for (ll i=1;i<g.size();i++)
        {
            cout << g[i].X+1 << " " << g[i].Y+1 << "\n";
        }
        return;
    }
    cout << "No\n";
}



int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}