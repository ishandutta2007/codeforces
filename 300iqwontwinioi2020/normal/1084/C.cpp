#include <bits/stdc++.h>

using namespace std;

int POWER (int x, int y, int z){
    int pas = 1, p = x;
    while (y){
        if ((y & 1))
            pas = pas * p % z;
        y /= 2;
        p = p * p % z;
    }
    return pas;
}

const int N = 300005, MOD = 1e9 + 7;
int n;
string S;
int dp[N];
int x;

int main()
{
    cin>>S;
    n = (int)S.size();
    S = "#" + S;
    for (int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        if (S[i] == 'a')
            dp[i] = (dp[i] + dp[x] + 1) % MOD;
        if (S[i] == 'b')
            x = i;
    }
    cout<<dp[n]<<endl;
    return 0;
}