#include<iostream>
#include<cstring>
using namespace std;
int n, m, i, j, ii, sol, val, x;
int d[2005][2050], dp[2050], c[4005], s[2005], v[2005], b[2050], sc[4005];
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = 1; i <= n; i++){
        cin>> s[i];
    }
    for(i = 1; i <= n + m; i++){
        cin>> c[i];
        sc[i] = sc[i - 1] + c[i];
    }
    for(i = 1; i <= m; i++){
        for(ii = 0; ii < 2048; ii++){
            d[i][ii] = -10000000;
        }
    }
    for(i = 1; i < 2048; i++){
        if(i % 2 == 1){
            b[i] = 0;
        }
        else{
            b[i] = 1 + b[i / 2];
        }
    }
    for(i = n; i >= 1; i--){
        for(j = 0; j < 2048; j++){
            dp[j] = -100000000;
        }
        dp[1] = c[ v[i] ];
        for(j = v[i]; j >= max(1, v[i] - 10); j--){
            for(ii = 1; ii < 2048; ii++){
                x = (ii >> (v[i] - j) ) + 1;
                val = d[j][ii] + c[ v[i] ] + sc[ v[i] + b[x] ] - sc[ v[i] ];
                dp[x] = max(dp[x], val);
            }
        }
        for(j = v[i] - 11; j >= 1; j--){
            dp[1] = max(dp[1], d[j][0] + c[ v[i] ]);
        }
        for(ii = 1; ii < 2048; ii++){
            dp[0] = max(dp[0], dp[ii]);
        }
        for(ii = 0; ii < 2048; ii++){
            dp[ii] -= s[i];
            d[ v[i] ][ii] = max(d[ v[i] ][ii], dp[ii]);
            sol = max(sol, dp[ii]);
        }
    }
    cout<< sol;
}