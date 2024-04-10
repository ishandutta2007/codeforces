#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = double;

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


/*void fft (vector<int> & a, bool invert) {
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



void solve()
{
    ll n;
    cin >> n;
    ll sz = 52;
    vector<vector<vector<ll>>> a(n,vector<vector<ll>>(sz,vector<ll>(2,-1)));
    for (ll i=0;i<n;i++)
    {
        string s;
        cin >> s;
        ll m = s.length();
        for (ll j=0;j<m;j++)
        {
            ll x;
            if (s[j]<='z' and s[j]>='a')
            {
                x = s[j]-'a';
            } else x = s[j]-'A'+26;
            if (a[i][x][1]!=-1) a[i][x][0] = a[i][x][1];
            a[i][x][1] = j;
        }
    }
    ll n2 = (1<<n);
    ll N = n2*sz;
    vector<vector<ll>> nxt(N);
    vector<ll> d(N), dp(N,-1000000), prv(N,-1);
    for (ll i=0;i<sz;i++)
    {
        for (ll msk=0;msk<n2;msk++)
        {
            ll st = i*n2+msk;
            vector<ll> p(n);
            ll ok = 1;
            for (ll b=0;b<n;b++)
            {
                if (msk&(1<<b)) p[b] = a[b][i][1];
                else p[b] = a[b][i][0];
                if (p[b]==-1) ok = 0;
            }
            if (ok==0)
            {
                d[st] = -1;
                continue;
            }
            for (ll j=0;j<sz;j++)
            {
                ll msk2 = 0;
                ll ok2 = 1;
                for (ll b=0;b<n;b++)
                {
                    ll k = 0;
                    while (k<2 and a[b][j][k]<=p[b]) k++;
                    if (k==2)
                    {
                        ok2 = 0;
                        break;
                    }
                    msk2 += (1<<b)*k;
                }
                if (ok2==0) continue;
                ll q = j*n2+msk2;
                d[q]++;
                nxt[st].push_back(q);
            }
        }
    }
    vector<ll> q;
    for (ll i=0;i<N;i++)
    {
        if (d[i]==0)
        {
            q.push_back(i);
            dp[i] = 1;
        }
    }
    for (ll z=0;z<q.size();z++)
    {
        ll u = q[z];
        for (ll v: nxt[u])
        {
            d[v]--;
            if (d[v]==0) q.push_back(v);
            if (dp[v]<dp[u]+1)
            {
                dp[v] = dp[u]+1;
                prv[v] = u;
            }
        }
    }
    ll mx = 0;
    ll p = -1;
    for (ll i=0;i<N;i++)
    {
        if (mx<dp[i])
        {
            p = i;
            mx = dp[i];
        }
    }
    cout << mx << "\n";
    string A;
    while (p!=-1)
    {
        ll x = p/n2;
        if (x<26) A += 'a'+x;
        else A += 'A'+x-26;
        p = prv[p];
    }
    reverse(A.begin(),A.end());
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