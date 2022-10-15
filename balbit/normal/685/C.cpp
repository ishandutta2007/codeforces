#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
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

const int maxn = 1e5+5;

int n;
ll x[maxn], y[maxn], z[maxn];
ll dat[maxn];

pair<ll, array<ll, 3> > re;

//ll gt(ll Y, ll Z) {
//    RREP(i,n) {
//        dat[i] = abs(y[i] - Y) + abs(z[i] - Z) + x[i];
//        if (i!=n-1) MX(dat[i], dat[i+1]);
//    }
//    ll tmp = -4e18-1;
//    ll tr = 4e18+1;
//    REP(i,n) {
//        MX(tmp, abs(y[i]-Y) + abs(z[i]-Z) - x[i]);
//        ll X = i==n-1?x[i] : (dat[i+1] - tmp) / 2;
//        if (tr > X+tmp) {
//            tr = X+tmp;
//            if (re.f > tr) {
//                re = {tr, {{X,Y,Z}}};
//            }
//        }
//    }
//    return tr;
//}

ll ymn, ymx, zmn, zmx;

ll yo[2][2];

ll gt(ll Z) {
    yo[0][0] = 4e18;
    yo[1][0] = 4e18;
    yo[0][1] = -4e18;
    yo[1][1] = -4e18;
    REP(i,n) {
        ll V = abs(z[i] - Z);
        MN(yo[0][0], x[i] + y[i] - V);
        MN(yo[1][0], x[i] - y[i] - V);
        MX(yo[1][1], x[i] + y[i] + V);
        MX(yo[0][1], x[i] - y[i] + V);
    }
    ll xpy2 = (yo[0][0] + yo[1][1]); // 2*(x+y)
    ll xmy2 = (yo[0][1] + yo[1][0]); // 2*(x-y)
    ll x4 = xpy2 + xmy2, y4 = xpy2 - xmy2;
    bool plx = x4>0, ply = y4>0;
    ll r1 = 1+((x4/2)&1), r2 = 1+((y4/2)&1);
    x4 /= 4; y4 /= 4;
    ll BG = 4e18+1;
    REP(XX, r1) REP(YY, r2) {
        ll xt = x4+(plx?XX:-XX); ll yt = y4+(ply?YY:-YY);
        ll bg = 0;
        REP(i,n) {
            MX(bg, abs(z[i] - Z) + abs(x[i] - xt) + abs(y[i] - yt));
        }
        if (bg < re.f) {
            re.f = bg;
            re.s = {{xt,yt,Z}};
        }
        MN(BG, bg);

    }
    return BG;
}



signed main(){
    IOS();

    int t; cin>>t;
    while (t--) {
        cin>>n;
        re = {4e18+1,{{-1,-1,-1}}};
        vector<array<ll, 3> > v(n);
        REP(i,n) REP(j,3) cin>>v[i][j];
        if (n == 1) {
            REP(i,3) cout<<v[0][i]<<' ';
            cout<<endl; continue;
        }

        sort(ALL(v));
        ymn = ymx = v[0][1];
        zmn = zmx = v[0][2];
//        vector<int> ys; ys.reserve(n);
        REP(i,n) {
            x[i] = v[i][0], y[i] = v[i][1], z[i] = v[i][2];
//            ys.pb(y[i]);
            MN(ymn, y[i]);
            MN(zmn, z[i]);
            MX(ymx, y[i]);
            MX(zmx, z[i]);
        }

        ll l = zmn, r = zmx;
        if (l == r) gt(l);
        while (l!=r) {
            ll mid = (l+r)/2 - (((l^r)&1) && (l+r<0));
            ll gm1 = gt(mid), gm2 = gt(mid+1);
            if (gm1 < gm2) {
                r = mid;
            }else l = mid+1;
            bug(l,r);
        }
        bug(l,r);
        REP(i,3) cout<<re.s[i]<<' ';
        cout<<endl;
    }

}