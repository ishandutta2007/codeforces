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
    string s;
    cin >> s;
    ll Q = 0;
    ll n = s.length();
    vector<ll> a(n);
    for (ll i=0;i<n;i++)
    {
        a[i] = s[i]-'0';
        Q += a[i];
    }
    /*if (Q==5)
    {
        ll F = 0;
        for (ll j=1;j<=5;j++)
        {
            if (a[n-j]!=1) F = 1;
        }
        if (F==0)
        {
            cout << 2 << "\n";
            cout << 1 << " " << n-1 << "\n";
            cout << n << " " << n << "\n";
            return;
        }
    }*/
    if (Q==0)
    {
        cout << -1 << "\n";
        return;
    }
    ll L = 0;
    ll B = 1;
    {
        while (B<Q) B *= 2;
        L = B-Q;
    }
    while (true)
    {
        vector<pair<ll,ll>> A;
        ll i = 0;
        while (i<n)
        {
            if (a[i]==0)
            {
                A.push_back({i,i});
                i++;
                continue;
            }
            ll S = 1;
            ll k = 1;
            ll j = i+1;
            while (true)
            {
                if (j==n)
                {
                    A.push_back({i,j-1});
                    i = j;
                    L -= (S-k);
                    break;
                }
                ll S2 = S*2+a[j];
                ll k2 = k+a[j];
                if (L<S2-k2)
                {
                    A.push_back({i,j-1});
                    i = j;
                    L -= (S-k);
                    break;
                }
                S = S2;
                k = k2;
                j++;
            }
        }
        if (L!=0)
        {
            B *= 2;
            L = B-Q;
            continue;
        }
        cout << A.size() << "\n";
        for (ll i=0;i<A.size();i++)
        {
            cout << A[i].X+1 << " " << A[i].Y+1 << "\n";
        }
        return;
    }
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