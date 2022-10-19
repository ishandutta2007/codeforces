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

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    F0(i,n) a[i] = ((a[i]+i)%n+n)%n;
    vb b(n,false);
    F0(i,n) b[a[i]] = true;
    int i = 0;
    while(i < n and b[i]) i++;
    if(i == n) cout<<"YES\n";
    else cout<<"NO\n";
}

int n,m;

bool hayHuecoEnFila(vvb& negro, int i){
    int j = 0;
    while(j < m and !negro[i][j]) j++;
    while(j < m and negro[i][j]) j++;
    while(j < m and !negro[i][j]) j++;
    return j < m;
}

bool hayHuecoEnColumna(vvb& negro, int j){
    int i = 0;
    while(i < n and !negro[i][j]) i++;
    while(i < n and negro[i][j]) i++;
    while(i < n and !negro[i][j]) i++;
    return i < n;
}

bool hayHueco(vvb& negro){
    F0(i,n) if(hayHuecoEnFila(negro,i)) return true;
    F0(j,m) if(hayHuecoEnColumna(negro,j)) return true;
    return false;
}

void dfs(vvb& negro, vvb& marcado, int i, int j){
    if(i < 0 or i >= n or j < 0 or j >= m)
        return;
    if(marcado[i][j] or !negro[i][j])
        return;
    marcado[i][j] = true;
    dfs(negro,marcado,i-1,j);
    dfs(negro,marcado,i+1,j);
    dfs(negro,marcado,i,j-1);
    dfs(negro,marcado,i,j+1);
}

void b(){
    cin>>n>>m;
    vvb negro(n,vb(m,false));
    char aux;
    F0(i,n) F0(j,m){
        cin>>aux;
        if(aux == '#') negro[i][j] = true;
    }

    vb filaOcupada(n,false);
    F0(i,n) F0(j,m) filaOcupada[i] = filaOcupada[i] or negro[i][j];
    vb columnaOcupada(m,false);
    F0(i,n) F0(j,m) columnaOcupada[j] = columnaOcupada[j] or negro[i][j];
    bool todasFilasOcupadas = true;
    F0(i,n) todasFilasOcupadas = todasFilasOcupadas and filaOcupada[i];
    bool todasColumnasOcupadas = true;
    F0(j,m) todasColumnasOcupadas = todasColumnasOcupadas and columnaOcupada[j];

    if(todasColumnasOcupadas != todasFilasOcupadas){
        cout<<"-1\n";
        return;
    }

    if(n == 1){
        if(negro[0][0]){
            int j = 0;
            while(j < m and negro[0][j]) j++;
            if(j < m) cout<<"-1\n";
            else cout<<"1\n";
        }
        else{
            int j = 0;
            while(j < m and !negro[0][j]) j++;
            if(j < m) cout<<"-1\n";
            else cout<<"0\n";
        }
        return;
    }

    if(m == 1){
        if(negro[0][0]){
            int i = 0;
            while(i < n and negro[i][0]) i++;
            if(i < n) cout<<"-1\n";
            else cout<<"1\n";
        }
        else {
            int i = 0;
            while(i < n and !negro[i][0]) i++;
            if(i < n) cout<<"-1\n";
            else cout<<"0\n";
        }
        return;
    }

    if(hayHueco(negro)){
        cout<<"-1\n";
        return;
    }

    int componentes = 0;
    vvb marcado(n,vb(m,false));
    F0(i,n) F0(j,m){
        if(negro[i][j] and !marcado[i][j]){
            dfs(negro,marcado,i,j);
            componentes++;
        }
    }
    cout<<componentes<<'\n';
}

bool dfs(vvi& grafo, vi& color, int nodo){
    if(color[nodo] == 2) return false;
    if(color[nodo] == 1) return true;
    color[nodo] = 1;
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        if(dfs(grafo,color,hijo)) return true;
    }
    color[nodo] = 2;
    return false;
}

bool hayCiclo(vvi& grafo){
    vi color(n+1);
    F1(i,n) if(dfs(grafo,color,i)) return true;
    return false;
}

void dfs2(vvi& grafo, vi& color, int componente, int nodo){
    if(color[nodo] != 0) return;
    color[nodo] = componente;
    F0(i,grafo[nodo].size()){
        int hijo = grafo[nodo][i];
        dfs2(grafo,color,componente,hijo);
    }
}

void c(){
    cin>>n>>m;
    vvi grafo(n+1);
    int u,v;
    F0(i,m){
        cin>>u>>v;
        grafo[u].pb(v);
    }

    if(hayCiclo(grafo)){
        cout<<"-1\n";
        return;
    }

    vi color(n+1);
    int componente = 0;
    F1(i,n) {
        if(color[i] == 0){
            componente++;
            dfs2(grafo,color,componente,i);
        }
    }

    vvi componentes(componente+1);
    F1(i,n) componentes[color[i]].pb(i);

    vb apunta(n+1,false);
    vb esApuntado(n+1,false);

    int res = 0;
    F1(c,componente){
        F0(j,componentes[c].size()){
            int nodo = componentes[c][j];
            F0(i,grafo[nodo].size()){
                int otro = grafo[nodo][i];
                esApuntado[otro] = true;
                apunta[nodo] = true;
            }
        }
        int apuntan = 0;
        int sonApuntados = 0;
        F0(j,componentes[c].size()) {
            int nodo = componentes[c][j];
            if(apunta[nodo]) apuntan++;
            if(esApuntado[nodo]) sonApuntados++;
        }
        if(sonApuntados > apuntan){
            F0(j,componentes[c].size()) {
                int nodo = componentes[c][j];
                swap(apunta[nodo],esApuntado[nodo]);
            }
        }
        res += min(apuntan,sonApuntados);
    }
    string asignacion;
    F1(i,n) {
        if(esApuntado[i]) asignacion.pb('E');
        else asignacion.pb('A');
    }
    cout<<res<<'\n';
    cout<<asignacion<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    b();
    return 0;
}