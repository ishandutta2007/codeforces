#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[2][100005];
int arr[2][100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[0][i];
    }
    for(int i = 1; i<=N; i++){
        cin >> arr[1][i];
    }
    for(int i = 1; i<=N; i++){
        dp[0][i] = max(dp[0][i-1], dp[1][i-1] + arr[0][i]);
        dp[1][i] = max(dp[1][i-1], dp[0][i-1] + arr[1][i]);
    }
    cout << max(dp[0][N], dp[1][N]) << endl;
}