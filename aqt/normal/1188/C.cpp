#include <bits/stdc++.h>

using namespace std;

int N, K;
long long dp[1005][1005];
int arr[1005];
int ptr[1005];
long long MOD = 998244353;

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long sub(long long a, long long b){
    a = add(a, -b);
    if(a < 0){
        a += MOD;
    }
    return a;
}

long long mult(long long a, long long b){
    return a*b%MOD;
}

int main(){
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        dp[1][i] = 1;
        dp[1][i] += dp[1][i-1];
    }
    sort(arr+1, arr+1+N);
    int R = arr[N]-arr[1];
    long long lst = 0, ans = 0;
    for(int v = R/(K-1); v; v--){
        for(int n = 1; n<=N; n++){
            while(ptr[n]+1 < n && arr[n] - arr[ptr[n]+1] >= v){
                ptr[n]++;
            }
        }
        for(int k = 2; k<=K; k++){
            for(int n = 1; n<=N; n++){
                dp[k][n] = add(dp[k-1][ptr[n]], dp[k][n-1]);
            }
        }
        ans = add(ans, mult(v, sub(dp[K][N], lst)));
        lst = dp[K][N];
    }
    cout << ans << endl;
}