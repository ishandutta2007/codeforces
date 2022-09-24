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



int main()
{
    ios_base::sync_with_stdio(false);
    set<pair<ll,ll>> kek;
    ll n, m, L, R;
    cin >> n >> m >> L >> R;
    ll mx = max(m,n);
    vector<vector<ll>> d(mx+1);
    for (ll i=1;i<=mx;i++)
    {
        for (ll j=i;j<=mx;j+=i)
        {
            d[j].push_back(i);
        }
    }
    ll A = m+1;
    ll B = m;
    vector<ll> val(m+1);
    for (ll x=1;x<=n;x++)
    {
        ll F = 0;
        while ((A-1)*x>=L)
        {
            A--;
            for (ll q: d[A])
            {
                if (val[q]!=-1)
                {
                    kek.erase({q,val[q]});
                }
                val[q] = A;
                kek.insert({q,val[q]});
            }
        }
        while (B*x>R and B>0)
        {
            for (ll q: d[B])
            {
                if (val[q]==B)
                {
                    kek.erase({q,B});
                    val[q] = -1;
                }
            }
            B--;
        }
        if (A<=B)
        {
            for (ll q: d[x])
            {
                ll M = n/(x/q);
                if (M==q) continue;
                auto it = kek.lower_bound({q+1,0});
                if (it==kek.end() or it->X>M) continue;
                pair<ll,ll> C = *it;
                ll y = C.Y;
                ll y2 = y/C.X*q;
                ll x2 = x*y/y2;
                cout << x << " " << y << " " << x2 << " " << y2 << "\n";
                F = 1;
                break;
            }
        }
        if (F==0) cout << -1 << "\n";
    }
}