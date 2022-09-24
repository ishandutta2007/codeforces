#pragma GCC optimize("Ofast")
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



int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i].X;
        a[i].Y = 1;
    }
    sort(a.begin(),a.end());
    {
        vector<pair<ll,ll>> a2;
        for (ll i=0;i<a.size();i++)
        {
            if (a2.size()>0 and a2.back().X==a[i].X) a2.back().Y += a[i].Y;
            else a2.push_back(a[i]);
        }
        a = a2;
    }
    vector<vector<vector<int>>> A(20);
    for (ll z=0;z<a.size();z++)
    {
        ll Q = a[z].Y;
        ll j = 0;
        while ((1<<j)<=Q) j++;
        vector<int> C(1<<j);
        for (ll i=0;i<=Q;i++) C[i] = 1;
        A[j].push_back(C);
    }
    for (ll b=0;b+1<20;b++)
    {
        ll sz = (1LL<<(b+1));
        while (A[b].size()>0)
        {
            vector<int> A0 = A[b].back();
            A[b].pop_back();
            A0.resize(sz);
            if (A[b].size()==0)
            {
                A[b+1].push_back(A0);
                continue;
            }
            vector<int> A1 = A[b].back();
            A[b].pop_back();
            A1.resize(sz);
            fft(A0,false);
            fft(A1,false);
            for (ll z=0;z<sz;z++)
            {
                A0[z] = (A0[z]*1LL*A1[z])%mod;
            }
            fft(A0,true);
            ll F = 0;
            for (ll z=sz/2;z<sz;z++)
            {
                if (A0[z]!=0) F = 1;
            }
            if (F==1) A[b+1].push_back(A0);
            else
            {
                A0.resize(sz/2);
                A[b].push_back(A0);
            }
        }
    }
    cout << A[19][0][n/2] << "\n";
}