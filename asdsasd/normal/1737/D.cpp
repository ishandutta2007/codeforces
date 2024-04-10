#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<atcoder/dsu>
using namespace std;
// using namespace atcoder;
const long long inf = 1LL << 60;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n, vector<int>());
    vector<vector<long long>> mi(n, vector<long long>(n, 1LL << 50));
    int v, u;
    long long c;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> c;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
        
        mi[u][v] = min(mi[u][v], c);
        mi[u][u] = min(mi[u][u], c);
        mi[v][v] = min(mi[v][v], c);
        mi[v][u] = min(mi[v][u], c);

    }

    vector<vector<int>> dist(n, vector<int>(n, -1));
    dist[0][n - 1] = 0;
    queue<int> que;
    que.push(n - 1);
    while(!que.empty()){
        int tmp = que.front();
        int i = tmp / n;
        int j = tmp - i * n;
        que.pop();
        int d = dist[i][j] + 1;
        if(i == j){
            for(auto k: edges[i]){
                if(dist[k][k] == -1){
                    dist[k][k] = d;
                    que.push(k * n + k);
                }
            }
        }
        for(auto k:edges[i]){
            if(dist[k][j] == -1){
                dist[k][j] = d;
                que.push(k * n + j);
            }
        }
        for(auto k:edges[j]){
            if(dist[i][k] == -1){
                dist[i][k] = d;
                que.push(i * n + k);
            }
        }
    }
    long long ans = inf;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j) ans = min(ans, mi[i][j] * (dist[i][j] + 1));
            else ans = min(ans, mi[i][j] * (dist[i][j] + 2));
        }
    }
    cout << ans << "\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}