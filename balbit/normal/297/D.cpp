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
const ll mod = 1e9+9;


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

const int maxn = 1005;

vector<int> lr[maxn];
vector<int> ud[maxn];

int re[maxn][maxn];

signed main(){
    IOS();
    int n, m, k; cin>>n>>m>>k;
    int nN = 0;
    int ntot = 0;
    REP(i,n) {
        if (i) REP(j,m) {
            char c; cin>>c; ud[i-1].pb(c=='N');
            nN += c=='E';
            ntot++;
        }
        REP(j,m-1) {
            char c; cin>>c; lr[i].pb(c=='N');
            nN += c=='E';
            ntot++;
        }
    }
    if (k==1) {
        if (nN*4 >= 3*ntot) {
            cout<<"YES"<<endl;
            REP(i,n) REP(j,m) cout<<1<<" \n"[j==m-1];
        }else{
            cout<<"NO"<<endl;
        }
        return 0;
    }
    bool swp = 0;
    if (n>m) {

        static vector<int> tl[maxn] = lr;
        static vector<int> tu[maxn] = ud;
        REP(i,maxn) lr[i].clear(), ud[i].clear();
        REP(i,m) {
            if (i) {
                REP(j,n) ud[i-1].pb(tl[j][i-1]);
            }
            REP(j,n-1) lr[i].pb(tu[j][i]);
        }
        swap(n,m);
         swp=1;
    }
    REP(i,n) {
        int score = 0;
        REP(j,m) {
            if (j) re[i][j] = re[i][j-1] ^ lr[i][j-1];
            else re[i][j]=0;
            if (i) {
                score += (re[i][j] ^ re[i-1][j]) == ud[i-1][j];
            }
        }
        if (i && score*2 < m) {
            bug(i);
            REP(j,m) re[i][j] ^= 1;
        }
    }
    cout<<"YES"<<endl;
    if (swp) {
        REP(j,m) REP(i,n) cout<<re[i][j]+1<<" \n"[i==n-1];
    }else{
        REP(i,n) REP(j,m) cout<<re[i][j]+1<<" \n"[j==m-1];
    }
}