#include <bits/stdc++.h>

using namespace std;

int N, M;
int fre[1000005];
int dp[1000005][5][3];

int main(){
    cin >> N >> M;
    for(int i =1 ; i<=N; i++){
        int n;
        cin >> n;
        fre[n]++;
    }
    int ans = 0;
    for(int i = 3; i<=M+3; i++){
        for(int b = 0; b<=min(2, fre[i]); b++){
            for(int a = b; a<=min(b+2, fre[i-1]); a++){
                for(int j = a-b; j<=min(4, fre[i-2]-b); j++){
                    if(fre[i-2]-j-b < 0){
                        continue;
                    }
                    dp[i][a][b] = max(dp[i][a][b], dp[i-1][j][a-b] + b + (fre[i-2]-j-b)/3);
                }
                ans = max(dp[i][a][b], ans);
            }
        }
    }
    cout << ans << endl;
}