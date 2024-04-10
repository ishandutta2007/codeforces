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

const double PI = acos(-1);
#define double long double
#define hypot hypotl
#define sqrt sqrtl

double a,b,l;
    double eps = 1e-9;

double gt(double x) {
    // x is on b
    double y = sqrt(l*l - x*x);
    if (x>b && (a*x <= y*(x-b))) return -1;
    double eb = hypot(a, b-x);
    double ea = hypot(a-y, b);
    double s = (l+ea+eb)/2;
    double area = sqrt(s*(s-eb)*(s-ea)*(s-l));
    double h = area * 2 / l;
    return h;
}

signed main(){
    IOS();
    cin>>a>>b>>l;
    double re = 0;
    if (l <= a) {
        re = min(b,l);
    }
    if (l<=b) {
        re = max(re, min(a,l));
    }
    if (re) {
        cout<<re<<endl; return 0;
    }
//    if (l >= 2* sqrt((a*a) + (b*b))) {
//
//    }
    double L = 0+0.00001, R = l-0.00001;
    for (int jo=0; jo<400; ++jo) {
        double mid = (L+R)/2;
        double tmp1 = gt((R-L)/3+L), tmp2 = gt((L)+(R-L)/3*2);
        if (tmp1 == -1 || tmp2 == -1) {
            cout<<"My poor head =("<<endl;
            return 0;
        }
        if (tmp1 >= tmp2){
            L = (R-L)/3+L;
        }else{
            R = (L)+(R-L)/3*2;
        }
    }
//    for (double ty = 0; ty < l; ty += 0.1) {
//        bug(gt(ty));
//    }
//    double k = l / hypot(a,b);
    cout<<fixed<<setprecision(10)<<min({l,gt(L)})<<endl;


}