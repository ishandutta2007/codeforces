#include <bits/stdc++.h>

using namespace std;

int dp[5005][5005];
int N, K;
int arr[5005];

int main(){
    cin >> N >> K;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+1+N);
    int ans = 0;
    for(int r = 1, l = 1; r<=N; r++){
        while(arr[r]-arr[l] > 5){
            l++;
        }
        for(int k = 1; k<=K; k++){
            dp[r][k] = max(dp[r-1][k], dp[l-1][k-1] + r-l+1);
            ans = max(dp[r][k], ans);
        }
    }
    cout << ans << endl;
}