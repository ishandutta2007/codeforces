#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
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
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
const ll mod = 998244353;

map<int,int> fact(int n){
    map<int,int> res;
    int x = 2;
    while(x*x <= n){
        while(n % x == 0) {
            res[x]++;
            n /= x;
        }
        x++;
    }
    if(n != 1) res[n]++;
    return res;
}

int p,alfa,n,m;
map<int,int> f;
bool trans = false;

int pot(int a, int exp){
    int res = 1;
    while(exp--) res *= a;
    return res;
}

bool preguntar(int tam, int i, int r){
    cout<<"? ";
    int h = n;
    int w = (1<<i) * tam;
    int i1 = 1, j1 = 1;
    int i2 = 1, j2 = r - w+1;
    if(j2 <= w){
        w /= 2;
        j2 = w+1;
    }
    if(trans) swap(h,w), swap(i1,j1), swap(i2,j2);
    cout<<h<<' '<<w<<' '<<i1<<' '<<j1<<' '<<i2<<' '<<j2<<'\n';

    int res;
    cin>>res;
    return res == 1;
}

//qvq tiene periodo n / (p**exp). Ya se que tiene periodo n / (p**(exp-1))
bool esPeriodico(int p, int exp){
    int r = m / pot(p,exp-1);
    int tam = m / pot(p,exp);
    int i = 0;
    while((1<<i) < p and preguntar(tam,i,r)) i++;
    return (1<<i) >= p;
}

int aux(int p, int alfa){
    int res = 1;
    while(res <= alfa and esPeriodico(p,res)) res++;
    return res;
}

int solve(){
    f = fact(m);
    int res = 1;
    for(auto x : f){
        tie(p,alfa) = x;
        res *= aux(p,alfa);
    }
    return res;
}

void F(){
    cin>>n>>m;
    int res = solve();
    trans = true;
    swap(n,m);
    res *= solve();
    cout<<"! "<<res<<'\n';
}

int main(){
    F();
}