#include <bits/stdc++.h>

using namespace std;

int N;
int cst[5];
int mp[1005];
int dp[1005][1<<16];
int msk[5] = {0, 1, 51, 1911, 65535};

int main(){
    cin >> N;
    for(int i = 1; i<=4; i++){
        cin >> cst[i];
    }
    for(int i = 0; i<4; i++){
        string s;
        cin >> s;
        for(int j = 1; j<=N; j++){
            if(s[j-1] == '*'){
                mp[j] |= 1<<i;
            }
        }
    }
    for(int i = 0; i<=N+3; i++){
        for(int m = 0; m<1<<16; m++){
            dp[i][m] = INT_MAX;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i<=N+3; i++){
        for(int m = (1<<16)-1; m>=0; m--){
            if(dp[i][m] == INT_MAX){
                continue;
            }
            //cout << i << " " << m << " " << dp[i][m] << endl;
            if(!(m&15)){
                dp[i+1][(m>>4)|(mp[i+1]<<12)] = min(dp[i+1][(m>>4)|(mp[i+1]<<12)], dp[i][m]);
                continue;
            }
            for(int j= 0; j<4; j++){
                for(int k = 1; k<=4-j; k++){
                    dp[i][((msk[k]<<j)^m)&m] = min(dp[i][((msk[k]<<j)^m)&m],
                                                dp[i][m] + cst[k]);
                }
            }
        }
    }
    cout << dp[N+3][0] << endl;
}