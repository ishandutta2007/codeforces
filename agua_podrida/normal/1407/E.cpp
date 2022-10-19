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
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 2e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define mod 1000000007

const int N = 500000;
vi g[N][2],gr[N][2];
int dist[N];
bool color[N],visto[N][2];
int n,m,u,v,c,d;

void bfs(){
    F0(i,n) dist[i] = INF;
    F0(i,n) color[i] = 0;
    queue<pi> q;
    q.push({0,n-1});
    while(!q.empty()){
        tie(d,v) = q.front();
        q.pop();
        dist[v] = d;
        for(auto u : gr[v][0]){
            if(visto[u][0]) continue;
            visto[u][0] = true;
            if(visto[u][1]) q.push({d+1,u});
            else color[u] = 1;
        }
        for(auto u : gr[v][1]){
            if(visto[u][1]) continue;
            visto[u][1] = true;
            if(visto[u][0]) q.push({d+1,u});
            else color[u] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    F0(i,m){
        cin>>u>>v>>c;
        u--; v--;
        if(u == v) continue;
        g[u][c].pb(v);
        gr[v][c].pb(u);
    }
    bfs();
    if(dist[0] == INF) dist[0] = -1;
    cout<<dist[0]<<'\n';
    F0(i,n) cout<<color[i];
    cout<<'\n';
}