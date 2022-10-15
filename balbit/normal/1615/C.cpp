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

const int maxn = 2e5+5;

//int cnt(int x, int bit) {
//    int re = 0;
//    re +=
//}

int a[2][maxn]; int n;

ll gt(int rnd) {
    int d0=0, d1=0;

    REP(i,n) {
        if ((a[0][i] ^ rnd) != a[1][i]) {
            if (a[0][i] == 1) ++d1;
            else ++d0;
        }
    }
    if (rnd) {
        if (d1 == d0+1) return d1+d0;
        return inf;
    }else{
        if (d1 == d0) return d1+d0;
        return inf;
    }
}

signed main(){
    IOS();



    int t; cin>>t;
    while (t--) {

         cin>>n;
        fill(a[0], a[0]+n+2, 0);
        fill(a[1], a[1]+n+2, 0);
        REP(ba, 2) REP(i,n) {
            char c; cin>>c;
            if (c=='1') a[ba][i] ^= 1;
        }

        ll g1 = gt(1), g0 = gt(0);
        ll mn = min(g1, g0);
        if (mn == inf) mn = -1;
        cout<<mn<<endl;


//        REP(i,n) {
//            if (a[i]) {
//                ++d1;
//            }else ++d0;
//        }

//        bug(n,df);
//        if (n % 2 == 1) {
//            // odd, invariant par
//            if (df % 2 == 1) {
//                // imp
//                cout<<-1<<endl;
//            }else{
//                // ??
//                cout<<d1<<endl;
//            }
//        }else{
//            if (d1 % 2 == 0) {
//                bug("dfa");
//                cout<<d1<<endl;
//            }else{
//                bug("ndf");
//                cout<<n-d1<<endl;
//            }
//        }

    }


}