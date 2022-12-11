#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> graph[400005];
bool bri[400005], used[400005];
int low[400005], vis[400005], t = 0;
pair<int, int> ans[400005];

void dfs1(int n, int p){
    low[n] = vis[n] = ++t;
    for(auto e : graph[n]){
        if(!vis[e.first]){
            dfs1(e.first, n);
            low[n] = min(low[n], low[e.first]);
            if(low[e.first] == vis[e.first]){
                bri[e.second] = 1;
            }
        }
        else if(e.first != p){
            low[n] = min(low[n], vis[e.first]);
        }
    }
}

int dfs2(int n, int p){
    int sz = 1;
    vis[n] = 1;
    for(auto e : graph[n]){
        if(!vis[e.first] && !bri[e.second]){
            sz += dfs2(e.first, n);
        }
    }
    return sz;
}

void dfs3(int n, int p){
    vis[n] = ++t;
    for(auto e : graph[n]){
        if(!used[e.second]){
            used[e.second] = 1;
            ans[e.second] = {e.first, n};
        }
        if(!vis[e.first]){
            dfs3(e.first, n);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, i}), graph[b].push_back({a, i});
    }
    dfs1(1, 0);
    int maxv = 0, maxi = 0;
    fill(vis+1, vis+1+N, 0);
    for(int i = 1; i<=N; i++){
        if(!vis[i]){
            int v = dfs2(i, 0);
            if(v > maxv){
                maxv = v;
                maxi = i;
            }
        }
    }
    fill(vis+1, vis+1+N, 0);
    dfs3(maxi, 0);
    cout << maxv << "\n";
    for(int i = 1; i<=M; i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}