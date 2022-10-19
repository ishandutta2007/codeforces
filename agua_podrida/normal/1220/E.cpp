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
ll mod = 998244353;

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
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void dfs1(vvi& grafo, vi& padre, int nodo){
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(padre[hijo] != 0) continue;
        padre[hijo] = nodo;
        dfs1(grafo,padre,hijo);
    }
}

ll dfs2(vvi& grafo, int nodo, vll& w, vb& marca){
    ll res = 0;
    marca[nodo] = true;
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(marca[hijo]) continue;
        maxi(res,dfs2(grafo,hijo,w,marca));
    }
    res += w[nodo];
    return res;
}

void tourism(){
    int n,m;
    cin>>n>>m;
    vll w(n+1);
    F1(i,n) cin>>w[i];
    int u,v;
    vvi grafo(n+1);
    vpi aristas;
    F0(i,m){
        cin>>u>>v;
        grafo[u].pb(v);
        grafo[v].pb(u);
        aristas.pb(mp(u,v));
    }
    int s;
    cin>>s;

    vi padre(n+1);
    padre[s] = -1;
    dfs1(grafo,padre,s);

    vb marca(n+1);
    marca[s] = true;
    F0(i,m){
        u = aristas[i].first;
        v = aristas[i].second;
        if(padre[u] == v or padre[v] == u) continue;
        marca[u] = true;
        marca[v] = true;
    }

    F1(i,n){
        if(!marca[i]) continue;
        int nodo = padre[i];
        while(nodo != -1 and !marca[nodo]){
            marca[nodo] = true;
            nodo = padre[nodo];
        }
    }
    ll res = 0;
    F1(i,n) if(marca[i]) res += w[i];

    ll maxArbol = 0;
    F1(i,n){
        if(marca[i]) continue;
        if(!marca[padre[i]]) continue;
        maxi(maxArbol,dfs2(grafo,i,w,marca));
    }
    res += maxArbol;

    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    tourism();
    return 0;
}