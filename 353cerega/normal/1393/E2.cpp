//#pragma GCC optimize("Ofast")
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

const ll mx = 1000010;
vector<ll> p(mx+1), p2(mx+1);

ll b = 29, b2 = 41;
ll n;
vector<vector<pair<ll,ll>>> pr, suf;
vector<vector<ll>> ord;
vector<string> s;

ll check(ll i, ll j, ll j2)
{
    ll sz = pr[i].size()-1;
    ll sz2 = pr[i+1].size()-1;
    if (j!=-1) sz--;
    if (j2!=-1) sz2--;
    ll L = 0, R = min(sz,sz2)+1;
    while (R-L>1)
    {
        ll M = (L+R)/2;
        pair<ll,ll> H = {0,0}, H2 = {0,0};
        if (j==-1 or M<=j) H = pr[i][M];
        else
        {
            H.X = (pr[i][j].X+suf[i][j+1].X-suf[i][M+1].X+mod)%mod;
            H.Y = (pr[i][j].Y+suf[i][j+1].Y-suf[i][M+1].Y+mod2)%mod2;
        }
        if (j2==-1 or M<=j2) H2 = pr[i+1][M];
        else
        {
            H2.X = (pr[i+1][j2].X+suf[i+1][j2+1].X-suf[i+1][M+1].X+mod)%mod;
            H2.Y = (pr[i+1][j2].Y+suf[i+1][j2+1].Y-suf[i+1][M+1].Y+mod2)%mod2;
        }
        if (H.X==H2.X and H.Y==H2.Y) L = M;
        else R = M;
    }
    if (L==sz) return 1;
    if (L==sz2) return 0;
    char ch, ch2;
    if (j==-1 or L<j) ch = s[i][L];
    else ch = s[i][L+1];
    if (j2==-1 or L<j2) ch2 = s[i+1][L];
    else ch2 = s[i+1][L+1];
    if (ch<=ch2) return 1;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    p[0] = p2[0] = 1;
    for (ll i=1;i<=mx;i++)
    {
        p[i] = p[i-1]*b%mod;
        p2[i] = p2[i-1]*b2%mod2;
    }
    cin >> n;
    s.resize(n);
    pr.resize(n);
    suf.resize(n);
    vector<vector<ll>> dp(n);
    for (ll i=0;i<n;i++)
    {
        cin >> s[i];
        ll sz = s[i].length();
        pr[i].resize(sz+1);
        suf[i].resize(sz+1);
        dp[i].resize(sz+1);
        if (i==0)
        {
            for (ll j=0;j<=sz;j++) dp[i][j] = 1;
        }
        pr[i][0] = {0,0};
        for (ll j=0;j<sz;j++)
        {
            pr[i][j+1].X = (pr[i][j].X+(s[i][j]-'a')*p[j])%mod;
            pr[i][j+1].Y = (pr[i][j].Y+(s[i][j]-'a')*p2[j])%mod2;
        }
        suf[i][sz] = {0,0};
        for (ll j=sz-1;j>0;j--)
        {
            suf[i][j].X = (suf[i][j+1].X+p[j-1]*(s[i][j]-'a'))%mod;
            suf[i][j].Y = (suf[i][j+1].Y+p2[j-1]*(s[i][j]-'a'))%mod2;
        }
        vector<ll> L, R;
        vector<ll> cur;
        for (ll j=0;j<sz;j++)
        {
            cur.push_back(j);
            if (j==sz-1)
            {
                for (ll x: cur) L.push_back(x);
                cur.clear();
                L.push_back(-1);
                continue;
            }
            if (s[i][j]<s[i][j+1])
            {
                for (ll x: cur) R.push_back(x);
                cur.clear();
                continue;
            }
            if (s[i][j]>s[i][j+1])
            {
                for (ll x: cur) L.push_back(x);
                cur.clear();
                continue;
            }
        }
        while (R.size()>0)
        {
            L.push_back(R.back());
            R.pop_back();
        }
        ord.push_back(L);
    }
    for (ll i=0;i+1<n;i++)
    {
        ll q = 0, q2 = 0;
        ll S = 0;
        while (q<ord[i].size() or q2<ord[i+1].size())
        {
            if (q2==ord[i+1].size())
            {
                S = (S+dp[i][q])%mod;
                q++;
                continue;
            }
            if (q==ord[i].size())
            {
                dp[i+1][q2] = S;
                q2++;
                continue;
            }
            if (check(i,ord[i][q],ord[i+1][q2]))
            {
                S = (S+dp[i][q])%mod;
                q++;
            }
            else
            {
                dp[i+1][q2] = S;
                q2++;
            }
        }
    }
    ll ans = 0;
    for (ll i=0;i<ord[n-1].size();i++)
    {
        ans = (ans+dp[n-1][i])%mod;
    }
    cout << ans << endl;
}