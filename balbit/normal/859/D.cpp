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

int w[66][66];
double mem[66*4][66];
double ch[66*4][66];

double ans(int o, int l, int r, int win) {
    if (l==r) {
        mem[o][win] = 0;
        ch[o][win]=1;
        return 0;
    }
    if (mem[o][win] !=-1) return mem[o][win];
    int mid = (l+r)/2;
    if (win<=mid) {
        mem[o][win] = ans(o*2,l,mid,win);
        ch[o][win] = ch[o*2][win];
        double ev = 0;
        double totch = 0;
        double secd = 0;
        FOR(j,mid+1,r+1) {
            ans(o*2+1,mid+1,r,j);
            ev += ch[o*2+1][j]*w[win][j]/100.0;
            MX(secd,mem[o*2+1][j]);
            totch += ch[o*2+1][j];
        }
        ch[o][win] *= ev;
        mem[o][win] += ch[o][win] * (r-l+1)/2 + secd;
//        if (totch!=1) {
//            bug(totch);
//            assert(0);
//        }
    }
    else {
        mem[o][win] = ans(o*2+1,mid+1,r,win);
        ch[o][win] = ch[o*2+1][win];
        double ev = 0;
        double totch = 0;
        double secd = 0;
        FOR(j,l,mid+1) {
            ans(o*2,l,mid,j);
            ev += ch[o*2][j]*w[win][j]/100.0;
            MX(secd,mem[o*2][j]);
            assert(mem[o*2][j] >= 0);
            totch += ch[o*2][j];
        }
        ch[o][win] *= ev;
        mem[o][win] += ch[o][win] * (r-l+1)/2 + secd;
//        if (totch!=1) {
//            bug(l,r,mid,win,totch);
//            assert(0);
//        }
    }
    return mem[o][win];
}

signed main(){
    IOS();
    int n; cin>>n;
    n = 1<<n;
    REP(i,n) REP(j,n) {
        cin>>w[i][j];
    }
    REP(i,66*4) REP(j,66) mem[i][j]=-1;
    double re = 0;
    REP(i,n) {
        MX(re, ans(1,0,n-1,i));
    }
    cout<<fixed<<setprecision(10)<<re<<endl;
}