#include <bits/stdc++.h>

using namespace std;

int N;
int dp[200005][3];
int who[200005];
int n[3];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n[0] >> n[1] >> n[2];
    for(int k = 0; k<3; k++){
        N += n[k];
        while(n[k]--){
            int a;
            cin >> a;
            who[a] = k;
        }
    }
    for(int i= 1; i<=N; i++){
        for(int k = 0; k<3; k++){
            dp[i][k] = dp[i-1][k] + (who[i] != k);
            if(k){
                dp[i][k] = min(dp[i][k], dp[i][k-1]);
            }
        }
    }
    cout << dp[N][2] << endl;
}