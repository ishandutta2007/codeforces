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

void a(){
    int n;
    cin>>n;
    if(n%2 == 0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vi res(2*n);
    int i = 0;
    while(i < n/2){
        res[2*i] = 4*i+1;
        res[2*i+n] = 4*i+2;
        res[2*i+1] = 4*i+4;
        res[2*i+1+n] = 4*i+3;
        i++;
    }
    res[n-1] = 2*n-1;
    res[2*n-1] = 2*n;
    F0(i,2*n) cout<<res[i]<<' ';
    cout<<'\n';
}

void eliminar(vi& v, int i){
    v[i] = v.back();
    v.pop_back();
}

void restaurar(vi& v, int aux, int i){
    v.pb(v[i]);
    v[i] = aux;
}

int distancia(vvi& grafo, int u, int v){
    queue<pi> q;
    q.push(mp(u,0));
    vbool visitados(grafo.size(),false);
    while(!q.empty()){
        pi p = q.front();
        q.pop();
        if(p.F == v) return p.S+1;
        if(visitados[p.F]) continue;
        visitados[p.F] = true;
        F0(i,grafo[p.F].size()) q.push(mp(grafo[p.F][i],p.S+1));
    }
    return INF;
}

int cicloCorto(vvi& grafo, int nodo){
    int res = INF;
    F0(i,grafo[nodo].size()){
        int aux = grafo[nodo][i];
        eliminar(grafo[nodo],i);
        mini(res,distancia(grafo,nodo,aux));
        restaurar(grafo[nodo],aux,i);
    }
    return res;
}

void b(){
    int n;
    cin>>n;
    vll a;
    ll aux;
    F0(i,n) {
        cin>>aux;
        if(aux != 0) a.pb(aux);
    }
    ll uno = 1;
    n = a.size();
    F0(j,63){
        int loTienen = 0;
        F0(i,n){
            if(a[i] & uno<<j) loTienen++;
        }
        if(loTienen >= 3){
            cout<<3<<'\n';
            return;
        }
    }
    vvi grafo(n);
    F0(u,n){
        REP(v,u+1,n-1){
            if(a[u] & a[v]){
                grafo[u].pb(v);
                grafo[v].pb(u);
            }
        }
    }
    int res = INF;
    F0(u,n){
        mini(res,cicloCorto(grafo,u));
    }
    if(res == INF) cout<<-1;
    else cout<<res;
    cout<<endl;
}

int main(){
    b();
    return 0;
}