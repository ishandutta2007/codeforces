#include <bits/stdc++.h>

using namespace std;

int N, K, T;
string s;
bool dp[5005][5005];
char ans[5005];

int main(){
    cin >> s;
    N = s.size();
    K = 31-__builtin_clz(N);
    T = N-(1<<K)+1;
    for(int k = 0; k<1<<K; k++){
        dp[0][k] = 1;
    }
    for(int i = 1; i<=T; i++){
        char b = 'z';
        for(int k = 0; k<1<<K; k++){
            if(dp[i-1][k]){
                b = min(b, s[i+k-1]);
            }
        }
        ans[i] = b;
        for(int k = 0; k<1<<K; k++){
            if(s[i+k-1] == b && dp[i-1][k]){
                dp[i][k] = 1;
            }
            else{
                for(int x = 0; x<K; x++){
                    if(dp[i][k^(1<<x)] && ((k>>x)&1)){
                        dp[i][k] = 1;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 1; i<=T; i++){
        cout << ans[i];
    }
}