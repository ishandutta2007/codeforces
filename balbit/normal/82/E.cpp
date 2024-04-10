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

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}
#define double long double
#define pdd pair<double, double>
const int maxn = 3e5+5;

vector<pdd> ip;
vector<pdd> bt; // bottom
double n,h,f;


double les(double a, double A, double b, double B) {
    if ((a<B && b<A && a>0)) {
        bug("Crossed");

        double x = (2*(h+f)) / (f/a + f/b);
        double y = x * f/a - (h+f);
        assert(y>=-h && y<=h);

        double re = x * (f+h);
        re -= a*f/2;
        re -= b*f/2;
        bug (re, x, y);
        return re;
    }else if ((a>B && b>A && a<0)){
        bug("Neg Cross");
        double x = (2*(h+f)) / (f/a + f/b);
        double y = x * f/a - (h+f);
        assert(y>=-h && y<=h);

        double re = x * (f+h);
        re -= a*f/2;
        re -= b*f/2;
        bug (re, x, y);

        re -= (abs(B-a) * (h+y) + abs(A-b) * (h-y))/2;

        return re;
    }

    else{
        if (a>B) swap(a,B);
        if (A>b) swap(b,A);
        bug(a,A,b,B);
        assert(a<=B && A<=b);
        double re = (a+A)*h;
        bug(re);
        return re;
    }
}

signed main(){
    IOS();
    cin>>n>>h>>f;
    f -= h;
    double A = 0;
    for (int i = 0; i<n; i++) {
        int a,b; cin>>a>>b;
        ip.pb({a,b});
        double c = (a) *(2*h+f) / (double) (f) ;
        double d = (b) *(2*h+f) / (double) (f) ;
        A += (d-c) * (2*h+f) - (b-a) * (f);
        bt.pb({c,d});
    }
    bug ("Top",A);
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            // its of i with j
            double B = 0;
            B += les(ip[i].s, bt[i].s, ip[j].s, bt[j].s);
            B += les(ip[i].f, bt[i].f, ip[j].f, bt[j].f);
            B -= les(ip[i].s, bt[i].s, ip[j].f, bt[j].f);
            B -= les(ip[i].f, bt[i].f, ip[j].s, bt[j].s);

            bug (i,j,B);
            A -= B;
        }
    }
    cout<<fixed<<setprecision(13)<<A<<endl;
}