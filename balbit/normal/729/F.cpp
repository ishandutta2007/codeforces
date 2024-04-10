#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
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

//const int maxn = 1e5+5;
const int MXv = 4005;
int rch[MXv/2+1][90][64][2]; // Answer for this state
bool done[MXv/2+1][90][64][2];
int ps[MXv];
int cnt = 0;
//int mk = 0, mdf = 0;
int n = 4000;
int mxA = 0;
int go(int A, int df, int k, bool Tp) {
//    MX(mxA, A);
    if (done[A][df][k][Tp])
        return rch[A][df][k][Tp];
//    int l, r;
    int re = 0;
//    bug("Done",A,df,k,Tp);
    done[A][df][k][Tp]=1;
    if (A+A+df>n) return rch[A][df][k][Tp]=iinf;
    if (A+A+df+k>n) return rch[A][df][k][Tp]=0;
    if (Tp == 0) {
        // Take from left
        re = max(
                 ps[A+k]-ps[A] - go(A+df,k-df, k,Tp^1),
                 ps[A+k+1]-ps[A]-go(A+df,k+1-df, k+1,Tp^1)
        );
    }else{
        re = max(
                 ps[n-A]-ps[n-A-k] - go(A+df, k-df, k, Tp^1),
                 ps[n-A]-ps[n-A-k-1]-go(A+df,k+1-df, k+1,Tp^1)
        );
    }
//    bug(A,df,k,Tp,re);
    return rch[A][df][k][Tp]=re;
}

signed main(){
    IOS();
    // 3079, 12
    cin>>n;
    REP(i,n) {
        cin>>ps[i+1]; ps[i+1] += ps[i];
    }
////    REP(i,MXv/2+100) REP(j,90) REP(k,64) REP(l,2) rch[i][j][k][l]=iinf;
    cout<<go(0,0,1,0)<<endl;
//    bug(mxA);
//    bug(cnt, mk, mdf);
}