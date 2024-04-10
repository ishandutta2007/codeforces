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

const int maxn = 300+3;

ll under[maxn][maxn];
ll X[maxn], Y[maxn];

inline int gt(int i, int j, int k) {
    // is k under i -> j?    0 if not, 1 if under point, 2 if completely under
    if (X[i] > X[j]) swap(i,j);
    if (X[k] < X[i] || X[k] > X[j]) {
        return 0;
    }
    if ((Y[j] - Y[i]) * (X[k] - X[i]) + (X[j] - X[i]) * Y[i] > Y[k] * (X[j] - X[i])) {
        if (X[k] == X[i] || X[k] == X[j]) return 1;
        return 2;
    }else return 0;
}


signed main(){
    IOS();
    ll n; cin>>n;
    REP(i,n) cin>>X[i]>>Y[i];
    REP(i,n) {
        REP(j,i) {
            REP(k,n) {
                if (k == i || k == j) continue;
                under[i][j] += gt(i,j,k);
            }
            if (X[i] > X[j]) under[i][j] = -under[i][j];
            under[j][i] = -under[i][j];
        }
    }
    ll five = n * (n-1) * (n-2) * (n-3) * (n-4) / (1*2*3*4*5);
    ll four = 0, three = 0;

    REP(i,n) REP(j,i) REP(k,j) {
        bug(i,j,k);
        bug(under[i][j], under[j][k], under[k][i]);
        ll in = abs(under[i][j] + under[j][k] + under[k][i]);
        bug(in);
        in -= gt(i,j,k) + gt(j,k,i) + gt(k,i,j);
//        bug(in);
        bug(i,j,k,in); assert(in %2 == 0); in /= 2;
        four += in * (ll)(n-3-in);
//        three += in * (in-1) / 2;
    }
    bug(five, four, three);
    four /= 2;
    cout<<five - four <<endl;
}