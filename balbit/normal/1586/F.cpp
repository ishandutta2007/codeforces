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

const int maxn = 1e3+5;

int wei[maxn][maxn];
int cnt[maxn][maxn]; // number of this digit

signed main(){
    IOS();
    int n,k; cin>>n>>k;
    int nc = 1;
    while (mpow(k, nc) < n) ++nc;

    vector<int> yar(nc);
    REP(i,n) {
//        for (int t : yar) cout<<t<<' ';
//        bug("endl");
        REP(K,nc) {
            cnt[i][K] = yar[K];
        }
        REP(j,i) {
            for (int K = 0; K<nc; ++K) {
                if (cnt[j][K] < cnt[i][K]) {
                    wei[j][i] = K+1; break;
                }
            }
        }
        if (i != n-1) {
            yar[0]++;
            for (int j = 0; j<nc; ++j) {
                if (yar[j] >= k) {
                    yar[j] = 0; ++yar[j+1];
                }
            }
        }
    }
    cout<<nc<<endl;
    REP(i,n) {
        for (int j = i+1; j<n; ++j) {
            cout<<wei[i][j]<<' ';
        }
    }

}