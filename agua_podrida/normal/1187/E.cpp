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
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define INF 1000000000
#define todo(v) v.begin(),v.end()

void a(){
    int n,s,t;
    cin>>n>>s>>t;
    int st = s+t-n;
    s -= st;
    t -= st;
    cout<<max(1,max(s,t)+1)<<'\n';
}

bool sePuede(vvi& apariciones, vi& aT, int mid){
    if (mid == 0)
        return false;
    F0(i,26) if(apariciones[i][mid-1] < aT[i]) return false;
    return true;
}

void b(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vvi aparicionesEnPrefijoPorLetra(26,vi(n,0));
    F0(i,n){
        int pos = (int) s[i] - (int)'a';
        aparicionesEnPrefijoPorLetra[pos][i]++;
    }
    F1(i,n-1){
        F0(j,26){
            aparicionesEnPrefijoPorLetra[j][i] += aparicionesEnPrefijoPorLetra[j][i-1];
        }
    }
    int m;
    cin>>m;
    string t;
    F0(i,m){
        cin>>t;
        vi aT(26);
        F0(j,t.size()){
            int pos = (int) t[j] - (int)'a';
            aT[pos]++;
        }
        int lo = 0;
        int hi = n;
        while(lo+1 != hi){
            int mid = (lo+hi)/2;
            if(sePuede(aparicionesEnPrefijoPorLetra,aT,mid)) hi = mid;
            else lo = mid;
        }
        cout<<hi<<'\n';
    }
}

void c(){
    int n,m;
    cin>>n>>m;
    int t,l,r;
    vpi desordenados;
    vbool crece(n+1,false);
    F0(i,m){
        cin>>t>>l>>r;
        if(t == 1) {
            for(int k = l+1; k <= r; k++) crece[k] = true;
        }
        else desordenados.pb(mp(l,r));
    }
    bool sePuede = true;
    F0(i,desordenados.size()){
        bool creciente = true;
        REP(k,desordenados[i].F+1,desordenados[i].S) if(!crece[k]) creciente = false;
        if(creciente) sePuede = false;
    }

    if(sePuede){
        cout<<"YES\n";
        int i = 1;
        int num = 2000;
        while(i <= n){
            if(!crece[i]){
                num--;
                cout<<num<<' ';
                i++;
            }
            else {
                num++;
                cout<<num<<' ';
                i++;
            }
        }
        cout<<'\n';
    }
    else cout<<"NO\n";
}

void dfs(vvi& grafo, vi& padre, vvi& hijos, vbool& visto, int nodo){
    visto[nodo] = true;
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(visto[hijo]) continue;
        padre[hijo] = nodo;
        hijos[nodo].pb(hijo);
        dfs(grafo,padre,hijos,visto,hijo);
    }
}

void calcularCardinales(vll& cardinal, vvi& hijos, int nodo){
    F0(i,hijos[nodo].size()){
        calcularCardinales(cardinal,hijos,hijos[nodo][i]);
        cardinal[nodo] += cardinal[hijos[nodo][i]];
    }
    cardinal[nodo]++;
}

void calcularHaciaArriba(vll& res,vll& cardinal, vvi& hijos, int nodo){
    res[nodo] = cardinal[nodo];
    F0(i,hijos[nodo].size()){
        calcularHaciaArriba(res,cardinal,hijos,hijos[nodo][i]);
        res[nodo] += res[hijos[nodo][i]];
    }
}

void bajarResultado(vll& res, vll& cardinal, vi& padre, vvi& hijos, int nodo){
    if(padre[nodo] > 0){
        int papi = padre[nodo];
        res[nodo] += res[papi] - res[nodo] - cardinal[nodo];
        res[nodo] += res.size()-1 - cardinal[nodo];
    }
    F0(i,hijos[nodo].size()) bajarResultado(res,cardinal,padre,hijos,hijos[nodo][i]);
}

void e(){
    int n;
    cin>>n;
    vvi grafo(n+1);
    int u,v;
    F0(i,n-1){
        cin>>u>>v;
        grafo[u].pb(v);
        grafo[v].pb(u);
    }
    vi padre(n+1);
    vvi hijos(n+1);
    vbool visto(n+1,false);
    dfs(grafo,padre,hijos,visto,1);
    vll cardinal(n+1);
    calcularCardinales(cardinal,hijos,1);
    vll res(n+1);
    calcularHaciaArriba(res,cardinal,hijos,1);

    bajarResultado(res,cardinal,padre,hijos,1);
    ll optimo = 0;
    F1(i,n) maxi(optimo,res[i]);
    cout<<optimo<<'\n';
}


void f(){

}

int main(){
    e();
    return 0;
}