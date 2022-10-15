#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
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
const ll mod = 998244353 ;


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

ll full[maxn], need[maxn]; // full[x] means i have stuff up to x-1, need[x] means i have stuff up to x-1 and also have x+1
ll re = 0;

inline void F(ll &a, ll b) {
    a += b; if (a >= mod) a -= mod;
    re += b; if (re >= mod) re -= mod;
}

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n);
        full[0] = 1;
        re = 0;
        REP(i,n) {
            cin>>a[i];
            if (a[i] > n+3) continue;
            F(full[a[i]+1] , full[a[i]+1]);
            F(full[a[i]+1], full[a[i]]);
//            F(full[a[i]+2] , need[a[i]]);
            F(need[a[i]+1] , need[a[i]+1]);
            if (a[i]) F(need[a[i]-1] , need[a[i]-1]);
            if (a[i]) F(need[a[i]-1], full[a[i]-1]);
        }

        REP(i,n+4) {
            full[i] = need[i] = 0;
        }

        cout<<re<<endl;

    }


}