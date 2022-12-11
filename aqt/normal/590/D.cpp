#include <bits/stdc++.h>

using namespace std;

int N, K, S;
int arr[155];
long long dp[2][155][12000];
//k, pos, swapval

int main(){
    cin >> N >> K >> S;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    long long ans = 0;
    if(N*(N-1)>>1 <= S){
        sort(arr, arr+1+N);
        for(int i= 1; i<=K; i++){
            ans += arr[i];
        }
    }
    else{
        ans = INT_MAX;
        for(int i = 1; i<=K; i++){
            for(int j = 0; j<=S; j++){
                for(int k = 0; k<=N; k++){
                    dp[i&1][k][j] = INT_MAX;
                }
            }
            for(int j = 0; j<=S; j++){
                for(int k = i; k<=N; k++){
                    if(j-(k-i) < 0){
                        dp[i&1][k][j] = dp[i&1][k-1][j];
                    }
                    else{
                        dp[i&1][k][j] = min(dp[i&1][k-1][j], dp[i&1^1][k-1][j-(k-i)] + arr[k]);
                    }
                }
            }
        }
        for(int j = 0; j<=S; j++){
            ans = min(dp[K&1][N][j], ans);
        }
    }
    cout << ans << endl;
}