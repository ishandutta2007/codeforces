#include <bits/stdc++.h>

using namespace std;

int N, M;
long long pos[5005];
pair<long long, int> item[5005];
long long dp[5005][5005];
deque<pair<long long, int>> dq;

int main(){
    cin >> N >> M;
    for(int i= 1; i<=N; i++){
        cin >> pos[i];
    }
    sort(pos+1, pos+1+N);
    for(int i = 1; i<=M; i++){
        cin >> item[i].first >> item[i].second;
    }
    sort(item+1, item+1+M);
    for(int i = 1; i<=N; i++){
        dp[0][i] = LLONG_MAX/4;
    }
    for(int k = 1; k<=M; k++){
        dq.push_back({0, 0});
        long long pre = 0;
        for(int i = 1; i<=N; i++){
            pre += abs(pos[i] - item[k].first);
            while(dq.size() && dq.back().first >= dp[k-1][i]-pre){
                dq.pop_back();
            }
            dq.push_back({dp[k-1][i]-pre, i});
            while(dq.size() && dq.front().second < i-item[k].second){
                dq.pop_front();
            }
            dp[k][i] = dq.front().first + pre;
        }
        dq.clear();
    }
    if(dp[M][N] >= LLONG_MAX/4){
        dp[M][N] = -1;
    }
    cout << dp[M][N] << endl;
}