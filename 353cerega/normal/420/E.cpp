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
    sz[v] = 1;
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

const ld PI = acos(-1);

pair<ld,ld> get(ll x, ll y, ll r, ll L)
{
    ld a = sqrt(x*x+y*y);
    ld p = PI-acos((a*a+r*r-L*L)*0.5/a/r);
    pair<ld,ld> d = {x/a*r,y/a*r};
    d = {d.X*cos(p)-d.Y*sin(p),d.X*sin(p)+d.Y*cos(p)};
    return {d.X+x,d.Y+y};
}

ld eps = 1e-10;

ll comp(pair<ld,ld> x, pair<ld,ld> y)
{
    ll Cx = 1, Cy = 1;
    if (x.Y>0 or (x.Y==0 and x.X>0)) Cx = 0;
    if (y.Y>0 or (y.Y==0 and y.X>0)) Cy = 0;
    if (Cx!=Cy)
    {
        if (Cx<Cy) return 1;
        else return 0;
    }
    ld S = x.X*y.Y-x.Y*y.X;
    if (S>0) return 1;
    return 0;
}

bool cmp(pair<pair<ld,ld>,ll> x, pair<pair<ld,ld>,ll> y)
{
    ll c = comp(x.X,y.X);
    if (c==1) return true;
    if (c==0) return false;
    return x.Y>y.Y;
}

void solve()
{
    ll n, d;
    cin >> n >> d;
    vector<pair<pair<ld,ld>,ll>> A;
    ll C = 0;
    ll ans = 0;
    for (ll i=0;i<n;i++)
    {
        ll x, y, r;
        cin >> x >> y >> r;
        ld L2 = sqrt(x*x+y*y);
        ll w = round(L2);
        ll mn = (w-2*r)/d*d;
        ll mx = (w+2*r)/d*d+d;
        mn = max(mn,0LL);
        while ((mn+r)*(mn+r)<x*x+y*y) mn += d;
        while ((mx-r)*(mx-r)>x*x+y*y) mx -= d;
        for (ll q=mn;q<=mx;q+=d)
        {
            pair<ld,ld> L = get(x,y,r,q);
            ld Q = L.Y*x-L.X*y;
            Q /= x*x+y*y;
            pair<ld,ld> R;
            R.X = L.X+Q*2*y;
            R.Y = L.Y-Q*2*x;
            swap(L,R);
            if (L.X*R.Y<L.Y*R.X) swap(L,R);
            {
                ll Cx = 1, Cy = 1;
                if (L.Y>0 or (L.Y==0 and L.X>0)) Cx = 0;
                if (R.Y>0 or (R.Y==0 and R.X>0)) Cy = 0;
                if (Cx>Cy) C++;
            }
            A.push_back({L,1});
            A.push_back({R,-1});
        }
    }
    sort(A.begin(),A.end(),cmp);
    ans = C;
    for (ll i=0;i<A.size();i++)
    {
        C += A[i].Y;
        ans = max(ans,C);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    cin.tie(0);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}