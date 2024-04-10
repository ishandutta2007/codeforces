#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
vector<int> graph[100005];
queue<int> ll;
int dep[100005];
int par[17][100005];
bool vis[100005];

int main(){
    scanf("%d %d %d", &N, &M, &Q);
    for(int i = 1; i<=M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i<=N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    ll.push(1);
    dep[1] = 1;
    vis[1] = 1;
    while(ll.size()){
        int n = ll.front();
        ll.pop();
        for(int e : graph[n]){
            if(!vis[e]){
                par[0][e] = n;
                dep[e] = dep[n] + 1;
                vis[e] = 1;
                ll.push(e);
            }
        }
    }
    for(int i = 1; i<=16; i++){
        for(int j = 1; j<=N; j++){
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
    while(Q--){
        int x, y;
        scanf("%d %d", &x, &y);
        int u = x, v = y;
        if(dep[u] < dep[v]){
            swap(u, v);
        }
        for(int i = 16; i>=0; i--){
            if(dep[par[i][u]] >= dep[v]){
                u = par[i][u];
            }
        }
        if(u == v){
            printf("%d\n", abs(dep[y] - dep[x]));
        }
        else{
            for(int i =16; i>=0; i--){
                if(par[i][u] != par[i][v]){
                    u = par[i][u];
                    v = par[i][v];
                }
            }
            int lca = par[0][u];
            int dis = dep[x] + dep[y] - 2*dep[lca];
            if(lower_bound(graph[u].begin(), graph[u].end(), v) != graph[u].end() && *
               lower_bound(graph[u].begin(), graph[u].end(), v) == v){
                printf("%d\n", dis-1);
            }
            else{
                printf("%d\n", dis);
            }
        }
    }
}