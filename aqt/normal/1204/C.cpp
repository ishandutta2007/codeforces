#include <bits/stdc++.h>

using namespace std;

int N, M;
int dist[105][105];
vector<int> ans;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        string s;
        cin >> s;
        for(int j =0 ; j<N; j++){
            if(s[j] == '1'){
                dist[i][j+1] = 1;
            }
            else{
                dist[i][j+1] = INT_MAX;
            }
        }
        dist[i][i] = 0;
    }
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++){
            for(int j= 1; j<=N; j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    /*
    for(int i = 1; i<=N; i++){
        for(int j= 1; j<=N; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    */
    cin >> M;
    int lst = 0, s = 0;
    cin >> lst;
    ans.push_back(lst);
    s = lst;
    int cnt = 0;
    for(int i = 2; i<=M; i++){
        int n;
        cin >> n;
        if(dist[s][n] == cnt+1){
            cnt++;
        }
        else{
            s = lst;
            ans.push_back(lst);
            cnt = 1;
        }
        lst = n;
    }
    ans.push_back(lst);
    cout << ans.size() << "\n";
    for(int n : ans){
        cout << n << " ";
    }
}