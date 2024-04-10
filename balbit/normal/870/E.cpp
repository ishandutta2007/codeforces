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

ll inv (ll b){
    return b==1?1:(mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e5+5;

vector<int> g[maxn];
bool seen[maxn];
stack<int> sn;
bool cyc = 0;
int sz = 0;
void dfs(int v, int p) {
    seen[v]=1; sn.push(v);
    for (int u : g[v]) {
        if (u!=p) {
            if (seen[u]) cyc = 1;
            else dfs(u,v);
        }
    }
}

signed main(){
    IOS();
    int n; cin>>n;
    map<int, vector<int> > vx, vy;
    vector<pii> pts;
    REP(i,n){
        int x, y; cin>>x>>y;
        pts.pb({x,y});
        vx[x].pb(i);
        vy[y].pb(i);
    }
    for (auto & ele : vx) {
        FOR(i, 1, SZ(ele.s)) {
            g[ele.s[i]].pb(ele.s[i-1]);
            g[ele.s[i-1]].pb(ele.s[i]);
        }
    }
    for (auto & ele : vy) {
        FOR(i, 1, SZ(ele.s)) {
            g[ele.s[i]].pb(ele.s[i-1]);
            g[ele.s[i-1]].pb(ele.s[i]);
        }
    }
    ll re = 1;
    REP(i,n) {
        if (!seen[i]) {
            bug(i);
            cyc = 0;
            dfs(i,-1);
            int m = SZ(sn);
            if (cyc) {
                set<int> sx, sy;
                while (!sn.empty()) {
                    sx.insert(pts[sn.top()].f);
                    sy.insert(pts[sn.top()].s);
                    bug(sn.top());
                    sn.pop();
                }
                int num = SZ(sx) + SZ(sy);
                re *= mpow(2,num); re %= mod;
            }else{
                while (!sn.empty()) {
                    bug(sn.top());
                    sn.pop();
                }
                re *= mpow(2,m+1)-1; re %= mod;
            }
        }
    }
    cout<<(re+mod)%mod<<endl;
    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}