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

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    int suma = 0;
    for(auto x : a) suma += x;
    if(suma % n) cout<<"1\n";
    else cout<<"0\n";
}


//cant < l que tengan encendido el bit i
int cuantos(int l, int i){
    int res = l / (1<<(i+1));
    res *= (1<<i);
    res += max(0,l % (1<<(i+1)) - (1<<i));
    return res;
}

void b(){
    int l,r;
    cin>>l>>r;
    int res = 0;
    F0(i,20){
        maxi(res,cuantos(r+1,i) - cuantos(l,i));
    }
    res = r-l+1-res;
    cout<<res<<'\n';
}

void c(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    if(a == b){
        cout<<"0\n";
        return;
    }
    if(a == string(n,'0')){
        cout<<"-1\n";
        return;
    }
    int unosa = 0, unosb = 0;
    for(auto c : a) if(c == '1') unosa++;
    for(auto c : b) if(c == '1') unosb++;

    if(unosb != unosa and unosb != 1 + n - unosa){
        cout<<"-1\n";
        return;
    }

    int res = n+1;

    if(unosb == unosa){
        int dif = 0;
        F0(i,n){
            if(a[i] != b[i]) dif++;
        }
        mini(res,dif);
    }

    if(unosb == 1 + n - unosa){
        int ig = 0;
        F0(i,n){
            if(a[i] == b[i]) ig++;
        }
        mini(res,ig);
    }

    cout<<res<<'\n';

}

struct dsu{

    dsu(int _n){
        n = _n;
        donde = vi(n);
        F0(i,n) donde[i] = i;
        a = vvi(n);
        F0(i,n) a[i].pb(i);
        color = vi(n);
    }

    bool unite(int u, int v, int c){
        int x = donde[u], y = donde[v];
        if(x == y){
            if(c == 1 and color[u] == color[v]) return false;
            if(c == 0 and color[u] != color[v]) return false;
            return true;
        }
        if(a[x].size() < a[y].size()) swap(x,y);
        int flip = 0;
        if(c == 1 and color[u] == color[v]) flip = 1;
        if(c == 0 and color[u] != color[v]) flip = 1;

        for(auto w : a[y]){
            a[x].pb(w);
            color[w] = (color[w] + flip) % 2;
            donde[w] = x;
        }

        a[y].clear();
        return true;
    }

    int n;
    vi donde;
    vvi a;
    vi color;
};

void d(){
    int n,m;
    cin>>n>>m;
    dsu uf(n+1);
    vpi E;
    map<pi,int> s;
    int u,v,c;
    bool res = true;
    F0(i,n-1){
        cin>>u>>v>>c;
        if(u > v) swap(u,v);
        E.pb({u,v});
        if(c != -1) {
            s[{u,v}] = c;
            c = __builtin_popcount(c) % 2;
            res = res and uf.unite(u,v,c);
        }
    }
    int p;
    F0(i,m){
        cin>>u>>v>>p;
        res = res and uf.unite(u,v,p);
    }

    if(res){
        cout<<"YES\n";
        for(auto uv : E){
            tie(u,v) = uv;
            c = abs(uf.color[u] - uf.color[v]);
            if(s.count({u,v})) cout<<u<<' '<<v<<' '<<s[{u,v}]<<'\n';
            else cout<<u<<' '<<v<<' '<<c<<'\n';
        }
    }
    else cout<<"NO\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) d();
}