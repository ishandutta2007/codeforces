#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = int;
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


ll A[1000001][5];

void updC(ll v)
{
    A[v][0] = 1;
    if (A[v][1]!=-1) A[v][0] += A[A[v][1]][0];
    if (A[v][2]!=-1) A[v][0] += A[A[v][2]][0];
}

void split(ll v, ll Q, ll &l, ll &r)
{
    if (v==-1)
    {
        l = r = -1;
        return;
    }
    ll C = 0;
    if (A[v][1]!=-1) C += A[A[v][1]][0];
    if (C>=Q) split(A[v][1],Q,l,A[v][1]), r = v;
    else split(A[v][2],Q-C-1,A[v][2],r), l = v;
    updC(v);
}

void merge(ll &v, ll l, ll r)
{
    if (l==-1 or r==-1)
    {
        if (l!=-1) v = l;
        else v = r;
        return;
    }
    if (A[l][3]>A[r][3]) merge(A[l][2],A[l][2],r), v = l;
    else merge(A[r][1],l,A[r][1]), v = r;
    updC(v);
}

ll get()
{
    
    ll x = 0;
    cin >> x;
    return x;
}

void solve()
{
    ll n, m;
    //cin >> n >> m;
    n = get();
    m = get();
    //mt19937 gen(time(0));
    //uniform_int_distribution<ll> uid(0,mod);
    for (ll i=0;i<n;i++)
    {
        A[i][3] = rand()*100000+rand();
        A[i][1] = A[i][2] = -1;
        A[i][4] = -1;
        A[i][0] = 1;
    }
    ll R = 0;
    for (ll i=1;i<n;i++) merge(R,R,i);
    vector<pair<ll,ll>> q(m);
    for (ll i=0;i<m;i++)
    {
        q[i].X = get();
        q[i].Y = get();
    }
    vector<ll> was(n+1);
    for (ll i=m-1;i>=0;i--)
    {
        ll x = q[i].X;
        ll y = q[i].Y;
        ll l0, l, r;
        split(R,1,l0,r);
        if (A[l0][4]!=-1 and A[l0][4]!=x)
        {
            cout << -1 << "\n";
            return;
        }
        if (A[l0][4]==-1)
        {
            A[l0][4] = x;
            if (was[x]==0) was[x] = 1;
            else
            {
                cout << -1 << "\n";
                return;
            }
        }
        split(r,y-1,l,r);
        merge(l,l,l0);
        merge(R,l,r);
    }
    vector<ll> vals(n,-1);
    for (ll i=0;i<n;i++)
    {
        ll l0;
        split(R,1,l0,R);
        if (A[l0][4]==-1) continue;
        vals[i] = A[l0][4];
    }
    ll mn = 1;
    for (ll i=0;i<n;i++)
    {
        if (vals[i]==-1)
        {
            while (was[mn]==1) mn++;
            was[mn] = 1;
            vals[i] = mn;
        }
    }
    for (ll i=0;i<n;i++) cout << vals[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    cin.tie(0);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}