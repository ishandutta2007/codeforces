//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
int mod = 998244353;

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

int MOD = 998244353;
int root = 31;
int root_1 = 128805723;
int root_pw = 1<<23;
int root2 = 30;
int MOD2 = 469762049;
int root_12 = 15658735;
int root_pw2 = 1<<26;


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


void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    ll m;
    cin >> m;
    vector<ll> b(m);
    for (ll i=0;i<m;i++) cin >> b[i];
    vector<ll> a2(n), b2(m);
    for (ll i=0;i<n;i++)
    {
        a2[i] += a[i]*2;
        if (i+1<n) a2[i+1] += a[i];
        if (i>0) a2[i-1] += a[i];
    }
    for (ll i=0;i<m;i++)
    {
        b2[i] += b[i]*2;
        if (i+1<m) b2[i+1] += b[i];
        if (i>0) b2[i-1] += b[i];
    }
    b2.pop_back();
    for (ll i=1;i+1<m;i++)
    {
        if (b2[i]>410000 or b2[i]<-410000)
        {
            cout << -1 << "\n";
            return;
        }
    }
    reverse(b2.begin(),b2.end());
    b2.pop_back();
    ll sz = 1;
    while (n+m>sz) sz *= 2;
    a2.resize(sz);
    b2.resize(sz);
    vector<int> ok(n-m+1,1);
    for (int w=0;w<2;w++)
    {
        mod = MOD;
        vector<int> a0(sz), b0(sz);
        for (ll i=0;i<n;i++)
        {
            a0[i] = (a2[i]+mod)%mod;
            b0[i] = (b2[i]+mod)%mod;
        }
        fft(a0,false);
        fft(b0,false);
        for (ll i=0;i<sz;i++) a0[i] = (a0[i]*1LL*b0[i])%mod;
        fft(a0,true);
        ll S = 0;
        for (ll i=0;i+2<m;i++)
        {
            S = (S+b2[i]*1LL*(b2[i]-1))%mod;
        }
        for (ll i=0;i<m-2;i++)
        {
            S = (S+a2[i]*1LL*(a2[i]+1))%mod;
        }
        for (ll i=0;i<n-m+1;i++)
        {
            S = (S+a2[i+m-2]*1LL*(a2[i+m-2]+1))%mod;
            S = (S-a2[i]*1LL*(a2[i]+1))%mod;
            if (S<0) S += mod;
            ll x = (S-2*a0[i+m-2])%mod;
            if (x!=0) ok[i] = 0;
        }
        swap(MOD,MOD2);
        swap(root,root2);
        swap(root_1,root_12);
        swap(root_pw,root_pw2);
    }
    for (ll i=0;i<n-m+1;i++)
    {
        if (ok[i]==0) continue;
        ll x = b[0]-a[i];
        ll y = a[i+1]-b[1];
        ll D = y-x;
        ll W1 = i/2+1;
        ll W0 = (i+1)/2+1;
        if (D>W1 or -D>W0) continue;
        ll C0 = 0, C1 = 0;
        if (D>0) C1 = D;
        else C0 = -D;
        ll L = 0, R = min(W0-C0,W1-C1)+1;
        while (R-L>1)
        {
            ll M = (L+R)/2;
            if ((W0-C0-M)*2>(C1+M)*2-1) L = M;
            else R = M;
        }
        C0 += L;
        C1 += L;
        ll Q = W0-C0;
        ll S = C1*C1-W0*W0+W0+Q*Q-Q;
        if ((C1+x)%2!=0)
        {
            ll F = 0;
            C0--;
            C1--;
            Q = W0-C0;
            S = C1*C1-W0*W0+W0+Q*Q-Q;
            if (S<=x and C0>=0 and C1>=0) F = 1;
            C0 += 2;
            C1 += 2;
            Q = W0-C0;
            S = C1*C1-W0*W0+W0+Q*Q-Q;
            if (S<=x and C0<=W0 and C1<=W1) F = 1;
            if (F==0) continue;
            C0--;
            C1--;
        } else if (S>x) continue;
        C0 -= L;
        C1 -= L;
        L = 0, R = min(W0-C0,W1-C1)+1;
        while (R-L>1)
        {
            ll M = (L+R)/2;
            if ((C0+M-1)*2<(W1-C1-M)*2+1) L = M;
            else R = M;
        }
        C0 += L;
        C1 += L;
        Q = W1-C1;
        S = W1*W1-Q*Q-C0*C0+C0;
        if ((C1+x)%2!=0)
        {
            ll F = 0;
            C0--;
            C1--;
            Q = W1-C1;
            S = W1*W1-Q*Q-C0*C0+C0;
            if (S>=x and C0>=0 and C1>=0) F = 1;
            C0 += 2;
            C1 += 2;
            Q = W1-C1;
            S = W1*W1-Q*Q-C0*C0+C0;
            if (S>=x and C0<=W0 and C1<=W1) F = 1;
            if (F==0) continue;
            C0--;
            C1--;
        } else if (S<x) continue;
        C0 -= L;
        C1 -= L;
        for (;;C0++,C1++)
        {
            Q = W0-C0;
            S = C1*C1-W0*W0+W0+Q*Q-Q;
            if (S>x) continue;
            Q = W1-C1;
            S = W1*W1-Q*Q-C0*C0+C0;
            if (S<x) continue;
            if ((x+C1)%2!=0) continue;
            x -= C1*C1;
            x += C0*(W0*2-1);
            x -= C0*C0;
            x /= 2;
            W0 -= C0;
            W1 -= C1;
            vector<ll> ans;
            for (ll j=0;j<C0;j++)
            {
                ll A = min(x,W0);
                x -= A;
                A = W0-A+j;
                ans.push_back(i+1-2*A);
            }
            for (ll j=C1-1;j>=0;j--)
            {
                ll A = min(x,W1);
                x -= A;
                ans.push_back(i-2*(A+j));
            }
            for (ll j=1;j+1<m;j++)
            {
                S = b[j]*2+b[j-1]+b[j+1];
                ll S2 = a[i+j]*2+a[i+j-1]+a[i+j+1];
                if (S!=S2) ans.push_back(i+j+1);
            }
            sort(ans.begin(),ans.end());
            cout << ans.size() << "\n";
            for (ll k: ans) cout << k+1 << " ";
            cout << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}