#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[200005];
long long dp[200005][3];
long long MOD = 998244353 ;

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long add(long long a, long long b, long long c = 0){
    return (a+b+c)%MOD;
}

long long sub(long long a, long long b){
    return (a-b+MOD)%MOD;
}

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long res = qikpow(b, e/2);
    res = mult(res, res);
    if(e&1){
        res = mult(res, b);
    }
    return res;
}

long long divd(long long a, long long b){
    assert(b);
    return mult(a, qikpow(b, MOD-2));
}

void dfs(int n){
    if(!graph[n].size()){
        dp[n][2] = 1;
        return;
    }
    dp[n][0] = 1;
    for(int e : graph[n]){
        dfs(e);
        dp[n][0] = mult(dp[n][0], add(dp[e][0], dp[e][2]));
    }
    long long tot = dp[n][0];
    for(int e : graph[n]){
        dp[n][1] = add(dp[n][1], mult(divd(tot, add(dp[e][0], dp[e][2])), add(dp[e][1], dp[e][2])));
    }
    dp[n][2] = 1;
    for(int e : graph[n]){
        dp[n][2] = mult(add(dp[e][0], dp[e][1], 2*dp[e][2]), dp[n][2]);
    }
    dp[n][2] = sub(dp[n][2], add(dp[n][0], dp[n][1]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 2; i<=N; i++){
        int p;
        cin >> p;
        graph[p].push_back(i);
    }
    dfs(1);
    cout << add(dp[1][0], dp[1][2]) << endl;
}