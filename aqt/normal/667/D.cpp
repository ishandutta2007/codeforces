#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[3005];
vector<pair<int, int>> from[3005], to[3005];
int dist[3005][3005];
vector<int> out;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i =1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int n = 1; n<=N; n++){
        fill(dist[n]+1, dist[n]+1+N, INT_MAX/2);
        dist[n][n] = 0;
        queue<int> qu;
        qu.push(n);
        while(qu.size()){
            int k = qu.front();
            qu.pop();
            for(int e : graph[k]){
                if(dist[n][e] > dist[n][k] + 1){
                    dist[n][e] = dist[n][k] + 1;
                    qu.push(e);
                }
            }
        }
    }
    for(int n = 1; n<=N; n++){
        for(int i = 1; i<=N; i++){
            if(i != n){
                if(dist[n][i] != INT_MAX/2){
                    from[n].push_back({dist[n][i], i});
                }
                if(dist[i][n] != INT_MAX/2){
                    to[n].push_back({dist[i][n], i});
                }
            }
        }
        sort(from[n].begin(), from[n].end(), greater<pair<int, int>>());
        sort(to[n].begin(), to[n].end(), greater<pair<int, int>>());
    }
    int ans = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            if(dist[i][j] != INT_MAX/2 && i != j){
                int opt1 = 0, opt2 = 0;
                for(int a = 0; a<3 && a < from[j].size(); a++){
                    for(int b = 0; b<3 && b < to[i].size(); b++){
                        if(from[j][a].second != to[i][b].second
                           && from[j][a].second != i && to[i][b].second != j){
                            if(ans < dist[i][j] + from[j][a].first + to[i][b].first){
                                ans = dist[i][j] + from[j][a].first + to[i][b].first;
                                out = {to[i][b].second, i, j, from[j][a].second};
                            }
                        }
                    }
                }
            }
        }
    }
    for(auto n : out){
        cout << n << " ";
    }
}