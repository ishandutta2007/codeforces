#include <bits/stdc++.h>
//#pragma GCC optimize("unroll-loops")
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

const int maxn = 1500+5;

int who[2][maxn][11];
int d[2][maxn][11];
int a[maxn][maxn];

vector<int> un(vector<int> &a, vector<int> &b) {
    if (a[0] == -1 || b[0] == -1) return {-1};
    int j = 0;
//    a.pb(c);
    vector<int> re; a.pb(1000000000);
//    bug("IN");
    REP(i, SZ(a)) {
        while (j < SZ(b) && b[j] < a[i]) {
//            if (b[j] >= c) {
//                if (b[j] != c)
//                    re.pb(c);
//                c = 1000000000;
//            }
            re.pb(b[j]); ++j;
        }
        if (j<SZ(b) && b[j] == a[i]) ++j;
//        if (a[i] >= c) {
//            if (a[i] != c)
//                re.pb(c);
//            c = 1000000000;
//        }
        re.pb(a[i]);
    }
    re.pop_back(); a.pop_back();
//    bug("OUT");
    return re;
}

bool have[maxn*maxn];
//void ins(vector<int> &a, int c) {
//    have[c]=1;
//    auto it = lower_bound(ALL(a), c);
////    if (it != a.end() && *it == c) return;
//    a.insert(it,c);
//}

int ans[maxn];

signed main(){
    IOS();
    int n,q; cin>>n>>q;
    REP(i,n) {
        REP(c,q) {
            who[0][i][c]=-1;
        }
    }
    REP(c,q)
        who[1][0][c]=-1;
    int BB = 0;
    REP1(i,n) REP1(j,n) cin>>a[i][j];
    REP1(i,n) {
        BB ^= 1;
        REP1(j,n) REP(c,q) who[BB][j][c]=-1, d[BB][j][c] = 0;
        REP1(j,n) {
            who[BB][j][0] = a[i][j];
            d[BB][j][0] = 1;
            int lc = 0, rc = 0;
            have[a[i][j]] = 1;
            int nowcol = 1;
//            vector<int> seen; seen.reserve(14); seen.pb(a[i][j]);
            while(1){
                if (lc >= q || rc >= q || d[BB][j-1][lc] == 0 || d[BB^1][j][rc] == 0) {
                    break;
                }
                int smol = min(d[BB][j-1][lc] , d[BB^1][j][rc]);
//                vector<int> things = un(who[BB][j-1][lc], who[BB^1][j][rc]);
//                ins(things, a[i-smol][j-smol]);
//                ins(things, a[i][j]);
//                vector<int> nw;
                bool bad = 0;
                auto go = [&]( int x) {
                    if (!have[x]) {
                        if (nowcol == q) {
                            bad = 1; return;
                        }
                        have[x] = 1; //seen.pb(x);
                        who[BB][j][nowcol] = x;
                        MX(d[BB][j][nowcol] , d[BB][j][nowcol-1]);
                        ++nowcol;
                    }
                };
//                if (nowcol < q)
                    go(who[BB][j-1][lc]);
//                if (nowcol < q)
                    go(who[BB^1][j][rc]);
                if( !bad )
                    MX(d[BB][j][nowcol-1],smol );
//                if (nowcol < q)
                    go(a[i-smol][j-smol]);
                if( !bad )
                    MX(d[BB][j][nowcol-1] , smol+1);
                else break;
//                if (SZ(thug) > q || thug[0] == -1) break;
//                int so = SZ(thug)-1;
//                if (d[BB][j][so] < smol+1) {
//                    d[BB][j][so] = smol+1;
//                    who[BB][j][so] = thug;
//                }
                if (d[BB][j-1][lc] == smol) ++ lc;
                else ++rc;
            }
            int bg = d[BB][j][nowcol-1];
//            for (int x : seen) have[x] = 0;
            REP(k, nowcol) have[who[BB][j][k]] = 0;
            #ifdef BALBIT
            bug(i,j,bg, nowcol);
            REP(k, nowcol) {
                cout<<who[BB][j][k]<<' ';
            }
//            for (int x : who[BB][j][q-1]) cout<<x<<' ';
            cout<<endl;
            bug("mm");
            #endif
            ans[bg+1]--;
        }
    }
    ans[1] += n*n;
    REP1(i,n) {
        ans[i] += ans[i-1]; cout<<ans[i]<<'\n';
    }
}