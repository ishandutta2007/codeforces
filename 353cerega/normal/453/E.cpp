//#pragma GCC optimize("Ofast")
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
    /*ll R = a*b-((ll)(a*1.0L*b/mod))*mod;
    if (R<0) R += mod;
    if (R>=mod) R -= mod;
    return R;*/
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


ll M = 500, N = 1;
vector<ll> a, mx, r;

vector<vector<pair<ll,pair<ll,ll>>>> nxt;
vector<ll> prv;
vector<ll> lst;

void build()
{
    lst.resize(N,-1);
    nxt.resize(N,vector<pair<ll,pair<ll,ll>>>(M+1));
    for (ll i=0;i<N;i++)
    {
        vector<pair<ll,ll>> ord;
        ll D = 0;
        for (ll j=i*M;j<(i+1)*M;j++)
        {
            if (r[j]==0)
            {
                ord.push_back({mod*2,j});
                continue;
            }
            ll T = mx[j]/r[j];
            if (mx[j]%r[j]!=0) T++;
            D += r[j];
            ord.push_back({T,j});
        }
        sort(ord.begin(),ord.end());
        nxt[i][0] = {0,{0,D}};
        ll S = 0;
        for (ll j=0;j<ord.size();j++)
        {
            ll p = ord[j].Y;
            S += mx[p];
            D -= r[p];
            ll t = ord[j].X;
            nxt[i][j+1] = {t,{S,D}};
        }
    }
}

ll get(ll p, ll T)
{
    if (lst[p]==-1)
    {
        ll A = 0;
        for (ll i=p*M;i<(p+1)*M;i++)
        {
            A += min(a[i]+(T-prv[i])*r[i],mx[i]);
        }
        return A;
    }
    ll L = 0, R = M+1;
    T -= lst[p];
    while (R-L>1)
    {
        ll m = (L+R)/2;
        if (nxt[p][m].X<=T) L = m;
        else R = m;
    }
    return nxt[p][L].Y.X+nxt[p][L].Y.Y*T;
}

void calc()
{
    ll T, L, R;
    cin >> T >> L >> R;
    L--;
    ll A = 0;
    for (ll j=L/M+1;j<R/M;j++)
    {
        A += get(j,T);
        lst[j] = T;
    }
    for (ll i=L;i<R and i<(L/M+1)*M;i++)
    {
        if (lst[i/M]!=-1)
        {
            prv[i] = lst[i/M];
            a[i] = 0;
        }
        A += min(a[i]+r[i]*(T-prv[i]),mx[i]);
        a[i] = 0;
        prv[i] = T;
    }
    if (L/M==R/M)
    {
        cout << A << "\n";
        if (lst[L/M]!=-1)
        {
            while (L%M!=0)
            {
                L--;
                prv[L] = lst[L/M];
                a[L] = 0;
            }
            while (R%M!=0)
            {
                prv[R] = lst[R/M];
                a[R] = 0;
                R++;
            }
            lst[L/M] = -1;
        }
        return;
    }
    if (lst[L/M]!=-1)
    {
        while (L%M!=0)
        {
            L--;
            prv[L] = lst[L/M];
            a[L] = 0;
        }
        lst[L/M] = -1;
    }
    if (R%M==0)
    {
        cout << A << "\n";
        return;
    }
    for (ll i=R/M*M;i<R;i++)
    {
        if (lst[i/M]!=-1)
        {
            prv[i] = lst[i/M];
            a[i] = 0;
        }
        A += min(a[i]+r[i]*(T-prv[i]),mx[i]);
        a[i] = 0;
        prv[i] = T;
    }
    if (lst[R/M]!=-1)
    {
        while (R%M!=0)
        {
            prv[R] = lst[R/M];
            a[R] = 0;
            R++;
        }
        lst[R/M-1] = -1;
    }
    cout << A << "\n";
}

void solve()
{
    ll n;
    cin >> n;
    a.resize(n), mx.resize(n), r.resize(n);
    prv.resize(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i] >> mx[i] >> r[i];
    }
    if (n%M!=0)
    {
        n += M-n%M;
        a.resize(n,0), mx.resize(n,0), r.resize(n,0);
        prv.resize(n,0);
    }
    N = n/M;
    build();
    ll q;
    cin >> q;
    while (q--) calc();
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