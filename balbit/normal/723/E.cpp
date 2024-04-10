#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define CU(x) (x)*(x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e5+15;

int deg[maxn];

map<int, bool> used;

vector<pii> g[maxn];
int it[maxn];
vector<int> tour;
bool done[maxn];
bool odd[maxn];
int id = 0;

void hier(int at){
    for (int &i = it[at]; i<deg[at];) {
        int v = g[at][i].f;
        if (used.count(g[at][i].s)){
            i++;
            continue;
        }
        used[g[at][i].s] = 1;
        i++;
        hier(v);
        
        tour.pb(at);
    }
    // done[at]=1;
}

vector<int> vodd;

void dfs(int at){
    done [at] = 1;
    if (odd[at]) {
        vodd.pb(at);
    }
    for (pii v : g[at]){
        if (!done[v.f]) dfs(v.f);
    }
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T; cin>>T;
    while (T--){
        int n, m; cin>>n>>m;
        fill(deg, deg+n, 0);
        // fill(indeg, indeg+n, 0);
        fill(done, done+n, 0);
        fill(it, it+n, 0);
        fill(odd, odd+n, 0);
        REP(i, n) g[i].clear();
        id=0;
        used.clear();
        REP(i, m){
            int a, b; cin>>a>>b;
            a--; b--;
            g[a].pb({b, id});
            g[b].pb({a, id++});
            deg[a]++; deg[b]++;
        }
        int ndeg = 0;
        REP(i,n ){
            if (deg[i]%2==0){
                ndeg++;
            }else {
                odd[i]=1;
            }
        }
        cout<<ndeg<<'\n';
        REP(at,n){
            if (!done[at]){
                // cout<<"ALIVE"<<endl;
                vodd.clear();
                dfs(at);
                // cout<<"OEIJWOEIFJ"<<endl;
                assert(vodd.size() %2 == 0);
                int noprint = id;
                set<pii> nono;
                for (int i = 0; i+1 < vodd.size(); i+=2){
                    deg[vodd[i]]++; deg[vodd[i+1]]++;
                    g[vodd[i]].pb({vodd[i+1], id});
                    g[vodd[i+1]].pb({vodd[i], id++});
                    nono.insert({vodd[i], vodd[i+1]});
                    // cout<<vodd[i]<<" to "<<vodd[i+1]<<endl;
                }
                tour.clear();
                // cout<<"ALIE"<<endl;
                hier(at);
                // cout<<"FEOINF"<<endl;
                REP(i, SZ(tour)){
                    int a = tour[i], b = tour[(i+1)%SZ(tour)];
                    if (nono.count({a,b})) {
                        nono.erase({a,b}); continue;
                    }
                    if (nono.count({b,a})) {
                        nono.erase({b,a}); continue;
                    }
                    cout<<a+1<<" "<<b+1<<'\n';
                }
            }
        }
    }

} 

/*
1
7 2
3 7
4 2
*/