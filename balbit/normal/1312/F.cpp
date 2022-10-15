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

const int maxn = 1e6+5;

int dp[maxn][3];
inline int mex(int a, int b) {
    if (a && b) return 0;
    if (a!=1 && b!=1) return 1;
    return 2;
}

inline int mex(int a, int b, int c) {
    if (a && b && c) return 0;
    if (a!=1 && b!=1 && c!=1) return 1;
    if (a!=2 && b!=2 && c!=2) return 2;
    return 3;
}

inline int mex(vector<int> a){
    SORT_UNIQUE(a);
    if (SZ(a) == 1) return a[0] == 0?1:0;
    if (SZ(a) == 2) return mex(a[0],a[1]);
    if (SZ(a) == 3) return mex(a[0],a[1], a[2]);
    if (SZ(a) == 4) return 4;
}

const int BB = 400;
int cyclen = -1;

inline int gt(ll x){
    return x <BB?x:(x-BB+125) % cyclen+BB-125;
}

signed main(){
    IOS();
    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        int x,y,z; cin>>x>>y>>z;
        vector<ll> a(n); for (int i = 0; i<n; ++i) cin>>a[i];
        for (int i = 0; i<5; ++i) for (int j = 0; j<3; ++j) dp[i][j] = 0;
        for (int i = 0; i<BB; ++i) {
            for (int j = 0; j<3; ++j) {
                if (!j) {
                    dp[i+5][j] = mex(dp[i+5-x][0],dp[i+5-y][1],dp[i+5-z][2]);
                }
                if (j == 1){
                    dp[i+5][j] = mex(dp[i+5-x][0],dp[i+5-z][2]);
                }
                if (j == 2) {
                    dp[i+5][j] = mex(dp[i+5-x][0],dp[i+5-y][1]);
                }
            }
        }
//        for (int j = 0; j<3; ++j) {
//            for (int i = 0; i<40; ++i) {
//                cout<<dp[i][j]<<' ';
//            }
//            cout<<endl;
//        }
        for (int i = BB; ; ++i) {
            for (int j = 0; j<3; ++j) {
                if (!j) {
                    dp[i+5][j] = mex(dp[i+5-x][0],dp[i+5-y][1],dp[i+5-z][2]);
                }
                if (j == 1){
                    dp[i+5][j] = mex(dp[i+5-x][0],dp[i+5-z][2]);
                }
                if (j == 2) {
                    dp[i+5][j] = mex(dp[i+5-x][0],dp[i+5-y][1]);
                }
            }
            bool mat=1;
            for (int j = 0; i-j>BB-125; ++j) {
                if (dp[i-j+5][0] != dp[BB-125-j+5][0] ||
                    dp[i-j+5][1] != dp[BB-125-j+5][1] ||
                    dp[i-j+5][2] != dp[BB-125-j+5][2]
                    ){
                        mat = 0; break;
                    }
            }
            if (mat) {
                cyclen = i - (BB-125); break;
            }
        }
        ll X = 0;
        int nm = 0;
//        vector<ll> god(n);
        int it = 0;
        for (ll &A : a) {
            --A;
            A = gt(A);
            int c = A+5;
            if (dp[c][0] == dp[c][1] && dp[c][1] == dp[c][2]) {
            }else{
//                nm++;
            }
//            god[it] = mex({dp[c-z][0],dp[c-z][1],dp[c-x][0],dp[c-x][1],dp[c-x][2],dp[c-y][0],dp[c-y][2]});
//            bug(it, A, god[it]);
            X ^= dp[c][0];
        }
        it = 0;
        bug(nm);
        int re = 0;
        for (ll A : a) {
            int c = A+5;

            X ^= dp[c][0];
//            if (dp[c][0] == dp[c][1] && dp[c][1] == dp[c][2]) {
//            }else{
////                nm--;
//            }
//            if (!nm){
                bug("HI");
                if (dp[(A-x)+5][0] == X) re++;
                if (dp[(A-y)+5][1] == X) re++;
                if (dp[(A-z)+5][2] == X) re++;
//            }

//            if (dp[c][0] == dp[c][1] && dp[c][1] == dp[c][2]) {
//            }else{
//                nm++;
//            }
                X ^= dp[c][0];
        }

        cout<<re<<endl;
    }


}