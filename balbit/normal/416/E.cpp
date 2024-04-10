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

const int maxn = 505;

ll g[maxn][maxn]; // Adjacency list
bool vis[maxn];
ll dst[maxn][maxn];
ll ans[maxn][maxn];
bitset<maxn> rch[maxn];
int odeg[maxn];
int into[maxn];

signed main(){
    IOS();
    int n, m; cin>>n>>m;
    REP(i,n) REP(j,n) dst[i][j]= (i==j)?0:inf, g[i][j]=inf;
    REP(i,m) {
        int a, b; cin>>a>>b; --a; --b;
        int w; cin>>w;
        g[a][b] = g[b][a] = dst[a][b] = dst[b][a] = w;
    }
    REP(k,n) REP(i,n) REP(j,n) {
        if (dst[i][j] > dst[i][k] + dst[k][j]) {
            dst[i][j] = dst[i][k] + dst[k][j];
        }
    }
    REP(st, n) {
        bug("Doing ", st);
        REP(i,n) {
            rch[i].reset();
            rch[i][i]=1;
            odeg[i]=0;
            into[i]=0;
        }
        REP(i,n) {
            FOR(j,0,n) {
                if (dst[st][i] + g[i][j] == dst[st][j] && dst[st][j]<inf-10000) {
                    odeg[i]++; into[j]++;
                    bug(i,j);
                }
            }
        }
        queue<int> q;
        REP(i,n) {
            if (odeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int j = q.front(); q.pop();
            REP(i,n) {
                if (dst[st][i] + g[i][j] == dst[st][j] && dst[st][j]<inf-10000) {
                    rch[i] |= rch[j];
                    odeg[i]--;
                    if (odeg[i]==0) q.push(i);
                }
            }
        }
        REP(i,n) {
            REP(j,n) {
                if (rch[i][j]) {
                    ans[st][j] += into[i];
                }
            }
        }
    }
    REP(i,n) {
        FOR(j,i+1,n) {
            cout<<ans[i][j]<<" ";
        }
    }

}