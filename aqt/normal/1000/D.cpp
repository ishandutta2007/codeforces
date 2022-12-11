#include <bits/stdc++.h>

using namespace std;

long long MOD = 998244353;
int N;
int arr[1005];
long long dp[1005];
long long pas[1005][1005]; //i choose j

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return a*b%MOD;
}

int main(){
    cin >> N;
    dp[0] = 1;
    for(int i = 0; i<=N; i++){
        pas[i][0] = pas[i][i] = 1;
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            pas[i][j] = add(pas[i-1][j], pas[i-1][j-1]);
        }
    }
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
        dp[i] = add(dp[i-1], dp[i]);
        if(arr[i] > 0){
            for(int j = i+arr[i]; j<=N; j++){
                dp[j+1] = add(dp[j+1], mult(dp[i], pas[j-i-1][arr[i]-1]));
            }
        }
    }
    cout << (add(dp[N], dp[N+1])-1+MOD)%MOD;
}