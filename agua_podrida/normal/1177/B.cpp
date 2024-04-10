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
typedef vector<bool> vb;
typedef vector<vb> vvb;
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
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define INF 100000000
#define todo(v) v.begin(),v.end()

void a(){
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    vi pre(n+1);
    vi post(n+1);
    int cant = 0;
    int i = 0;
    while(cant < m){
        if(s[i] == t[cant]) cant++;
        i++;
        pre[i] = cant;
    }

    cant = 0;
    i = 0;
    while(cant < m){
        if(s[n-i-1] == t[m-1-cant]) cant++;
        i++;
        post[i] = cant;
    }

    int dejoAtras = 0;
    while(post[dejoAtras] < m) dejoAtras++;
    int dejoAdelante = 0;
    int res = dejoAtras;
    F0(i,m){
        while(dejoAtras > 0 and post[dejoAtras-1] == m-i-1) dejoAtras--;
        while(dejoAdelante < n and pre[dejoAdelante] == i) dejoAdelante++;
        mini(res,dejoAdelante+dejoAtras);
    }
    res = n-res;
    cout<<res<<'\n';
}

void b(){
    int n,m,q;
    cin>>n>>m>>q;
    vi porCiudad(m+1);
    int aux;
    while(n--){
        cin>>aux;
        porCiudad[aux]++;
    }
    vi copia = porCiudad;
    sort(todo(porCiudad));
    vpi desdeX;
    int t = n+1;
    int i = 1;
    int x = porCiudad[1];
    while(i <= n){
        while(i < n and porCiudad[i+1] == x) i++;
    }
}

vll repBase10(ll n){
    vll res;
    while(n != 0){
        res.pb(n%10);
        n /= 10;
    }
    reverse(todo(res));
    return res;
}

void c(){
    ll n;
    cin>>n;
    ll digitos = 1;
    ll aux = 9;
    while(n - aux*digitos > 0){
        n -= aux*digitos;
        aux *= 10;
        digitos++;
    }
    ll res;
    if(digitos == 1) res = n;
    else {
        n--;
        ll numero = n/digitos;
        ll base = (ll) (pow(10.0,digitos-1)+0.5);
        numero += base;
        vll b10 = repBase10(numero);
        res = b10[n%digitos];
    }
    cout<<res<<'\n';
}

int main(){
    c();
    return 0;
}