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
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define todo(v) v.begin(),v.end()
const ll mod = 998244353;
const ll INF  = 8e18;
const int inf = 1e9;
const double eps = 0.00000001;

const int N = 1e5;

ll fact[N+1];
ll inv_fact[N+1];

ll pot_mod(ll a, ll exp){
    if(exp == 0) return 1;
    ll b = pot_mod(a,exp/2);
    b = (b*b)%mod;
    if(exp%2) b = (b*a)%mod;
    return b;
}

ll inv(ll a){
    return pot_mod(a,mod-2);
}

void precalc(){
    fact[0] = inv_fact[0] = 1;

    F1(i,N) fact[i] = fact[i-1] * i % mod;
    F1(i,N) inv_fact[i] = inv(fact[i]);
}

ll comb(int n, int k){
    return fact[n] * inv_fact[k] % mod * inv_fact[n-k] % mod;
}

ll coso(int x, int y){
    ll res = 0;
    F1(i,min(x,y)+1) res = (res + comb(x+1,i) * comb(y+1,i)) % mod;
    return res;
}

ll coso2(int x, int y){
    if(min(x,y) == 0)
        return 1;
    ll res = 0;
    F0(i,min(x,y)+1) res = (res + comb(x,i) * comb(y,i)) % mod;
    return res;
}

pair<int,int> limpiar(vll& a, int& n){
    int x = 0, y = 0;
    while(!a.empty() and a.back() == 0) y++, a.pop_back();
    reverse(todo(a));
    while(!a.empty() and a.back() == 0) x++, a.pop_back();
    reverse(todo(a));
    n = a.size();
    return {x,y};
}

void e(){
    int n;
    cin>>n;
    vll a(n);
    F0(i,n) cin>>a[i];
    int x,y;
    tie(x,y) = limpiar(a,n);
    if(n == 0){
        cout<<pot_mod(2,y-1)<<'\n';
        return;
    }

    ll izq = 0;
    ll der = 0;
    for(auto x : a) der += x;
    int i = 0; // izq = [0,i), der = [i,n)
    while(izq + a[i] <= der - a[i]) izq += a[i], der -= a[i], i++;
    int j = i; // der = [j,n)
    ll suma = 0; //suma de dps calculados (multiplicado por coso(x,y))
    ll dpi;
    while(i >= 0){
        while(der > izq) {
            der -= a[j];
            j++;
        }
        if(a[i] != 0 and izq == der){
            dpi = suma + 1;
            int xi = 0, yi = 0;
            while(i > 0 and a[i-1] == 0) i--, xi++;
            while(j < n and a[j] == 0) j++, yi++;
            if(i + xi == j) suma += dpi * (pot_mod(2,xi+1)-1);
            else suma += dpi * coso(xi,yi);
            suma %= mod;
        }
        i--;
        if(i >= 0) izq -= a[i];
    }
    cout<<dpi*coso2(x,y)%mod<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalc();
    int t;
    cin>>t;
    while(t--) e();
}