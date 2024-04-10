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
#define mod 998244353

void floyd(vvi& d){
    int n = d.size();
    F0(k,n) F0(i,n) F0(j,n) mini(d[i][j],d[i][k] + d[k][j]);
}

void dfs(vvi& g, vi& color, int c, int v){
    if(color[v] != -1) return;
    color[v] = c;
    c++;
    c %= 2;
    for(auto u : g[v]) dfs(g,color,c,u);
}

bool esBipartito(vvi& g){
    int n = g.size();
    vi color(n,-1);
    F0(i,n) dfs(g,color,0,0);
    F0(u,n) {
        for(auto v : g[u]) if(color[u] == color[v]) return false;
    }
    return true;
}

void e(){
    int n,m;
    cin>>n>>m;
    vvi g(n);
    vvi d(n,vi(n,INF));
    int u,v,b;
    F0(i,m) {
        cin>>u>>v>>b;
        u--; v--;
        d[u][v] = 1;
        d[v][u] = 1;
        if(b == 1) d[v][u] = -1;
        g[u].pb(v);
        g[v].pb(u);
    }

    if(!esBipartito(g)) {
        cout<<"NO\n";
        return;
    }
    F0(i,n) d[i][i] = 0;

    floyd(d);

    F0(i,n) {
        if(d[i][i] < 0) {
            cout<<"NO\n";
            return;
        }
    }

    u = 0; v = 0;
    F0(i,n) F0(j,n) if(d[i][j] > d[u][v]) {
                u = i;
                v = j;
            }

    cout<<"YES\n";
    cout<<d[u][v]<<'\n';
    F0(i,n) cout<<d[u][i]<<' ';
    cout<<'\n';
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