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
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll mx = 0;
    ll A = 0, B = 0;
    vector<vector<ll>> kek;
    ll S = 0;
    unordered_map<ll,ll> num;
    for (ll i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        ll j = 60;
        ll k = 0;
        ll prv = -1;
        while (true)
        {
            if (num.count(x)==0)
            {
                num[x] = S++;
                vector<ll> t(6,-1);
                kek.push_back(t);
            }
            ll p = num[x];
            ll z = 0;
            if (kek[p][z]==prv) z += 3;
            if (kek[p][z+1]!=-1 and kek[p][z+1]+k>mx)
            {
                mx = kek[p][z+1]+k;
                A = i+1;
                B = kek[p][z+2];
            }
            z = 0;
            if (kek[p][z]==prv)
            {
                if (kek[p][z+1]<k)
                {
                    kek[p][z+1] = k;
                    kek[p][z+2] = i+1;
                }
            }
            else
            {
                z += 3;
                if (kek[p][z+1]<k)
                {
                    kek[p][z] = prv;
                    kek[p][z+1] = k;
                    kek[p][z+2] = i+1;
                }
                if (kek[p][z+1]>kek[p][z-2])
                {
                    for (ll q=0;q<3;q++) swap(kek[p][z+q],kek[p][z-3+q]);
                }
            }
            if (x==0) break;
            while (j>0 and x<=(1LL<<(j-1))) j--;
            prv = x;
            k++;
            x = (1LL<<j)-x;
        }
    }
    cout << A << " " << B << " " << mx << endl;
}