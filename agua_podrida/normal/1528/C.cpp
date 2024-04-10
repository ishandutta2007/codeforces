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
#define INF 1e18
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const ll mod = 998244353;

int res;
const int N = 3e5;
int lef[N],rig[N];

void dfs(vvi& g, int v, set<pi>& s){
    vpi poner;
    auto it = s.lower_bound({lef[v],rig[v]});
    if(it != s.end() and it->second <= rig[v]) {

    }
    else if(it != s.begin()){
        it--;
        if(it->second >= rig[v]) poner.pb(*it), s.erase(it);
        s.insert({lef[v],rig[v]});
    }
    else{
        s.insert({lef[v],rig[v]});
    }
    maxi(res,(int) s.size());
    for(auto u : g[v]){
        dfs(g,u,s);
    }
    for(auto p : poner) s.insert(p);
    s.erase({lef[v],rig[v]});
}


void dfs1(vvi& g, int v, int& i){
    mini(lef[v],i);
    i++;
    for(auto u : g[v]){
        i++;
        dfs1(g,u,i);
    }
    maxi(rig[v],i);
    i++;
}

void c(){
    int n;
    cin>>n;
    F0(i,n) lef[i] = 1e9;
    F0(i,n) rig[i] = -1;
    vvi g(n);
    int p;
    F1(i,n-1){
        cin>>p;
        p--;
        g[p].pb(i);
    }
    vvi g1(n);
    F1(i,n-1){
        cin>>p;
        g1[p-1].pb(i);
    }
    int i = 0;
    dfs1(g1,0,i);
    res = 0;
    set<pi> s;
    dfs(g,0,s);

    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) c();
    return 0;
}