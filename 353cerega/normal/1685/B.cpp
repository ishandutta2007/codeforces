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




void solve()
{
    vector<ll> C(4);
    for (ll i=0;i<4;i++) cin >> C[i];
    ll CA = C[0]+C[2]+C[3];
    ll CB = C[1]+C[2]+C[3];
    string s;
    cin >> s;
    ll n = s.length();
    for (ll i=0;i<n;i++)
    {
        if (s[i]=='A') CA--;
        else CB--;
    }
    if (CA!=0 or CB!=0)
    {
        cout << "NO\n";
        return;
    }
    vector<vector<ll>> was(n,vector<ll>(2));
    vector<vector<ll>> q(2);
    ll S = 0;
    for (ll i=0;i+1<n;i++)
    {
        if (s[i]==s[i+1]) continue;
        ll Q = 1;
        ll j = i;
        while (j+1<n and s[j]!=s[j+1])
        {
            j++;
            Q++;
        }
        if (Q%2==1)
        {
           S += Q/2;
        } else
        {
            if (s[i]=='A') q[0].push_back(Q/2);
            else q[1].push_back(Q/2);
        }
        i = j;
    }
    sort(q[0].begin(),q[0].end());
    reverse(q[0].begin(),q[0].end());
    sort(q[1].begin(),q[1].end());
    reverse(q[1].begin(),q[1].end());
    for (ll p=0;p<2;p++)
    {
        while (q[p].size()>0 and C[2+p]>=q[p].back())
        {
            C[2+p] -= q[p].back();
            q[p].pop_back();
        }
    }
    for (ll x: q[0]) S += x-1;
    for (ll x: q[1]) S += x-1;
    if (C[2]+C[3]>S)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    //T = 1;
    cin >> T;
    while (T--) solve();
}