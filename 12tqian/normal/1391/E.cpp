#include<bits/stdc++.h>
using namespace std;

const int MAX = 5e5 + 5;
vector<int> adj[MAX];
int depth[MAX];
int par[MAX];
bool vis[MAX];
int n, m;
void dfs_process(int src){
    vis[src] = true;
    for(int nxt: adj[src]){
        if(vis[nxt]) continue;
        depth[nxt] = depth[src] + 1;
        par[nxt] = src;
        dfs_process(nxt);
    }
}
void solve_case(){
    cin >> n >> m;
    int lim = (n + 1) / 2;
    for(int i = 0; i < n; i++){
        adj[i].clear();
        vis[i] = false;
    }
    par[0] = -1; depth[0] = 0;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs_process(0);
    int max_depth = 0;
    for(int i = 0; i < n; i++){
        if(depth[i] + 1 >= lim){
            vector<int> res;
            int cur = i;
            while(cur != -1){
                res.push_back(cur);
                cur = par[cur];
            }
            cout << "PATH" << '\n';
            cout << (int) res.size() << '\n';
            for(int x: res) cout << x + 1 << " ";
            cout << '\n';
            return;
        }
    }
    vector<vector<int>> nodes(n + 1);
    for(int i = 0; i < n; i++) nodes[depth[i]].push_back(i);
    vector<pair<int, int>> res;
    for(vector<int> dep: nodes){
        for(int i = 0; i < (int) dep.size() - 1; i += 2){
            res.emplace_back(dep[i], dep[i + 1]);
        }
    }
    cout << "PAIRING" << '\n';
    cout << (int) res.size() << '\n';
    for(pair<int, int> x: res){
        cout << x.first + 1 << " " << x.second + 1 << '\n';
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int test_cases; cin >> test_cases;
    while(test_cases--) solve_case();
    return 0;
}