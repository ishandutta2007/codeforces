#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    return b==1?1:(mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e5+5;

//int id[maxn]; // Id of the position of its storage
const int BS = 250;
ll dp[BS+1][maxn];
ll tmp[maxn], fac[maxn], ifac[maxn];
int IDAT = 0;

signed main(){
    IOS();
    fac[0]=ifac[0]=1;
    REP1(i,maxn-1) {
        fac[i] = fac[i-1] * i % mod;
        ifac[i] = inv(fac[i]);
    }
    REP1(m,BS) {
        dp[m][0]=1;
        ll p25 = 25;
        REP1(i,maxn-1-m) {
            dp[m][i] = dp[m][i-1] * 26 + fac[i+m-1] * ifac[m-1] % mod * ifac[i] % mod * p25 % mod;
            dp[m][i] %= mod; p25 = p25 * 25 % mod;
        }
    }
    int q; cin>>q;
    string s; cin>>s;
    int m = s.length();
    if (m > BS) {
        tmp[0]=1;
        ll p25 = 25;
        REP1(i,maxn-1-m) {
            tmp[i] = tmp[i-1] * 26 + fac[i+m-1] * ifac[m-1] % mod * ifac[i] % mod * p25 % mod;
            tmp[i] %= mod; p25 = p25 * 25 % mod;
        }
    }
    REP(cnt, q){
        int TP; cin>>TP;
        if (TP == 1) {
            cin>>s; m = s.length();
            if (m > BS) {
                tmp[0]=1;
                ll p25 = 25;
                REP1(i,maxn-1-m) {
                    tmp[i] = tmp[i-1] * 26 + fac[i+m-1] * ifac[m-1] % mod * ifac[i] % mod * p25 % mod;
                    tmp[i] %= mod; p25 = p25 * 25 % mod;
                }
            }
        }else{
            int n; cin>>n; n-=m;
            if (n<0) {
                cout<<0<<endl; continue;
            }
            if (m > BS ) cout<<tmp[n]<<endl;
            else cout<<dp[m][n]<<endl;
        }
    }

    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}