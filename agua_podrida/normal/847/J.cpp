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
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)

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

int n,m;


int fordFulkerson(vector<map<int,int>>& g, int src, int dst){
    int flow = 0;
    int res = 0;
    vi padre(g.size());
    while(flow < m) {
        F1(i,n) g[m+i][n+m+1]++;
        res++;
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
    }

    return res;
}

void j(){
    cin>>n>>m;
    vpi E(m+1);
    int u,v;
    vector<map<int,int>> g(n+m+2);
    //0 fuente
    //1..m aristas
    //m+1..m+n alumnxs
    //m+n+1 sumidero
    F1(i,m) g[0][i] = 1;
    F1(i,m){
        cin>>u>>v;
        E[i] = {u,v};
        g[i][m+u] = 1;
        g[i][m+v] = 1;
    }

    cout<<fordFulkerson(g,0,n+m+1)<<'\n';

    F1(e,m){
        tie(u,v) = E[e];
        if(g[m+u][e] > 0) cout<<u<<' '<<v<<'\n';
        else cout<<v<<' '<<u<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../evolution/evolution-11-common-endings.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    j();
    return 0;
}