#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> graph[100005];
bool done[100005];
int wt[100005];
int par[100005];
int dgr[100005];
int leaf[100005][2];
int sum[100005];
vector<pair<pair<int, int>, int>> ans;
queue<int> qu;

void dfs(int n){
    for(auto e : graph[n]){
        if(par[n] != e.first){
            par[e.first] = n;
            wt[e.first] = e.second;
            dfs(e.first);
            dgr[n]++;
            if(leaf[n][0]){
                leaf[n][1] = leaf[e.first][0];
            }
            else{
                leaf[n][0] = leaf[e.first][0];
            }
        }
    }
    if(!dgr[n]){
        leaf[n][0] = n;
        qu.push(n);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<N; i++){
        int a, b, v;
        cin >> a >> b >> v;
        graph[a].push_back({b, v});
        graph[b].push_back({a, v});
    }
    int rt = 0;
    for(int i = 1; i<=N; i++){
        if(graph[i].size() == 2){
            if(graph[i][0].second != graph[i][1].second){
                cout << "NO" << endl;
                return 0;
            }
        }
        if(!rt && graph[i].size() == 1){
            rt = i;
        }
    }
    dfs(rt);
    for(int t = 1; t<N; t++){
        int n = qu.front();
        qu.pop();
        if(!leaf[n][1]){
            ans.push_back({{rt, n}, wt[n]});
        }
        else{
            ans.push_back({{rt, leaf[n][0]}, wt[n]/2});
            ans.push_back({{rt, leaf[n][1]}, wt[n]/2});
            ans.push_back({{leaf[n][0], leaf[n][1]}, -wt[n]/2});
        }
        dgr[par[n]]--;
        if(!dgr[par[n]]){
            qu.push(par[n]);
        }
        int crnt = n;
        int w = wt[n];
        while(crnt != rt){
            wt[crnt] -= w;
            crnt = par[crnt];
        }
    }
    cout << "YES" << "\n";
    cout << ans.size() << "\n";
    for(auto p : ans){
        cout << p.first.first << " " << p.first.second << " " << p.second << "\n";
    }
}