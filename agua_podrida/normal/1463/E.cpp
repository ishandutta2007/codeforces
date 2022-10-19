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

int n,k;

bool dfs(vvi& g, vi& visite, int v){
    if(visite[v] == 2) return false;
    if(visite[v] == 1) return true;
    visite[v] = 1;
    for(auto u : g[v]){
        if(dfs(g,visite,u)) return true;
    }
    visite[v] = 2;
    return false;
}

bool tieneCiclo(vvi& g){
    vi visite(n+1);
    F1(v,n){
        if(dfs(g,visite,v)) return true;
    }
    return false;
}

class dsu {
public:
    dsu(int n){
        set = vector<deque<int>>(n);
        F0(i,n) set[i].pb(i);
        donde = vi(n);
        F0(i,n) donde[i] = i;
    }
    int find(int i){
        return donde[i];
    }
    bool unite(int s, int t){
        int u = s; int v = t;
        s = donde[s]; t = donde[t];
        if(t == s) return true;
        if(set[s].back() != u or set[t].front() != v) return true;
        if(set[s].size() < set[t].size()) {
            while(!set[s].empty()) {
                int a = set[s].back();
                donde[a] = t;
                set[t].push_front(a);
                set[s].pop_back();
            }
        }
        else {
            while(!set[t].empty()){
                int a = set[t].front();
                donde[a] = s;
                set[s].push_back(a);
                set[t].pop_front();
            }
        }
        return false;
    }

    vector<deque<int>> set;
    vi donde;
};

vi res;

void toposort(vvi& g, dsu& uf, vb& visite, int v){
    if(visite[v]) return;
    visite[v] = true;
    for(auto u : g[v]) toposort(g,uf,visite,u);
    while(!uf.set[v].empty()) {
        int a = uf.set[v].back();
        uf.set[v].pop_back();
        res.pb(a);
    }
}

void e(){
    cin>>n>>k;
    vvi g(n+1);
    vpi E;
    int u,v;
    F1(u,n){
        cin>>v;
        if(v == 0) continue;
        g[v].pb(u);
        E.pb({v,u});
    }
    dsu uf(n+1);
    vpi xy;
    F0(i,k){
        cin>>u>>v;
        if(uf.unite(u,v)){
            cout<<"0\n";
            return;
        }
        xy.pb({u,v});
        g[u].pb(v);
    }
    if(tieneCiclo(g)) {
        cout<<"0\n";
        return;
    }

    vvi gp(n+1);
    vi din(n+1);
    for(auto e : E){
        u = uf.find(e.first); v = uf.find(e.second);
        if(u == v) continue;
        gp[u].pb(v);
        din[v]++;
    }
    for(auto e : xy) {
        u = uf.find(e.first); v = uf.find(e.second);
        if(u == v) continue;
        gp[u].pb(v);
        din[v]++;
    }
    if(tieneCiclo(gp)) {
        cout<<"0\n";
        return;
    }

    vb visite(n+1);
    F1(v,n) if(din[v] == 0) toposort(gp,uf,visite,v);
    reverse(todo(res));
    for(auto v : res) cout<<v<<' ';
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