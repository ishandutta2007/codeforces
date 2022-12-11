#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[200005];
int val[200005];
bool vis[200005];
pair<int, int> edge[200005];
int ans[200005];

void dfs(int n, int p){
    vis[n] = 1;
    for(int e : graph[n]){
        if(e == p){
            continue;
        }
        if(edge[e].first == n){
            int k = edge[e].second;
            if(vis[k]){
                continue;
            }
            dfs(k, e);
            ans[e] = (val[k]);
            val[k] = 0;
            val[n] += ans[e];
        }
        else{
            int k = edge[e].first;
            if(vis[k]){
                continue;
            }
            dfs(k, e);
            ans[e] = -(val[k]);
            val[k] = 0;
            val[n] -= ans[e];
        }
    }
//    cout << " " << n << " " << val[n] << " " << p << endl;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> val[i];
    }
    cin >> M;
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(i);
        graph[b].push_back(i);
        edge[i] = {a, b};
    }
    bool pos = 1;
    for(int n = 1; n<=N; n++){
        if(!vis[n]){
            dfs(n, 0);
            if(val[n]){
                pos = 0;
            }
        }
    }
    if(pos){
        cout << "Possible" << "\n";
        for(int i = 1; i<=M; i++){
            cout << ans[i] << "\n";
        }
    }
    else{
        cout << "Impossible" << "\n";
    }
}