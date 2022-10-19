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

void dfs(vector<set<int>>& g, vb& visitado, int v){
    if(visitado[v]) return;
    visitado[v] = true;
    for(auto u : g[v]) dfs(g,visitado,u);
}

bool haceFalta(vector<set<int>>& g, int u, int v){
    g[u].erase(v);
    vb visitado(20,false);
    dfs(g,visitado,u);
    g[u].insert(v);
    return !visitado[v];
}

int f(vector<set<int>> g, vpi& E){
    int u,v;
    for(auto e : E){
        tie(u,v) = e;
        if(!haceFalta(g,u,v)){
            g[u].erase(v);
        }
    }
    int res = 0;
    F0(i,20) res += g[i].size();
    return res;
}

void c(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    vector<set<int>> g(20);
    vpi E;
    F0(i,n){
        if(s[i] != t[i]) {
            g[s[i] - 'a'].insert(t[i] - 'a');
            E.pb({s[i] - 'a',t[i] - 'a'});
        }
    }
    int res = 10000;
    int iter = 625;
    while(iter--) {
        random_shuffle(todo(E));
        mini(res,f(g,E));
    }
    cout<<res<<'\n';
}

void d(){
    int n,m;
    cin>>n>>m;
    vvi a(n,vi(m));
    F0(i,n) F0(j,m) cin>>a[i][j];
    vi r(n),c(m);
    F0(i,n) F0(j,m) maxi(r[i],a[i][j]);
    F0(i,n) F0(j,m) maxi(c[j],a[i][j]);

    sort(todo(r));
    reverse(todo(r));
    sort(todo(c));
    reverse(todo(c));

    vvi b(n,vi(m));
    int ir = 1;
    int ic = 1;
    queue<pi> disp;
    b[0][0] = n*m;
    int poniendo = n*m-1;
    int i = 0, j = 0;
    while(poniendo >= 1){
        if(r[ir] == poniendo and c[ic] == poniendo){
            i++; j++;
            b[i][j] = poniendo;
            ir++; ic++;
            F0R(ip,i) disp.push({ip,j});
            F0R(jp,j) disp.push({i,jp});
        }
        else if(r[ir] == poniendo){
            i++;
            b[i][j] = poniendo;
            ir++;
            F0R(jp,j) disp.push({i,jp});
        }
        else if(c[ic] == poniendo){
            j++;
            b[i][j] = poniendo;
            ic++;
            F0R(ip,i) disp.push({ip,j});
        }
        else {
            int ip,jp;
            tie(ip,jp) = disp.front();
            disp.pop();
            b[ip][jp] = poniendo;
        }
        poniendo--;
    }

    F0(i,n) {
        F0(j,m){
            cout<<b[i][j]<<' ';
        }
        cout<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    d();
}