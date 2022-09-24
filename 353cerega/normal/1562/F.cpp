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

mt19937 gen(time(0));
uniform_int_distribution<int> uid(0,mod);

ll n;

ll mx = 300000;
vector<ll> d(mx+1), pr;

void prec()
{
    d[1] = 1;
    for (ll i=2;i<=mx;i++)
    {
        if (d[i]==0)
        {
            d[i] = i;
            pr.push_back(i);
        }
        for (ll j=0;j<pr.size() and pr[j]<=d[i] and pr[j]*i<=mx;j++)
        {
            d[pr[j]*i] = pr[j];
        }
    }
}

ll ask(ll a, ll b)
{
    cout << "? " << a+1 << " " << b+1 << endl;
    ll x;
    cin >> x;
    return x;
}

ll get(ll i)
{
    ll p = uid(gen)%n;
    while (p==i) p = uid(gen)%n;
    ll R = ask(i,p);
    for (ll z=0;z<30;z++)
    {
        p = uid(gen)%n;
        while (p==i) p = uid(gen)%n;
        ll R2 = ask(i,p);
        R = gcd(R,R2);
    }
    return R;
}

void solve2()
{
    vector<ll> a(3);
    a[0] = ask(0,1);
    a[1] = ask(0,2);
    a[2] = ask(1,2);
    ll M = max(a[0],a[1]);
    M = max(M,a[2]);
    ll L = 0, R = mx;
    while (R-L>1)
    {
        ll x = (R+L)/2;
        if (x*x+x>M) R = x;
        else L = x;
    }
    vector<ll> Q = {L-1,L,L+1};
    while (true)
    {
        vector<ll> b(3);
        b[0] = Q[0]*Q[1]/gcd(Q[0],Q[1]);
        b[1] = Q[0]*Q[2]/gcd(Q[0],Q[2]);
        b[2] = Q[1]*Q[2]/gcd(Q[1],Q[2]);
        ll ok = 1;
        for (ll j=0;j<3;j++)
        {
            if (a[j]!=b[j]) ok = 0;
        }
        if (ok==1)
        {
            cout << "!";
            for (ll i=0;i<3;i++) cout << " " << Q[i];
            cout << endl;
            return;
        }
        next_permutation(Q.begin(),Q.end());
    }
}

void solve()
{
    cin >> n;
    vector<ll> a(n);
    if (n==3)
    {
        solve2();
        return;
    }
    if (n<120)
    {
        for (ll i=0;i<n;i++)
        {
            a[i] = get(i);
        }
        cout << "!";
        for (ll i=0;i<n;i++)
        {
            cout << " " << a[i];
        }
        cout << endl;
        return;
    }
    ll p;
    while (true)
    {
        p = uid(gen)%n;
        while (a[p]!=0) p = uid(gen)%n;
        a[p] = get(p);
        if (d[a[p]]==a[p] and a[p]>=n/2) break;
    }
    for (ll i=0;i<n;i++)
    {
        if (i==p) continue;
        a[i] = ask(i,p)/a[p];
        if (a[i]==2) a[i] = get(i);
    }

    cout << "!";
    for (ll i=0;i<n;i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    prec();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}