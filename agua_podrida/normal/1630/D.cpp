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
const int mod = 1e9+7;
const int INF  = 1e9;
const double eps = 0.00000001;

ll powmod(ll a, ll exp){
    if(exp == 0) return 1;
    ll b = powmod(a,exp/2);
    b = (b*b) % mod;
    if(exp%2) b = (b*a) % mod;
    return b;
}

ll inv(ll a){
    return powmod(a,mod-2);
}

const int N = 1e6;

ll fact[N+1], invfact[N+1],pot2[N+1];

void precalc(){
    fact[0] = invfact[0] = pot2[0] = 1;
    F1(i,N) fact[i] = (fact[i-1] * (ll) i) % mod;
    F1(i,N) invfact[i] = inv(fact[i]);
    F1(i,N) pot2[i] = pot2[i-1] * 2 % mod;
}

ll comb(int n, int k){
    ll res = fact[n];
    res *= invfact[k];
    res %= mod;
    res *= invfact[n-k];
    res %= mod;
    return res;
}

void a(){
    int n,k;
    cin>>n>>k;
    if(k == 3 and n == 4){
        cout<<"-1\n";
        return;
    }

    vi par(n);
    F0(i,n) par[i] = (n-1) ^ i;
    if(k == n-1){
        par[1] = 3;
        par[3] = 1;
        par[n-1] = n-2;
        par[n-2] = n-1;
        par[0] = n-4;
        par[n-4] = 0;
    }
    else if(k != 0){
        par[n-1] = k;
        par[k] = n-1;
        par[(n-1) ^ k] = 0;
        par[0] = (n-1) ^ k;
    }
    F0(i,n){
        if(par[i] != -1){
            cout<<i<<' '<<par[i]<<'\n';
            par[par[i]] = -1;
        }
    }
}

void b(){
    int n,k;
    cin>>n>>k;
    vi a(n);
    F0(i,n) cin>>a[i];
    vi b = a;
    sort(todo(b));
    int x = b[0], y = b[n-1];
    int dentro = (n+k+1)/2;
    F0(l,n-dentro+1){
        int r = l+dentro-1;
        if(b[r] - b[l] < y - x){
            x = b[l], y = b[r];
        }
    }
    cout<<x<<' '<<y<<'\n';
    int l = 0;
    while(k > 1){
        int r = l;
        int coso = 0;
        while(coso <= 0){
            if(x <= a[r] and a[r] <= y) coso++;
            else coso--;
            r++;
        }
        cout<<l+1<<' '<<r<<'\n';
        l = r;
        k--;
    }
    cout<<l+1<<' '<<n<<'\n';
}

void sacarcontenidos(vpi& v){
    int r = -1;
    vpi res;
    F0(i,v.size()){
        if(v[i].second > r){
            r = v[i].second;
            res.pb(v[i]);
        }
    }
    v = res;
}

void c(){
    int n;
    cin>>n;
    vi prim(n+1,-1), ult(n+1,-1);
    int x;
    F0(i,n){
        cin>>x;
        if(prim[x] == -1) prim[x] = i;
        ult[x] = i;
    }

    vpi intervalos;
    F1(i,n){
        if(prim[i] == -1) continue;
        if(prim[i] == ult[i]) continue;
        intervalos.pb({prim[i],ult[i]});
    }
    if(intervalos.empty()){
        cout<<"0\n";
        return;
    }
    sort(todo(intervalos));
    sacarcontenidos(intervalos);
    int res = intervalos[0].second - intervalos[0].first - 1;
    int i = 0;
    int sig = i+1;
    while(sig < intervalos.size()){
        int pongo = sig;
        int j = sig;
        while(j < intervalos.size() and intervalos[j].first < intervalos[i].second){
            if(intervalos[j].second > intervalos[pongo].second) pongo = j;
            j++;
        }
        res += intervalos[pongo].second - max(intervalos[i].second, intervalos[pongo].first+1);
        if(intervalos[pongo].first < intervalos[i].second) res--;
        i = pongo;
        sig = max(j,pongo+1);
    }
    cout<<res<<'\n';
}

ll gcd(ll a , ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

void d(){
    int n,m;
    cin>>n>>m;
    vll a(n);
    F0(i,n) cin>>a[i];
    ll x;
    ll g = 0;
    F0(i,m) {
        cin>>x;
        g = gcd(g,x);
    }

    ll res = 0;
    for(auto x : a) res += abs(x);
    if(g == 1) {
        cout<<res<<'\n';
        return;
    }
    ll op1 = 0, op2 = 0;
    F0(i,g){
        ll mejor = 1e9;
        int neg = 0;
        int j = i;
        while(j < n){
            mini(mejor,abs(a[j]));
            if(a[j] < 0) neg++;
            j += g;
        }
        if(neg%2) op1 += mejor;
        else op2 += mejor;
    }
    res -= min(op1,op2) * 2;
    cout<<res<<'\n';
}

int main(){
    precalc();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) d();
}