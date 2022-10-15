#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif
 
const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 998244353;
 
 
void GG(){cout<<"0\n"; exit(0);}
 
ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}
 
ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}
 
const int maxn = 1e6+5;
 
void NTT(vector<ll> &a, ll mo, bool rev=0){
    // mo has to be 2^k * c + 1
    int n = SZ(a);
    while ((n&(-n))!=n) {
        a.pb(0); n++;
    }
    for (int i = 1, j = 0; i<n; i++){
        int bit = n>>1;
        while (j>=bit) j-=bit, bit>>=1; j+=bit;
        if (i<j) swap(a[i], a[j]);
    }
    for (int B = 2; B<=n; B*=2){
        ll w0 = mpow(3,(mo-1)/(B),mo);
        for (int i = 0; i<n; i+=B){
            ll w = 1;
            for (int j = 0; j<B/2; j++){
                ll u = a[i+j], v = w*a[i+j+B/2]%mo;
                a[i+j] = u+v, a[i+j+B/2] = u-v;
                if (a[i+j]>=mo) a[i+j]-=mo; if (a[i+j+B/2]<0) a[i+j+B/2]+=mo;
                w = w*w0%mo;
            }
        }
    }
    if (rev) {
        reverse(next(a.begin()),a.end());
        ll invn = inv(n,mo);
        REP(i,n) a[i] = a[i]*invn%mo;
    }
}
vector<ll> mul (vector<ll> a, vector<ll> b, ll mo = mod){
    int n = 1; while (n < SZ(a) + SZ(b)) n*=2;
    vector<ll> x(n), y(n);
    REP(i, SZ(a)) x[i] = a[i]; REP(j, SZ(b)) y[j] = b[j];
    NTT(x,mo); NTT(y,mo);
    REP(i, n) x[i] = x[i] * y[i] % mo;
    NTT(x,mo,1);
    while (x.size()>1 && x.back()==0) x.pop_back(); return x;
}
 
ll fac[maxn], ifac[maxn];
 
ll C(int a, int b) {
    return b > a? 0 : fac[a] * ifac[b] % mod * ifac[a-b] % mod;
}
 
signed main(){
    IOS();
    fac[0] = ifac[0] = 1;
    REP1(i,200005-1) {
        fac[i] = fac[i-1] * (ll)i % mod;
        ifac[i] = inv(fac[i]);
    }
    int n, fooo; cin>>n>>fooo;
    string s; cin>>s;
    array<int, 2> q = {{0,0}};
    int sig = 0;
    REP(i,n) {
        if (s[i] == '?') ++q[i&1];
        if (s[i] == 'w') {
            if (i&1) sig --;
            else sig++;
        }
    }
    bug(sig);
    vector<ll> A(q[0]+1),B(q[1]+1);
    REP(i, q[0]+1) {
        A[i] = C(q[0], i);
    }
    REP(i, q[1] + 1) {
        B[q[1] - i] = C(q[1], i);
    }
    vector<ll> C = mul(A,B);
    ll ways = 0, cnt = 0;
    REP(i, SZ(C)) {
        int tmp = sig + i - q[1];
        if (tmp % 2 == 0) {
            cnt += C[i] * abs(tmp) / 2;
            ways += C[i];
            cnt %= mod; ways %= mod;
        }
    }
    cout<<cnt * inv(ways) % mod<<endl;
 
}