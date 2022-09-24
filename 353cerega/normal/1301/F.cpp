#pragma GCC optimize("Ofast")
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


int d[1000][1000], d2[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> a(n,vector<ll>(m));
    vector<vector<pair<ll,ll>>> Q(k);
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            cin >> a[i][j];
            a[i][j]--;
            Q[a[i][j]].push_back({i,j});
        }
    }
    ll W;
    cin >> W;
    vector<vector<ll>> F(W,vector<ll>(4));
    vector<ll> A(W);
    for (ll z=0;z<W;z++)
    {
        for (ll i=0;i<4;i++)
        {
            cin >> F[z][i];
            F[z][i]--;
        }
        A[z] = abs(F[z][0]-F[z][2])+abs(F[z][1]-F[z][3]);
    }
    vector<ll> dx = {1,-1,0,0};
    vector<ll> dy = {0,0,1,-1};
    for (ll z=0;z<k;z++)
    {
        for (ll i=0;i<n;i++)
        {
            for (ll j=0;j<m;j++) d[i][j] = d2[i][j] = -1;
        }
        {
            vector<pair<ll,ll>> q;
            vector<ll> was(k);
            was[z] = 1;
            for (pair<ll,ll> cur: Q[z])
            {
                d[cur.X][cur.Y] = 0;
                q.push_back(cur);
            }
            for (ll w=0;w<q.size();w++)
            {
                ll x = q[w].X;
                ll y = q[w].Y;
                ll C = a[x][y];
                if (was[C]==0)
                {
                    was[C] = 1;
                    for (pair<ll,ll> cur: Q[C])
                    {
                        if (d[cur.X][cur.Y]!=-1) continue;
                        d[cur.X][cur.Y] = d[x][y]+1;
                        q.push_back(cur);
                    }
                }
                for (ll r=0;r<4;r++)
                {
                    ll x2 = x+dx[r];
                    ll y2 = y+dy[r];
                    if (x2<0 or y2<0 or x2>=n or y2>=m or d[x2][y2]!=-1) continue;
                    d[x2][y2] = d[x][y]+1;
                    q.push_back({x2,y2});
                }
            }
        }
        {
            vector<pair<ll,ll>> q;
            for (pair<ll,ll> cur: Q[z])
            {
                d2[cur.X][cur.Y] = 0;
                q.push_back(cur);
            }
            for (ll w=0;w<q.size();w++)
            {
                ll x = q[w].X;
                ll y = q[w].Y;
                for (ll r=0;r<4;r++)
                {
                    ll x2 = x+dx[r];
                    ll y2 = y+dy[r];
                    if (x2<0 or y2<0 or x2>=n or y2>=m or d2[x2][y2]!=-1) continue;
                    d2[x2][y2] = d2[x][y]+1;
                    q.push_back({x2,y2});
                }
            }
        }
        for (ll i=0;i<W;i++)
        {
            A[i] = min(A[i],d2[F[i][0]][F[i][1]]+d[F[i][2]][F[i][3]]+1LL);
        }
    }
    for (ll i=0;i<W;i++) cout << A[i] << "\n";
}