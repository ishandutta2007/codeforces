#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
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
const ll inf = 0x3f3f3f3f3f3f3f3f;
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

ll dp[1<<17][71];
int dst[71][71];

vector<int> ga[maxn];
vector<pii> g[maxn];


vector<int> vs;
int grp[maxn], BG[maxn]; // BG = big group

void dfs(int v, int col) {
    vs.pb(v);
    grp[v] = col;
    for (int u : ga[v]) {
        if (grp[u] == -1) {
            dfs(u, col);
        }
    }
}

ll ans[maxn];

signed main(){
    IOS();
    int n,m,A,B; cin>>n>>m>>A>>B;
    memset(dst, 0x3f, sizeof dst); // dst is the min number of A-edges needed to walk these two nodes
    REP(i,n) dst[i][i] = 0;
    vector<pii> sus;
    REP(i,m) {
        int a,b,w; cin>>a>>b>>w;
        --a; --b;
        if (w == A) {
            ga[a].pb(b); ga[b].pb(a);
            dst[a][b] = dst[b][a] = 1;
            g[a].pb({b,w}); g[b].pb({a,w});
        }else{
            sus.pb({a,b});
        }
    }



    REP(k,n) REP(i,n) REP(j,n) MN(dst[i][j], dst[i][k] + dst[k][j]);

    memset(grp, -1, sizeof grp);
    memset(BG, -1, sizeof BG);

    int IT = 0;

    REP(i,n) {
        if (grp[i] == -1) {
            vs.clear();
            dfs(i, i);
            if (SZ(vs) > 3) {
                for (int x : vs) {
                    BG[x] = IT;
//                    for (int y : vs) {
//                        if (dst[x][y] > 1) g[x].pb({y, dst[x][y] * A});
//                    }
                }
                ++IT;
            }
        }
    }

    for (pii P : sus) {
        if (grp[P.f] != grp[P.s]) {
            int a = P.f, b = P.s;
            g[a].pb({b,B}); g[b].pb({a,B});
        }
    }

    memset(dp, 0x3f, sizeof dp);
    memset(ans, 0x3f, sizeof ans);
    int startmsk = 0;
    if (~BG[0]) {
        startmsk = 1<<BG[0];
    }
    dp[startmsk][0] = 0;


    typedef pair<int, pii> piii;

    priority_queue<piii, vector<piii>, greater<piii> > pq;
    pq.push({0, {startmsk,0}});

    while (!pq.empty()) {
        auto E = pq.top(); pq.pop();
        int w = E.f, M = E.s.f, v = E.s.s; // careful, big M
        if (dp[M][v] != w) continue;
        MN(ans[v], dp[M][v]);
        int mybit = ((~BG[v])?(1<<BG[v]) : 0);
        for (pii ed : g[v]) {
            int u = ed.f;
            int bit = ((~BG[u])?(1<<BG[u]) : 0);
            if (bit != mybit && (M & bit)) continue;
            int tM = M | bit;
            if (dp[M][v] + ed.s < dp[tM][u]) {
                dp[tM][u] = dp[M][v] + ed.s;
                pq.push({dp[tM][u], {tM, u}});
            }
        }
    }

    REP(i,n) {
        cout<<ans[i]<<endl;
    }
}