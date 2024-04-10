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
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    F0(i,n) cin>>a[i];
    F0(i,n) cin>>b[i];
    vi pos(n+1,-1);
    F0(i,n) pos[b[i]] = i;
    if(pos[1] != -1){
        int i = pos[1];
        while(i+1 < n and b[i+1] == b[i] + 1) i++;
        if(i+1 == n){
            int j = b[i]+1;
            int posReq = -1;
            while(j <= n and pos[j] <= posReq) {
                j++;
                posReq++;
            }
            if(j > n){
                cout<<pos[1]<<'\n';
                return;
            }
        }
    }
    int res = n;
    F1(i,n){
        if(pos[i] == -1) continue;
        maxi(res,pos[i]+n-i+2);
    }
    cout<<res<<'\n';
}

void dfs(vvi& grafo, vvi& hijos, vb& visitado,int nodo){
    if(visitado[nodo]) return;
    visitado[nodo] = true;
    F0(i,grafo[nodo].size()){
        int presuntoHijo = grafo[nodo][i];
        if(!visitado[presuntoHijo]) {
            hijos[nodo].pb(presuntoHijo);
            dfs(grafo,hijos,visitado,presuntoHijo);
        }
    }
}

ll calcular(vvi& hijos, vll& factorial, int nodo){
    if(hijos[nodo].empty()) return 1;
    ll res = hijos[nodo].size()+1;
    F0(i,hijos[nodo].size()) res = (res * calcular(hijos,factorial,hijos[nodo][i])) % mod;
    res *= factorial[hijos[nodo].size()];
    res %= mod;
    return res;
}

ll potencia(ll n, ll exp){
    if(exp == 0) return 1;
    ll res = potencia(n,exp/2);
    res = (res * res) % mod;
    if(exp % 2 == 1) res = (res*n) % mod;
    return res;
}

ll inverso(ll n){
    return potencia(n,mod-2);
}

void b(){
    int n;
    cin>>n;
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
    vll factorial(n+1);
    factorial[0] = 1;
    F1(i,n) factorial[i] = (factorial[i-1] * (ll) i) % mod;
    ll res = calcular(hijos,factorial,1);
    res *= inverso(hijos[1].size()+1);
    res %= mod;
    res *= n;
    res %= mod;
    cout<<res<<'\n';
}

int main(){
    b();
    return 0;
}