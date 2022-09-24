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
 
 
int parent[8000001];
int rnk[8000001];
 
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
}
 
ll n;
 
int k = 0;
int mx = 9000000;
vector<int> T(mx);
 
ll ord[8000000];
 
void add(ll L, ll R, int t)
{
    if (R==L) return;
    for (ll j=0;j<=n;j++)
    {
        if (L&(1LL<<j))
        {
            if (R>=L+(1LL<<j))
            {
                make_set(k);
                ord[k] = L;
                T[k] = t;
                k++;
                L += (1LL<<j);
            }
        }
    }
    for (ll j=n;j>=0;j--)
    {
        if (L+(1LL<<j)<=R)
        {
            make_set(k);
            ord[k] = L;
            T[k] = t;
            k++;
            L += (1LL<<j);
        }
    }
}
vector<ll> cnt(200000);
 
int U[60000000], V[60000000];
 
void rec(ll tl, ll tr, ll L, ll R)
{
    if (L+1==R) return;
    ll M = L;
    ll tm = (tl+tr)/2;
    while (ord[M]<tm) M++;
    rec(tl,tm,L,M);
    rec(tm,tr,M,R);
    ll d = tm-tl;
    ll j = L;
    ll j2 = M;
    while (j<M and j2<R)
    {
        if (ord[j+1]+d<=ord[j2])
        {
            j++;
            continue;
        }
        if (ord[j2+1]<=ord[j]+d)
        {
            j2++;
            continue;
        }
        ll u = j;
        ll v = j2;
        cnt[min(T[u],T[v])]++;
        if (ord[j+1]+d<=ord[j2+1]) j++;
        else j2++;
    }
}
 
void rec2(ll tl, ll tr, ll L, ll R)
{
    if (L+1==R) return;
    ll M = L;
    ll tm = (tl+tr)/2;
    while (ord[M]<tm) M++;
    rec2(tl,tm,L,M);
    rec2(tm,tr,M,R);
    ll d = tm-tl;
    ll j = L;
    ll j2 = M;
    while (j<M and j2<R)
    {
        if (ord[j+1]+d<=ord[j2])
        {
            j++;
            continue;
        }
        if (ord[j2+1]<=ord[j]+d)
        {
            j2++;
            continue;
        }
        ll u = j;
        ll v = j2;
        ll z = min(T[u],T[v]);
        cnt[z]--;
        U[cnt[z]] = u;
        V[cnt[z]] = v;
        if (ord[j+1]+d<=ord[j2+1]) j++;
        else j2++;
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    ll m;
    cin >> n >> m;
    vector<vector<ll>> a(m,vector<ll>(3));
    vector<pair<pair<ll,ll>,ll>> ord2;
    for (ll i=0;i<m;i++)
    {
        string s;
        cin >> s >> a[i][0] >> a[i][1];
        if (s=="block")
        {
            a[i][2] = 0;
            a[i][1]++;
            ord2.push_back({{a[i][0],a[i][1]},i});
        }
        else a[i][2] = 1;
    }
    sort(ord2.begin(),ord2.end());
    ll W = 0;
    for (ll j=0;j<ord2.size();j++)
    {
        if (W!=ord2[j].X.X)
        {
            add(W,ord2[j].X.X,m);
        }
        add(ord2[j].X.X,ord2[j].X.Y,ord2[j].Y);
        W = ord2[j].X.Y;
    }
    if (W!=(1LL<<n))
    {
        add(W,(1LL<<n),m);
    }
    ord[k] = (1LL<<n);
    rec(0,(1LL<<n),0,k);
    for (ll i=1;i<=m;i++) cnt[i] += cnt[i-1];
    cnt[m+1] = cnt[m];
    rec2(0,(1LL<<n),0,k);
    vector<ll> ans;
    ll q = m+1;
    for (ll z=m-1;z>=0;z--)
    {
        if (a[z][2]==0) continue;
        while (q>z)
        {
            q--;
            for (ll j=cnt[q];j<cnt[q+1];j++)
            {
                union_sets(U[j],V[j]);
            }
        }
 
        ll P, Q;
        ll L = 0, R = k;
        while (R-L>1)
        {
            ll M = (R+L)/2;
            if (ord[M]<=a[z][0]) L = M;
            else R = M;
        }
        P = L;
        L = 0, R = k;
        while (R-L>1)
        {
            ll M = (R+L)/2;
            if (ord[M]<=a[z][1]) L = M;
            else R = M;
        }
        Q = L;
        if (find_set(P)==find_set(Q)) ans.push_back(1);
        else ans.push_back(0);
    }
    reverse(ans.begin(),ans.end());
    for (ll i=0;i<ans.size();i++)
    {
        cout << ans[i] << "\n";
    }
}