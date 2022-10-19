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
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    vpll student(n);
    ll a,b;
    F0(i,n){
        cin>>student[i].F;
    }
    F0(i,n){
        cin>>student[i].S;
    }
    sort(todo(student));
    vb adentro(n,false);
    ll res = 0;
    vll contenedores;
    F1(i,n-1){
        if(student[i].F == student[i-1].F){
            adentro[i] = true;
            adentro[i-1] = true;
            res += student[i-1].S;
            res += student[i].S;
            contenedores.pb(student[i].F);
            int j = i;
            while(i+1 < n and student[j].F == student[i+1].F) {
                i++;
                adentro[i] = true;
                res += student[i].S;
            }
        }
    }
    F0(i,n){
        if(adentro[i]) continue;
        ll algo = student[i].F;
        int j = 0;
        while(j < contenedores.size() and (contenedores[j] | algo) != contenedores[j]) j++;
        if(j < contenedores.size()) res += student[i].S;
    }
    cout<<res<<'\n';
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

void dfs(vvi& grafo, vvi& hijos, vb& visitado, int nodo){
    if(visitado[nodo]) return;
    visitado[nodo] = true;
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(!visitado[hijo]){
            hijos[nodo].pb(hijo);
            dfs(grafo,hijos,visitado,hijo);
        }
    }
}

void comprimir(vpll& gcds){
    vpll res;
    F0(i,gcds.size()){
        if(!res.empty() and gcds[i].F == res.back().F) res.back().S += gcds[i].S;
        else res.pb(gcds[i]);
    }
    gcds = res;
}

ll resolver(vvi&  hijos, vll& beauty, vpll& gcds, int nodo){
    ll res = 0;
    ll vi = beauty[nodo];
    vpll nuevosGcds;
    nuevosGcds.pb(mp(vi,1));
    F0(i,gcds.size()){
        ll b = gcds[i].F;
        ll apariciones = gcds[i].S;
        nuevosGcds.pb(mp(gcd(b,vi),apariciones));
    }
    sort(todo(nuevosGcds));
    comprimir(nuevosGcds);
    F0(i,nuevosGcds.size()) res = (res + nuevosGcds[i].F * nuevosGcds[i].S) % mod;
    F0(i,hijos[nodo].size()){
        res += resolver(hijos,beauty,nuevosGcds,hijos[nodo][i]);
        res %= mod;
    }
    return res;
}

void b(){
    int n;
    cin>>n;
    vll beauty(n+1);
    F1(i,n) cin>>beauty[i];
    vvi grafo(n+1);
    int u,v;
    F0(i,n-1){
        cin>>u>>v;
        grafo[u].pb(v);
        grafo[v].pb(u);
    }
    vvi hijos(n+1);
    vb visitado(n+1,false);
    dfs(grafo,hijos,visitado,1);
    vpll gcds;
    ll res = resolver(hijos,beauty,gcds,1);
    cout<<res<<'\n';
}

int main(){
    b();
    return 0;
}