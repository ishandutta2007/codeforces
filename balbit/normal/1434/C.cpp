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

const int maxn = 1e6+5;

#define LL __int128

LL a,b,c,d;

inline LL gt(LL x) {
    LL L = max(d * (x-1) - c + d-1,(LL)0) / d;
    LL Lp = L * d + c - d * (x-1);
    LL ms = (Lp + Lp + (x-1-L) * d) * (x-L) * b / 2;
//    bug(L, Lp, ms);
    LL re = -a * x + (x) * b * c - ms;
    return re;
}
//

void rd(LL &x) {
    ll hi; cin>>hi; x = hi;
}
//bool kill(LL M) {
//
//}

signed main(){
    IOS();
    int t; cin>>t;

    while(t--) {
        rd(a);
        rd(b);
        rd(c);
        rd(d);
        if (a > b * c) {
            cout<<-1<<endl; continue;
        }
        LL mn = 0;

//        for (int x = 1; x<5; ++x) {
////            bug(gt(x));
//            mn = min(mn, gt(x));
//        }
        LL l = 0, r = 1000000000;
        while (l != r) {
            LL mid = (l+r)/2;
            LL g1 = gt(mid);
            LL g2 = gt(mid+1);
            if (g1 == g2) {
                mn=min(mn, g1); break;
            }
            mn = min(mn, min(g1, g2));
            if (g1 < g2) {
                r = mid;
            }else{
                l = mid+1;
            }
        }
        if (mn < -2e18) {
            cout<<-1<<endl;
        }else
            cout<<-(ll)mn<<endl;
    }
}

// 1 4 1 7 5