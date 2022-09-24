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
 
 
vector<ll> a;
 
ll t[1200000], t2[1200000], rev[1200000];
ll L[1200000], R[1200000];
ll L01[1200000], R01[1200000];
ll L10[1200000], R10[1200000];
 
void rec(ll v, ll len1, ll len2)
{
    t[v] = max(t[2*v],t[2*v+1]);
    t2[v] = max(t2[2*v],t2[2*v+1]);
    L[v] = L[2*v];
    R[v] = R[2*v+1];
    if (R[2*v]>0 and L[2*v+1]>0)
    {
        if (L[v]==len1) L[v] += L[2*v+1];
        if (R[v]==len2) R[v] += R[2*v];
    }
    if (R[2*v]<0 and L[2*v+1]<0)
    {
        if (L[v]==-len1) L[v] += L[2*v+1];
        if (R[v]==-len2) R[v] += R[2*v];
    }
    L01[v] = L01[2*v];
    L10[v] = L10[2*v];
    R01[v] = R01[2*v+1];
    R10[v] = R10[2*v+1];
    if (L[2*v]==len1) L01[v] += L01[2*v+1];
    else
    {
        if (L01[v]==len1 and L[2*v+1]<0) L01[v] -= L[2*v+1];
    }
    if (L[2*v]==-len1) L10[v] += L10[2*v+1];
    else
    {
        if (L10[v]==len1 and L[2*v+1]>0) L10[v] += L[2*v+1];
    }
    if (R[2*v+1]==-len2) R01[v] += R01[2*v];
    else
    {
        if (R01[v]==len2 and R[2*v]>0) R01[v] += R[2*v];
    }
    if (R[2*v+1]==len2) R10[v] += R10[2*v];
    else
    {
        if (R10[v]==len2 and R[2*v]<0) R10[v] -= R[2*v];
    }
    if (L[2*v+1]>0)
    {
        ll x = max(0LL,R[2*v]);
        t[v] = max(t[v],x+L01[2*v+1]);
        t2[v] = max(t2[v],R10[2*v]+L[2*v+1]);
    } else
    {
        ll x = max(0LL,-R[2*v]);
        t[v] = max(t[v],R01[2*v]-L[2*v+1]);
        t2[v] = max(t2[v],x+L10[2*v+1]);
    }
}
 
void build(ll v, ll tl, ll tr)
{
    rev[v] = 0;
    if (tl==tr)
    {
        L01[v] = R01[v] = L10[v] = R10[v] = 1;
        t[v] = t2[v] = 1;
        if (a[tl]==0)
        {
            L[v] = R[v] = 1;
        }
        else
        {
            L[v] = R[v] = -1;
        }
        return;
    }
    ll tm = (tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    rec(v,tm-tl+1,tr-tm);
}
 
void push2(ll v)
{
    rev[v] = 1-rev[v];
    L[v] = -L[v];
    R[v] = -R[v];
    swap(t[v],t2[v]);
    swap(L01[v],L10[v]);
    swap(R01[v],R10[v]);
}
 
void push(ll v)
{
    if (rev[v]==0) return;
    rev[v] = 0;
    push2(2*v);
    push2(2*v+1);
}
 
void upd(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r)
    {
        push2(v);
        return;
    }
    push(v);
    ll tm = (tl+tr)/2;
    if (l<=tm) upd(2*v,tl,tm,l,r);
    if (r>tm) upd(2*v+1,tm+1,tr,l,r);
    rec(v,tm-tl+1,tr-tm);
}
 
ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl==l and tr==r)
    {
        return t[v];
    }
    ll tm = (tl+tr)/2;
    push(v);
    if (r<=tm) return get(v*2,tl,tm,l,r);
    if (l>tm) return get(v*2+1,tm+1,tr,l,r);
    ll A = max(get(v*2,tl,tm,l,tm),get(v*2+1,tm+1,tr,tm+1,r));
    {
        ll x = max(min(R[v*2],tm+1-l),0LL);
        ll y = min(L01[v*2+1],r-tm);
        A = max(A,x+y);
    }
    {
        ll x = max(min(-L[v*2+1],r-tm),0LL);
        ll y = min(R01[v*2],tm+1-l);
        A = max(A,x+y);
    }
    return A;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    a.resize(n);
    for (ll i=0;i<n;i++)
    {
        if (s[i]=='>') a[i] = 0;
        else a[i] = 1;
    }
    build(1,0,n-1);
    for (ll z=0;z<q;z++)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        upd(1,0,n-1,l,r);
        cout << get(1,0,n-1,l,r) << "\n";
    }
}