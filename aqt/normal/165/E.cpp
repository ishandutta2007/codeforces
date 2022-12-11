#include <bits/stdc++.h>

using namespace std;

int dp[1<<22];
int N;
int arr[1000005];

int main(){
    cin >> N;
    fill(dp, dp+(1<<22), -1);
    for(int i = 0; i<N; i++){
        cin >> arr[i];
        dp[arr[i]] = arr[i];
    }
    for(int m = 0; m<1<<22; m++){
        for(int i = 0; i<22; i++){
            if(m&(1<<i)){
                if(dp[m^(1<<i)] != -1){
                    dp[m] = dp[m^(1<<i)];
                }
            }
        }
    }
    for(int i = 0; i<N; i++){
        printf("%d ", dp[((1<<22)-1)^arr[i]]);
    }
}