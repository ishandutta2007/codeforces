#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

#define int ll

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

const int maxn = 1e2+5;

char col[maxn][maxn];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

char g[maxn][maxn];


char id(int x){
    if (x<=9) return '0'+x;
    if (x-10<26) return 'a'+(x-10);
    return 'A' + (x-10-26);
}

main(){
    IOS();
    int T; cin>>T;
    while (T--){
        int n, m, ck;
        
        cin>>n>>m>>ck;

        int nr = 0;
        REP(i,n) REP(j,m){
            cin>>g[i][j]; 
            if (g[i][j] == 'R') {
                nr++; 
            }
        }
        int pc = nr / ck; int extra = nr - pc * ck;
        int nat = 0;
        int idat = 0;
        int left = nr;
        REP(i,n) {
            if (i%2==0) {
                REP(j,m){
                    col[i][j] = id(idat);
                    if (g[i][j] == 'R') {
                        nat ++; left--;
                    }
                    if (nat == (pc + (extra > 0))) {
                        extra --; nat =0; idat ++; 
                        if (left == 0) idat--;
                    }
                }
            }else{
                RREP(j,m){
                    col[i][j] = id(idat);
                    if (g[i][j] == 'R') {
                        nat ++; left--;
                    }
                    if (nat == (pc + (extra > 0))) {
                        extra --; nat =0; idat ++; 
                        if (left == 0) idat--;
                    }
                }
            }
        }
        REP(i,n )REP(j,m){
            cout<<col[i][j];
            if (j==m-1) cout<<'\n';
        }

    }
    
    
}