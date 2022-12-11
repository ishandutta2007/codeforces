#include <bits/stdc++.h>

using namespace std;

int N, K;
bool dp[55][55];
long long arr[55];

int main(){
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    long long pre = 0;
    for(int b = 60; b>=0; b--){
        for(int i= 0; i<=N; i++){
            for(int j =0;j <=K; j++){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        pre |= (1LL<<b);
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=K; j++){
                long long tot = 0;
                for(int k = i; k>0; k--){
                    tot += arr[k];
                    dp[i][j] |= (((pre&tot) == pre) && dp[k-1][j-1]);
                }
            }
        }
        if(!dp[N][K]){
            pre ^= (1LL<<b);
        }
    }
    cout << pre << endl;
}