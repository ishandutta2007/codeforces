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
ll mod = 998244353;

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
    int b,p,f,h,c;
    cin>>b>>p>>f>>h>>c;
    if(h < c){
        swap(h,c);
        swap(p,f);
    }
    int res = 0;
    b /= 2;
    res += min(p,b) * h;
    b -= min(p,b);
    res += min(b,f) * c;
    cout<<res<<'\n';
}

void b(){
    int n,m;
    cin>>n>>m;
    vvi A(n,vi(m));
    F0(i,n){
        F0(j,m) cin>>A[i][j];
    }

    vvi B(n,vi(m));
    vpi operaciones;
    F0(i,n-1){
        F0(j,m-1){
            if(A[i][j] * A[i][j+1] * A[i+1][j] * A[i+1][j+1] > 0){
                B[i][j] = 1;
                B[i][j+1] = 1;
                B[i+1][j] = 1;
                B[i+1][j+1] = 1;
                operaciones.pb(mp(i+1,j+1));
            }
        }
    }

    if(A == B){
        cout<<operaciones.size()<<'\n';
        F0(i,operaciones.size()) cout<<operaciones[i].F<<' '<<operaciones[i].S<<'\n';
    }
    else cout<<-1;
}

void c(){
    ll n;
    ll a,b;
    cin>>n>>a>>b;
    string ruta;
    cin>>ruta;
    ll res = 0;
    res += b*(n+1);
    res += a*n;

    bool estoyAbajo = true;
    F0(i,n){
        if(estoyAbajo and ruta[i] == '0') continue;
        if(estoyAbajo and ruta[i] == '1') {
            estoyAbajo = false;
            res += a+b;
        }
        else if(!estoyAbajo and ruta[i] == '1'){
            res += b;
        }
        else if(!estoyAbajo and ruta[i] == '0'){
            int cantCeros = 0;
            while(i + cantCeros < n and ruta[i+cantCeros] == '0') cantCeros++;
            if(i + cantCeros == n){
                res += a+b;
            }
            else {
                res += min((ll) (cantCeros - 1) * b, 2 * a);
                res += 2*b;
            }
            i += cantCeros;
        }
    }
    cout<<res<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) c();
    return 0;
}