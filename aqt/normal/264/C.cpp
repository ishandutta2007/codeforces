#include <bits/stdc++.h>

using namespace std;

int N, Q;
int clr[100005];
long long val[100005];
long long dp[100005];

long long solve(long long a, long long b){
    int bstidx = 0, nxtbstidx = 0;
    for(int i = 1; i<=N; i++){
        int n = clr[i];
        long long c = max(dp[n], dp[n] + val[i]*a);
        if(dp[n] == LLONG_MIN+10){
            c = LLONG_MIN+10;
        }
        if(bstidx == n){
            c = max(c, dp[nxtbstidx]+val[i]*b);
        }
        else{
            c = max(c, dp[bstidx]+val[i]*b);
        }
        dp[n] = c;
        if(dp[bstidx] <= dp[n] && n != bstidx){
            nxtbstidx = bstidx;
            bstidx = n;
        }
        else if(dp[nxtbstidx] < dp[n] && n != bstidx){
            nxtbstidx = n;
        }
    }
    long long ret = dp[bstidx];
    fill(dp+1, dp+N+1, LLONG_MIN+10);
    return ret;
}

int main(){
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> val[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> clr[i];
    }
    fill(dp+1, dp+N+1, LLONG_MIN+10);
    while(Q--){
        long long a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}