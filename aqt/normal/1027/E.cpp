#include <bits/stdc++.h>

using namespace std;

int N, K;
long long MOD = 998244353;

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long dp1[2][505][505];
long long dp2[505][505];

int main(){
    cin >> N >> K;
    dp1[1][1][1] = 2;
    for(int i = 2; i<=N; i++){
        for(int k = 1; k<=i; k++){
            for(int l = 1; l<=k; l++){
                dp1[i&1][k][l] = 0;
                dp1[i&1][k][l] = add(dp1[i&1^1][k][l-1], dp1[i&1][k][l]);
                if(k == l){
                    dp1[i&1][k][l] = add(dp1[i&1][k][l], dp1[i&1^1][k-1][l-1]);
                }
                dp1[i&1][k][1] = add(dp1[i&1][k][1], dp1[i&1^1][k][l]);
            }
        }
    }
    for(int n = 1; n<=N; n++){
        dp2[n][0] = 1;
        for(int i =1; i<=N; i++){
            for(int j = max(0, i-n); j<i; j++){
                dp2[n][i] = add(dp2[n][i], dp2[n][j]);
            }
        }
    }
    long long ans = 0;
    for(int k = 1; k<=min(N, K); k++){
        long long s = 0;
        for(int i = 1; i<=k; i++){
            s = add(s, dp1[N&1][k][i]);
        }
        //cout << k << " " << s << " " << min(N, (K-1)/k) << " " << dp2[min(N, (K-1)/N)][N] << endl;
        ans = add(ans, mult(dp2[min(N, (K-1)/k)][N], s));
    }
    cout << ans << endl;
}