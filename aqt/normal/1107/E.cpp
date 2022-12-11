#include <bits/stdc++.h>

using namespace std;

long long dp[105][105][105];
int N;
string s;
long long arr[105];

long long rec(int p, int l, int r){
    if(r < l){
        return 0;
    }
    if(dp[p][l][r] != -1){
        return dp[p][l][r];
    }
    dp[p][l][r] = rec(1, l+1, r) + arr[p];
    for(int i = l+1; i<=r; i++){
        if(s[l] == s[i]){
            dp[p][l][r] = max(dp[p][l][r], rec(1, l+1, i-1) + rec(p+1, i, r));
        }
    }
    return dp[p][l][r];
}

int main(){
    cin >> N >> s;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=N; j++){
            for(int k = 0; k<=N; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    cout << rec(1, 0, N-1);
}