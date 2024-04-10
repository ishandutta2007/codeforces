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

__int128 gcd(__int128 a, __int128 b)
{
    if (a<b) swap(a,b);
    if (b==0) return a;
    return gcd(b,a%b);

}

__int128 get()
{
    string s;
    cin >> s;
    __int128 x = 0;
    for (ll i=0;i<s.length();i++) x = x*10+(s[i]-'0');
    return x;
}

void fin(__int128 x)
{
    vector<ll> a;
    while (x>0)
    {
        a.push_back(x%10);
        x /= 10;
    }
    reverse(a.begin(),a.end());
    for (ll i=0;i<a.size();i++) cout << a[i];
    cout << " ";
}

set<__int128> pr0;

void add(__int128 x)
{
    if (x==1) return;
    if (pr0.count(x)!=0) return;
    for (auto q: pr0)
    {
        __int128 x2 = gcd(x,q);
        if (x2!=1)
        {
            pr0.erase(q);
            add(q/x2);
            add(x/x2);
            add(x2);
            return;
        }
    }
    pr0.insert(x);
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<__int128> a(n);
    vector<__int128> b(m);
    vector<ll> w(n), w2(m);
    ll F = 0, F2 = 0;
    for (ll i=0;i<n;i++)
    {
        a[i] = get();
        add(a[i]);
        if (a[i]==1) F = 1;
    }
    for (ll i=0;i<m;i++)
    {
        b[i] = get();
        add(b[i]);
        if (b[i]==1) F2 = 1;
    }
    if (F==1 and F2==1)
    {
        cout << "YES\n";
        cout << 1 << " " << 1 << "\n" << 1 << "\n" << 1 << "\n";
        return;
    }
    vector<__int128> pr;
    for (__int128 x: pr0)
    {
        pr.push_back(x);
    }
    ll sz = pr.size();
    vector<vector<pair<ll,ll>>> A(n), B(m);
    for (ll i=0;i<n;i++)
    {
        __int128 x = a[i];
        for (ll z=0;z<sz;z++)
        {
            while (gcd(x,pr[z])!=1)
            {
                x /= pr[z];
                if (A[i].size()==0 or A[i].back().X!=z) A[i].push_back({z,1});
                else A[i].back().Y++;
            }
        }
    }
    for (ll i=0;i<m;i++)
    {
        __int128 x = b[i];
        for (ll z=0;z<sz;z++)
        {
            while (gcd(x,pr[z])!=1)
            {
                x /= pr[z];
                if (B[i].size()==0 or B[i].back().X!=z) B[i].push_back({z,1});
                else B[i].back().Y++;
            }
        }
    }
    while (true)
    {
        ll D = 0;
        vector<ll> cur(sz);
        for (ll i=0;i<m;i++)
        {
            if (w2[i]==1) continue;
            for (ll z=0;z<B[i].size();z++)
            {
                cur[B[i][z].X] = max(cur[B[i][z].X],B[i][z].Y);
            }
        }
        for (ll i=0;i<n;i++)
        {
            if (w[i]==1) continue;
            ll W = 0;
            for (ll z=0;z<A[i].size();z++)
            {
                if (cur[A[i][z].X]<A[i][z].Y) W = 1;
            }
            if (W!=0)
            {
                w[i] = 1;
                D = 1;
            }
        }
        swap(a,b);
        swap(n,m);
        swap(w,w2);
        swap(A,B);
        for (ll i=0;i<sz;i++) cur[i] = 0;
        for (ll i=0;i<m;i++)
        {
            if (w2[i]==1) continue;
            for (ll z=0;z<B[i].size();z++)
            {
                cur[B[i][z].X] = max(cur[B[i][z].X],B[i][z].Y);
            }
        }
        for (ll i=0;i<n;i++)
        {
            if (w[i]==1) continue;
            ll W = 0;
            for (ll z=0;z<A[i].size();z++)
            {
                if (cur[A[i][z].X]<A[i][z].Y) W = 1;
            }
            if (W!=0)
            {
                w[i] = 1;
                D = 1;
            }
        }
        swap(a,b);
        swap(n,m);
        swap(w,w2);
        swap(A,B);
        ll F0 = 0;
        for (ll z=0;z<n;z++)
        {
            if (w[z]==0) F0 = 1;
        }
        if (F0==0)
        {
            cout << "NO\n";
            return;
        }
        F0 = 0;
        for (ll z=0;z<m;z++)
        {
            if (w2[z]==0) F0 = 1;
        }
        if (F0==0)
        {
            cout << "NO\n";
            return;
        }
        if (D==0)
        {
            cout << "YES\n";
            ll k = 0, k2 = 0;
            for (ll i=0;i<n;i++)
            {
                if (w[i]==0) k++;
            }
            for (ll i=0;i<m;i++) if (w2[i]==0) k2++;
            cout << k << " " << k2 << "\n";
            for (ll i=0;i<n;i++)
            {
                if (w[i]==0) fin(a[i]);
            }
            cout << "\n";
            for (ll i=0;i<m;i++)
            {
                if (w2[i]==0) fin(b[i]);
            }
            cout << "\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) solve();
}