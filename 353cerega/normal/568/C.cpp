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

inline ll mul(ll a, ll b, ll M)
{
    if (a*b<M) return a*b;
    else return a*b%M;
}

inline ll pew(ll a, ll b, ll M)
{
    ll res = 1;
    while (b)
    {
        if (b&1LL) res = mul(res,a,M);
        a = mul(a,a,M);
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


ll g[410][410];

void solve()
{
    string s;
    cin >> s;
    ll K = s.length();
    ll n, m;
    cin >> n >> m;
    ll N = 2*n;
    for (ll i=0;i<N;i++)
    {
        for (ll j=0;j<N;j++) g[i][j] = 0;
    }
    for (ll i=0;i<m;i++)
    {
        ll p1, p2;
        char c1, c2;
        cin >> p1 >> c1 >> p2 >> c2;
        p1--, p2--;
        ll w1 = 0, w2 = 0;
        if (c1=='V') w1++;
        if (c2=='V') w2++;
        g[p1*2+w1][p2*2+w2] = 1;
        g[p2*2+1-w2][p1*2+1-w1] = 1;
    }
    for (ll i=0;i<N;i++)
    {
        for (ll j=0;j<N;j++)
        {
            for (ll k=0;k<N;k++)
            {
                if (g[i][k]==1 and g[k][j]==1) g[i][j] = 1;
            }
        }
    }
    string W;
    cin >> W;
    ll F = 1;
    for (ll i=0;i+1<K;i++)
    {
        if (s[i]!=s[i+1]) F = 0;
    }
    ll mn = 0;
    if (s[0]=='V') mn = 1;
    ll mx = 1-mn;
    vector<ll> cols = {mn,mx};
    vector<ll> st(2,K);
    for (ll i=K-1;i>=0;i--)
    {
        if (s[i]=='C') st[0] = i;
        else st[1] = i;
    }
    for (ll d=0;d<=n and (d==0 or F==0);d++)
    {
        vector<ll> col(n,-1);
        ll bad = 0;
        for (ll i=0;i<n-d;i++)
        {
            ll C = 0;
            if (s[W[i]-'a']=='V') C = 1;
            if (col[i]!=-1 and C!=col[i])
            {
                bad = 1;
                break;
            }
            col[i] = C;
            for (ll j=0;j<N;j++)
            {
                if (g[i*2+C][j]==0) continue;
                ll C2 = j&1;
                if (col[j/2]!=-1 and col[j/2]!=C2)
                {
                    bad = 1;
                    break;
                }
                col[j/2] = C2;
            }
        }
        if (bad==1) continue;
        if (d==0)
        {
            cout << W << "\n";
            return;
        }
        ll mn0 = K, mn1 = K;
        for (ll p=K-1;p>=W[n-d]-'a'+1;p--)
        {
            if (s[p]=='C') mn0 = p;
            else mn1 = p;
        }
        if (mn0==K and mn1==K) continue;
        ll r = 0;
        if (mn0>mn1)
        {
            swap(mn0,mn1);
            r = 1-r;
        }
        vector<ll> col2 = col;
        {
            ll C = r;
            ll i = n-d;
            if (col[i]!=-1 and C!=col[i])
            {
                bad = 1;
            }
            col[i] = C;
            for (ll j=0;j<2*n;j++)
            {
                if (g[i*2+C][j]==0) continue;
                ll C2 = j&1;
                if (col[j/2]!=-1 and col[j/2]!=C2)
                {
                    bad = 1;
                    break;
                }
                col[j/2] = C2;
            }
        }
        for (ll i=n-d+1;i<n;i++)
        {
            ll ok = 0;
            for (ll C: cols)
            {
                if (col[i]!=-1 and C!=col[i]) continue;
                ll FF = 0;
                for (ll j=0;j<N;j++)
                {
                    if (g[i*2+C][j]==0) continue;
                    ll C2 = j&1;
                    if (col[j/2]!=-1 and col[j/2]!=C2)
                    {
                        FF = 1;
                        break;
                    }
                }
                if (FF==1) continue;
                col[i] = C;
                for (ll j=0;j<2*n;j++)
                {
                    if (g[i*2+C][j]==0) continue;
                    ll C2 = j&1;
                    col[j/2] = C2;
                }
                ok = 1;
                break;
            }
            if (ok==0)
            {
                bad = 1;
            }
        }
        if (bad==0)
        {
            for (ll i=0;i<n-d;i++)
            {
                cout << W[i];
            }
            cout << char('a'+mn0);
            for (ll i=n-d+1;i<n;i++)
            {
                cout << char('a'+st[col[i]]);
            }
            cout << "\n";
            return;
        }
        bad = 0;
        col = col2;
        if (mn1==K) continue;
        {
            ll C = 1-r;
            ll i = n-d;
            if (col[i]!=-1 and C!=col[i])
            {
                bad = 1;
            }
            col[i] = C;
            for (ll j=0;j<N;j++)
            {
                if (g[i*2+C][j]==0) continue;
                ll C2 = j&1;
                if (col[j/2]!=-1 and col[j/2]!=C2)
                {
                    bad = 1;
                    break;
                }
                col[j/2] = C2;
            }
        }
        for (ll i=n-d+1;i<n;i++)
        {
            ll ok = 0;
            for (ll C: cols)
            {
                if (col[i]!=-1 and C!=col[i]) continue;
                ll FF = 0;
                for (ll j=0;j<N;j++)
                {
                    if (g[i*2+C][j]==0) continue;
                    ll C2 = j&1;
                    if (col[j/2]!=-1 and col[j/2]!=C2)
                    {
                        FF = 1;
                        break;
                    }
                }
                if (FF==1) continue;
                col[i] = C;
                for (ll j=0;j<2*n;j++)
                {
                    if (g[i*2+C][j]==0) continue;
                    ll C2 = j&1;
                    col[j/2] = C2;
                }
                ok = 1;
                break;
            }
            if (ok==0)
            {
                bad = 1;
                break;
            }
        }
        if (bad==0)
        {
            for (ll i=0;i<n-d;i++)
            {
                cout << W[i];
            }
            cout << char('a'+mn1);
            for (ll i=n-d+1;i<n;i++)
            {
                cout << char('a'+st[col[i]]);
            }
            cout << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}