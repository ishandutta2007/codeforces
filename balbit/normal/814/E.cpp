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

bool D = 0;
ll dp[2][54][54][54][54];
ll me;
inline void f(int a, int b,int c, int d, ll v) {
    if (v&&a>=0&&b>=0&&c>=0&&d>=0) {
        dp[D][a][b][c][d] = (dp[D][a][b][c][d] + v*me) % mod;
    }
}
#define REP(i,n) for (int i= 0; i<n; ++i)
signed main(){
    IOS();
    int n; cin>>n;
    vector<int> A(n);
    for (int i = 0; i<n; ++i) {
        cin>>A[i];
    }
    dp[0][A[0] == 3][A[0] == 2][A[1] == 3][A[1] == 2] ++;
    D = 1; // D is the layer we are updating
    for (int i = 2; i<n; ++i) {
        memset(dp[D], 0, sizeof dp[D]);
        if (A[i] == 2) {
            REP(a,51) REP(b,51) REP(c,51) REP(d,51) {
                me = dp[D^1][a][b][c][d];
                if (!me) continue;

                f(a-1,b+1,c-1,d+1,a*c);
                f(a,b-1,c-1,d+1,b*c);
                f(a-1,b+1,c,d-1,a*d);
                f(a,b-1,c,d-1,b*d);

                if (a==0 && b == 0) f(c-1,d+1,0,1,c);
                if (a==0 && b == 0) f(c,d-1,0,1,d);
                f(a-1,b+1,c,d+1,a);
                f(a,b-1,c,d+1,b);
            }
        }else{
            REP(a,51) REP(b,51) REP(c,51) REP(d,51) {
                me = dp[D^1][a][b][c][d];
                if (!me) continue;
                {// take 3
                    f(a-1,b+1,c-1,d-1+1,a*c*d);
                    f(a-1,b+1,c-2,d+2,a*c*(c-1)/2);
                    f(a-1,b+1,c,d-2,a*d*(d-1)/2);

                    f(a,b-1,c-1,d-1+1,b*c*d);
                    f(a,b-1,c-2,d+2,b*c*(c-1)/2);
                    f(a,b-1,c,d-2,b*d*(d-1)/2);
                }

                {// take 2
                    f(a-1,b+1,c-1,d+1+1,a*c);
                    f(a,b-1,c-1,d+1+1,b*c);
                    f(a-1,b+1,c,d-1+1,a*d);
                    f(a,b-1,c,d-1+1,b*d);
                }

                { // take 1
                    if (a==0 && b == 0) f(c-1,d+1,1,0,c);
                    if (a==0 && b == 0) f(c,d-1,1,0,d);
                    f(a-1,b+1,c+1,d,a);
                    f(a,b-1,c+1,d,b);
                }
            }
        }
        D^=1;
    }
    bug(dp[D][0][0][0][0]);
    cout<<dp[D^1][0][0][0][0]<<endl;
}