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
const int inf = 1e9+100;
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

typedef array<int, 5> Vec;
typedef array<Vec, 5> Mat;

Mat mo[maxn*4];
int need[5] = {2,0,1,7,-1};
int a[maxn];

void mul(Mat &c, Mat a, Mat b) {
    REP(i,5) fill(ALL(c[i]), inf);
    REP(i,5) REP(j,5) REP(k,5){
        MN(c[i][j], a[i][k] + b[k][j]);
    }
}
void mul(Vec &c, Vec a, Mat b) {
    fill(ALL(c), inf);
    REP(i,5) REP(j,5){
        MN(c[j], a[i] + b[i][j]);
    }
}

void build(int o, int l, int r) {
    if (l == r) {
        Mat & hi = mo[o];
        REP(i,5)REP(j,5) {
            hi[i][j] = inf;
        }
        if (a[l] != 6) {
            REP(i,5) {
                hi[i][i+(a[l] == need[i])]=0;
                if (a[l] == need[i]) {
                    hi[i][i] = 1;
                }
            }
        }else{
            REP(i,5) {
                if (i != 3 && i != 4) {
                    hi[i][i] = 0;
                }else{
                    hi[i][i] = 1;
                }
            }
        }
        return;
    }
    int mid = (l+r)/2;
    build(o*2,l,mid); build(o*2+1,mid+1,r);
    mul(mo[o], mo[o*2], mo[o*2+1]);
}





Vec now;

void QU(int L, int R, int o=1, int l=0, int r = maxn-1) {
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        mul(now, now, mo[o]);
        return;
    }
    int mid = (l+r)/2;
    QU(L,R, o*2, l, mid); QU(L,R,o*2+1, mid+1,r);
}


signed main(){
    IOS();
    int n,q; cin>>n>>q;
    REP(at,n) {
        char c; cin>>c;
        a[at] = c-'0';

    }

//    for (int j = 1; j < 19; ++j) {
//        REP(i,n) {
//            int to = i + (1<<(j-1));
//            if (to < n) {
//                mul(mo[j][i], mo[j-1][i], mo[j-1][to]);
//            }else{
//                mo[j][i] = mo[j-1][i];
//            }
//        }
//    }

    build(1, 0, n-1);

    while (q--) {
        int a,b; cin>>a>>b; --a; --b;
//        ++b;
//        Vec V;
        fill(ALL(now), inf);
        now[0] = 0;
        QU(a,b,1,0,n-1);
//        for (int j = 19-1; j>=0; --j) {
//            if (a + (1<<j) <= b) {
//                mul(now, now, mo[j][a]);
//                a+=(1<<j);
//            }
//        }
//        bug(a);
        ll ar = now[4];
        if (ar == inf) ar = -1;
        cout<<ar<<endl;
    }


}