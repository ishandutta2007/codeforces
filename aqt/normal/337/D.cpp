#include <bits/stdc++.h>

using namespace std;

int N, K, L;
bool tkn[100005];
vector<int> graph[100005];
int dist[100005][2];

void dfs(int n, int p, int t){
    for(int e : graph[n]){
        if(e != p){
            dist[e][t] = dist[n][t] + 1;
            dfs(e, n, t);
        }
    }
}

int main(){
    cin >> N >> K >> L;
    for(int i = 1; i<=K; i++){
        int n;
        cin >> n;
        tkn[n] = 1;
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0, 0);
    int nxt = 1;
    for(int i = 1; i<=N; i++){
        if(tkn[i] && dist[i][0] > dist[nxt][0]){
            nxt = i;
        }
    }
    dist[nxt][0] = 0;
    dfs(nxt, 0, 0);
    for(int i = 1; i<=N; i++){
        if(tkn[i] && dist[i][0] > dist[nxt][0]){
            nxt = i;
        }
    }
    dfs(nxt, 0, 1);
    int cnt = 0;
    for(int i= 1; i<=N; i++){
        if(max(dist[i][0], dist[i][1]) <= L){
            cnt++;
        }
    }
    cout << cnt << endl;
}