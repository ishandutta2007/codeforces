#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
string s;
int lst[26];
long long dp[105][105];
long long M = 1000000000000000000LL;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K >> s;
    for(int i = 0; i<=N; i++){
        dp[i][0]= 1;
    }
    for(int i =1; i<=N; i++){
        for(int j = 1; j<=i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            dp[i][j] -= (lst[(int) (s[i-1]-'a')] == 0?0:dp[lst[(int) (s[i-1]-'a')]-1][j-1]);
        }
        lst[s[i-1]-'a'] = i;
    }
    long long n = 0, ans = 0;
    for(int i = N; i>=0; i--){
        if(n - K + dp[N][i]>= 0){
            ans += (K - n)*(1LL*N-i);
            n = K;
            break;
        }
        else{
            ans += (dp[N][i])*(1LL*N-i);
            n += dp[N][i];
        }
    }
    if(n < K){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
}