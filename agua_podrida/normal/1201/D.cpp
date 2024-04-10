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
#define INF 1000000000000

#define todo(v) v.begin(),v.end()

ll expN(ll b, ll exp){
    if(exp == 0) return 1;
    ll res = expN(b,exp/2);
    res *= res;
    if(exp%2 == 1) res *= b;
    return res;
}

void a(){
    int n;
    ll I;
    cin>>n>>I;
    vi audio(n);
    F0(i,n) cin>>audio[i];
    sort(todo(audio));

    ll lim = 8* I / n;
    lim = expN(2,lim);

    int l = 0; int r = 0;
    int distintos = 1;
    int res = n;
    while(r < n and distintos <= lim){
        r++;
        if(audio[r] != audio[r-1]) distintos++;
    }
    mini(res,n-r+l);
    while(r < n){
        l++;
        while(l < n and audio[l] == audio[l-1]) l++;
        r++;
        while(r < n and audio[r] == audio[r-1]) r++;
        mini(res,n-r+l);
    }
    cout<<res<<'\n';
}

struct segmentMax {
    segmentMax(int nn){
        n = nn;
        tree = vi(2*n);
    }

    segmentMax(vi& v){
        n = v.size();
        tree = vi(2*n);
        F0(i,n){
            tree[i+n] = v[i];
        }
        for(int i = n-1; i >= 1; i--){
            tree[i] = max(tree[2*i],tree[2*i+1]);
        }
    }

    int maxr(int a, int b){
        int res = -1;
        a += n; b += n;
        while(a <= b){
            if(a%2 == 1) maxi(res,tree[a++]);
            if(b%2 == 0) maxi(res,tree[b--]);
            a /= 2;
            b /= 2;
        }
        return res;
    }

    void actualizar(int i, int x){
        i += n;
        tree[i] = x;
        i /= 2;
        while(i >= 1){
            tree[i] = max(tree[2*i],tree[2*i+1]);
            i /= 2;
        }
    }

    int n;
    vi tree;
};

void b(){
    int aux;
    int p,x;
    int n;
    cin>>n;
    vi A(n+1);
    F1(i,n) cin>>A[i];

    int q;
    cin>>q;
    segmentMax tree(q);
    vi ultimaAcutalizacion(n+1,0);
    int t = 0;
    while(q--){
        cin>>aux;
        if(aux == 1){
            cin>>p>>x;
            A[p] = x;
            ultimaAcutalizacion[p] = t;
        }
        if(aux == 2){
            cin>>x;
            tree.actualizar(t,x);
        }
        t++;
    }
    F1(i,n){
        maxi(A[i],tree.maxr(ultimaAcutalizacion[i],t-1));
    }
    F1(i,n) cout<<A[i]<<' ';
    cout<<endl;
}

void c(){
    int n,m;
    cin>>n>>m;
    vpi aristas(m+1);
    int u,v;
    F1(i,m){
        cin>>u>>v;
        aristas[i] = mp(u,v);
    }
    vi matching;
    set<int> nodosQuemados;
    F1(i,m){
        u = aristas[i].F;
        v = aristas[i].S;
        if(nodosQuemados.count(u) == 0 and nodosQuemados.count(v) == 0){
            nodosQuemados.insert(u);
            nodosQuemados.insert(v);
            matching.pb(i);
        }
    }
    if(matching.size() >= n){
        cout<<"Matching"<<'\n';
        F0(i,n) cout<<matching[i]<<' ';
        cout<<'\n';
    }
    else{
        int couteados = 0;
        cout<<"IndSet\n";
        F1(i,3*n){
            if(nodosQuemados.count(i) == 0){
                cout<<i<<' ';
                couteados++;
            }
            if(couteados == n) break;
        }
        cout<<'\n';
    }
}

void aa(){
    int n,m;
    cin>>n>>m;
    vector<string> respuestas;
    string aux;
    F0(i,n){
        cin>>aux;
        respuestas.pb(aux);
    }
    vi puntajes(m);
    F0(i,m) cin>>puntajes[i];
    int res = 0;
    F0(i,m){
        vi apariciones(5);
        F0(k,n){
            int r = (int) respuestas[k][i] - (int) 'A';
            apariciones[r]++;
        }
        sort(todo(apariciones));
        res += apariciones[4] * puntajes[i];
    }
    cout<<res<<'\n';
}

void cc(){
    int n,k;
    cin>>n>>k;
    vi A(n);
    F0(i,n) cin>>A[i];
    sort(todo(A));
    int iguales = 1;
    int i = n/2;
    int median = A[n/2];
    while(i+1 < n and k - iguales * (A[i+1] - median) >= 0){
        k -= iguales * (A[i+1] - median);
        median = A[i+1];
        iguales++;
        i++;
    }
    if(i == n-1){
        median += k / iguales;
    }
    else {
        median += k / iguales;
    }
    cout<<median<<'\n';
}

int bb(vi& v, int x){
    if(v[0] > x) return -1;
    int lo = 0;
    int hi = v.size();
    while(lo + 1 != hi){
        int mid = (lo+hi)/2;
        if(v[mid] <= x) lo = mid;
        else hi = mid;
    }
    return lo;
}

ll calcular(int i, int j ,map<pi,ll>& DP,vi& columnasSeguras,vpi& minMaxPorFila,vi& proxFilaConCosas,int n,int m,int ultFila){
    if(DP.count(mp(i,j))) return DP[mp(i,j)];
    if(i == ultFila){//Es la ultima fila con cosas
        DP[mp(i,j)] = INF;
        ll caminoDer = abs(minMaxPorFila[i].S - j);
        ll caminoIzq = minMaxPorFila[i].S - minMaxPorFila[i].F;
        mini(DP[mp(i,j)],caminoDer + caminoIzq);

        caminoIzq = abs(minMaxPorFila[i].F - j);
        caminoDer = minMaxPorFila[i].S - minMaxPorFila[i].F;
        mini(DP[mp(i,j)],caminoDer + caminoIzq);
    }
    else {
        int extIzq = minMaxPorFila[i].F;
        int extDer = minMaxPorFila[i].S;
        //Calculo sin cosas para extIzq
        int proxFila = proxFilaConCosas[i];
        int posEscalera = bb(columnasSeguras,extIzq);
        ll sinCosasExtIzq = INF;
        if(posEscalera != -1){
            int colEsc = columnasSeguras[posEscalera];
            int cuantoSubo = proxFila - i;
            int cuantoCamino = abs(colEsc-extIzq);
            calcular(proxFila,colEsc,DP,columnasSeguras,minMaxPorFila,proxFilaConCosas,n,m,ultFila);
            mini(sinCosasExtIzq,DP[mp(proxFila,colEsc)] + cuantoSubo + cuantoCamino);
        }
        if(posEscalera+1 < columnasSeguras.size()){
            int colEsc = columnasSeguras[posEscalera+1];
            int cuantoSubo = proxFila - i;
            int cuantoCamino = abs(colEsc-extIzq);
            calcular(proxFila,colEsc,DP,columnasSeguras,minMaxPorFila,proxFilaConCosas,n,m,ultFila);
            mini(sinCosasExtIzq,DP[mp(proxFila,colEsc)] + cuantoSubo + cuantoCamino);
        }
        //Idem para ExtDer
        proxFila = proxFilaConCosas[i];
        posEscalera = bb(columnasSeguras,extDer);
        ll sinCosasExtDer = INF;
        if(posEscalera != -1){
            int colEsc = columnasSeguras[posEscalera];
            int cuantoSubo = proxFila - i;
            int cuantoCamino = abs(colEsc-extDer);
            calcular(proxFila,colEsc,DP,columnasSeguras,minMaxPorFila,proxFilaConCosas,n,m,ultFila);
            mini(sinCosasExtDer,DP[mp(proxFila,colEsc)] + cuantoSubo + cuantoCamino);
        }
        if(posEscalera+1 < columnasSeguras.size()){
            int colEsc = columnasSeguras[posEscalera+1];
            int cuantoSubo = proxFila - i;
            int cuantoCamino = abs(colEsc-extDer);
            calcular(proxFila,colEsc,DP,columnasSeguras,minMaxPorFila,proxFilaConCosas,n,m,ultFila);
            mini(sinCosasExtDer,DP[mp(proxFila,colEsc)] + cuantoSubo + cuantoCamino);
        }

        DP[mp(i,j)] = INF;
        ll caminoDer = abs(minMaxPorFila[i].S - j);
        ll caminoIzq = minMaxPorFila[i].S - minMaxPorFila[i].F;
        mini(DP[mp(i,j)],caminoDer + caminoIzq + sinCosasExtIzq);

        caminoIzq = abs(minMaxPorFila[i].F - j);
        caminoDer = minMaxPorFila[i].S - minMaxPorFila[i].F;
        mini(DP[mp(i,j)],caminoDer + caminoIzq + sinCosasExtDer);
    }
    return DP[mp(i,j)];
}

void dd(){
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    vpi minMaxPorFila;
    F0(i,n+1) minMaxPorFila.pb(mp(m+1,0));
    int ri,ci;
    int ultFila = 0;
    F0(i,k){
        cin>>ri>>ci;
        mini(minMaxPorFila[ri].F,ci);
        maxi(minMaxPorFila[ri].S,ci);
        maxi(ultFila,ri);
    }
    vi proxFilaConCosas(n+1);
    int filaSig = ultFila;
    for(int i = n; i > 0; i--){
        if(minMaxPorFila[i].S != 0){
            proxFilaConCosas[i] = filaSig;
            filaSig = i;
        }
    }
    vi columnasSeguras(q);
    F0(i,q) cin>>columnasSeguras[i];
    sort(todo(columnasSeguras));
    map<pi,ll> DP;
    ll res;
    if(minMaxPorFila[1].S == 0){
        ll colEsc = (ll) columnasSeguras[0];
        ll camino = colEsc-1;
        ll subo = filaSig-1;
        res = calcular(filaSig,(int) colEsc,DP,columnasSeguras,minMaxPorFila,proxFilaConCosas,n,m, ultFila);
        res += camino;
        res += subo;
    }
    else res = calcular(1,1,DP,columnasSeguras,minMaxPorFila,proxFilaConCosas,n,m, ultFila);
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("../subtle_sabotage.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    dd();
    return 0;
}