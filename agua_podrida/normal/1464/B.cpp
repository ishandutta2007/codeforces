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
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

void dfs(vvi& g, vi& color, int comp, int v){
    if(color[v] != -1) return;
    color[v] = comp;
    for(auto u : g[v]) dfs(g,color,comp,u);
}

bool esCiclo(vvi& g, vi& c){
    for(auto v : c) if(g[v].size() < 2) return false;
    return true;
}

void a(){
    int n,m;
    cin>>n>>m;
    vpi a;
    vi pory(n+1,-1);
    int x,y;
    F0(i,m) {
        cin>>x>>y;
        if(x == y) {
            i--;
            m--;
            continue;
        }
        a.pb({x,y});
        pory[y] = i;
    }

    vvi g(m);
    F0(i,a.size()){
        int x = a[i].first;
        if(pory[x] != -1) {
            g[i].pb(pory[x]);
            g[pory[x]].pb(i);
        }
    }

    int res = m;

    vi color(m,-1);
    int comp = 0;
    F0(i,m) {
        if(color[i] == -1) {
            dfs(g,color,comp,i);
            comp++;
        }
    }

    vvi c(comp);
    F0(i,m) c[color[i]].pb(i);

    F0(i,comp) if(esCiclo(g,c[i])) res++;

    cout<<res<<'\n';

}

void b(){
    string s;
    cin>>s;
    ll x,y;
    cin>>x>>y;
    int n = s.size();
    vll ceroSuf(n+1),unoSuf(n+1);
    F0(i,n) {
        if(s[i] == '1') unoSuf[i]++;
        if(s[i] == '0') ceroSuf[i]++;
    }

    F0R(i,n) unoSuf[i] += unoSuf[i+1];
    F0R(i,n) ceroSuf[i] += ceroSuf[i+1];

    int m = 0;
    F0(i,n) if(s[i] == '?') m++;
    vll costo1(m+1);
    vll costo0(m+1);

    ll unos = 0;
    ll ceros = 0;
    int j = 0;
    F0(i,n) {
        if(s[i] == '0') ceros++;
        if(s[i] == '1') unos++;
        if(s[i] == '?'){
            costo1[j] = ceros*x + ceroSuf[i+1] * y;
            costo0[j] = unos*y + unoSuf[i+1] * x;
            j++;
        }
    }

    vll costo0pref = costo0;
    vll costo0suf = costo0;
    vll costo1pref = costo1;
    vll costo1suf = costo1;
    F1(i,m) costo0pref[i] += costo0pref[i-1];
    F0R(i,m) costo0suf[i] += costo0suf[i+1];
    F1(i,m) costo1pref[i] += costo1pref[i-1];
    F0R(i,m) costo1suf[i] += costo1suf[i+1];

    ll res = INF;
    F0(i,m) {
        mini(res,costo1pref[i] + costo0suf[i+1] + (ll) (i+1) * (ll) (m-i-1) * y);
        mini(res,costo0pref[i] + costo1suf[i+1] + (ll) (i+1) * (ll) (m-i-1) * x);
    }
    if(m == 0) res = 0;
    unos = 0;
    ceros = 0;
    F0(i,n){
        if(s[i] == '?') continue;
        if(s[i] == '0'){
            res += y*unos;
            ceros++;
        }
        else {
            res += x*ceros;
            unos++;
        }
    }
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    b();
    return 0;
}