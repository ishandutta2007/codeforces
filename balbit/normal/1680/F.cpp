#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define int ll
#define f first
#define s second

#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)

#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)
#define pb push_back
#define SZ(x) (int)((x).size())

#define ALL(x) (x).begin(), (x).end()

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<" "<<#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do( T && x ) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do( T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif

const int maxn = 1e6+5;


int par[maxn], ps[maxn], dep[maxn];
int stamp[maxn];
int cant[maxn];
vector<int> g[maxn];
vector<int> tree[maxn];
bool seen[maxn];
int nbad = 0;
int most = 0;
int who = -1;
int ts = 0;
void dfs(int v, int p) {
    seen[v] = 1; par[v] = p;
    stamp[v] = ts++;
    if (p != -1) tree[p].pb(v);
    for (int u : g[v]) {
        if (u == p) continue;
        if (seen[u]) {
            if (stamp[u] > stamp[v]) continue;
            if (dep[u] == dep[v]) {
                // bad
                ps[v]++; ps[u]--;
                ++nbad;
            }else {
                cant[v] ++; cant[u]--;
            }
        }else{
            dep[u] = dep[v] ^ 1;
            dfs(u,v);
            ps[v] += ps[u];
            cant[v] += cant[u];
        }
    }
    bug(v, ps[v]);
    if (cant[v] == 0) if (ps[v] > most) {
        who = v; // the imposter (?!)
        most = ps[v];
    }
}

void d2(int v) {
    dep[v] ^= 1;
    for (int u : tree[v]) {
        d2(u);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    bug(1,2);
    int t; cin>>t;
    while (t--) {
        int n,m; cin>>n>>m;
        REP(i,n) {
            dep[i] = ps[i] = cant[i] = seen[i] = 0;
            g[i].clear(); tree[i].clear();
        }
        nbad = 0;
        vector<pii> ed;
        REP(i,m) {
            int a,b; cin>>a>>b;
            --a; --b;
            g[a].pb(b); g[b].pb(a);
            ed.pb({a,b});
        }
        most = 0; who = -1;
        dfs(0, -1);
        bug(most, nbad);
        if (most >= nbad || nbad <= 1) {
            cout<<"YES"<<endl;
            if (nbad > 1) {
                d2(who);
            }

            int test = 0;
            for (pii p : ed) {
                test += dep[p.f] && dep[p.s];
                if (!dep[p.f] && !dep[p.s]) test += 2;
            }

            bug(test);

            if (test > 1) {
                REP(i,n) dep[i] ^= 1;
            }

            REP(i,n) cout<<dep[i];
            cout<<endl;
        }else {
            cout<<"NO"<<endl;
        }

    }

}