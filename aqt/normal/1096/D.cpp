#include <bits/stdc++.h>

using namespace std;

int N;
string s;
string t = "hard";
long long arr[200000];
long long dp[200000][5];

int main(){
    cin >> N;
    getline(cin, s);
    getline(cin, s);
    for(int i=  1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=N; i++){
        dp[i][0] = dp[i-1][0];
        if(s[i-1] == t[0]){
            dp[i][0] += arr[i];
        }
        for(int j = 1; j<4; j++){
            if(s[i-1] == t[j]){
                dp[i][j] = min(dp[i-1][j] + arr[i], dp[i-1][j-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << min(dp[N][0], min(dp[N][1], min(dp[N][2], dp[N][3]))) << endl;
}