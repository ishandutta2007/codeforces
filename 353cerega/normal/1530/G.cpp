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


ll n, k;

vector<pair<ll,ll>> ord, ord2;

ll calc(vector<ll> &a, ll p)
{
    ll A = 0;
    for (ll i=0;i<=p;i++) A += a[i]+1;
    return A;
}

void trans0(vector<ll> &a)
{
    if (a.back()!=0)
    {
        ll L = calc(a,0)-1;
        ll R = calc(a,k)-2;
        ord.push_back({L,R});
        a[0] += a[k];
        a[k] = 0;
        for (ll p=1;p<k-p;p++) swap(a[p],a[k-p]);
    }
    for (ll p=1;p<k-p;p++)
    {
        if (a[p]>a[k-p]) break;
        if (a[p]<a[k-p])
        {
            ll L = calc(a,0)-1;
            ll R = calc(a,k)-2;
            ord.push_back({L,R});
            for (ll j=1;j<k-j;j++) swap(a[j],a[k-j]);
            break;
        }
    }
}

void trans2(vector<ll> &a)
{
    while (true)
    {
        ll F = 0;
        for (ll i=2;i<=k;i+=2) if (a[i]!=0) F = 1;
        if (F==0) break;
        ll L = calc(a,0)-1;
        ll R = calc(a,k)-2;
        ord.push_back({L,R});
        a[0] += a[k];
        a[k] = 0;
        for (ll i=1;i<k-i;i++) swap(a[i],a[k-i]);
        L = calc(a,1)-1;
        R = calc(a,k)-1;
        ord.push_back({L,R});
        for (ll i=1;i<k-i;i++) swap(a[i+1],a[k-i+1]);
    }
    while (true)
    {
        ll F = 0;
        for (ll i=1;i<=k;i+=2) if (a[i]!=0) F = 1;
        if (F==0) break;
        ll L = calc(a,0);
        ll R = calc(a,k)-1;
        ord.push_back({L,R});
        a[k+1] += a[1];
        a[1] = 0;
        for (ll i=1;i<k-i;i++) swap(a[i+1],a[k-i+1]);
        L = calc(a,0)-1;
        R = calc(a,k)-2;
        ord.push_back({L,R});
        for (ll i=1;i<k-i;i++) swap(a[i],a[k-i]);
    }
}

void trans1(vector<ll> &a)
{
    while (true)
    {
        ll F = 0;
        for (ll i=1;i<=k;i++) if (a[i]!=0) F = 1;
        if (F==0) return;
        ll L = calc(a,0)-1;
        ll R = calc(a,k)-2;
        ord.push_back({L,R});
        a[0] += a[k];
        a[k] = 0;
        for (ll i=1;i<k-i;i++) swap(a[i],a[k-i]);
        L = calc(a,1)-1;
        R = calc(a,k)-1;
        ord.push_back({L,R});
        for (ll i=1;i<k-i;i++) swap(a[i+1],a[k-i+1]);
    }
}

void trans(vector<ll> &a)
{
    if (a.size()==k+1)
    {
        trans0(a);
        return;
    }
    while (a.size()>k+2)
    {
        if (a.back()==0)
        {
            a.pop_back();
            continue;
        }
        ll p = a.size()-1;
        ll L = calc(a,p-k)-1;
        ll R = calc(a,p)-2;
        ord.push_back({L,R});
        a[p-k] += a[p];
        a.pop_back();
        for (ll i=1;i<k-i;i++) swap(a[p-k+i],a[p-i]);
    }
    if (a.back()!=0)
    {
        ll p = a.size()-1;
        ll L = calc(a,p-k)-1;
        ll R = calc(a,p)-2;
        ord.push_back({L,R});
        a[p-k] += a[p];
        a[p] = 0;
        for (ll i=1;i<k-i;i++) swap(a[p-k+i],a[p-i]);
    }
    if (k%2==1) trans1(a);
    else trans2(a);
}

void solve()
{
    cin >> n >> k;
    vector<ll> a(1), b(1);
    string s;
    cin >> s;
    for (ll i=0;i<n;i++)
    {
        if (s[i]=='1') a.push_back(0);
        else a.back()++;
    }
    cin >> s;
    for (ll i=0;i<n;i++)
    {
        if (s[i]=='1') b.push_back(0);
        else b.back()++;
    }
    if (a.size()!=b.size())
    {
        cout << "-1\n";
        return;
    }
    {
        ll F = 0;
        for (ll i=0;i<a.size();i++)
        {
            if (a[i]!=b[i]) F = 1;
        }
        if (F==0)
        {
            cout << 0 << "\n";
            return;
        }
    }
    if (k==0 or a.size()<=k)
    {
        cout << "-1\n";
        return;
    }
    ord.clear();
    trans(b);
    ord2 = ord;
    ord.clear();
    trans(a);
    {
        ll F = 0;
        for (ll i=0;i<a.size();i++)
        {
            if (a[i]!=b[i]) F = 1;
        }
        if (F==1)
        {
            cout << -1 << "\n";
            return;
        }
    }
    while (ord2.size()>0)
    {
        ord.push_back(ord2.back());
        ord2.pop_back();
    }
    cout << ord.size() << "\n";
    for (ll i=0;i<ord.size();i++)
    {
        cout << ord[i].X+1 << " " << ord[i].Y+1 << "\n";
    }
    ord.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    cin >> T;
    while (T--) solve();
}