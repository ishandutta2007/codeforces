#include <bits/stdc++.h>

using namespace std;

int N, K;
long long choose[255][255];
long long dp[255][255];
long long MOD = 1e9+7;
long long pows[255][2];

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
    for(int i = 0; i<=N; i++){
        choose[i][0] = 1;
        for(int j = 1; j<=i; j++){
            choose[i][j] = add(choose[i-1][j-1], choose[i-1][j]);
        }
    }
    pows[0][0] = pows[0][1] = 1;
    for(int i = 1; i<=N; i++){
        pows[i][0] = mult(pows[i-1][0], K);
        pows[i][1] = mult(pows[i-1][1], K-1);
    }
    dp[0][0] = 1;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            for(int k = 1; k<=j; k++){
                dp[i][j] = add(dp[i][j],
                               mult(mult(pows[j-k][0], pows[N-j][1]),
                                    mult(dp[i-1][j-k], choose[N-j+k][k])));
            }
            dp[i][j] = add(dp[i][j], mult(dp[i-1][j], mult(pows[N-j][1],
                                                           sub(pows[j][0], pows[j][1]))));
        }
    }
    cout << dp[N][N] << "\n";
}