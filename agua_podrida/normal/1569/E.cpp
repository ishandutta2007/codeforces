#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
using ll = long long;
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
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define todo(v) v.begin(),v.end()
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
double PI = acos(-1.0);
#define fora(e,v) for(auto e : v)
const ll mod = 998244353;
const ll INF  = 1e18;
const double eps = 0.00000001;

int k,n;
ll h;
pair<int,vi> res;

ll potA[18];

vi cuantos;

void precalccuantos(){
    cuantos = vi(k+1,1);
    F0R(i,k-1){
        cuantos[i] = 2*cuantos[i+1];
    }
}

int pos(int gane){
    int res = (1<<(k-1))+1;
    while(gane--){
        res = min(res/2+1,res-1);
    }
    return res;
}

ll valor(int gane){
    return potA[pos(gane)];
}

void precalc(){
    precalccuantos();
    REP(i,2,17) potA[i] = (potA[i-1] * potA[1]) % mod;
}

map<int,vi> dp;

bool inc(vi& coso){
    int i = 1;
    while(i < k+1 and coso[i] == cuantos[i]) coso[i] = 0, i++;
    if(i < k+1) coso[i]++;
    return i < k+1;
}

void calculardp(){
    vi coso(k+1);
    do {
        ll suma = 0;
        F1(i,k){
            suma += valor(i) * coso[i];
            suma += valor(0) * (cuantos[i] - coso[i]);
            suma %= mod;
        }
        dp[suma] = coso;
    } while(inc(coso));
}

int cuantosgana(int eq, int partidos){
    int i = eq/2 + n/2;
    int res = 1;
    while(i > 1){
        bool soyizq = (i%2) == 0;
        bool ganaizq = (partidos & (1<<(i/2))) == 0;
        if(soyizq == ganaizq) res++;
        else i = 0;
        i /= 2;
    }
    return res;
}

void calcular(int partidos){
    ll suma = 0;
    int eq = 0;
    while(eq < n){
        suma += (eq+1) * valor(cuantosgana(eq,partidos));
        suma %= mod;
        eq += 2;
    }
    suma = h-suma;
    if(suma < 0) suma += mod;
    if(dp.count(suma)) res = {partidos,dp[suma]};
}

void combinar(){
    int partidos = res.first;
    vi coso = res.second;
    vi res(n);
    int eq = 0;
    while(eq < n){
        res[eq] = cuantosgana(eq,partidos);
        if(coso[res[eq]]) coso[res[eq]]--, swap(res[eq],res[eq+1]);
        eq += 2;
    }
    for(auto x : res) cout<<pos(x)<<' ';
    cout<<'\n';
}

void a(){
    res = {-1,{}};
    cin>>k>>potA[1]>>h;
    n = (1<<k);
    precalc();
    calculardp();
    F0(eq,n/2){
        h -= (2*eq+1) * valor(0);
        h %= mod;
    }
    if(h < 0) h += mod;
    int partidos = 0;
    while(partidos < (1<<(n/2))){
        calcular(partidos);
        partidos += 2;
    }
    if(res.first == -1) cout<<"-1\n";
    else combinar();
}

int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    a();
    return 0;
}