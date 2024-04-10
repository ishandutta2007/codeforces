#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
const ll mod2 = 998244353;

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

vector<ll> d, pr;

set<ll> kek;
map<pair<ll,ll>,ll> lul;

ll b = 29, b2 = 41;
vector<ll> p, p2;
pair<ll,ll> H = {0,0};

void add(ll q)
{
    if (kek.count(q)!=0)
    {
        kek.erase(q);
        H.X -= p[q];
        H.Y -= p2[q];
        if (H.X<0) H.X += mod;
        if (H.Y<0) H.Y += mod2;
    }
    else
    {
        kek.insert(q);
        H.X += p[q];
        H.Y += p2[q];
        if (H.X>=mod) H.X -= mod;
        if (H.Y>=mod2) H.Y -= mod2;
    }
}

ll solve(ll n)
{
    p.resize(n+1);
    p2.resize(n+1);
    p[0] = p2[0] = 1;
    for (ll i=1;i<=n;i++)
    {
        p[i] = p[i-1]*b%mod;
        p2[i] = p2[i-1]*b2%mod2;
    }
    for (ll i=2;i<=n;i++)
    {
        if (d[i]==0)
        {
            d[i] = i;
            pr.push_back(i);
        }
        for (ll j=0;j<pr.size() and pr[j]<=d[i] and pr[j]*i<=n;j++)
        {
            d[pr[j]*i] = pr[j];
        }
    }
    for (ll i=1;i<=n;i++)
    {
        if (i%2==n%2)
        {
            ll x = i;
            while (x>1)
            {
                ll q = d[x];
                add(q);
                x /= q;
            }

        }
    }
    if (kek.size()==0)
    {
        cout << n << "\n";
        for (ll i=1;i<=n;i++) cout << i << " ";
        return 1;
    }
    ll A = 0;
    set<ll> keks;
    pair<ll,ll> h = {0,0};
    for (ll i=1;i<=n;i++)
    {
        ll x = i;
        while (x>1)
        {
            ll q = d[x];
            if (keks.count(q)!=0)
            {
                if (kek.count(q)!=0) A--;
                keks.erase(q);
                h.X -= p[q];
                h.Y -= p2[q];
                if (h.X<0) h.X += mod;
                if (h.Y<0) h.Y += mod2;
            }
            else
            {
                if (kek.count(q)!=0) A++;
                keks.insert(q);
                h.X += p[q];
                h.Y += p2[q];
                if (h.X>=mod) h.X -= mod;
                if (h.Y>=mod2) h.Y -= mod2;
            }
            x /= q;
        }
        lul[h] = i;
        if (A==kek.size() and keks.size()==A)
        {
            cout << n-1 << "\n";
            for (ll j=1;j<=n;j++)
            {
                if (i==j) continue;
                cout << j << " ";
            }
            return 1;
        }
    }
    if (n%2==0)
    {
        cout << n-2 << "\n";
        for (ll i=1;i<=n;i++)
        {
            if (i!=2 and i!=n/2) cout << i << " ";
        }
        return 1;
    }
    return 0;
}

ll solve2(ll n, ll B)
{
    if (B==n)
    {
        for (ll i=1;i<=B;i++)
        {
            ll x = i;
            while (x>1)
            {
                ll q = d[x];
                add(q);
                x /= q;
            }
        }
    } else
    {
        for (ll i=B+1;i<=B+1;i++)
        {
            ll x = i;
            while (x>1)
            {
                ll q = d[x];
                add(q);
                x /= q;
            }
        }
    }
    if (lul.count(H)==0) return 0;
    ll w = lul[H];
    cout << n-2 << "\n";
    for (ll j=1;j<=n;j++)
    {
        if (w==j or j==B) continue;
        cout << j << " ";
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    d.resize(n+1);
    if (solve(n)) return 0;
    for (ll j=n;j>1;j--)
    {
        if (solve2(n,j)) return 0;
        if (d[j]==j) break;
    }
    cout << n-3 << "\n";
    for (ll i=1;i<=n;i++)
    {
        if (i!=2 and i!=n/2 and i!=n) cout << i << " ";
    }
    return 0;
}