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

ll mx = 1;

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

ll Q = 0;
vector<vector<vector<ll>>> q(2);
int A[600100][61];
int Z[2][1000100];
vector<ll> F;
ll t = 0;

void add(ll b, ll x, ll d, ll w)
{
    ll c = 1-b;
    ll P = Z[b][q[b].size()/2];
    ll sz = q[c].size();
    ll x1, x2;
    {
        ll L = 0;
        ll R = sz/2+1;
        ll S = A[P][60];
        if (q[b].size()%2==1) S += q[b].back()[0];
        while (R-L>1)
        {
            ll M = (R+L)/2;
            if (A[Z[c][M]][60]<=S) L = M;
            else R = M;
        }
        x1 = A[Z[c][L]][d];
        ll L2 = L*2;
        ll M = S-A[Z[c][L]][60];
        while (L2<q[c].size())
        {
            ll del = min(M,q[c][L2][0]);
            if (q[c][L2][1]==d) x1 += del;
            M -= del;
            if (M==0) break;
            L2++;
        }
    }
    q[b].push_back({x,d,w});
    P = q[b].size()/2;
    if (q[b].size()%2==0)
    {
        Z[b][P] = F[t++];
        for (ll j=0;j<=60;j++)
        {
            A[Z[b][P]][j] = A[Z[b][P-1]][j];
        }
        A[Z[b][P]][d] += x;
        A[Z[b][P]][60] += x;
        {
            ll d0 = q[b][q[b].size()-2][1];
            ll x0 = q[b][q[b].size()-2][0];
            A[Z[b][P]][d0] += x0;
            A[Z[b][P]][60] += x0;
        }
    }
    P = Z[b][P];
    {
        ll L = 0;
        ll R = sz/2+1;
        ll S = A[P][60];
        if (q[b].size()%2==1) S += q[b].back()[0];
        while (R-L>1)
        {
            ll M = (R+L)/2;
            if (A[Z[c][M]][60]<=S) L = M;
            else R = M;
        }
        x2 = A[Z[c][L]][d];
        ll L2 = L*2;
        ll M = S-A[Z[c][L]][60];
        while (L2<q[c].size())
        {
            ll del = min(M,q[c][L2][0]);
            if (q[c][L2][1]==d) x2 += del;
            M -= del;
            if (M==0) break;
            L2++;
        }
    }
    Q += x2-x1;
}

void del(ll b)
{
    ll c = 1-b;
    ll d = q[b].back()[1];
    ll sz = q[c].size();
    ll P = Z[b][q[b].size()/2];
    ll x1, x2;
    {
        ll L = 0;
        ll R = sz/2+1;
        ll S = A[P][60];
        if (q[b].size()%2==1) S += q[b].back()[0];
        while (R-L>1)
        {
            ll M = (R+L)/2;
            if (A[Z[c][M]][60]<=S) L = M;
            else R = M;
        }
        x1 = A[Z[c][L]][d];
        ll L2 = L*2;
        ll M = S-A[Z[c][L]][60];
        while (L2<q[c].size())
        {
            ll del = min(M,q[c][L2][0]);
            if (q[c][L2][1]==d) x1 += del;
            M -= del;
            if (M==0) break;
            L2++;
        }
    }
    q[b].pop_back();
    if (q[b].size()%2==1) F.push_back(P);
    P = Z[b][q[b].size()/2];
    {
        ll L = 0;
        ll R = sz/2+1;
        ll S = A[P][60];
        if (q[b].size()%2==1) S += q[b].back()[0];
        while (R-L>1)
        {
            ll M = (R+L)/2;
            if (A[Z[c][M]][60]<=S) L = M;
            else R = M;
        }
        x2 = A[Z[c][L]][d];
        ll L2 = L*2;
        ll M = S-A[Z[c][L]][60];
        while (L2<q[c].size())
        {
            ll del = min(M,q[c][L2][0]);
            if (q[c][L2][1]==d) x2 += del;
            M -= del;
            if (M==0) break;
            L2++;
        }
    }
    Q += x2-x1;
}


void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), c(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        for (ll j=0;j<60;j++)
        {
            if (a[i]&(1LL<<j)) c[i]++;
        }
    }
    ll ans = 0;
    Z[0][0] = 0;
    Z[0][1] = 1;
    for (ll i=0;i<2;i++)
    {
        for (ll j=0;j<=60;j++) A[i][j] = 0;
    }
    for (ll i=2;i<600010;i++) F.push_back(i);
    for (ll i=0;i<n;i++)
    {
        while (q[0].size()>0 and a[i]>=q[0].back()[2])
        {
            del(0);

        }
        while (q[1].size()>0 and a[i]<=q[1].back()[2])
        {
            del(1);
        }
        ll S = 0, S2 = 0;
        ll P = q[0].size()/2;
        S += A[Z[0][P]][60];
        if (q[0].size()%2==1) S += q[0].back()[0];
        P = q[1].size()/2;
        S2 += A[Z[1][P]][60];
        if (q[1].size()%2==1) S2 += q[1].back()[0];
        S = i+1-S;
        S2 = i+1-S2;
        add(0,S,c[i],a[i]);
        add(1,S2,c[i],a[i]);
        ans += Q;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}