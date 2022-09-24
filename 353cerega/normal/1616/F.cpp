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



void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n,vector<ll>(n,-1));
    vector<ll> d(m,-1);
    for (ll i=0;i<m;i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--, c--;
        if (c==-2) c++;
        if (u>v) swap(u,v);
        a[u][v] = i;
        d[i] = c;
    }
    vector<vector<ll>> A;
    for (ll i=0;i<n;i++)
    {
        for (ll j=i+1;j<n;j++)
        {
            if (a[i][j]==-1) continue;
            if (d[a[i][j]]!=-1)
            {
                vector<ll> Q(m+1);
                Q[a[i][j]] = 1;
                Q[m] = d[a[i][j]];
                A.push_back(Q);
            }
            for (ll k=j+1;k<n;k++)
            {
                if (a[i][k]==-1 or a[j][k]==-1) continue;
                vector<ll> w(3);
                w[0] = a[i][j];
                w[1] = a[j][k];
                w[2] = a[i][k];
                vector<ll> Q(m+1);
                for (ll r=0;r<3;r++)
                {
                    Q[w[r]] = 1;
                }
                A.push_back(Q);
            }
        }
    }
    ll sz = A.size();
    ll j = 0;
    vector<ll> lul(m,-1);
    for (ll i=0;i<m;i++)
    {
        ll ok = 0;
        for (ll q=j;q<sz;q++)
        {
            if (A[q][i]!=0)
            {
                swap(A[q],A[j]);
                ok = 1;
                break;
            }
        }
        if (ok==0) continue;
        lul[i] = j;
        for (ll q=j+1;q<sz;q++)
        {
            if (A[q][i]!=0)
            {
                ll D = A[j][i]*(3-A[q][i])%3;
                for (ll z=i;z<=m;z++)
                {
                    A[q][z] = (A[q][z]+D*A[j][z])%3;
                }
            }
        }
        j++;
    }
    for (ll q=j;q<sz;q++)
    {
        if (A[q][m]!=0)
        {
            cout << -1 << "\n";
            return;
        }
    }
    for (ll i=m-1;i>=0;i--)
    {
        if (lul[i]==-1)
        {
            if (d[i]==-1) d[i] = 0;
            continue;
        }
        ll p = lul[i];
        ll S = A[p][m];
        for (ll z=i+1;z<m;z++)
        {
            S -= A[p][z]*d[z];
        }
        S *= A[p][i];
        S %= 3;
        if (S<0) S += 3;
        d[i] = S;
    }
    for (ll i=0;i<m;i++)
    {
        cout << d[i]+1 << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}