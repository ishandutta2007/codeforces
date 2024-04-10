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




void solve2(ll n)
{
    ll n2 = (1LL<<n);
    vector<ll> A(n);
    for (ll m=0;m<n2;m++)
    {
        vector<ll> cur(n), dir(n), sz(n);
        for (ll i=0;i<n;i++)
        {
            cur[i] = i;
            sz[i] = 1;
            dir[i] = m/(1LL<<i)%2;
        }
        while (cur.size()>1)
        {
            dir[0] = 0;
            dir[cur.size()-1] = 1;
            for (ll b=0;b+1<cur.size();b++)
            {
                if (dir[b]!=0 or dir[b+1]!=1) continue;
                ll S = sz[b+1]+sz[b];
                ll num = cur[b];
                ll d = dir[b];
                if (sz[b+1]>=sz[b]) num = cur[b+1], d = dir[b+1];
                vector<ll> cur2, dir2, sz2;
                for (ll i=0;i<b;i++)
                {
                    cur2.push_back(cur[i]);
                    dir2.push_back(dir[i]);
                    sz2.push_back(sz[i]);
                }
                cur2.push_back(num);
                dir2.push_back(d);
                sz2.push_back(S);
                for (ll i=b+2;i<cur.size();i++)
                {
                    cur2.push_back(cur[i]);
                    dir2.push_back(dir[i]);
                    sz2.push_back(sz[i]);
                }
                cur = cur2;
                dir = dir2;
                sz = sz2;
                break;
            }
        }
        A[cur[0]]++;
    }
    for (ll i=0;i<n;i++) cout << A[i] << " ";
    cout << endl;
}

unordered_map<int,int> val;

ll calc(ll L, ll d)
{
    if (L<=2) return 1;
    if (L==3 and d==1) return 1;
    if (val.count(L*mod+d)==0)
    {
        ll x = 0;
        if (L%2!=d%2 or L<d+2)
        {
            x = 2*calc(L-1,d)%mod;
        }
        else
        {
            x = (2*calc(L-1,d)-calc((L+d)/2-d,d)+mod)%mod;
        }
        val[L*mod+d] = x;
        return x;
    }
    return val[L*mod+d];
}

void solve(ll n)
{
    //ll n;
    //cin >> n;
    if (n==1)
    {
        cout << 1 << "\n";
        return;
    }
    vector<ll> p2(n+1), pp(n+1);
    p2[0] = pp[0] = 1;
    pp[1] = pew(2,mod-2);
    for (ll i=1;i<=n;i++) p2[i] = p2[i-1]*2%mod, pp[i] = pp[i-1]*pp[1]%mod;
    ll S = 0;
    vector<ll> A(n+1);
    ll j = n;
    for (ll i=n;i>=2;i--)
    {
        ll x = pp[i-i/2];
        if (i==n) x = x*2%mod;
        while ((j+2)/2>i)
        {
            S = (S+A[j])%mod;
            j--;
        }
        A[i] = (x*(mod+1-S)+mod)%mod;
    }
    for (ll i=1;i<=n;i++) cout << A[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        solve(n);
    }
}