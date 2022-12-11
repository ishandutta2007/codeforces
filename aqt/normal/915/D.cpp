#include <bits/stdc++.h>

using namespace std;

int N, M;
bool graph[505][505];
vector<pair<int, int>> v;
int vis[505];

bool iscyclic(int n, bool b){
    vis[n] = 1;
    for(int e = 1; e <= N; e++){
        if(graph[n][e]){
            if(!vis[e] && iscyclic(e, b)){
                if(b){
                    v.push_back({n, e});
                }
                return 1;
            }
            else if(vis[e] == 1){
                if(b){
                    v.push_back({n, e});
                }
                return 1;
            }
        }
    }
    vis[n] = 2;
    return 0;
}

int main(){
    cin >> N >> M;
    for(int i= 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
    for(int i = 1; i<=N; i++){
        if(!vis[i] && iscyclic(i, 1)){
            break;
        }
    }
    if(v.empty()){
        cout << "YES" << endl;
        return 0;
    }
    for(auto p : v){
        graph[p.first][p.second] = 0;
        fill(vis+1, vis+1+N, 0);
        bool b = 1;
        for(int n = 1; n<=N; n++){
            if(!vis[n] && iscyclic(n, 0)){
                b = 0;
            }
        }
        if(b){
            cout << "YES" << endl;
            return 0;
        }
        graph[p.first][p.second] = 1;
    }
    cout << "NO" << endl;
}