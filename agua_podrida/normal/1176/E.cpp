#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vbool;
int mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define INF 100000000
#define todo(v) v.begin(),v.end()

class unionFindPC {
public:
    unionFindPC(int n);
    int find(int i); // pre, el nodo est
    void unite(int s, int t);
private:
    vector<int> set; //en la posicin de cada elemento est su padre
    vector<int> peso; //peso
};

unionFindPC::unionFindPC(int n) {
    set = vector<int> (n);
    peso = vector<int> (n, 1);
    for(int i = 0; i< n; i++){
        set[i] = i; // al principio cada uno es su propio padre
    }
}

int unionFindPC::find(int i) {
    if(set[i] != i)
        set[i] = find(set[i]);
    return set[i];
}

void unionFindPC::unite(int s, int t) {
    int i = find(s);
    int j = find(t);
    if (i == j) return;
    if (peso[i] <= peso[j]) swap(i, j);
    set[j] = i;
    peso[i] += peso[j];
    peso[j] = 1;// tcnicamente no hace falta ponerlo, por invariante el peso me importa solamente en las races
}

void dfs(vvi& grafo, vbool& visitado, int nodo, vi& pares, vi& impares, bool esPar){
    if(visitado[nodo]) return;
    visitado[nodo] = true;
    if(esPar) pares.pb(nodo);
    else impares.pb(nodo);
    F0(i,grafo[nodo].size())
        dfs(grafo,visitado,grafo[nodo][i],pares,impares,!esPar);
}

void a(){
    int n,m;
    cin>>n>>m;
    vvi grafo(n+1);
    int u,v;
    while(m--){
        cin>>u>>v;
        grafo[u].pb(v);
        grafo[v].pb(u);
    }
    vbool visitado(n+1);
    vi pares;
    vi impares;
    dfs(grafo,visitado,1,pares,impares,true);
    if(pares.size() <= impares.size()){
        cout<<pares.size()<<'\n';
        F0(i,pares.size()) cout<<pares[i]<<' ';
        cout<<'\n';
    }
    else {
        cout<<impares.size()<<'\n';
        F0(i,impares.size()) cout<<impares[i]<<' ';
        cout<<'\n';
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) a();
    return 0;
}