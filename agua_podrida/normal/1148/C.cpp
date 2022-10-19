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

void a(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll res = c*2;
    res += min(a,b)*2;
    if(a != b) res++;
    cout<<res<<endl;
}

int bb(vll& v, ll x){
    if(x > v.back()) return -1;
    if(x <= v[0]) return 0;
    int lo = 0;
    int hi = v.size()-1;
    while(lo != hi-1){
        int k = (lo+hi)/2;
        if(x <= v[k]) hi = k;
        else lo = k;
    }
    return hi;
}

void b(){
    int n,m,k;
    ll ta,tb;
    cin>>n>>m>>ta>>tb>>k;
    vll a(n);
    F0(i,n)
        cin>>a[i];
    vll b(m);
    F0(i,m)
        cin>>b[i];
    if(k >= min(n,m)){
        cout<<-1<<endl;
        return;
    }
    ll res = 0;
    F0(i,k+1){//cancelo i de A y k-i de B
        ll llegaAB = a[i] + ta;
        int j = bb(b,llegaAB);
        if(j == -1){
            cout<<-1<<endl;
            return;
        }
        int canceloB = k-i;
        if(j + canceloB >= m){
            cout<<-1<<endl;
            return;
        }
        res = max(res, b[j+canceloB] + tb);
    }
    cout<<res<<endl;
}

void mandarAlPrincipio(vi& p, vi& dondeEsta, int i, int& m, int n, vi& a, vi& b){
    if(dondeEsta[i] == i) return;
    if(dondeEsta[i] >= i + n/2){
        a.eb(i);
        b.eb(dondeEsta[i]);
        int aux = p[i];
        p[i] = p[dondeEsta[i]];
        p[dondeEsta[i]] = aux;
        dondeEsta[aux] = dondeEsta[i];
        dondeEsta[i] = i;
        m++;
        return;
    }
    if(i > n/2){
        a.eb(1); a.eb(1); a.eb(1);
        b.eb(dondeEsta[i]); b.eb(i); b.eb(dondeEsta[i]);
        m += 3;
        dondeEsta[p[i]] = dondeEsta[i];
        p[dondeEsta[i]] = p[i];
        dondeEsta[i] = i;
        p[i] = i;
        return;
    }
    if(dondeEsta[i] <= n/2){
        a.eb(i); a.eb(dondeEsta[i]); a.eb(i);
        b.eb(n); b.eb(n); b.eb(n);
        m += 3;
        dondeEsta[p[i]] = dondeEsta[i];
        p[dondeEsta[i]] = p[i];
        dondeEsta[i] = i;
        p[i] = i;
        return;
    }
    a.eb(1); a.eb(1); a.eb(i); a.eb(1); a.eb(1);
    b.eb(dondeEsta[i]); b.eb(n); b.eb(n); b.eb(n); b.eb(dondeEsta[i]);
    dondeEsta[p[i]] = dondeEsta[i];
    p[dondeEsta[i]] = p[i];
    dondeEsta[i] = i;
    p[i] = i;
    m += 5;
}

void c(){
    int n;
    cin>>n;
    vi p(n+1);
    F1(i,n){
        cin>>p[i];
    }
    vi dondeEsta(n+1);
    F1(i,n){
        dondeEsta[p[i]] = i;
    }
    int m = 0;
    vi a,b;
    F1(i,n){
        mandarAlPrincipio(p,dondeEsta,i,m,n,a,b);
    }
    cout<<m<<'\n';
    F0(i,m){
        cout<<a[i]<<" "<<b[i]<<'\n';
    }
}

int main() {
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}