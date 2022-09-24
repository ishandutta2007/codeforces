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




void solve()
{
    ll S = 26;
    vector<vector<ll>> C(3,vector<ll>(S+1));
    ll n = 0;
    {
        vector<string> s(3);
        for (ll i=0;i<3;i++) cin >> s[i];
        if (s[0].length()<s[1].length()) swap(s[0],s[1]);
        if (s[0].length()<s[2].length()) swap(s[0],s[2]);
        n = s[0].length();
        for (ll j=0;j<3;j++)
        {
            for (ll i=0;i<s[j].length();i++) C[j][s[j][i]-'A']++;
            C[j][S] = n-s[j].length();
        }
    }
    vector<vector<ll>> A(3);
    ll L = n;
    for (ll j=0;j<S;j++)
    {
        while (L>0)
        {
            vector<pair<ll,ll>> kek(3);
            for (ll i=0;i<3;i++)
            {
                kek[i] = {C[i][j],i};
            }
            sort(kek.begin(),kek.end());
            ll p = kek[1].Y;
            ll p2 = kek[2].Y;
            if (kek[1].X==0) break;
            A[3-p-p2].push_back(j);
            L--;
            C[p][j]--;
            C[p2][j]--;
        }
    }
    vector<pair<ll,ll>> ans;
    for (ll i=0;i<3;i++)
    {
        while (L>0 and C[i][S]>0)
        {
            L--;
            C[i][S]--;
            vector<ll> p;
            if (i==0) p = {1,2};
            if (i==1) p = {0,2};
            if (i==2) p = {0,1};
            vector<ll> cur;
            for (ll x: p)
            {
                for (ll j=0;j<=S;j++)
                {
                    if (C[x][j]>0)
                    {
                        C[x][j]--;
                        cur.push_back(j);
                        break;
                    }
                }
            }
            ans.push_back({cur[0],cur[1]});
        }
    }
    for (ll i=0;i<3;i++)
    {
        for (ll j=0;j<=S;j++)
        {
            while (C[i][j]>0 and A[i].size()>0)
            {
                ans.push_back({A[i].back(),j});
                C[i][j]--;
                A[i].pop_back();
            }
        }
    }
    vector<ll> R(3*L);
    for (ll i=0;i<3;i++)
    {
        ll p = i;
        for (ll j=0;j<=S;j++)
        {
            while (C[i][j]>0)
            {
                R[p] = j;
                p += 3;
                C[i][j]--;
            }
        }
    }
    if (L%2==1)
    {
        ans.push_back({R.back(),R.back()});
        R.pop_back();
    }
    for (ll i=0;i<R.size();i+=2)
    {
        ans.push_back({R[i],R[i+1]});
    }
    cout << ans.size() << "\n";
    for (ll i=0;i<ans.size();i++)
    {
        ll x1 = ans[i].X;
        ll x2 = ans[i].Y;
        x1 = min(x1,S-1);
        x2 = min(x2,S-1);
        cout << char(x1+'A') << char(x2+'A') << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    //cin >> T;
    T = 1;
    while (T--) solve();
}