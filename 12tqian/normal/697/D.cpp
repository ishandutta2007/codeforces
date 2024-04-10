#include <bits/stdc++.h>
using namespace std;
static vector<vector<int>> adj;
const int MAX = 1000005;
int v [MAX];
double e [MAX];
static int vis[MAX];
void bfs(int src){
    v[src] = 1;
    vis[src] = 1;
    for(int x: adj[src]){
        if(vis[x] == 0){
            bfs(x);
            v[src] += v[x];
        }
    }
}
void bfs1(int src){
    list<int> q;
    q.push_back(src);
    e[src] = 1;
    while(!q.empty()){
        int s = q.front();
        q.pop_front();
        double sum = 0;
        int num = 0;
        for(int n: adj[s]){
            sum += (v[n] *.5);
            num += 1;
        }
        for(int n: adj[s]){
            e[n] = sum - v[n]*.5 + 1+e[s];
        }
        for(int n: adj[s]){
            q.push_back(n);
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        e[i] = 0;
        vis[i] = 0;
        vector<int> temp;
        adj.emplace_back(temp);
    }
    for(int i = 0; i<n-1; i++){
        int d;
        scanf("%d", &d);
        //adj[i+1].emplace_back(d-1);
        adj[d-1].emplace_back(i+1);
    }
    bfs(0);
    bfs1(0);
    for(int i = 0; i<n; i++){
        cout << e[i] << " " ;
    }
    return 0;
}