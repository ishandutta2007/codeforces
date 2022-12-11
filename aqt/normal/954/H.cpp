#include <bits/stdc++.h>

using namespace std;

int N;
long long MOD = 1e9+7, inv2 = 500000004;
int dp[5005][10005], tot[10005], amt[20005], ans[20005];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return (a*b)%MOD;
}

long long sub(long long a, long long b){
    a = add(a, -b);
    if(a < 0){
        a += MOD;
    }
    return a;
}

int main(){
    cin >> N;
    tot[1] = amt[1] = 1;
    for(int i = 2; i<=N; i++){
        cin >> amt[i];
        tot[i] = mult(amt[i], tot[i-1]);
    }
    for(int i = N; i; i--){
        dp[i][0] = 1;
        for(int j = N; j>i; j--){
            dp[i][j-i] = mult(amt[i+1], dp[i+1][j-i-1]);
        }
        for(int j = 1; j<=2*N-2; j++){
            ans[j] = add(mult(tot[i], dp[i][j]), ans[j]);
        }
    }
    for(int i = 2; i<=N; i++){
        long long cnt = 1;
        for(int j = 2; j<=2*N; j++){
            dp[i][j] = add(dp[i-1][j-1], dp[i][j]);
            dp[i][j] = sub(dp[i][j], cnt);
            cnt = mult(cnt, amt[i-1+j]);
        }
    }
    for(int d = 1; d<=2*N-2; d++){
        long long out = 0;
        for(int i = 1; i<=N; i++){
            out = add(out, mult(dp[i][d], tot[i]));
        }
        out = sub(out, ans[d]);
        out = mult(out, inv2);
        out = add(ans[d], out);
        cout << out << " ";
    }
}