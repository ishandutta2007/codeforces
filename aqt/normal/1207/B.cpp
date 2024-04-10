#include <bits/stdc++.h>

using namespace std;

int N, M;
int tar[55][55];
int cur[55][55];
vector<pair<int, int>> ans;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        for(int j= 1; j<=M; j++){
            cin >> tar[i][j];
        }
    }
    for(int i= 1; i<N; i++){
        for(int j= 1; j<M; j++){
            if(tar[i][j] == 1 && tar[i+1][j] == 1 && tar[i][j+1] == 1 && tar[i+1][j+1] == 1){
                ans.push_back({i, j});
                cur[i][j] = cur[i+1][j] = cur[i][j+1] = cur[i+1][j+1] = 1;
            }
        }
    }
    for(int i =1 ; i<=N; i++){
        for(int j= 1; j<=M; j++){
            if(cur[i][j] != tar[i][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans.size() <<"\n";
    for(auto p : ans){
        cout << p.first << " " << p.second << "\n";
    }
}