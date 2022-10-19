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
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 2e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define mod 1000000007

vector<unordered_set<int>> g;
vb visitado;
vi falta;
vvi gc;
int toca;

void bfs(int v, int p){
    queue<pi> q;
    q.push({v,p});
    while(!q.empty()){
        tie(v,p) = q.front();
        q.pop();
        visitado[v] = true;
        int i = 0;
        while(i < falta.size()){
            int u = falta[i];
            if(g[v].count(u)) i++;
            else if(u == v) {
                falta[i] = falta.back();
                falta.pop_back();
            }
            else {
                falta[i] = falta.back();
                falta.pop_back();
                q.push({u,v});
                gc[u].pb(v);
                gc[v].pb(u);
            }
        }
    }
}

vi P,Q;
vi alt;

void dfs(int v, int p){
    if(visitado[v]) return;
    visitado[v] = true;
    alt[v] = 0;
    for(auto u : gc[v]){
        if(u == p) continue;
        dfs(u,v);
        maxi(alt[v],alt[u]+1);
    }
    int aux = toca;
    if(alt[v] == 1){
        for(auto u : gc[v]){
            if(u == p) continue;
            if(alt[u] == -1) continue;
            P[u] = toca;
            Q[u] = toca+1;
            toca++;
        }
        P[v] = toca;
        Q[v] = aux;
        toca++;
        alt[v] = -1;
    }
    else if(v == p){
        int hijo = -1;
        for(auto u : gc[v]) if(alt[u] == -1) hijo = u;
        if(hijo != -1) {
            Q[v] = toca;
            P[v] = toca-1;
            P[hijo] = toca;
        }
        else {
            Q[v] = toca;
            P[v] = toca;
        }
        toca++;
    }
}

void d(){
    int n,m;
    cin>>n>>m;
    P.resize(n);
    Q.resize(n);
    alt.resize(n);
    gc = vvi(n);
    int u,v;
    toca = 1;
    g = vector<unordered_set<int>>(n);
    visitado = vb(n,false);
    falta.resize(n);
    F0(i,n) falta[i] = i;
    F0(i,m){
        cin>>u>>v;
        u--; v--;
        g[u].insert(v);
        g[v].insert(u);
    }

    F0(v,n) if(!visitado[v]) bfs(v,v);

    visitado = vb(n,false);

    F0(v,n) dfs(v,v);

    F0(i,n) cout<<P[i]<<' ';
    cout<<'\n';
    F0(i,n) cout<<Q[i]<<' ';
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) d();
}