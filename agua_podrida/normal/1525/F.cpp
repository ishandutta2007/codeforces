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
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const ll mod = 1000000007;
const ll INF  = 1e9;
const double eps = 0.000000001;

int n,m,k,src,dst,u,v;
vi tengo_que_sacar;

bool bfs(vector<map<int,int>>& g, vi& padre, int src, int dst){
    F0(i,padre.size()) padre[i] = -1;
    queue<int> q;
    q.push(src);
    int nodo;
    while(!q.empty()){
        nodo = q.front();
        q.pop();
        forall(it,g[nodo]){
            if(padre[it->first] != -1) continue;
            if(it->second == 0) continue;
            padre[it->first] = nodo;
            if(it->first == dst) return true;
            q.push(it->first);
        }
    }
    return false;
}

int fordFulkerson(vector<map<int,int>>& g, int src, int dst){
    int flow = 0;
    vi padre(g.size());
    while(bfs(g,padre,src,dst)){
        //desde padre para atras busco el de minima capacidad
        int nodo = dst;
        int cuello = INF;
        while(nodo != src){
            int anterior = padre[nodo];
            mini(cuello,g[anterior][nodo]);
            nodo = anterior;
        }
        //sumo a flow
        flow += cuello;
        //actualizo grafo
        nodo = dst;
        while(nodo != src){
            int anterior = padre[nodo];
            g[anterior][nodo] -= cuello;
            g[nodo][anterior] += cuello;
            nodo = anterior;
        }
    }

    return flow;
}

void coso(vector<map<int,int>> g){
    vector<map<int,int>> h = g;
    int F = fordFulkerson(h,src,dst);
    int Fp;
    while(F > 0){
        h = g;
        F1(v,n) {
            h[src][v] = 0;
            Fp = fordFulkerson(h,src,dst);
            if(Fp < F){
                g[src][v] = 0;
                tengo_que_sacar.pb(v);
                break;
            }
            h = g;
        }
        if(Fp < F) {
            F = Fp;
            continue;
        }
        F1(v,n){
            h[v+n][dst] = 0;
            Fp = fordFulkerson(h,src,dst);
            if(Fp < F){
                g[v+n][dst] = 0;
                tengo_que_sacar.pb(-v);
                break;
            }
            h = g;
        }
        F = Fp;
    }
}

ll dp[51][51];
int nxt[51][51];
vll x,y;

ll f(int i, int j){
    if(i == k) return 0;
    if(dp[i][j] == -1){
        dp[i][j] = 0;
        F0(gasto,j+1) {
            if(j-gasto < n-i-1 and f(i+1,j-gasto) + max(0ll,x[i] - (ll) gasto * y[i]) > dp[i][j]){
                dp[i][j] = f(i+1,j-gasto) + max(0ll,x[i] - (ll) gasto * y[i]);
                nxt[i][j] = j-gasto;
            }
        }
    }
    return dp[i][j];
}

void F(){
    cin>>n>>m>>k;
    vector<map<int,int>> g(2*n+2);
    src = 0;
    dst = 2*n+1;
    F0(i,m){
        cin>>u>>v;
        g[u][v+n] = 1;
    }
    F1(i,n) g[src][i] = 1;
    F1(i,n) g[n+i][dst] = 1;
    coso(g);

    x = vll(k),y = vll(k);
    F0(i,k) cin>>x[i]>>y[i];

    F0(i,51) F0(j,51) dp[i][j] = -1;
    int M = fordFulkerson(g,src,dst);
    F0(i,k+1) F0(j,M+1) f(i,j);
    vi res;
    int i = 0, j = M;
    reverse(todo(tengo_que_sacar));
    while(i != k){
        int jp = nxt[i][j];
        F0(p,j-jp) res.pb((int) tengo_que_sacar.back()), tengo_que_sacar.pop_back();
        res.pb(0);
        i++, j = jp;
    }
    cout<<res.size()<<'\n';
    for(auto x : res) cout<<x<<' ';
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    F();
    return 0;
}