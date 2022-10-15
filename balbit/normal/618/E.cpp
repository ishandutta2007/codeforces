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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 3e5+5;

#define double long double
#define acos acosl
#define cos cosl
#define sin sinl

const double PI = acos(-1);

double COS[360], SIN[360];
double X[maxn], Y[maxn];
int d[maxn];
int ang[maxn];
int nang[maxn];

const int BS = 800;

struct OP{
    bool add;
    int me;
    double px, py;
    int al;
};

signed main(){
    IOS();
    for (int i = 0; i<360; ++i) {
        COS[i] = cos(i*PI/180.0);
        SIN[i] = sin(i*PI/180.0);
        if (i % 90 == 0) bug(i,COS[i], SIN[i]);
    }
    int n,m; cin>>n>>m;
    fill(d, d+n+1, 1);

        cout<<fixed<<setprecision(9);
    for (int st = 0; st < m; st += BS) {
        int i2 = min(BS+st, m);
        ang[0] = nang[0];
        for (int i = 1; i<=n; ++i) {
            X[i] = X[i-1] + COS[ang[i-1]] * d[i-1];
            Y[i] = Y[i-1] + SIN[ang[i-1]] * d[i-1];
            ang[i] = (ang[i-1] + nang[i])%360;
        }
//        memset(nang, 0, sizeof nang);
        vector<OP > op;
        vector<int> upd(n,0);
        for (int i = st; i < i2; ++i) {
            int tp, me, v; cin>>tp>>me>>v;
            --me;
            for (int &it = upd[me]; it < SZ(op); ++it){
                OP & o = op[it];
                if (o.me <= me) {
                    if (o.add) {
                        X[me] += o.px; Y[me] += o.py;
                    }else{
                        double sx = X[me] - o.px, sy = Y[me] - o.py;
                        X[me] = sx * COS[o.al] - sy * SIN[o.al] + o.px;
                        Y[me] = sx *SIN[o.al] + sy * COS[o.al] + o.py;
                        ang[me] = (ang[me] + o.al) % 360;
                    }
                }
            }
            bug(me, X[me], Y[me]);
            bug(ang[me]);
            if (tp == 1) {
                op.pb({1,me+1,v*COS[ang[me]],v*SIN[ang[me]],0});
                d[me] += v;
            }else{
                v = 360-v;
                op.pb({0,me,X[me],Y[me],v});
                nang[me] += v; nang[me] %= 360;
                ang[me] %= 360;
            }

            OP &o = op.back();
            if (o.add) {
                X[n] += o.px; Y[n] += o.py;
            }else{
                double sx = X[n] - o.px, sy = Y[n] - o.py;
                X[n] = sx * COS[o.al] - sy * SIN[o.al] + o.px;
                Y[n] = sx *SIN[o.al] + sy * COS[o.al] + o.py;
            }

            cout<<X[n]<<' '<<Y[n]<<endl;
        }
    }



}