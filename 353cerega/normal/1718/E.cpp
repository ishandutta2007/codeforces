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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n,vector<ll>(m));
    vector<vector<ll>> b(n,vector<ll>(m));
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++) cin >> a[i][j];
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++) cin >> b[i][j];
    }
    ll F = 0;
    if (n>m)
    {
        vector<vector<ll>> a2(m,vector<ll>(n));
        vector<vector<ll>> b2(m,vector<ll>(n));
        for (ll i=0;i<n;i++)
        {
            for (ll j=0;j<m;j++)
            {
                a2[j][i] = a[i][j];
                b2[j][i] = b[i][j];
            }
        }
        swap(n,m);
        a = a2;
        b = b2;
        F = 1;
    }
    vector<vector<pair<ll,ll>>> kek(n);
    vector<vector<pair<ll,ll>>> lul(m);
    vector<vector<pair<ll,ll>>> kek2(n);
    vector<vector<pair<ll,ll>>> lul2(m);
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            if (a[i][j]!=0)
            {
                kek[i].push_back({a[i][j],j});
                lul[j].push_back({a[i][j],i});
            }
            if (b[i][j]!=0)
            {
                kek2[i].push_back({b[i][j],j});
                lul2[j].push_back({b[i][j],i});
            }
        }
        sort(kek[i].begin(),kek[i].end());
        sort(kek2[i].begin(),kek2[i].end());
    }
    for (ll i=0;i<m;i++)
    {
        sort(lul[i].begin(),lul[i].end());
        sort(lul2[i].begin(),lul2[i].end());
    }
    vector<ll> nxt(n,-1), nxt2(m,-1);
    vector<ll> prv(n,-1), prv2(m,-1);
    for (ll i=0;i<n;i++)
    {
        if (nxt[i]!=-1) continue;
        ll ok = 0;
        for (ll st=0;st<n;st++)
        {
            if (prv[st]!=-1) continue;
            vector<pair<ll,ll>> p, q;
            p.push_back({i,st});
            nxt[i] = st;
            prv[st] = i;
            ll Lp = 0, Lq = 0, bad = 0;
            while ((Lp<p.size() or Lq<q.size()) and bad==0)
            {
                if (Lp<p.size())
                {
                    ll x = p[Lp].X;
                    ll y = p[Lp].Y;
                    if (kek[x].size()!=kek2[y].size())
                    {
                        bad = 1;
                        break;
                    }
                    Lp++;
                    for (ll w=0;w<kek[x].size();w++)
                    {
                        if (kek[x][w].X!=kek2[y][w].X)
                        {
                            bad = 1;
                            break;
                        }
                        ll x1 = kek[x][w].Y, y1 = kek2[y][w].Y;
                        if (nxt2[x1]==y1) continue;
                        if (nxt2[x1]!=-1 or prv2[y1]!=-1)
                        {
                            bad = 1;
                            break;
                        }
                        nxt2[x1] = y1;
                        prv2[y1] = x1;
                        q.push_back({x1,y1});
                    }
                    continue;
                }
                if (Lq<q.size())
                {
                    ll x = q[Lq].X;
                    ll y = q[Lq].Y;
                    if (lul[x].size()!=lul2[y].size())
                    {
                        bad = 1;
                        break;
                    }
                    Lq++;
                    for (ll w=0;w<lul[x].size();w++)
                    {
                        if (lul[x][w].X!=lul2[y][w].X)
                        {
                            bad = 1;
                            break;
                        }
                        ll x1 = lul[x][w].Y, y1 = lul2[y][w].Y;
                        if (nxt[x1]==y1) continue;
                        if (nxt[x1]!=-1 or prv[y1]!=-1)
                        {
                            bad = 1;
                            break;
                        }
                        nxt[x1] = y1;
                        prv[y1] = x1;
                        p.push_back({x1,y1});
                    }
                    continue;
                }
            }
            if (bad==0)
            {
                ok = 1;
                break;
            }
            for (auto x: p)
            {
                nxt[x.X] = -1;
                prv[x.Y] = -1;
            }
            for (auto x: q)
            {
                nxt2[x.X] = -1;
                prv2[x.Y] = -1;
            }
        }
        if (ok==0)
        {
            cout << -1 << "\n";
            return;
        }
    }
    vector<vector<ll>> Q;
    for (ll i=0;i<n;i++)
    {
        if (prv[i]!=i)
        {
            Q.push_back({1+F,i,prv[i]});
            ll w = prv[i];
            nxt[w] = nxt[i];
            prv[nxt[w]] = w;
            prv[i] = nxt[i] = i;
        }
    }
    for (ll i=0;i<m;i++)
    {
        if (prv2[i]!=i and prv2[i]!=-1)
        {
            ll w = prv2[i];
            Q.push_back({2-F,i,w});
            swap(nxt2[w],nxt2[i]);
            if (nxt2[w]!=-1) prv2[nxt2[w]] = prv2[i];
            prv2[i] = i;
        }
    }
    cout << Q.size() << "\n";
    for (ll i=0;i<Q.size();i++) cout << Q[i][0] << " " << Q[i][1]+1 << " " << Q[i][2]+1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}