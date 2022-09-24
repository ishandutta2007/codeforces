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


ll a, b, c;
vector<ll> kek;

ll calc(ll C0, ll C1, ll D, ll E, ll s)
{
    ll A = 0;
    ll W = 0;
    ll q = s;
    ll P = 0;
    ll z = 0;
    while (true)
    {
        if (q==0 and C0==0 and D==0 and E==0) return A;
        if (q==1 and C1==0) return A;
        if (q==1)
        {
            q = 1-q;
            W += b;
            C1--;
            A = max(A,W);
            continue;
        }
        q = 1-q;
        if (C1!=0 and C0!=0)
        {
            z++;
            W += a;
            C0--;
            A = max(A,W);
            continue;
        }
        if (C1!=0)
        {
            W -= c;
            if (D>0 and kek[P]<=z)
            {
                P++;
                D--;
                C1++;
            }
            else E--;
            continue;
        }
        if (C0!=0) A = max(A,W+a);
        if (D>0 and kek[P]<=z)
        {
            P++;
            D--;
            C1++;
            W -= c;
            continue;
        }
        E--;
        W -= c;
    }
}

void solve()
{
    ll n;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    ll k = 0;
    ll p = 2;
    ll C0 = 0, C1 = 0;
    ll prv = -1;
    kek.clear();
    for (ll i=0;i<n;i++)
    {
        if (s[i]=='0' and (i==0 or s[i-1]!=s[i])) prv = i;
        if (i>0 and s[i]==s[i-1])
        {
            if (s[i]=='0') C0++;
            else C1++;
        }
        if (prv!=0 and s[i]=='0' and i+1!=n and s[i+1]=='1')
        {
            kek.push_back(i-prv);
        }
        if (s[i]-'0'!=p)
        {
            k++;
            p = s[i]-'0';
        }
    }
    sort(kek.begin(),kek.end());
    for (ll i=1;i<kek.size();i++)
    {
        kek[i] += kek[i-1];
    }
    ll D = 0;
    if (k>=2) D = (k-2)/2;
    if (p==1) D = (k-1)/2;
    ll E = 0;
    if (p==0) E = 1;
    if (k>1 and p%2!=k%2) E++;
    ll A = calc(C0,C1,D,E,0);
    A = max(A,calc(C0,C1,D,E,1));
    cout << A << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}