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

const int maxn = 1e5+5;
#define pdd pair<double, double>

struct seg{
    double a,b;
    double c; // a * x^2 + b * x + c
    double l,r;
    double eval(double x) {
        return a * x * x + b * x + c;
    }
    void add(double aa, double bb, double cc) {
        a += aa; b += bb; c += cc;
    }
    void shift(int k) {
        // g(x) = f(x-k)
        c = c - b * k + k * k * a;
        b = b - 2 * k * a;
        l += k; r += k;
    }
    pair<double, double> getmin(){
        // val, position
        double cen = -b/(double)(2*a);
        if (l < cen && cen < r) {
            return {eval(cen), cen};
        }
        return min(make_pair(eval(l), l), make_pair(eval(r), r));
    }
};

signed main(){
    IOS();

    ll n, q, A, B;
    cin>>n>>q>>A>>B;
    ll K = B-A;
    vector<ll> x(n), rawx(n);
    q -= (n-1) * A;

    bug(q);

    vector<seg> v;
    v.pb({0,0,0,1,q});

    vector<double> exp;

    double bobo = -1;

    REP(i,n) {
        cin>>x[i]; rawx[i] = x[i]; x[i] -= A * i;
        pdd bst = {-1, -1};
        int who = -1;
        REP(j, SZ(v)) {
            auto &s = v[j];
            s.add(1, -2 * x[i], x[i] * x[i]);
            auto gg = s.getmin();
            if (who == -1 || gg < bst) {
                bst = gg;
                who = j;
            }
        }
        bug(bst.f, bst.s);
        bobo = bst.f;
        double pt = bst.s;
        exp.pb(pt);
        v.insert(v.begin() + who + 1, seg{0,0,bst.f,pt,pt+K});
        v.insert(v.begin() + who + 2, v[who]);
        v[who].r = pt; v[who+2].l = pt;
        for (int j = who+2; j < SZ(v); ++j) {
            v[j].shift(K);
        }

        // trim
        while (v.back().l > q) {
            v.pop_back();
        }
        if (v.back().r > q) {
            v.back().r = q;
        }
//        for (auto s : v) {
//            cout<<s.l<<' '<<s.r<<" - ";
//        }
//        cout<<endl;
    }

    vector<double> y;

    double now = exp.back();
    bug(now);

    y.pb(now + A * (n-1));

    RREP(i, SZ(exp) - 1) {
        if( now > exp[i] ) {
            now = max(exp[i], now - K);
        }
        y.pb(now + A * i);
    }

    double re = 0;

    reverse(ALL(y));
    REP(i, n) {
        bug(abs(y[i] - rawx[i]));
        re += (y[i] - rawx[i]) * (y[i] - rawx[i]);
    }

    bug(re);
    cout<<fixed<<setprecision(10);
    for (double d : y) cout<<d<<' ';
    cout<<endl;
    cout<<bobo<<endl;


}

/*
2 5 4  5
5 5
*/