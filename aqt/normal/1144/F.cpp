#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[200005];
int clr[200005];
bool vis[200005];
pair<int, int> edge[200005];
bool works = 1;

void dfs(int n){
    for(int e : graph[n]){
        if(!vis[e]){
            vis[e] = 1;
            clr[e] = (clr[n]+1)%2;
            dfs(e);
        }
        else if(clr[e] != (clr[n]+1)%2){
            cout << "NO" << endl;
            exit(0);
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        edge[i] = {a,b};
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    cout << "YES" << endl;
    for(int i = 1; i<=M; i++){
        cout << clr[edge[i].first];
    }
}