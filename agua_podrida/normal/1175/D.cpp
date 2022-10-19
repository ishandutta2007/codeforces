#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<bool> vbool;
typedef unsigned int uint;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first;
#define S second;

bool hayCoincidencia(vi& a, vi& b){
    int i = 0;
    int j = 0;
    while(i< a.size() && j < b.size() && a[i] != b[j]){
        if(a[i] < b[j]) i++;
        else j++;
    }
    return i<a.size() && j<b.size();
}

ll potenciaModulo(ll base, ll exp, ll m){
    if(exp == 0) return 1;
    return (base * potenciaModulo(base,exp-1,m)) % m;
}

void letitflow(int x){
    int m = 1000000007;
    ll n;
    cin>>n;
    string G0, G1, G2;
    cin>>G0>>G1>>G2;
    cout<<"Case #"<<x<<": ";
    if(n % 2 == 1){
        cout<<0<<endl;
        return;
    }
    if(G0[0] == '#'){
        cout<<0<<endl;
        return;
    }
    if(G2[n-1] == '#'){
        cout<<0<<endl;
        return;
    }
    F0(i,n){
        if(G1[i] == '#'){
            cout<<0<<endl;
            return;
        }
    }
    vi obstAb, obstArr;
    F1(i,n-2){
        if(G0[i] == '#'){
            obstArr.pb((i-1)/2);
            if(i%2 == 1) i++;
        }
    }
    F1(i,n-2){
        if(G2[i] == '#'){
            obstAb.pb((i-1)/2);
            if(i%2 == 1) i++;
        }
    }
    if(hayCoincidencia(obstAb,obstArr)){
        cout<<0<<endl;
        return;
    }
    ll cantObstrucciones = (ll) obstAb.size() + (ll) obstArr.size();
    ll exp = (n-2)/2 - cantObstrucciones;
    if(exp < 0){
        cout<<0<<endl;
        return;
    }
    ll base = 2;
    ll res = potenciaModulo(base,exp,m);
    cout<<res<<endl;
}

vi obtenerPreorder(int raiz, vi& hijosIzq,vi& hijosDer){
    if(raiz == 0) return {};
    vi izq = obtenerPreorder(hijosIzq[raiz],hijosIzq,hijosDer);
    vi der = obtenerPreorder(hijosDer[raiz],hijosIzq,hijosDer);
    vi res;
    res.eb(raiz);
    F0(i,izq.size()) res.eb(izq[i]);
    F0(i,der.size()) res.eb(der[i]);
    return res;
}

vi obtenerPostorder(int raiz, vi& hijosIzq,vi& hijosDer){
    if(raiz == 0) return {};
    vi izq = obtenerPostorder(hijosIzq[raiz],hijosIzq,hijosDer);
    vi der = obtenerPostorder(hijosDer[raiz],hijosIzq,hijosDer);
    vi res;
    F0(i,izq.size()) res.eb(izq[i]);
    F0(i,der.size()) res.eb(der[i]);
    res.eb(raiz);
    return res;
}

void pintarCiclo(vi& ciclos, int i, int& cantCiclos, vi& grafo){
    if(ciclos[i] != -1) return;
    cantCiclos++;
    while(ciclos[i] == -1){
        ciclos[i] = cantCiclos;
        i = grafo[i];
    }
}

void ethanTraversesATree(int x){
    int n,k;
    cin>>n>>k;
    vi hijosIzq(n+1);
    vi hijosDer(n+1);
    F1(i,n)
        cin>>hijosIzq[i]>>hijosDer[i];
    vi preOrder = obtenerPreorder(1,hijosIzq,hijosDer);
    vi postOrder = obtenerPostorder(1,hijosIzq,hijosDer);
    vi grafo(n+1);
    F1(i,n)
        grafo[preOrder[i-1]] = postOrder[i-1];
    vi ciclos(n+1,-1);
    int cantCiclos = 0;
    F1(i,n){
        pintarCiclo(ciclos,i,cantCiclos,grafo);
    }
    if (cantCiclos < k){
        cout<<"Case #"<<x<<": "<<"Impossible"<<endl;
        return;
    }
    F1(i,n)
        ciclos[i] = min(ciclos[i],k);
    cout<<"Case #"<<x<<": ";
    F1(i,n)
        cout<<ciclos[i]<<" ";
    cout<<endl;
}

void calcularAlturas(vll& H, ll W, ll X, ll Y, ll Z, int n){
    for(int i = 3; i <= n; i++)
        H[i] = (W * H[i-2] + X * H[i-1] + Y) % Z;
}

void calcularIntervalosCrecimiento(vll& H, vpi& intCrec, vpi& intDecrec, int n){
    int i = 0;
    while(i < n){
        int comienzo = i;
        while(i < n && H[i] <= H[i+1]) i++;
        intCrec.eb(mp(comienzo,i));
        comienzo = i;
        while(i < n && H[i] >= H[i+1]) i++;
        intDecrec.eb(mp(comienzo,i));
    }
}

void platformParkour(int x){
    int n,m;
    cin>>n>>m;
    vll H(n+1);
    ll W,X,Y,Z;
    cin>>H[1]>>H[2]>>W>>X>>Y>>Z;
    calcularAlturas(H,W,X,Y,Z,n);
    vll src(m+1);
    vll dst(m+1);
    vll up(m+1);
    vll down(m+1);
    F1(i,m)
        cin>>src[i]>>dst[i]>>up[i]>>down[i];
    vpi intCrec, intDecrec;
    calcularIntervalosCrecimiento(H,intCrec,intDecrec,n);
    //Calcular limites arriba abajo para ambos lados

    //Resolver para cada intervalo (creciente o decreciente) para los dos lados. SOLO BAJANDO ALTURAS

    //Devuelvo el maximo dividido 2
}

void a(){
    ll n,k;
    cin>>n>>k;
    ll pasos = 0;
    while(n != 0){
        if(n % k == 0) {
            n/=k;
            pasos++;
        }
        else {
            pasos += n%k;
            n -= n%k;
        }
    }
    cout<<pasos<<endl;
}

void b(){
    int n;
    cin>>n;
    ll limite = 4294967295;
    string aux;
    vll fors;
    ll res = 0;
    ll prod = 1;
    int prodEnOverflow = 0;
    F0(i,n){
        cin>>aux;
        if(aux == "add"){
            if(prod + res > limite || prodEnOverflow > 0){
                cout<<"OVERFLOW!!!"<<endl;
                return;
            }
            res += prod;
        }
        else if(aux == "for"){
            int forn;
            cin>>forn;
            fors.eb(forn);
            if(prod * forn > limite || prodEnOverflow > 0){
                prodEnOverflow++;
            }
            else{
                prod *= forn;
            }
        }
        else {
            if(prodEnOverflow > 0){
                prodEnOverflow--;
            }
            else {
                prod /= fors.back();
            }
            fors.pop_back();
        }
    }
    cout<<res<<endl;
}

void c(){
    int n,k;
    cin>>n>>k;
    vll A(n);
    F0(i,n) cin>>A[i];
    ll minima = 10000000000;
    ll res;
    F0(i,n-k){
        if(A[i+k] - A[i] < minima){
            minima = A[i+k] - A[i];
            res = (A[i+k] + A[i])/2;
        }
    }
    cout<<res<<endl;
}

void responderQuery(vvi& aDonde, int lgn){
    int a,b;
    cin>>a>>b;
    int res = 0;
    while(a < b){
        if(a == aDonde[0][a]){
            cout<<-1<<endl;
            return;
        }
        if(aDonde[0][a] >= b){
            res++;
            break;
        }
        int i = 0;
        while(i < lgn && aDonde[i][a] < b) i++;
        res += (int) pow(2,i-1);
        a = aDonde[i-1][a];
    }
    cout<<res<<endl;
}

int logint(int n){
    int res = 0;
    while(n > 1){
        n /= 2;
        res++;
    }
    return res;
}

void e(){
    int n,m;
    cin>>n>>m;
    vpi intervalos;
    int a,b;
    F0(i,n) {
        cin>>a>>b;
        intervalos.eb(mp(a,b));
    }
    sort(intervalos.begin(),intervalos.end());
    int lgn = logint(n);
    vvi aDondeLlegoDesde(lgn+1,vi(500005,0));
    F0(i,n){
        aDondeLlegoDesde[0][intervalos[i].first] = max(aDondeLlegoDesde[0][intervalos[i].first],intervalos[i].second);
    }
    F1(i,aDondeLlegoDesde[0].size()-1) aDondeLlegoDesde[0][i] = max(aDondeLlegoDesde[0][i],aDondeLlegoDesde[0][i-1]);

    F1(i,lgn){
        F0(j,500005){
            aDondeLlegoDesde[i][j] = aDondeLlegoDesde[i-1][aDondeLlegoDesde[i-1][j]];
        }
    }

    F0(i,m){
        responderQuery(aDondeLlegoDesde,lgn);
    }
}

void d(){
    int n,k;
    cin>>n>>k;
    vll A(n);
    F0(i,n) cin>>A[i];
    vll sumasSufijos(n);
    ll suma = 0;
    for(int i = n-1; i >= 0; i--){
        suma += A[i];
        sumasSufijos[i] = suma;
    }

    ll res = sumasSufijos[0];

    sumasSufijos[0] = sumasSufijos.back();
    sumasSufijos.pop_back();
    sort(sumasSufijos.begin(),sumasSufijos.end());
    reverse(sumasSufijos.begin(),sumasSufijos.end());
    F0(i,k-1){
        res += sumasSufijos[i];
    }
    cout<<res<<endl;
}

int main() {
    d();
    return 0;
}