#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

struct MaxFlow{
    struct Edge{
        int to , cap;
    };
    int s , t;
    vector<Edge> E;
    vector<vector<int>> adj;
    vector<int> dist , ptr;

    void init(int n){
        E.clear(); adj.clear(); dist.clear(); ptr.clear();
        adj.resize(n); dist.resize(n); ptr.resize(n);
    }

    void addEdge(int v , int u , int cap){
        adj[v].push_back(SZ(E)); E.push_back({u , cap});
        adj[u].push_back(SZ(E)); E.push_back({v , 0});
    }

    int BFS(){
        fill(all(ptr) , 0);
        fill(all(dist) , MOD);
        queue<int> Q;
        dist[s] = 0;
        Q.push(s);
        while(!Q.empty()){
            int v = Q.front(); Q.pop();
            for(int i : adj[v]){
                if(E[i].cap == 0)   continue;
                if(dist[E[i].to] != MOD)    continue;
                dist[E[i].to] = dist[v] + 1;
                Q.push(E[i].to);
            }
        }
        return (dist[t] != MOD);
    }

    int DFS(int v , int f = MOD){
        if(v == t)  return f;
        int ans = 0;
        for( ; ptr[v] < SZ(adj[v]) ; ptr[v]++){
            int i = adj[v][ptr[v]];
            if(dist[E[i].to] != dist[v] + 1 || E[i].cap == 0) continue;
            int flow = min(f , E[i].cap);
            int res = DFS(E[i].to , flow);
            ans += res; f -= ans;
            E[i].cap -= res;
            E[(i ^ 1)].cap += res;
            if(f == 0)  break;
        }
        return ans;
    }

    int maxFlow(int _s , int _t){
        s = _s; t = _t;
        int ans = 0;
        while(BFS()){
            ans += DFS(s);
        }
        return ans;
    }
} flow;

int n , m , A[MAXN] , B[MAXN] , ans[MAXN];
vector<int> vec;
vector<pii> E;

void solve(int l, int r, vector<int> vec){
    if(r - l == 1){
        for(int i : vec){
            ans[i] = B[l];
        }
        return;
    }
    int mid = l + r >> 1;
    flow.init(n + 2);
    for(pii i : E){
        flow.addEdge(i.Y , i.X , MOD);
    }
    for(int i : vec){
        if(A[i] < B[mid]){
            flow.addEdge(0 , i , 1);
        }
        else{
            flow.addEdge(i , n + 1 , 1);
        }
    }
    flow.maxFlow(0 , n + 1);
    vector<int> L , R;
    for(int i : vec){
        if(flow.dist[i] != MOD){
            L.push_back(i);
        }
        else{
            R.push_back(i);
        }
    }
    solve(l , mid , L);
    solve(mid , r , R);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i];
        B[i - 1] = A[i];
        vec.push_back(i);
    }
    sort(B , B + n);
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin >> v >> u;
        E.push_back({v , u});
    }
    solve(0 , n , vec);
    for(int i = 1 ; i <= n ; i++){
        cout << ans[i] << sep;
    }

    return 0;
}
/*

*/