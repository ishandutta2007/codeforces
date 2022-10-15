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

const int M = 1e3+5;

double bar = log(3) / (double)log(2);

struct nb{
    int a,b; // 2^a * 3^b
    bool operator < (const nb &oth) const {
        return (a-oth.a) * log(2) < (oth.b-b) * log(3);
    }
    nb operator * (nb oth) {
        return {a+oth.a, b +oth.b};
    }
    nb operator / (nb oth) {
        return {a-oth.a, b -oth.b};
    }
};

int a[M][M];
int U[M][M],D[M][M],L[M][M],R[M][M];
int UL[M][M],UR[M][M],DL[M][M],DR[M][M];
nb u[M][M], l[M][M], ul[M][M], ur[M][M];
#define REP(i,n) for (int i = 0; i<(n); ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=(n); ++i)
#define RREP1(i,n) for (int i = n; i>0; --i)


signed main(){
    IOS();
    bug(bar);
    int n; cin>>n;
    REP1(i,n) REP1(j,n){
        char c; cin>>c;
        a[i][j] = c-'0';
    }
    bug("Hey");
    // remember to deal with all 0
    nb re = {0,0};
    bool X = 0;
    REP1(i,n){
        REP1(j,n) {

            if (a[i][j]) {
                X=1;
                U[i][j] = U[i-1][j]+1;
                L[i][j] = L[i][j-1]+1;
                UL[i][j] = UL[i-1][j-1]+1;
                UR[i][j] = UR[i-1][j+1]+1;

            }
            nb me = {a[i][j] == 2, a[i][j] == 3};
            u[i][j] = u[i-1][j] * me;
            l[i][j] = l[i][j-1] * me;
            ul[i][j] = ul[i-1][j-1] * me;
            ur[i][j] = ur[i-1][j+1] * me;
        }
    }
    if (X==0){
        cout<<0<<endl; return 0;
    }
    RREP1(i,n) RREP1(j,n){
        if (a[i][j]) {
            D[i][j] = D[i+1][j] + 1;
            R[i][j] = R[i][j+1] + 1;
            DL[i][j] = DL[i+1][j-1] + 1;
            DR[i][j] = DR[i+1][j+1] + 1;
        }
    }

    REP1(i,n) REP1(j,n) {
        // Deal with orthogonal
        if (a[i][j]) {
            int m = min(min(U[i][j], L[i][j]), min(D[i][j], R[i][j]));
            bug(i,j,m);
            nb me = l[i][j+m-1] / l[i][j-m];
            nb me2 = u[i+m-1][j] / u[i-m][j];
            bug(me.a, me.b, me2.a, me2.b);
            me = (me * me2) / (nb{a[i][j] == 2, a[i][j] == 3});
            if (re < me) {
                re = me;
            }
        }

    }
    bug(re.a, re.b);

    REP1(i,n) REP1(j,n) {
        // Deal with orthogonal
        if (a[i][j]) {
            int m = min(min(UL[i][j], UR[i][j]), min(DL[i][j], DR[i][j]));
            bug(i,j,m);
            nb me = ul[i+m-1][j+m-1] / ul[i-m][j-m];
            nb me2 = ur[i+m-1][j-m+1] / ur[i-m][j+m];
            me = (me * me2) / (nb{a[i][j] == 2, a[i][j] == 3});
            bug(me.a, me.b);

            if (re < me) {
                re = me;
            }
        }

    }

    bug(re.a, re.b);
    cout<<mpow(2,re.a) * mpow(3,re.b) % mod<<endl;

}