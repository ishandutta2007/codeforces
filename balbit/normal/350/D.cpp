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

const int maxn = 3e5+5;

int n,m;
double vert = 3.13159225;
const double eps = 1e-8;
struct ID{
    double slo; // y/x if not vertical, 1/0 if vertical
    double yat; // where y is if x = 0, x-pos if vertical
    bool operator < (const ID &b) const {
        return abs(slo-b.slo)>eps?slo<b.slo : yat < b.yat;
    }
    bool operator == (const ID &b) const {
        return abs(slo-b.slo)<eps && abs(yat - b.yat) < eps;
    }
//    bool operator != (const ID &b) const {
//        return slo!=b.slo || yat != b.yat;
//    }
};

vector<int> v;

int leq(int x){
    return upper_bound(ALL(v), x) - v.begin();
}

signed main(){
    IOS();
    int n,m; cin>>n>>m;
    vector<pair<ID, pii> > qu;
    for (int i = 0; i<n; i++) {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        x1*=2;
        y1*=2;
        x2*=2;
        y2*=2;
        int dx = (x2-x1), dy = y2-y1;
        if (dx) {
            double slo = dy/(double)dx;
            qu.pb({{slo, y1-slo*x1}, {x1, x2}});
        }else{
            qu.pb({{vert,x1}, {y1,y2}});
        }
    }
    vector<pair<ID, int> > pt;
    vector<pair<pii, int> > C;
    for (int i = 0; i<m; i++){
        int x,y,r; cin>>x>>y>>r; x*=2; y*=2; r*=2;
        for (int j = 0; j<i; j++) {
            if (C[j].s == r && r*r*4 < SQ(x-C[j].f.f) + SQ(y-C[j].f.s)) {
                int dx = C[j].f.f-x, dy = C[j].f.s-y;

                if (dy) {
                    int mx = (x+C[j].f.f)/2;
                    int my = (y+C[j].f.s)/2;

                    double slo = -dx/(double)dy;
                    pt.pb({{slo,my-slo*mx}, mx});
                }else{
                    int mx = (x+C[j].f.f)/2;
                    int my = (y+C[j].f.s)/2;
                    pt.pb({{vert,mx},my});
                }
            }
        }
        C.pb({{x,y},r});
    }
    sort(ALL(pt));
    sort(ALL(qu));
    pt.pb({{1092.2,420},1}); // buffer
    for (auto x : pt) {
        bug(x.f.slo,x.f.yat,x.s);
    }
    for (auto x : qu) {
        bug(x.f.slo,x.f.yat,x.s.f,x.s.s);
    }
    int it = 0;
    m = SZ(qu);
    ll re = 0;
    int INF = 1e9+5;
    for (int i = 0; i<SZ(pt); i++) {
        if (i && !(pt[i].f==pt[i-1].f) ) {
            bug(i);
            for (int x : v) bug(x);
            v.pb(INF); sort(ALL(v));
            while (it < m && qu[it].f < pt[i-1].f) ++it;
            while (it < m && qu[it].f == pt[i-1].f) {
                int a = qu[it].s.f, b = qu[it].s.s;
                if (a > b) swap(a,b);
                bug(leq(b),leq(a-1));
                re += leq(b)-leq(a-1);
                ++it;
            }
            v.clear();
        }
        if (i==SZ(pt)) continue;
        v.push_back(pt[i].s);
    }
    cout<<re<<endl;
}