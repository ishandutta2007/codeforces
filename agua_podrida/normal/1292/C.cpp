#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
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
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
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
#define F first
#define S second
#define INF 1000000000
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

int n;

void dfs(vvi& grafo, vi& padre, int nodo){
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(hijo == padre[nodo]) continue;
        padre[hijo] = nodo;
        dfs(grafo,padre,hijo);
    }
}

void calcularTam(vvi& grafo, vi& padre, vi& tam, int nodo){
    tam[nodo] = 1;
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(hijo == padre[nodo]) continue;
        calcularTam(grafo,padre,tam,hijo);
        tam[nodo] += tam[hijo];
    }
}

ll calcularDP(vvll& dp, vvi& padre, vvi& tam, int u, int v){
    if(u == v) return 0;
    if(dp[u][v] == -1){
        dp[u][v] = calcularDP(dp,padre,tam,padre[v][u],v);
        maxi(dp[u][v],calcularDP(dp,padre,tam,u,padre[u][v]));
        dp[u][v] += (ll) (tam[u][v] * tam[v][u]);
    }
    return dp[u][v];
}

void c(){
    cin>>n;
    int u,v;
    vvi grafo(n+1);
    F0(i,n-1){
        cin>>u>>v;
        grafo[u].pb(v);
        grafo[v].pb(u);
    }

    vvi tam(n+1,vi(n+1));
    vvi padre(n+1,vi(n+1,-1));
    F1(i,n) dfs(grafo,padre[i],i);
    F1(i,n) calcularTam(grafo,padre[i],tam[i],i);

    vvll dp(n+1,vll(n+1,-1));
    ll res = 0;
    F1(u,n) F1(v,n) maxi(res,calcularDP(dp,padre,tam,u,v));

    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}