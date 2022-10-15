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

const int maxn = 2e5+5;

ll sub[maxn], up[maxn]; // max in subtree, max above
ll w[maxn];
ll now = 0, re = inf;
ll bigval = 0;
vector<int >g[maxn];

void dfs1(int v, int p) {
    MX(bigval, w[v]);
    for (int u : g[v]) {
        if (u != p) {
            dfs1(u, v);
            MX(sub[v], max(sub[u], w[u]));
        }
    }
}

void dfs2(int v, int p) {
    bug(v+1, up[v], now+bigval);
    vector<int> subs;
    for (int u : g[v]) {
        if (u != p) {
            subs.pb(max(sub[u], w[u]));
        }
    }
    sort(ALL(subs), greater<int>());
    subs.pb(0);
    ll notme = max(sub[v], up[v]);
    ll need = max(0ll, w[v] - notme);
    MN(re, now + bigval + need);
    for (int u : g[v]) {
        if (u != p) {
            now -= max(w[u]-sub[u], 0ll);
            ll oth = max(up[v], max(sub[u], w[u]) == subs[0]?subs[1]:subs[0]);
            up[u] = max(oth, w[v]);
            now += max(w[v] - oth, 0ll);

            dfs2(u, v);

            now -= max(w[v] - oth, 0ll);
            now += max(w[u]-sub[u], 0ll);
        }
    }
}

signed main(){
    IOS();

    int n; cin>>n;
    REP(i,n) {
        cin>>w[i];
    }

    REP(i,n-1) {
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }

    dfs1(0, -1);
    REP(i,n) {
        if (i != 0) now += max(w[i] - sub[i], 0ll);
    }
    dfs2(0,-1);

    cout<<re<<endl;

}