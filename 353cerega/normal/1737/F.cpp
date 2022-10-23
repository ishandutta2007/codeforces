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

const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;

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
}



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


vector<ll> a10 = {2,1,3};
vector<ll> a01 = {2,1};
vector<vector<ll>> a02 = {{1,2},{2,0},{1,1},{0,2},{2,1},{1,0},{2,2},{0,1}};


void solve()
{
    ll k;
    cin >> k;
    vector<ll> a(k);
    ll F = 0;
    ll C3 = 0, C4 = 0;
    vector<ll> p3, p4;
    ll N = 1;
    for (ll i=0;i<k;i++)
    {
        cin >> a[i];
        if (a[i]>3) F = 1;
        if (a[i]==3) C4++, p4.push_back(i);
        if (a[i]==2) C3++, p3.push_back(i);
    }
    if (C4>1 or (C4==1 and C3>0)) F = 1;
    if (C3>2) F = 1;
    if (F==1)
    {
        cout << -1 << "\n";
        return;
    }
    vector<vector<ll>> A;
    vector<ll> was(k);
    if (C4==1)
    {
        N = 3;
        A.resize(3,vector<ll>(k));
        for (ll i=0;i<3;i++)
        {
            A[i][p4[0]] = a10[i];
        }
        was[p4[0]] = 1;
    }
    if (C3==1)
    {
        N = 2;
        A.resize(2,vector<ll>(k));
        for (ll i=0;i<2;i++)
        {
            A[i][p3[0]] = a01[i];
        }
        was[p3[0]] = 1;
    }
    if (C3==2)
    {
        N = 8;
        A.resize(N,vector<ll>(k));
        for (ll i=0;i<N;i++)
        {
            A[i][p3[0]] = a02[i][0];
            A[i][p3[1]] = a02[i][1];
        }
        was[p3[0]] = was[p3[1]] = 1;
    }
    if (N==1)
    {
        was[0] = 1;
        A.resize(N,vector<ll>(k));
        A[0][0] = 1;
    }
    for (ll w=0;w<k;w++)
    {
        if (was[w]==1) continue;
        ll n = N*2+1;
        vector<vector<ll>> B(n,vector<ll>(k));
        if (C4!=0)
        {
            for (ll i=0;i<N;i++)
            {
                B[i] = A[i];
                B[i][w] = (i+N-1)%2;
                if (i+1==N) continue;
                B[N*2-2-i] = A[i];
                B[N*2-2-i][w] = (i+N)%2;
            }
            B[N*2-1][w] = 1;
            B[N*2] = A[N-1];
            B[N*2][w] = 1;
        } else
        {
            for (ll i=0;i<N;i++)
            {
                B[i] = A[i];
                B[N*2-1-i] = A[i];
                B[i][w] = i%2;
                B[N*2-1-i][w] = 1-i%2;
            }
            B[n-1][w] = 1;
        }
        N = n;
        A = B;
    }
    for (ll i=0;i<N;i++)
    {
        for (ll j=0;j<k;j++) cout << A[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}