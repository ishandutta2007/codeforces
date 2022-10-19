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

const int N = 2e5;
vvpll g;
ll d[N][2][2];
int n,m;

void dijkstra(){
    ll dist,w;
    int v,a,b,u;
    F0(i,n) F0(a,2) F0(b,2) d[i][a][b] = -1;
    priority_queue<tuple<ll,int,int,int>> q;
    q.push({0,0,0,0});
    while(!q.empty()){
        tie(dist,v,a,b) = q.top();
        q.pop();
        if(d[v][a][b] != -1) continue;
        dist = -dist;
        d[v][a][b] = dist;
        for(auto uw : g[v]){
            tie(u,w) = uw;
            q.push({-dist-w,u,a,b});
            if(a == 0) q.push({-dist-2*w,u,1,b});
            if(b == 0) q.push({-dist,u,a,1});
            if(a == 0 and b == 0) q.push({-dist-w,u,1,1});
        }
    }
}

void minimum_path(){
    cin>>n>>m;
    g.resize(n);
    int u,v;
    ll w;
    F0(i,m){
        cin>>u>>v>>w;
        u--; v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    dijkstra();
    F1(i,n-1) cout<<d[i][1][1]<<' ';
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    minimum_path();
}