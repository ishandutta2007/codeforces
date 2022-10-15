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

const int maxn = 2e5+5;

int a[maxn], clr[maxn],sdp[maxn],pdp[maxn];
vector<int> g[maxn];
int M = 0;
ll re = 0;
void dfs1(int v, int p) {
    if (a[v] < M) clr[v] = 1;
    int scl = 0, mxw = 0;
    for (int u : g[v]) {
        if (u!=p){
            dfs1(u,v);
            clr[v] += clr[u];
            if (clr[u] == 0) scl += sdp[u];
            else MX(mxw, sdp[u]);
        }
    }
    if (a[v] >= M) sdp[v] = 1 + scl + mxw;
    bug(v, sdp[v]);
}

void dfs2(int v, int p) {
    int scl = a[v]>=M;
    vector<int> mxw;

    if (v!=1) {
        if (clr[1] == clr[v]) {
            // Nothing in parent
            scl += pdp[v];
        }else{
            mxw.pb(pdp[v]);
        }
    }
//    if (SZ(g[v]) > 1) {
    for (int u : g[v]) {
        if (u!=p) {
            if (clr[u]==0) scl += sdp[u];
            else{
                mxw.pb(sdp[u]);
            }
        }
    }
    while (SZ(mxw) < 2) mxw.pb(0);
    nth_element(mxw.begin(), mxw.begin()+1, mxw.end(), greater<int> ());
    bug(v);
#ifdef BALBIT
        REP(i, SZ(mxw)) {
            cout<<mxw[i]<<' ';
        }
        cout<<endl;
#endif
    for (int u : g[v]) {
        if (u!=p) {
            if (a[v]>=M) {
                if (clr[u]==0) pdp[u] = scl-sdp[u]+mxw[0];
                else{
                    if (sdp[u] == mxw[0]) pdp[u] = scl + mxw[1];
                    else pdp[u] = scl + mxw[0];
                }
            }else{
                pdp[u] = 0;
            }
            dfs2(u,v);
        }
    }
    if (a[v] >= M)
        MX(re, mxw[0] + scl);
//    }
}

signed main(){
    IOS();
    int n, k; cin>>n>>k;
    REP(i,n) {
        cin>>a[i+1];
    }
    REP(i,n-1) {
        int x, y; cin>>x>>y;
        g[x].pb(y); g[y].pb(x);
    }
    int l = 0, r = 1e6+10;
    while (l!=r) {
        M = (l+r)/2;
        fill(clr, clr+n+1,0);
        fill(sdp, sdp+n+1,0);
        fill(pdp, pdp+n+1,0);
        re = 0;
        dfs1(1,-1);
        dfs2(1,-1);
        bug(l,r,re);
        if (re >= k) {
            l = M+1;
        }else{
            r = M;
        }
    }
    cout<<l-1<<endl;
    // Check your array bounds!
    // Think about corner cases (smallest or biggest?)
}