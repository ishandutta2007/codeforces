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

const int maxn = 1e6+5;

ll sumto[maxn];

ll valof(int x){
    int num = sqrt(2*x+0.25)-0.5;
    return (num+1)*(ll)x-sumto[num];
}

vector<pii> g[maxn],gt[maxn];
int scc[maxn];
vector<int> ord;
int odeg[maxn];
map<int, int> sccg[maxn];
int nscc = 0;
bool seen[maxn];
ll sccv[maxn];
void d1(int v) {
    seen[v]=1;
    for (pii u : g[v]){
        if (!seen[u.f]){
            d1(u.f);
        }
    }
    ord.pb(v);
}
ll re = 0;
void d2(int v){
    seen[v]=1;
    scc[v]=nscc;
    for (pii u : gt[v]){
        if (!seen[u.f]){
            d2(u.f);
        }
        if (scc[u.f]==scc[v]){
            sccv[scc[u.f]] += valof(u.s);
        }else{
            sccg[scc[u.f]][scc[v]] = max(sccg[scc[u.f]][scc[v]], u.s);
        }
    }
}
signed main(){
    IOS();
    for(int i = 1; sumto[i-1]<1e14; i++){
        sumto[i] = sumto[i-1]+(i)*(ll)(i+1)/2;
//        bug(i,sumto[i]);
    }
    int n, m; cin>>n>>m;
    REP(i,m){
        int a, b; cin>>a>>b; --a; --b;
        int w; cin>>w;
        g[a].pb({b,w}); gt[b].pb({a,w});
    }
    int S; cin>>S;
    REP(i,n){
        if (!seen[i]) d1(i);
    }
    fill(seen, seen+n,0);
    RREP(i,n){
        if (!seen[ord[i]]) {
            bug(ord[i]);
            d2(ord[i]);
            nscc++;
        }
    }
    REP(i,n) bug(i,scc[i]);
    bug(nscc);
    queue<int> q;
    vector<vector<int> > rev(nscc);
    REP(i,nscc){
        odeg[i] = SZ(sccg[i]);
        for (pii u : sccg[i]) rev[u.f].pb(i);
        if (odeg[i]==0 && i < nscc) {
            q.push(i); bug("q",i);
        }
    }
    while (!q.empty()){
        int v = q.front(); q.pop();
        // v is an scc
        ll oth = 0;
        for (pii u : sccg[v]){
                bug(u.s);
            MX(oth, u.s+sccv[u.f]);
        }
        sccv[v]+=oth;
        bug(v, sccv[v]);
        for (int u : rev[v]){
            odeg[u]--; if (odeg[u]==0) q.push(u);
        }
    }
    cout<<sccv[scc[S-1]]<<endl;
    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}