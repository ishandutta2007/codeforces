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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    vll v(3);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    sort(v.begin(),v.end());
    ll res = 0;
    if(v[1] - v[0] < d) res += d - (v[1] - v[0]);
    if(v[2] - v[1] < d) res += d - (v[2] - v[1]);
    cout<<res<<'\n';
}

void responder(vi& t, int ti, int m, int suma){
    if(suma <= m - ti){
        cout<<0<<' ';
        return;
    }
    int res = 0;
    int i = 100;
    while(suma > m - ti){
        if(suma - t[i]*i <= m-ti){
            res += (suma - (m-ti) + i-1) / i;
            suma = 0;
        }
        else {
            suma -= t[i]*i;
            res += t[i];
        }
        i--;
    }
    cout<<res<<' ';
}

void c(){
    int n,m;
    cin>>n>>m;
    vi t(101,0);
    int ti;
    int suma = 0;
    F1(i,n){
        cin>>ti;
        responder(t,ti,m,suma);
        suma += ti;
        t[ti]++;
    }
    cout<<'\n';
}

void b(){
    string a;
    string b;
    cin>>a;
    cin>>b;
    int i = 0;
    char ulta = a[0];
    int j = 0;
    while(i < a.size()){
        int iguales = 0;
        while(i < a.size() && a[i] == ulta) {
            iguales++;
            i++;
        }
        int igualesb = 0;
        while(j < b.size() && b[j] == ulta){
            igualesb++;
            j++;
        }
        if(igualesb < iguales){
            cout<<"NO\n";
            return;
        }
        ulta = a[i];
    }
    if(j == b.size())
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

bool esMonotona(vi& v){
    if (v.size() <= 1) return true;
    int c = v[1] - v[0];
    int i = 1;
    while(i < v.size() && v[i] - v[i-1] == c) i++;
    if(i == v.size()) return true;
    else return false;
}

void d(){
    int n;
    cin>>n;
    vi v(n);
    F0(i,n) cin>>v[i];
    vpi conPos;
    F0(i,n) conPos.eb(mp(v[i],i));
    sort(conPos.begin(),conPos.end());
    vi posVieja;
    sort(v.begin(),v.end());
    F0(i,n) posVieja.eb(conPos[i].second);
    int c = v[1] - v[0];
    int i = 1;
    int res = -1;
    bool noAnduvo = false;
    while(i < n){
        if(v[i] - v[i-1] != c){
            if(res == -1){
                res = i;
                i++;
                if(i < n && v[i] - v[i-2] != c){
                    noAnduvo = true;
                    break;
                }
            }
            else {
                noAnduvo = true;
                break;
            }
        }
        i++;
    }
    if(noAnduvo) {
        vi sinPrimero = v;
        reverse(sinPrimero.begin(),sinPrimero.end());
        sinPrimero.pop_back();
        if(esMonotona(sinPrimero)){
            cout<<posVieja[0]+1<<'\n';
            return;
        }
        vi sinSegundo = v;
        reverse(sinSegundo.begin(),sinSegundo.end());
        sinSegundo[v.size()-2] = sinSegundo.back();
        sinSegundo.pop_back();
        if(esMonotona(sinSegundo)){
            cout<<posVieja[1]+1<<'\n';
            return;
        }
        cout<<-1<<'\n';
        return;
    }
    if(res == -1) res++;
    cout<<posVieja[res]+1<<'\n';
}

ll max3(ll a, ll b, ll c){
    if(a >= b && a >= c) return a;
    return max(b,c);
}

int tiempoTotal(int subset, vi& t,int n){
    int suma = 0;
    F0(i,n){
        if(subset & (1<<i)) suma += t[i];
    }
    return suma;
}

ll ordenesAux(int ultimo, vll& porGenero, int mod){
    if(porGenero[1] == 0 && porGenero[2] == 0 & porGenero[3] == 0) return 1;
    if(ultimo == 1 && porGenero[2] == 0 && porGenero[3] == 0) return 0;
    if(ultimo == 2 && porGenero[1] == 0 && porGenero[3] == 0) return 0;
    if(ultimo == 3 && porGenero[2] == 0 && porGenero[1] == 0) return 0;

    ll res = 0;
    if(ultimo != 2 && porGenero[2] > 0){
        porGenero[2]--;
        res += ordenesAux(2,porGenero,mod);
        res %= mod;
        porGenero[2]++;
    }
    if(ultimo != 1 && porGenero[1] > 0){
        porGenero[1]--;
        res += ordenesAux(1,porGenero,mod);
        res %= mod;
        porGenero[1]++;
    }
    if(ultimo != 3 && porGenero[3] > 0){
        porGenero[3]--;
        res += ordenesAux(3,porGenero,mod);
        res %= mod;
        porGenero[3]++;
    }
    return res;
}

ll ordenesDistintos(vll& porGenero, ll mod){
    ll res = 0;
    if(porGenero[1] > 0) {
        porGenero[1]--;
        res += ordenesAux(1,porGenero,mod);
        porGenero[1]++;
    }
    if(porGenero[2] > 0) {
        porGenero[2]--;
        res += ordenesAux(2,porGenero,mod);
        porGenero[2]++;
    }
    if(porGenero[3] > 0) {
        porGenero[3]--;
        res += ordenesAux(3,porGenero,mod);
        porGenero[3]++;
    }
    return res;
}

ll contarFormas(int subset, vi& genero, ll mod, vll& fact,int n){
    vll cancionesPorGenero(4,0);
    F0(i,n) {
        if(subset & (1<<i)) cancionesPorGenero[genero[i]]++;
    }
    ll mas = max3(cancionesPorGenero[1],cancionesPorGenero[2],cancionesPorGenero[3]);
    if(mas > (cancionesPorGenero[1] + cancionesPorGenero[2] + cancionesPorGenero[3] + 1)/2)
        return 0;
    ll res = fact[cancionesPorGenero[1]];
    res *= fact[cancionesPorGenero[2]];
    res %= mod;
    res *= fact[cancionesPorGenero[3]];
    res %= mod;

    res *= ordenesDistintos(cancionesPorGenero,mod);
    res %= mod;

    return res;
}

void g(){
    ll mod = 1000000007;
    vll fact(16,0);
    fact[0] = 1;
    F1(i,15) fact[i] = (fact[i-1] * i) % mod;
    int n, T;
    cin>>n>>T;
    vi genero(n);
    vi t(n);
    F0(i,n) cin>>t[i]>>genero[i];
    ll res = 0;
    for(int subset = 0; subset < (1<<n); subset++){
        if(tiempoTotal(subset,t,n) == T){
            res += contarFormas(subset,genero,mod,fact,n);
            res %= mod;
        }
    }
    cout<<res<<'\n';
}

int main() {
    g();
    return 0;
}