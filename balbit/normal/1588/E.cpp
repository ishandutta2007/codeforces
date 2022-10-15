#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 zck_is_king
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

const int maxn = 1e5+5;

struct pt{
    ll x,y;

};

ll dst(pt a, pt b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

const double PI = acos(-1);

double mn[maxn], mx[maxn];
bool dead[maxn], to[maxn];

inline bool btw(double L, double R, double v) {
    double lrdiff = R-L;
    if (v < 0) v += 2*PI;
    double vrdiff = R-v;
    if (vrdiff < 0) vrdiff += 2*PI;
    return (lrdiff >= vrdiff);
}

pair<double, double> mrg(double L1, double R1, double L2, double R2) {
    assert(R1 >= 0 && R1 < 2*PI && R2 >= 0 && R2 < 2*PI);
    if (!btw(L1, R1, R2)) {
        swap(L1, L2); swap(R1, R2);
    }
    if (!btw(L1, R1, R2)) {
        return {0,0};
    }
    double rl;
    if (btw(L1, R1, L2)) {
        rl = L2;
    }else {
        rl = L1;
    }
    if (R2 - rl < 0) rl -= 2*PI;
    if (R2 - rl > PI) rl += 2*PI;
    return {rl, R2};
}

vector<pt> v;
bool test(int i, int j) {
    double ang = atan2(v[j].y-v[i].y, v[j].x-v[i].x);
    if (btw(mn[i], mx[i], ang)) {
        return 1;
    }
    return 0;
}

signed main(){
    IOS();
    ll n, r; cin>>n>>r;
    v.resize(n);
    REP(i,n) {
        cin>>v[i].x>>v[i].y;
    }

    REP(i,n) {
//        bool to = 0;
        REP(j,n) {
            if (dst(v[i], v[j]) > r*r) {
                double ang = atan2(v[j].y-v[i].y, v[j].x - v[i].x);
                if (ang < 0) ang += 2*PI;
                double dd = sqrt(dst(v[i], v[j]));
                double thet = asin(r / dd);
                bug(i,j,ang, thet);
                double Mn = ang - thet, Mx = ang + thet;
                if (Mx >= 2*PI) Mx -= 2*PI;
                while (Mn > Mx) {
                    Mn -= 2*PI;
                }
                if (!to[i]) {
                    mn[i] = Mn; mx[i] = Mx;
                    to[i] = 1;
                }else{
                    // merge ranges
                    {
                        tie(mn[i], mx[i]) = mrg(mn[i], mx[i], Mn, Mx);
                        if (mn[i] == 0 && mx[i] == 0) {
                            dead[i] = 1; break;
                        }
                    }
                }
            }
        }
    }
    int re = 0;
    REP(i,n) {
        if (!dead[i]) {
            REP(j,i) {
                if (!dead[j]) {
                    if (to[i] == 0 || to[j] == 0 || (test(i,j) && test(j,i))) {
                        re++;
                        bug(i,j);
                    }
                }
            }
        }
    }
    cout<<re<<endl;
}