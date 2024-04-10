#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
#define RREP(i,n) for (int i = n-1; i>=0; --i)
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
const ll mod = 1e9+7 ;


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

const int maxn = 5e5+5;

ll cnt[70], cntno[70];
ll arr[maxn];
signed main(){
    IOS();

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        fill(cnt, cnt+61+1, 0);
//        fill(cntno, cntno+61+1, 0);
        ll all = 0;
        REP(i,n) {
            ll x; cin>> x; all += x; all %= mod;
            for (int j = 0; j<61; ++j) {
                if (x & (1ll<<j)) {
                    cnt[j] ++;
                }
            }
            arr[i] = x ;
        }
        ll re = 0;
        REP(X,n) {
            ll a = 0, o = all;
            for (int i = 0; i<61; ++i) {
                if (arr[X] & (1ll<<i)) {
                    a += (cnt[i]*((1ll<<i)%mod))%mod; a %= mod;
                    o += ((n-cnt[i])*((1ll<<i)%mod))%mod; o %= mod; //if (o<0) o += mod;
                }
                else{
                }
            }
            bug(arr[X], a,o);
            re += a % mod * o % mod; re %= mod;
        }
        cout<<re<<endl;

    }
}