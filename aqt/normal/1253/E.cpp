#include <bits/stdc++.h>

using namespace std;

int N, M;
int dp[85][100005];
int pre[85][100005];
pair<int, int> arr[85];
int cnt[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        int x, d;
        cin >> x >> d;
        arr[i].first = x+d, arr[i].second = x-d;
        cnt[max(x-d, 0)]++;
        cnt[min(x+d+1, M+1)]--;
    }
    for(int i = 1; i<=M; i++){
        cnt[i] += cnt[i-1];
        for(int j = 0; j<=N; j++){
            dp[j][i] = INT_MAX/2;
        }
    }
    sort(arr+1, arr+1+N);
    for(int k = 1; k<=N; k++){
        swap(arr[k].first, arr[k].second);
        for(int i = arr[k].second+1; i<=M; i++){
            int t = max(1, arr[k].first-(i-arr[k].second));
            dp[k][i] = dp[k-1][t-1] + i - arr[k].second;
        }
        dp[k][min(M, arr[k].second)] = dp[k-1][max(1, arr[k].first)-1];
        for(int i = arr[k].first-1; i > 0; i--){
            int t = min(M, arr[k].second+(arr[k].first-i));
            dp[k][t] = min(dp[k][t], dp[k-1][i-1] + arr[k].first - i);
        }
        dp[k][M] = min(dp[k-1][M], dp[k][M]);
        for(int i = M-1; i>=0; i--){
            dp[k][i] = min(dp[k-1][i], min(dp[k][i], dp[k][i+1]));
        }
    }
    /*
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=M; i++){
            cout << dp[k][i] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[N][M] << endl;
}