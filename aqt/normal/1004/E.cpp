#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> graph[100005];
int dist[2][100005];
int par[2][100005];
bool partdia[100005];
bool vis[100005];

void dfs(int n, int p, int t, int k = 0){
    vis[n] = k;
    for(auto e : graph[n]){
        if(e.first != p && !vis[e.first] && !partdia[e.first]){
            dist[t][e.first] = dist[t][n] + e.second;
            par[t][e.first] = n;
            dfs(e.first, n, t, k);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i<N; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    dfs(1, 0, 0);
    int a = 0;
    for(int i = 1; i<=N; i++){
        a = dist[0][i] > dist[0][a] ? i : a;
    }
    dist[0][a] = 0;
    dfs(a, 0, 0);
    int b = 0;
    for(int i = 1; i<=N; i++){
        b = dist[0][i] > dist[0][b] ? i : b;
    }
    dfs(b, 0, 1);
    int c = a;
    for(int i = 1; i<=N; i++){
        c = max(dist[0][c], dist[1][c]) > max(dist[0][i], dist[1][i]) ? i : c;
    }
    int crnta = c, crntb = c;
    vis[c] = 1;
    par[0][a] = a;
    par[1][b] = b;
    partdia[c] = 1;
    for(K--; K; K--){
        if(dist[0][crnta] > dist[1][crntb]){
            crnta = par[0][crnta];
        }
        else{
            crntb = par[1][crntb];
        }
        partdia[crnta] = partdia[crntb] = 1;
    }
    for(int i = 1; i<=N; i++){
        if(partdia[i]){
            dist[0][i] = 0;
            dfs(i, 0, 0, 1);
        }
    }
    int ans = 0;
    for(int i = 1; i<=N; i++){
        ans = max(ans, dist[0][i]);
    }
    cout << ans << endl;
}