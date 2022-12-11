#include <bits/stdc++.h>

using namespace std;

int N, K;
long long dp[1005][2005][4];
long long MOD = 998244353;
long long t[4][4]; //m2, m1

long long add(long long a, long long b){
    return (a+b)%MOD;
}

int main(){
    cin >> N >> K;
    dp[1][1][0] = 1;
    dp[1][2][1] = 1;
    dp[1][2][2] = 1;
    dp[1][1][3] = 1;
    t[0][1] = 1;
    t[0][2] = 1;
    t[0][3] = 1;
    t[1][2] = 2;
    t[2][1] = 2;
    t[3][0] = 1;
    t[3][1] = 1;
    t[3][2] = 1;
    for(int i = 2; i<=N; i++){
        for(int k = 1; k<=K; k++){
            for(int m1 = 0; m1<4; m1++){
                for(int m2 = 0; m2<4; m2++){
                    if(k>=t[m2][m1]){
                        dp[i][k][m1] = add(dp[i-1][k-t[m2][m1]][m2], dp[i][k][m1]);
                    }
                }
            }
        }
    }
    long long ans = 0;
    for(int m = 0; m<4; m++){
        ans = add(ans, dp[N][K][m]);
    }
    cout << ans << endl;
}