#include <bits/stdc++.h>

using namespace std;

int N, M, T, K;
int arr[1505];
int pre[1505];
int dp[1505][1505];
int best[1505][1505];
int overlap[1505];
int nonoverlap[1505];
pair<int, int> pr[1505];

int solve(int n){
    for(int i = 1; i<=N; i++){
        pre[i] = pre[i-1] + (arr[i] <= n);
    }
    for(int j = 1; j<=T; j++){
        for(int i = 1; i<=M; i++){
            dp[j][i] = best[j][i] = 0;
            dp[j][i] = pre[pr[i].first]-pre[pr[i].second-1] + best[j-1][nonoverlap[i]];
            if(overlap[i]){
                dp[j][i] = max(dp[j][i], dp[j-1][overlap[i]]+pre[pr[i].first]
                               -pre[pr[overlap[i]].first]);
            }
            best[j][i] = max(best[j][i-1], dp[j][i]);
        }
    }
    return best[T][M];
}

int main(){
    cin >> N >> M >> T >> K;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=M; i++){
        cin >> pr[i].second >> pr[i].first;
    }
    sort(pr+1, pr+1+M);
    for(int i = 1; i<=M; i++){
        //cout << pr[i].first << " " << pr[i].second << endl;
        for(int j = 1; j<i; j++){
            //cout << pr[j].first << " " << pr[i].second << endl;
            if(pr[j].first < pr[i].second){
                nonoverlap[i] = j;
            }
            else if(!overlap[i] || pr[overlap[i]].second > pr[j].second){
                overlap[i] = j;
            }
        }
        //cout << i << " " << nonoverlap[i] << " " << overlap[i] << endl;
    }
    int l = 0, r = 1000000000, ans = -1;
    while(l <= r){
        int mid = l+r>>1;
        if(solve(mid) < K){
            l = mid + 1;
        }
        else{
            ans =mid;
            r = mid - 1;
        }
    }
    cout << ans << endl;
}