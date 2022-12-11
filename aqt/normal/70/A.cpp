#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[1001];
long long p[1001];
long long MOD = 1000003;

int main(){
    cin >> N;
    p[0] = dp[0] = 1;
    for(int i = 1; i<=N; i++){
        p[i] = (p[i-1]*2)%MOD;
        for(int j = 0; j<i; j++){
            dp[i] += (p[j]*dp[i-j-1])%MOD;
        }
    }
    cout << dp[N]%MOD << endl;
}