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
const ll mod = 1000000007;

const int N  = 2e5;
int n;
ll a[N],b[N],c[N],d[N];

struct pair_hash {
    inline std::size_t operator()(const std::pair<ll,ll> & v) const {
        return ((v.first%mod)*31+ v.second % mod) % mod;
    }
};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

pll recta1(int i){
    ll num = c[i] * b[i];
    ll den = (a[i]+b[i]) * d[i];
    ll g = gcd(num,den);
    num /= g;
    den /= g;
    return {num,den};
}

pll recta2(int i){
    ll num = (c[i]+d[i]) * b[i];
    ll den = a[i] * d[i];
    ll g = gcd(num,den);
    num /= g;
    den /= g;
    return {num,den};
}

unordered_map<pll,map<int,pll>,pair_hash> g;
vi res;
unordered_map<pll,pll,pair_hash> padre;
vpll orden;

void dfs(pll v, pll p){
    if(padre.count(v)) return;
    orden.pb(v);
    padre[v] = p;
    for(auto e : g[v]){
        int id = e.first;
        pll u = e.second;
        dfs(u,v);
    }
}

void coso(pll v){
    pll u;
    int id;
    vector<pair<int,pll>> a;
    for(auto e : g[v]) a.pb(e);
    int i = 0;
    while(i < a.size() and a[i].second != padre[v]) i++;
    if(i < a.size()) swap(a[0],a[i]);
    while(a.size() >= 2){
        F0(j,2){
            id = a.back().first;
            u = a.back().second;
            a.pop_back();
            g[u].erase(id);
            res.pb(id);
        }
    }
}

void e(){
    cin>>n;
    F0(i,n) cin>>a[i]>>b[i]>>c[i]>>d[i];
    F0(i,n){
        pll u = recta1(i);
        pll v = recta2(i);
        g[u][i+1] = v;
        g[v][i+1] = u;
    }
    for(auto it : g){
        pll v = it.first;
        dfs(v,v);
    }
    F0R(i,orden.size()){
        pll v = orden[i];
        coso(v);
    }

    cout<<res.size()/2<<'\n';
    F0(i,res.size()) {
        cout<<res[i];
        if(i%2) cout<<'\n';
        else cout<<' ';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    e();
}