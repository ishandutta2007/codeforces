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

const int maxn = 2e5+5;
#define REP(i,n) for (int i = 0; i<n; ++i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
bool flp[maxn]; // does this edge flip?
vector<int> hv[maxn]; // which 2 points does this edge connect
vector<int> me[maxn]; // for each node, which numbers does it have
vector<pii> g[maxn]; // to, flip
// edges are 1-based
bool seen[maxn];
ll dp[maxn][2][2]; // v, my value, end xor
inline void f(ll &x){if(x>=mod)x-=mod;}
#define pll pair<ll,ll>

vector<pll> ways;
vector<int> vis;
int ev;
void dfs(int v, int p, bool fp) {
    vis.pb(v);
    seen[v] = 1;
    if (p!=-1) {
        if (SZ(me[v]) > 1) REP(a,2) REP(b,2) REP(r,2){
            dp[v][a][r] += dp[p][b^fp][(b|a)^r];
            f(dp[v][a][r]);
        }
        else REP(b,2) REP(r,2){
            dp[v][b][r] += dp[p][b^fp][r^b];
        }
    }
    int nto=0;
    for (pii x : g[v]) {
        if (x.f != p) {
            if (!seen[x.f]) {
                dfs(x.f,v,x.s);
                nto++;
            }
        }
    }
    if (nto == 0) {
        ev = v;
    }else assert(nto == 1);
}
ll d[maxn][2];
signed main(){
    IOS();
    int n,m; cin>>n>>m;
    for (int i = 0; i<n; ++i) {
        int k; cin>>k;
        REP(j,k){
            int x; cin>>x; hv[abs(x)].pb(i);
            me[i].pb(abs(x));
            flp[abs(x)] ^= (x > 0);
        }
    }
    REP1(i,m) {
        if (SZ(hv[i]) > 1) {
            assert(SZ(hv[i]) == 2);
            g[hv[i][0]].pb({hv[i][1], flp[i]});
            g[hv[i][1]].pb({hv[i][0], flp[i]});
        }
    }
    REP(i,n){
        if (SZ(g[i]) == 1 && !seen[i]) {
            if (SZ(me[i]) == 1) dp[i][0][0] = dp[i][1][1] = 1;
            else if (me[i][0] != me[i][1])
                dp[i][0][0]=1,dp[i][0][1]=1,dp[i][1][1]=2;
            else if (flp[me[i][0]]) {
                dp[i][0][1] = 2;
            }else{
                dp[i][0][0] = dp[i][1][1] = 1;
            }
            dfs(i,-1,0);
            bug(SZ(g[i]));
            if (SZ(g[i])) bug(g[i][0].f);
            bug(i, ev);
//            ways.pb({0,4});
            ways.pb({dp[ev][0][0] + dp[ev][1][0], dp[ev][1][1] + dp[ev][0][1]});
            assert(ways.back().f != 0 || ways.back().s != 0);
            bug(i);
            bug(ways.back().f, ways.back().s);
        }
        if (SZ(g[i]) == 0 && !seen[i]) {
            if (SZ(me[i]) == 1)
                ways.pb({1,1});
            else
            ways.pb({1,3});
            seen[i] = 1;
        }
    }
    ll remul = 1;
    REP1(i,m) {
        if (SZ(hv[i]) == 0) {
            remul = remul * 2 % mod;
        }
    }
    REP(i,n){
        if (!seen[i]) {
            if (g[i][0].f == i) {
                bug(g[i][0].s);
                if (g[i][0].s == 0)
                    ways.pb({1,1});
                else
                    ways.pb({0,2});
//                bug(ways.back().f, ways.back().s);
                continue;
            }

            bug("Starting with",i);
            assert(SZ(g[i]) == 2);
            ll w0 = 0, w1 = 0;
            bool F = g[i][1].s;

            REP(a,2) REP(b,2) {
                if (a || b)
                for (int x : vis) memset(dp[x],0,sizeof dp[x]),seen[x]=0;
                vis.clear();
                dp[i][b][a|b] = 1;
                dfs(i,-1,0);
                w0 += dp[ev][F^a][0];
                w1 += dp[ev][F^a][1];
            }

            ways.pb({w0%mod,w1%mod});
//            assert(w0 != 0 || w1!=0);
            bug(w0, w1);
        }
    }
//    for (pll &p : ways) {
//        if (p.f == 0 && p.s == 0) while(1);
//    }
    d[0][0] = 1;
    for (int i = 0; i<SZ(ways); ++i) {
        d[i+1][0] = d[i][0] * ways[i].f + d[i][1] * ways[i].s;
        d[i+1][1] = d[i][0] * ways[i].s + d[i][1] * ways[i].f;
        d[i+1][0] %= mod; d[i+1][1] %= mod;
    }
//    assert(d[SZ(ways)][1] >0 || d[SZ(ways)][0] >0);
    cout<<d[SZ(ways)][1]*remul%mod<<endl;

}