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




int main()
{
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> a(n);
    for (ll i=0;i<n;i++) cin >> a[i].X >> a[i].Y;
    ll m;
    cin >> m;
    vector<vector<ll>> Q(m,vector<ll>(4));
    ll N = n;
    for (ll i=0;i<m;i++)
    {
        cin >> Q[i][0];
        if (Q[i][0]==1)
        {
            cin >> Q[i][1] >> Q[i][2];
            a.push_back({Q[i][1],Q[i][2]});
            Q[i][3] = N;
            N++;
            continue;
        }
        if (Q[i][0]==3) continue;
        cin >> Q[i][1];
        Q[i][1]--;
    }
    vector<ll> was(N);
    for (ll i=0;i<n;i++) was[i] = 1;
    /*vector<vector<ll>> dp(m+1,vector<ll>(k+1)), dp2(m+1,vector<ll>(k+1));
    for (ll i=0;i<n;i++)
    {
        ll c = a[i].X;
        ll d = a[i].Y;
        for (ll z=k-d;z>=0;z--)
        {
            dp[0][z+d] = max(dp[0][z+d],dp[0][z]+c);
        }
    }
    for (ll i=0;i<m;i++)
    {
        for (ll z=0;z<=k;z++) dp[i+1][z] = dp[i][z];
        if (Q[i][0]!=1) continue;
        ll c = Q[i][1];
        ll d = Q[i][2];
        for (ll z=k-d;z>=0;z--)
        {
            dp[i+1][z+d] = max(dp[i+1][z+d],dp[i+1][z]+c);
        }
    }
    for (ll i=m-1;i>=0;i--)
    {
        for (ll z=0;z<=k;z++) dp2[i][z] = dp2[i+1][z];
        if (Q[i][0]!=2) continue;
        ll c = a[Q[i][1]].X;
        ll d = a[Q[i][1]].Y;
        for (ll z=k-d;z>=0;z--)
        {
            dp2[i][z+d] = max(dp2[i][z+d],dp2[i][z]+c);
        }
    }*/
    ll M = 200;
    ll R = -1;
    vector<ll> cur(k+1);
    vector<ll> val;
    ll mod2 = 10000019;
    vector<ll> was2(N);
    for (ll p=0;p<m;p++)
    {
        if (p%M==0)
        {
            R = min(m,p+M);
            for (ll i=0;i<=k;i++) cur[i] = 0;
            for (ll i=0;i<N;i++) was2[i] = was[i];
            val.clear();
            for (ll z=p;z<R;z++)
            {
                if (Q[z][0]==1)
                {
                    if (was2[Q[z][3]]!=2) val.push_back(Q[z][3]);
                    was2[Q[z][3]] = 2;
                }
                if (Q[z][0]==2)
                {
                    if (was2[Q[z][1]]!=2) val.push_back(Q[z][1]);
                    was2[Q[z][1]] = 2;
                }
            }
            for (ll i=0;i<N;i++)
            {
                if (was2[i]==1)
                {
                    ll c = a[i].X;
                    ll d = a[i].Y;
                    for (ll z=k-d;z>=0;z--)
                    {
                        cur[z+d] = max(cur[z+d],cur[z]+c);
                    }
                }
            }
        }
        if (Q[p][0]==1)
        {
            was[Q[p][3]] = 1;
            continue;
        }
        if (Q[p][0]==2)
        {
            was[Q[p][1]] = 0;
            continue;
        }
        vector<ll> A(k+1);
        for (ll i=0;i<=k;i++) A[i] = cur[i];
        for (auto x: val)
        {
            if (was[x]==0) continue;
            pair<ll,ll> y = a[x];
            ll c = y.X;
            ll d = y.Y;
            for (ll z=k-d;z>=0;z--)
            {
                A[z+d] = max(A[z+d],A[z]+c);
            }
        }
        ll W = 0;
        ll q = 1;
        for (ll i=1;i<=k;i++)
        {
            W = (W+q*A[i])%mod;
            q = q*mod2%mod;
        }
        cout << W << "\n";
    }
}