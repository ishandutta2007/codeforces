#include <iostream>
using namespace std;

int dp[120][10100];

void solve(){
    int n;
    scanf("%d", &n);
    int minf = -1e9;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 10000; j++){
            dp[i][j] = minf;
        }
    }
    dp[0][0] = 0;
    int total = 0;
    int b, a;
    for(int t = 0; t < n; t++){
        scanf("%d %d", &b, &a);
        total += a;
        for(int i = n; i > 0; i--){
            for(int j = a; j <= 10000; j++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a] + b);
            }
        }
    }
    float sub;
    for(int i = 1; i <= n; i++){
        float tmp = 0.0;
        for(int a = 0; a <= 10000; a++){
            sub = (float)a + (float)(total - a) / 2;
            tmp = max(tmp, min(sub, (float)dp[i][a]));
        }
        printf("%f ", tmp);
    }
}

int main(void){
        solve();
}