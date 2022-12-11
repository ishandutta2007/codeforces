#include <bits/stdc++.h>

using namespace std;

int N, S;
vector<int> graph[200005];
int dist[200005];

void dfs1(int n, int p){
    for(int e : graph[n]){
        if(e !=p ){
            dist[e] = dist[n] + 1;
            dfs1(e, n);
        }
    }
}

int dfs2(int n, int p, int d){
    if(d >= dist[n]){
        return 0;
    }
    int crnt = dist[n];
    for(int e : graph[n]){
        if(e != p){
            crnt = max(crnt, dfs2(e, n, d+1));
        }
    }
    return crnt;
}

int main(){
    cin >> N >> S;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        if(a > b){
            swap(a, b);
        }
        if(a == 1){
            graph[a].push_back(b);
        }
        else{
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    dfs1(1, 0);
    cout << dfs2(S, 0, 0)*2 << endl;
}