#include <bits/stdc++.h>
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

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n,m; cin>>n>>m;
        vector<int> a(n+10,0);
//        vector<int> len;
        vector<int> ps;
        REP1(i,n) {
            char c; cin>>c;
            a[i] = c=='1';
//            cin>>a[i];
        }
        a[n+1] = 1;
//        a[n+2] = 1;
        int lst = -1;
        REP1(i,n+1) {
            if (a[i] == 1) {
                if (i == n+1) {
                    if (lst == -1) continue;
                    for (int j = 0; j<m; ++j) {
                        if (lst+1+j == i) break;
                        a[min(i, lst+1+j)] = 1;
                        bug(j);
                    }
                    break;
                }
                if (lst != -1) {
                    int len = i - lst - 1;
                    int stp = min(m, len/2);
                    for (int j = 0; j<stp; ++j) {
                        a[lst+1+j] = a[i-1-j] = 1;
                    }
                }else{
                    for (int j = 0; j<m; ++j) {
                        if (i-j-1==0) break;
                        a[max(0,i-j-1)] = 1;
                    }
                }
                lst = i;
            }
        }

//        REP1(i,n) {
//            if (a[i] == 0 && a[i-1] == 1) {
//                ps.pb(i);
//            }
//        }

//        REP1(i,n) {
//            if (a[i] == 1) {
//                REP1(j,m) {
//                    if (a[i-j] == 1) break;
//                    a[i-j] = 1;
//                }
//            }
//        }
//        for (int i = n; i>=1; --i) {
//            if (a[i] == 1) {
//                REP1(j,m) {
//                    if (a[i+j] == 1) break;
//                    a[i+j] = 1;
//                }
//            }
//        }
        REP1(i,n) cout<<a[i];
        cout<<endl;

    }

}