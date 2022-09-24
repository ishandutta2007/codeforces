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
    ll n;
    cin >> n;
    vector<ll> d(n);
    for (ll i=0;i<n;i++)
    {
        cin >> d[i];
        d[i]--;
    }
    vector<vector<ll>> g(n);
    for (ll i=1;i<n;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    {
        vector<ll> q;
        for (ll i=0;i<n;i++)
        {
            if (d[i]==0) q.push_back(i);
        }
        for (ll z=0;z<q.size();z++)
        {
            ll u = q[z];
            for (ll v: g[u])
            {
                if (d[v]!=-1) continue;
                d[v] = d[u]+1;
                q.push_back(v);
            }
        }
    }
    vector<vector<ll>> G(n);
    for (ll i=0;i<n;i++)
    {
        ll F = 0;
        for (ll v: g[i])
        {
            if (d[i]==d[v]) F = 1;
        }
        if (F==1) G[d[i]].push_back(i);
    }
    vector<ll> A(n);
    for (ll i=0;i<n;i++)
    {
        A[i] = d[i];
    }
    for (ll W=0;W<n;W++)
    {
        if (G[W].size()==0) continue;
        deque<pair<ll,ll>> q;
        vector<ll> D(n,mod);
        for (ll x: G[W])
        {
            D[x] = 0;
            q.push_back({x,0});
        }
        vector<pair<ll,ll>> cur;
        while (q.size()!=0)
        {
            while (q.size()!=0 and (cur.size()==0 or (cur.back().Y==q.front().Y and d[cur.back().X]==d[q.front().X])))
            {
                cur.push_back(q.front());
                q.pop_front();
            }
            while (cur.size()>0)
            {
                ll x = cur.back().X;
                ll Q = cur.back().Y;
                cur.pop_back();
                if (D[x]!=Q) continue;
                for (ll v: g[x])
                {
                    if (d[v]<d[x]) continue;
                    if (d[v]==d[x])
                    {
                        if (D[v]<=D[x]+1) continue;
                        D[v] = D[x]+1;
                        q.push_front({v,D[v]});
                        continue;
                    }
                    ll T = max(D[x]-1,0LL);
                    if (D[v]<=T) continue;
                    D[v] = T;
                    q.push_back({v,T});
                }
            }
        }
        for (ll z=0;z<n;z++)
        {
            if (D[z]!=0) continue;
            A[z] = max(A[z],d[z]*2-W);
        }
    }
    for (ll i=0;i<n;i++) cout << A[i] << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    solve();
}