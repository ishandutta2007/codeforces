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




void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    set<ll> pos;
    vector<vector<ll>> Q(q,vector<ll>(2));
    vector<ld> pr(q);
    pos.insert(0);
    pos.insert(n);
    for (ll i=0;i<q;i++)
    {
        cin >> Q[i][0] >> Q[i][1];
        Q[i][0]--;
        pos.insert(Q[i][0]);
        pos.insert(Q[i][1]);
        cin >> pr[i];
    }
    ll S = 0;
    {
        vector<ll> pos2;
        for (ll x: pos) pos2.push_back(x);
        S = pos2.size()-1;
        vector<ll> a2(S);
        map<ll,ll> num;
        for (ll i=0;i<=S;i++)
        {
            num[pos2[i]] = i;
            if (i!=S)
            {
                for (ll j=pos2[i];j<pos2[i+1];j++)
                {
                    a2[i] = max(a2[i],a[j]);
                }
            }
        }
        n = S;
        a = a2;
        for (ll i=0;i<q;i++)
        {
            Q[i][0] = num[Q[i][0]];
            Q[i][1] = num[Q[i][1]];
        }
    }
    vector<pair<ll,ll>> ord(q);
    for (ll i=0;i<q;i++) ord[i] = {Q[i][1]-Q[i][0],i};
    sort(ord.begin(),ord.end());
    vector<vector<ld>> P(n,vector<ld>(1,1.0));
    for (ll j=0;j<q;j++)
    {
        ll p = ord[j].Y;
        ll L = Q[p][0];
        ll R = Q[p][1];
        ld Pr = pr[p];
        for (ll i=L+1;i<R;i++)
        {
            if (P[i].size()==0) continue;
            if (a[i]>a[L])
            {
                swap(a[i],a[L]);
                swap(P[i],P[L]);
            }
            ll sz = P[L].size();
            ll sz2 = a[i]-a[L];
            sz2 += P[i].size();
            sz = max(sz,sz2);
            vector<ld> P2(sz);
            for (ll x=0;x<P[L].size();x++)
            {
                for (ll y=0;y<P[i].size();y++)
                {
                    ll w = max(x,y-a[L]+a[i]);
                    P2[w] += P[L][x]*P[i][y];
                }
            }
            P[L] = P2;
            P[i].clear();
        }
        ll sz = P[L].size()+1;
        vector<ld> P2(sz);
        for (ll i=0;i+1<sz;i++)
        {
            P2[i] += P[L][i]*(1-Pr);
            P2[i+1] += P[L][i]*Pr;
        }
        P[L] = P2;
    }
    {
        ll L = 0;
        ll R = n;
        for (ll i=L+1;i<R;i++)
        {
            if (P[i].size()==0) continue;
            if (a[i]>a[L])
            {
                swap(a[i],a[L]);
                swap(P[i],P[L]);
            }
            ll sz = P[L].size();
            ll sz2 = a[i]-a[L];
            sz2 += P[i].size();
            sz = max(sz,sz2);
            vector<ld> P2(sz);
            for (ll x=0;x<P[L].size();x++)
            {
                for (ll y=0;y<P[i].size();y++)
                {
                    ll w = max(x,y-a[L]+a[i]);
                    P2[w] += P[L][x]*P[i][y];
                }
            }
            P[L] = P2;
            P[i].clear();
        }
    }
    ld A = 0;
    for (ll i=0;i<P[0].size();i++)
    {
        A += P[0][i]*(a[0]+i);
    }
    cout.precision(20);
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }
}