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

void e(){
    int n;
    cin>>n;
    vll s(n);
    vll t(n);
    F0(i,n) cin>>s[i];
    F0(i,n) cin>>t[i];
    vll saux = s;
    //quiero saber en que posicion quedo cada uno
    multiset<pair<ll,int>> posiciones; //para cada valor las posiciones en las que aparece en s;
    F0(i,n){
        posiciones.insert(mp(saux[i],i));
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    vi enQuePosicionEstaba;
    F0(i,n){
        auto it = posiciones.lower_bound(mp(s[i],0));
        int posicion = (*it).second;
        enQuePosicionEstaba.eb(posicion);
        posiciones.erase(it);
    }
    if(s.back() < t.back() || s[0] > t[0]){
        cout<<"NO"<<'\n';
        return;
    }
    ll sum = 0;
    F0(i,n){
        sum += s[i];
        sum -= t[i];
    }
    if(sum != 0){
        cout<<"NO"<<'\n';
        return;
    }
    vi iSalida;
    vi jSalida;
    vll dSalida;
    int usados = 1;
    F0(i,n){
        //mando a su lugar a s[i]
        while(s[i] != t[i]){
            if(s[usados] <= t[i]){
                usados++;
                continue;
            }
            ll d = min(t[i]-s[i],s[usados]-t[i]);
            s[i] += d;
            s[usados] -= d;
            iSalida.eb(i);
            jSalida.eb(usados);
            dSalida.eb(d);
        }
    }
    cout<<"YES"<<'\n';
    cout<<iSalida.size()<<'\n';
    F0(i,iSalida.size()){
        cout<<enQuePosicionEstaba[iSalida[i]]+1<<" "<<enQuePosicionEstaba[jSalida[i]]+1<<" "<<dSalida[i]<<'\n';
    }
}

void a(){
    int n;
    cin>>n;
    vi v(2*n);
    F0(i,2*n) cin>>v[i];
    int j = 1;
    while(j < 2*n && v[0] == v[j]) j++;
    if(j == 2*n) {
        cout<<-1<<endl;
        return;
    }
    int sumaDer = 0;
    F0(i,n) sumaDer += v[i];
    int sumaIzq = 0;
    F0(i,n) sumaIzq += v[i+n];
    if(sumaDer == sumaIzq){
        bool salir = false;
        F0(i,n) {
            F0(j, n) {
                if(v[i] != v[j+n]){
                    int aux = v[i];
                    v[i] = v[j+n];
                    v[j+n] = aux;
                    salir = true;
                    break;
                }
            }
            if(salir) break;
        }
    }
    F0(i,2*n) cout<<v[i]<<" ";
    cout<<endl;
}

void b(){
    int n;
    cin>>n;
    vi v(n);
    F0(i,n) cin>>v[i];
    int i = 0;
    while(i<n && v[i]%2 == 0) i++;
    if(i != n){
        i = 0;
        while(i<n && v[i]%2== 1) i++;
        if(i != n) sort(v.begin(),v.end());
    }
    F0(i,n) cout<<v[i]<<" ";
    cout<<endl;
}

void c(){

}

int main() {
    b();
    return 0;
}