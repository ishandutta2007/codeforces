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



int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i].X >> a[i].Y;
        a[i].X--, a[i].Y--;
    }
    vector<ll> Q(n), Q2(n);
    {
        vector<vector<pair<ll,ll>>> ord(n);
        for (ll i=0;i<n;i++)
        {
            ord[a[i].X].push_back({a[i].Y,i});
        }
        set<pair<ll,ll>> kek;
        for (ll i=0;i<n;i++)
        {
            for (auto x: ord[i]) kek.insert(x);
            ll p = kek.begin()->Y;
            Q[i] = p;
            kek.erase({a[p].Y,p});
        }
    }
    ll ok = 1;
    {
        Q2 = Q;
        set<pair<ll,ll>> kek;
        for (ll i=0;i<n;i++)
        {
            ll p = Q[i];
            auto it = kek.lower_bound({a[p].X,0});
            if (it!=kek.end() and it->Y>=i)
            {
                ok = 0;
                swap(Q2[it->X],Q2[i]);
                break;
            }
            while (true)
            {
                it = kek.lower_bound({i,0});
                if (it==kek.begin()) break;
                it--;
                if (it->Y>a[p].Y) break;
                kek.erase(it);
            }
            kek.insert({i,a[p].Y});
        }
    }
    vector<ll> A(n), A2(n);
    for (ll i=0;i<n;i++)
    {
        A[Q[i]] = i;
        A2[Q2[i]] = i;
    }
    if (ok==1)
    {
        cout << "YES\n";
        for (ll i=0;i<n;i++) cout << A[i]+1 << " ";
    } else
    {
        cout << "NO\n";
        for (ll i=0;i<n;i++) cout << A[i]+1 << " ";
        cout << "\n";
        for (ll i=0;i<n;i++) cout << A2[i]+1 << " ";
    }
}