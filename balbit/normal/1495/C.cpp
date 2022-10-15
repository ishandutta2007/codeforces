#include <bits/stdc++.h>
#undef BALBIT
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

int g[505][505];

signed main(){
    IOS();
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n,m; cin>>n>>m;
        REP(i,n) REP(j,m) {
            char c; cin>>c;
            if (c == '.') g[i][j] = 0;
            else g[i][j] = 2;
        }
        if (n == 1 || m == 1) {
            REP(i,n) {
                REP(j,m) cout<<'X';
                cout<<endl;
            }
            continue;
//            cout<<endl;
        }
        int sh = m%3==0?1:0;
        REP(j,m) {
            if (j % 3 != sh) {
                int oth = (j+1)%3==sh?j-1:j+1;
                if (g[1][j]==2 || (oth >=0 && oth < m && n > 1 && g[1][oth]==2) ) {
                    MX(g[1][j],1);
                }else{
                    MX(g[0][j], 1);
                }
            }
        }
        REP(i,n) REP(j,m) {
            if (j % 3 == sh) {
                MX(g[i][j], 1);
            }
        }
        REP(i,n) REP(j,m) {
            if (g[i][j] == 0) cout<<'.'; else cout<<'X';
            if (j ==m-1) cout<<'\n';
        }

    }


}