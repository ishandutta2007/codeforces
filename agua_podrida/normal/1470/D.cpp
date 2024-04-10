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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

int n,m;

void dfs(vvi& g, vb& visite, int v){
    if(visite[v]) return;
    visite[v] = true;
    for(auto u : g[v]) dfs(g,visite,u);
}

bool esConexo(vvi& g){
    vb visite(n+1,false);
    dfs(g,visite,1);
    F1(i,n) if(!visite[i]) return false;
    return true;
}

void dfs2(vvi& g, vb& visite, set<int>& I, int v){
    if(visite[v]) return;
    visite[v] = true;
    bool tengoVecI = false;
    for(auto u : g[v]) if(I.count(u)) tengoVecI = true;
    if(!tengoVecI) I.insert(v);
    for(auto u : g[v]) dfs2(g,visite,I,u);
}

void d(){
    cin>>n>>m;
    vvi g(n+1);
    int u,v;
    F0(i,m){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(!esConexo(g)) {
        cout<<"NO\n";
        return;
    }

    set<int> I;
    vb visite(n+1,false);
    dfs2(g,visite,I,1);

    cout<<"YES\n";
    cout<<I.size()<<'\n';
    for(auto v : I) cout<<v<<' ';
    cout<<'\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) d();
    return 0;
}