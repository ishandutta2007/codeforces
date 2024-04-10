#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> graph[100005];
int low[100005], vis[100005], t = 0;
bool pos = 1;
vector<pair<int, int>> ans;
bool used[400005];

void dfs(int n, int p){
    low[n] = vis[n] = ++t;
    for(auto e : graph[n]){
        if(!vis[e.first]){
            dfs(e.first, n);
            low[n] = min(low[n], low[e.first]);
        }
        else if(e.first != p){
            low[n] = min(low[n], vis[e.first]);
        }
        if(e.first != p){
            if(!used[e.second]){
                ans.push_back({n, e.first});
                used[e.second] = 1;
            }
        }
    }
    if(low[n] == vis[n] && p){
        pos = 0;
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, i}), graph[b].push_back({a, i});
    }
    dfs(1, 0);
    if(pos){
        for(auto p : ans){
            cout << p.first << " " << p.second << "\n";
        }
    }
    else{
        cout << 0 << "\n";
    }
}