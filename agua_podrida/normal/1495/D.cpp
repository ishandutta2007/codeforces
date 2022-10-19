#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
const ll mod = 998244353;

const int N = 400;
int n,m;
ll res[N][N];
vvi g;
vi d[N];
bool ok[N];

void bfs(vi& d, int v){
    queue<pi> q;
    q.push({v,0});
    while(!q.empty()){
        if(d[q.front().first] == -1){
            d[q.front().first] = q.front().second;
            for(auto u : g[q.front().first]) q.push({u,q.front().second+1});
        }
        q.pop();
    }
}

ll resolverAux(int v, vi& coso){
    ll res = 1;
    for(auto w : coso) ok[w] = true;
    ok[v] = true;
    for(auto w : coso){
        ll cand = 0;
        for(auto u : g[w]) if(ok[u] and d[v][u]+1 == d[v][w]) cand++;
        res *= cand;
        res %= mod;
    }
    for(auto w : coso) ok[w] = false;
    ok[v] = false;
    return res;
}

vi coso[N];

ll resolver(int u, int v){
    vi caminoMinimo(d[u][v]+1,-1);
    F0(w,n){
        if(d[u][w] + d[v][w] == d[u][v]){
            if(caminoMinimo[d[u][w]] != -1)
                return 0;
            caminoMinimo[d[u][w]] = w;
        }
    }
    F0(i,d[u][v]+1) coso[i].clear();
    F0(w,n){
        if(d[u][w] + d[v][w] == d[u][v]) continue;
        if((d[u][w] - d[v][w] + d[u][v]) % 2) return 0;
        int x = (d[u][w] - d[v][w] + d[u][v]) / 2;
        if(d[w][caminoMinimo[x]] + d[u][caminoMinimo[x]] != d[u][w]) return 0;
        if(d[w][caminoMinimo[x]] + d[v][caminoMinimo[x]] != d[v][w]) return 0;
        coso[x].pb(w);
    }
    ll res = 1;
    F0(x,d[u][v]+1) res = (res * resolverAux(caminoMinimo[x],coso[x])) % mod;
    return res;
}

void D(){
    F0(i,n) ok[i] = false;
    cin>>n>>m;
    g = vvi(n);
    int u,v;
    F0(i,m){
        cin>>u>>v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    F0(i,n) d[i] = vi(n,-1);
    F0(i,n) bfs(d[i],i);
    F0(i,n) F0(j,n){
        if(d[i][j] == -1){
            F0(k,n) {
                F0(kk, n) cout << "0 ";
                cout << '\n';
            }
            return;
        }
    }

    F0(j,n) F0(i,j+1) res[i][j] = res[j][i] = resolver(i,j);

    F0(i,n) {
        F0(j,n) cout<<res[i][j]<<' ';
        cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    D();
}