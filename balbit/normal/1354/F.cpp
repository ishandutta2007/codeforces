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

const int maxn = 1e6+5;

struct Edge{
    int to, rev;
    ll cost, cap, flow=0; // Can have negative flow!!!!!
    Edge(int to, int rev, ll cost, ll cap): to(to), rev(rev), cost(cost), cap(cap) {}
};

struct MCMF{
    int n, s, t;
    vector<int> par, id;
    vector<ll> dist;
    vector<vector<Edge> > g;
    MCMF(int n,int s,int t): n(n), s(s), t(t){
        par.resize(n); id.resize(n); dist.resize(n,inf);
        g.resize(n);
    }
    void add(int v, int u, ll f, ll c){
        g[v].pb({u,SZ(g[u]),c,f});
        g[u].pb({v,SZ(g[v])-1,-c,0});
    }
    bool spfa(){ // SPFA
        queue<int> q ({s});
        vector<int> vis(n,0);
        fill(ALL(dist), inf); dist[s] = 0;
        while (!q.empty()){
            int v = q.front(); q.pop();
            vis[v] = 0;
            for (int i = 0; i<SZ(g[v]); i++){
                Edge &e = g[v][i];
                if (e.cap - e.flow==0) continue;
                if (dist[e.to] > dist[v] + e.cost){
                    dist[e.to] = dist[v] + e.cost;
                    par[e.to] = v; id[e.to] = i;
                    if (!vis[e.to]){
                        q.push(e.to); vis[e.to] = 1;
                    }
                }
            }
        }
        return dist[t] != inf;
    }
    pair<ll, ll> mf(){
        pair<ll, ll> re = {0,0};
        while (spfa()){
            ll famt = inf;
            for (int v = t; v!=s; v = par[v]){
                Edge &e = g[par[v]][id[v]];
                MN(famt, e.cap - e.flow);
            }
            for (int v = t; v!=s; v = par[v]){
                Edge &e = g[par[v]][id[v]];
                e.flow += famt;
                g[e.to][e.rev].flow -= famt;
            }
            re.f += famt;
            re.s += dist[t] * famt;
        }
        return re;
    }
};

signed main(){
    IOS();

    int T; cin>>T;
    while (T--) {
        int n,k; cin>>n>>k;
        int N = n+k+3, S = N-1, T = N-2;
        MCMF dd(N,S,T);
        for (int j = 0; j<k; ++j) {
            dd.add(S,j+n,1,0);
        }
        int sb = 0;
        vector<pii> st;
        for (int i =0 ; i<n; ++i) {
            int a,b; cin>>a>>b; st.pb({a,b});
            sb += b * (k-1);
            for (int j = 0; j<k; ++j) {
                dd.add(j+n,i,1,-(j * b + a - b*(k-1)));
            }
            dd.add(i,T,1,0);
        }
        int fw = dd.mf().s;
        bug(fw, sb);
//        cout<<-fw+sb<<endl;
        vector<int> leave;
        vector<int> hv(n+1);
        for (int i = 0; i<n; ++i) {
            for (auto &e : dd.g[i]) {
                if (e.to == T && e.flow) {
                    bug(i,e.flow);
                    leave.pb(i);
                    hv[i] = 1;
                }
            }
        }
        sort(ALL(leave), [&](int a, int b){return st[a].s < st[b].s;});
        vector<int>re;
        for (int i = 0 ;i<SZ(leave)-1; ++i) {
            re.pb(leave[i]+1);
        }
        for (int i = 0; i<n; ++i) {
            if (!hv[i]) {
                re.pb(i+1); re.pb(-(i+1));
            }
        }
        re.pb(leave.back()+1);
        cout<<SZ(re)<<endl;
        for (int x : re) cout<<x<<' '; cout<<endl;
    }

}