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
#define INF 1e17
#define todo(v) v.begin(),v.end()
#define eps 0.000000001


void a(){
    int n,m;
    cin>>n>>m;
    ll res = 0;
    vll fib(100005);
    fib[1] = 1;
    REP(i,2,100004) fib[i] = (fib[i-1] + fib[i-2])%mod;
    res += fib[n+1];
    res += fib[m+1];
    res --;
    res *= 2;
    res %= mod;
    cout<<res<<'\n';
}

void miShift(vi& p, int posMin){
    posMin++;
    int n = p.size()-1;
    vi nuevo(n+1);
    int j = 0;
    while(j+posMin <= n) {
        nuevo[j+1] = p[posMin+j];
        j++;
    }
    int i = 0;
    while(i < posMin){
        nuevo[j] = p[i];
        j++;
        i++;
    }
    F1(i,n) p[i] = nuevo[i] - nuevo.back();
}

struct respuesta {
    respuesta(int a, int b, int c){
        cant = a; l = b; r = c;
    }
    bool operator<(respuesta otra){
        return cant < otra.cant;
    }
    int cant;
    int l;
    int r;

};

int posMin;

respuesta pisoEn0(vi& p, int n){
    respuesta res(-1,0,0);
    int l = 0;
    int r = 0;
    int cant = 0;

    int i = 1;
    while(i<=n){
        while(i <= n and p[i] < 2) i++;
        l = i;
        cant = 0;
        while(i <= n and p[i] >= 2) {
            if(p[i] == 2) cant++;
            i++;
        }
        if(cant > res.cant) res = respuesta(cant,l,i);
    }
    F1(i,n) if(p[i] == 0) res.cant++;
    res.l += posMin;
    if(res.l > n) res.l -= n;
    res.r += posMin;
    if(res.r > n) res.r -= n;
    return res;
}

respuesta pisoEn1(vi& p, int n){
    respuesta res(-1,0,0);
    int l = 0;
    int r = 0;
    int cant = 0;

    int i = 1;
    while(i<=n){
        while(i <= n and p[i] == 0) i++;
        l = i;
        cant = 0;
        while(i <= n and p[i] != 0) {
            if(p[i] == 1) cant++;
            i++;
        }
        if(cant > res.cant) res = respuesta(cant,l,i);
    }
    res.l += posMin;
    if(res.l > n) res.l -= n;
    res.r += posMin;
    if(res.r > n) res.r -= n;
    return res;
}

void b(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi p(n+1);
    F1(i,n) if (s[i-1] == '(') p[i] = p[i-1]+1;
            else p[i] = p[i-1]-1;

    if(p[n] != 0) {
        cout<<"0\n1 1\n";
        return;
    }

    posMin = 1;
    F1(i,n) if(p[i] < p[posMin]) posMin = i;

    miShift(p,posMin);
    vector<respuesta> res;
    res.pb(pisoEn0(p,n));
    res.pb(pisoEn1(p,n));

    int cantCeros = 0;
    F1(i,n) if(p[i] == 0) cantCeros++;
    res.pb(respuesta(cantCeros,1,1));

    sort(todo(res));
    cout<<res.back().cant<<'\n'<<res.back().l<<' '<<res.back().r<<'\n';
}

int main() {
    b();
}