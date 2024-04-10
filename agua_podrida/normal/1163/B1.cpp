#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = a; i <=b; i++)
#define F1(i,n) for(int i = 1; i<= n;i++)
#define F0(i,n) for(int i = 0; i< n;i++)
#define forall(it,s) for(auto it = s.begin(); it != s.end(); it++)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define  F first
#define S second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;

void a(){
    int n,m;
    cin>>n>>m;
    if(m == 0) cout<<1<<'\n';
    else cout<<min(m,n-m)<<'\n';
}

void b(){
    vi cantidadPorColor(100005,0);
    vi coloresPorCantidad(100005,0);
    int n;
    cin>>n;
    coloresPorCantidad[0] = n;
    vi colores(100005,0);
    int res = 0;
    F1(i,n){
        int aux;
        cin>>aux;
        colores[i] = aux;
        coloresPorCantidad[cantidadPorColor[aux]]--;
        cantidadPorColor[aux]++;
        coloresPorCantidad[cantidadPorColor[aux]]++;
        //todos salvo un 1 agrego grande
        if(coloresPorCantidad[cantidadPorColor[aux]] * cantidadPorColor[aux] == i-1 && coloresPorCantidad[1] == 1)
            res = i;
        //todos salvo un uno agrego el uno
        if(cantidadPorColor[aux] == 1 && cantidadPorColor[colores[i-1]] * coloresPorCantidad[cantidadPorColor[colores[i-1]]] == i-1)
            res = i;
        //caso borde todos son uno
        if(coloresPorCantidad[1] == i) {
            res = i;
        }
        //todos igual salvo un +1 agrego el grande
        if(cantidadPorColor[aux] >= 2 && coloresPorCantidad[cantidadPorColor[aux]-1] * (cantidadPorColor[aux]-1) == i - cantidadPorColor[aux])
            res = i;
        //todos igual salvo un +1 agrego el chico
        int faltan = i - coloresPorCantidad[cantidadPorColor[aux]] * cantidadPorColor[aux];
        if(faltan == cantidadPorColor[aux]+1 && coloresPorCantidad[faltan] == 1)
            res = i;
    }
    cout<<res<<'\n';
}

int main(){
    b();
    return 0;
}