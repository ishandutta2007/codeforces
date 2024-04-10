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
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 1000000007;

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
#define INF 1e17
#define todo(v) v.begin(),v.end()
#define eps 0.000000001



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

struct Arista {
    Arista(ll c,int i,int j) {
        costo = c; u = i ; v = j;
    }

    bool operator<(Arista otra) { return costo < otra.costo;}
    ll costo;
    int u;
    int v;
};

int main() {
    int n;
    cin>>n;
    vpll ciudad(n+1);
    F1(i,n) cin>>ciudad[i].F>>ciudad[i].S;
    vll c(n+1);
    F1(i,n) cin>>c[i];
    vll k(n+1);
    F1(i,n) cin>>k[i];

    vector<Arista> aristas;
    F1(i,n){
        REP(j,i+1,n){
            ll costo = k[i] + k[j];
            costo *= abs(ciudad[i].F - ciudad[j].F) + abs(ciudad[i].S - ciudad[j].S);
            aristas.pb(Arista(costo,i,j));
        }
    }
    F1(i,n) aristas.pb(Arista(c[i],0,i));

    sort(todo(aristas));

    unionFindPC kruskal(n+1);

    int componentes = n+1;
    ll res = 0;
    vi plantas;
    vpi rutas;
    F0(i,aristas.size()){
        if(componentes == 1) break;
        ll costo = aristas[i].costo;
        int u = aristas[i].u;
        int v = aristas[i].v;
        if(kruskal.find(u) == kruskal.find(v)) continue;
        res += costo;
        kruskal.unite(u,v);
        if(u == 0) plantas.pb(v);
        else rutas.pb(mp(u,v));
    }

    cout<<res<<'\n';
    cout<<plantas.size()<<'\n';
    F0(i,plantas.size()) cout<<plantas[i]<<' ';
    cout<<'\n';
    cout<<rutas.size()<<'\n';
    F0(i,rutas.size()) cout<<rutas[i].F<<' '<<rutas[i].S<<'\n';
    return 0;
}