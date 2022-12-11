#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int mp[305][305];
int m[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> pos[100000];
int dp[305][305];
int dist[305][305];

int main(){
    cin >> N >> M >> K;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cin >> mp[i][j];
            pos[mp[i][j]].push_back({i, j});
        }
    }
    for(auto n : pos[1]){
        dp[n.first][n.second] = n.first-1 + n.second - 1;
    }
    for(int k = 1; k<K; k++){
        if(N*M >= (int) (pos[k].size()) * (int) (pos[k+1].size())){
            for(auto m : pos[k+1]){
                dp[m.first][m.second] = INT_MAX;
            }
            for(auto n : pos[k]){
                for(auto m : pos[k+1]){
                    dp[m.first][m.second] = min(dp[m.first][m.second], dp[n.first][n.second]
                                                + abs(n.first - m.first)
                                                + abs(n.second - m.second));
                }
            }
        }
        else{
            queue<pair<int ,int>> qu;
            for(int i = 1; i<=N; i++){
                for(int j= 1; j<=M; j++){
                    dist[i][j] = INT_MAX;
                }
            }
            for(auto n : pos[k]){
                dist[n.first][n.second] = dp[n.first][n.second];
                qu.push(n);
            }
            while(qu.size()){
                pair<int, int> p = qu.front();
                qu.pop();
                for(int i = 0; i<4; i++){
                    if(dist[p.first+m[i][0]][p.second+m[i][1]] > dist[p.first][p.second] + 1){
                        dist[p.first+m[i][0]][p.second+m[i][1]] = dist[p.first][p.second] + 1;
                        qu.push({p.first+m[i][0], p.second+m[i][1]});
                    }
                }
            }
            for(auto n : pos[k+1]){
                dp[n.first][n.second] = dist[n.first][n.second];
            }
        }
    }
    cout << dp[pos[K][0].first][pos[K][0].second] << endl;
}