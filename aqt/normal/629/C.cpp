#include <bits/stdc++.h>

using namespace std;

int N, M;
string s;
int dp[2005][2005];
int MOD = 1000000007;
int pre = 0, suf = 0;

int add(int a, int b){
    return (a+b)%MOD;
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int main(){
    cin >> N >> M >> s;
    dp[0][0] = 1;
    for(int i = 1; i<=2000; i++){
        dp[i][0] = dp[i-1][1];
        for(int j = 1; j<=2000; j++){
            dp[i][j] = add(dp[i-1][j-1], dp[i-1][j+1]);
        }
    }
    int cnt = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == ')'){
            cnt++;
            pre = max(cnt, pre);
        }
        else{
            cnt--;
        }
    }
    cnt = 0;
    for(int i = s.size()-1; i>=0; i--){
        if(s[i] == '('){
            cnt++;
            suf = max(cnt, suf);
        }
        else{
            cnt--;
        }
    }
    long long ans = 0;
    for(int i = 0; i<=N-M; i++){
        for(int j = pre; j<=i; j++){
            if(j-pre+suf > N-M-i || j-pre+suf < 0){
                continue;
            }
            ans = add(ans, mul(dp[i][j], dp[N-M-i][j-pre+suf]));
        }
    }
    cout << ans << endl;
}