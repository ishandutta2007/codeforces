#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int dp[505][505];

int solve(int l, int r){
    if(l > r){
        return 0;
    }
    if(dp[l][r]+1){
        return dp[l][r];
    }
    dp[l][r] = solve(l+1, r) + 1;
    for(int i = l+1; i<=r; i++){
        if(s[i-1] == s[l-1]){
            dp[l][r] = min(dp[l][r], solve(l+1, i-1) + solve(i, r));
        }
    }
    return dp[l][r];
}

int main(){
    cin >> N >> s;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            dp[i][j] = -1;
        }
    }
    cout << solve(1, N) << endl;
}