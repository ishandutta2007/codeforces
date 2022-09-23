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
    sz[v] = 1;
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

vector<vector<ll>> a(8,vector<ll>(3));

vector<vector<ll>> cur;

void check()
{
    vector<vector<ll>> A(8);
    vector<ll> was(8);
    vector<vector<ll>> d(3,vector<ll>(3));
    for (ll i=0;i<3;i++)
    {
        for (ll b=0;b<3;b++) d[i][b] = (cur[i+1][b]-cur[0][b]);
    }
    vector<vector<ll>> C(8,vector<ll>(3));
    for (ll i=0;i<8;i++)
    {
        for (ll j=0;j<3;j++) C[i][j] = a[i][j];
    }
    for (ll msk=0;msk<8;msk++)
    {
        vector<ll> val(3);
        for (ll b=0;b<3;b++)
        {
            val[b] = cur[0][b];
            for (ll i=0;i<3;i++)
            {
                if ((msk&(1LL<<i))==0) continue;
                val[b] += d[i][b];
            }
        }
        ll F = 0;
        for (ll j=0;j<8;j++)
        {
            if (was[j]==1) continue;
            vector<ll> was2(3);
            ll bad = 0;
            for (ll p=0;p<3;p++)
            {
                ll FF = 0;
                for (ll p2=0;p2<3;p2++)
                {
                    if (was2[p2]==1) continue;
                    if (val[p]==C[j][p2])
                    {
                        was2[p2] = 1;
                        FF = 1;
                        break;
                    }
                }
                if (FF==0) bad = 1;
            }
            if (bad==0)
            {
                C[j] = val;
                was[j] = 1;
                F = 1;
                break;
            }
        }
        if (F==0) return;
    }
    cout << "YES\n";
    for (ll i=0;i<8;i++)
    {
        for (ll j=0;j<3;j++) cout << C[i][j] << " ";
        cout << "\n";
    }
    exit(0);
}

bool check2()
{
    if (cur.size()<2) return true;
    ll L = 0;
    for (ll b=0;b<3;b++)
    {
        L += (cur[1][b]-cur[0][b])*(cur[1][b]-cur[0][b]);
    }
    if (L==0) return false;
    if (cur.size()==2) return true;

    for (ll k=cur.size()-1;k<cur.size();k++)
    {
        ll L2 = 0;
        for (ll b=0;b<3;b++)
        {
            L2 += (cur[k][b]-cur[0][b])*(cur[k][b]-cur[0][b]);
        }
        if (L!=L2) return false;
        for (ll j=1;j+1<cur.size();j++)
        {
            ll S = 0;
            for (ll b=0;b<3;b++)
            {
                S += (cur[k][b]-cur[0][b])*(cur[j][b]-cur[0][b]);
            }
            if (S!=0) return false;
        }
    }
    return true;
}

void rec(vector<ll> p, ll j)
{
    while (true)
    {
        if (check2())
        {
            if (p.size()==4) check();
            else
            {
                for (ll w=j+1;w<8;w++)
                {
                    cur.push_back(a[w]);
                    p.push_back(w);
                    rec(p,w);
                    p.pop_back();
                    cur.pop_back();
                }
            }
        }
        if (!next_permutation(cur.back().begin(),cur.back().end())) break;
    }
}

void solve()
{
    ll n = 8;
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<3;j++) cin >> a[i][j];
        sort(a[i].begin(),a[i].end());
    }
    vector<ll> p;
    cur.push_back(a[0]);
    p.push_back(0);
    rec(p,0);
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}