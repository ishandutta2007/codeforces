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
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    vi p(n);
    F0(i,n) {
        cin>>p[i];
    }
    if(n == 1) {cout<<"0\n"; return;}
    int pares = n/2;
    int impares = (n+1)/2;

    F0(i,n){
        if(p[i] == 0) continue;
        if(p[i]%2 == 1) impares--;
        else pares--;
    }

    if(pares+impares == n){
        cout<<"1\n";
        return;
    }

    vi imp1,par1,imp2,par2;

    int complejidad = 0;
    int l = 0;
    int r;
    while(l < n){
        while(l < n and p[l] != 0) l++;
        r = l;
        while(r < n and p[r] == 0) r++;
        if(l == 0){
            if(p[r]%2 == 1) imp1.pb(r-l);
            else par1.pb(r-l);
        }
        else if(r == n){
            if(p[l-1]%2 == 1) imp1.pb(r-l);
            else par1.pb(r-l);
        }
        else if(p[l-1]%2 == 0 and p[r]%2 == 0) par2.pb(r-l);
        else if(p[l-1]%2 == 1 and p[r]%2 == 1) imp2.pb(r-l);
        else complejidad++;
        l = r;
    }

    sort(todo(par1));
    reverse(todo(par1));
    sort(todo(par2));
    reverse(todo(par2));
    sort(todo(imp1));
    reverse(todo(imp1));
    sort(todo(imp2));
    reverse(todo(imp2));

    while(!par2.empty() and pares >= par2.back()){
        pares -= par2.back();
        par2.pop_back();
    }
    while(!par1.empty() and pares >= par1.back()){
        pares -= par1.back();
        par1.pop_back();
    }
    while(!imp2.empty() and impares >= imp2.back()){
        impares -= imp2.back();
        imp2.pop_back();
    }
    while(!imp1.empty() and impares >= imp1.back()){
        impares -= imp1.back();
        imp1.pop_back();
    }

    F0(i,n-1) if(p[i] != 0 and p[i+1] != 0 and (p[i]+p[i+1])%2 != 0) complejidad++;

    complejidad += imp1.size();
    complejidad += 2*imp2.size();
    complejidad += par1.size();
    complejidad += 2*par2.size();

    cout<<complejidad<<'\n';
}

int calcularTam(int nodo, vvi& hijos, vi& tam){
    int tamSubarboles = 0;
    F0(i,hijos[nodo].size()) tamSubarboles += calcularTam(hijos[nodo][i],hijos,tam);
    tam[nodo] = tamSubarboles+1;
    return tam[nodo];
}

void sumarSubarbolMayoresA(vvi& hijos, int nodo, vi& a, int sum, int c){
    F0(i,hijos[nodo].size()) sumarSubarbolMayoresA(hijos,hijos[nodo][i],a,sum,c);
    if(a[nodo] >= c) a[nodo] += sum;
}

void calcularA(int nodo, vi& a, vi& c, vvi& hijos, vi& tam){
    F0(i,hijos[nodo].size()) calcularA(hijos[nodo][i],a,c,hijos,tam);
    a[nodo] = c[nodo]+1;
    if(hijos[nodo].empty()) return;

    int sum = tam[hijos[nodo][0]];
    F1(i,hijos[nodo].size()-1){
        sumarSubarbolMayoresA(hijos,hijos[nodo][i],a,sum,0);
        sum += tam[hijos[nodo][i]];
    }
    sumarSubarbolMayoresA(hijos,nodo,a,1,a[nodo]);
    a[nodo] = c[nodo]+1;
}

void b(){
    int n;
    cin>>n;
    vi padre(n+1);
    vvi hijos(n+1);
    vi c(n+1);
    vi a(n+1);
    vi tam(n+1);
    int raiz;

    F1(i,n) cin>>padre[i]>>c[i];
    F1(i,n) if(padre[i] == 0) raiz = i; else hijos[padre[i]].pb(i);
    calcularTam(raiz,hijos,tam);

    F1(i,n) if(c[i] >= tam[i]) {
            cout<<"NO\n";
            return;
        }

    calcularA(raiz,a,c,hijos,tam);

    cout<<"YES\n";
    F1(i,n-1) cout<<a[i]<<' ';
    cout<<a.back()<<'\n';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    b();
    return 0;
}