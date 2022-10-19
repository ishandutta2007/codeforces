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

vector<int, int> &
getVector(const unordered_map<ll, int> &trad, vector<map<int, int>> &g, int dst, int &prox, ll res, int v, int i);

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
#define eps 0.000000001
#define mod 1000000007
#define PI acos(-1.0)

vi hijos;
vi dp,a,path;
vb sirve;
map<int,vi> m;

void dfs(vvi& g, int v, int p, int prof){
    path.pb(v);
    if(m.count(a[v]) and !m[a[v]].empty()){
        int w = m[a[v]].back();
        dp[0]++;
        w = path[w+1];
        dp[w]--;

        w = m[a[v]][0];
        hijos[path[w]]++;
    }
    m[a[v]].pb(prof);
    for(auto u : g[v]){
        if(u == p) continue;
        dfs(g,u,v,prof+1);
    }
    m[a[v]].pop_back();
    path.pop_back();
}

void dfs2(vvi& g, int suma, int v, int p){
    suma += dp[v];
    if(suma == 0) sirve[v] = true;
    for(auto u : g[v]){
        if(u == p) continue;
        dfs2(g,suma,u,v);
    }
}

void e(){
    int n;
    cin>>n;
    hijos.resize(n);
    a.resize(n);
    dp.resize(n);
    sirve = vb(n,false);
    F0(i,n) cin>>a[i];
    vvi g(n);
    int u,v;
    F0(i,n-1){
        cin>>u>>v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(g,0,-1,0);

    F0(i,n) m[a[i]].pb(i);
    for(auto it : m){
        vi pos = it.second;
        if(pos.size() <= 1) continue;
        for(auto v : pos){
            if(hijos[v] < pos.size()-1) dp[v]++;
        }
    }

    dfs2(g,0,0,-1);

    int res = 0;
    for(auto s : sirve) if(s) res++;
    cout<<res<<'\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    e();
    return 0;
}