#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[100005];
long long dp[100005][2];
bool clr[100005];
long long MOD = 1e9+7;

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long qikpow(long long b, long long e){
    if(!e){
        return 1;
    }
    long long ret = qikpow(b, e/2);
    ret = mult(ret, ret);
    if(e&1){
        ret = mult(ret, b);
    }
    return ret;
}

long long divd(long long a, long long b){
    return mult(a, qikpow(b, MOD-2));
}

void dfs(int n){
    for(int e : graph[n]){
        dfs(e);
    }
    if(clr[n]){
        dp[n][1] = 1;
        for(int e : graph[n]){
            dp[n][1] = mult(dp[n][1], add(dp[e][0], dp[e][1]));
        }
    }
    else{
        dp[n][0] = 1;
        long long tot = 1;
        for(int e : graph[n]){
            tot = mult(tot, add(dp[e][0], dp[e][1]));
        }
        for(int e : graph[n]){
            dp[n][1] = add(dp[n][1], mult(divd(tot, add(dp[e][0], dp[e][1])), dp[e][1]));
        }
        dp[n][0] = tot;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 2; i<=N; i++){
        int p;
        cin >> p;
        p++;
        graph[p].push_back(i);
    }
    for(int i = 1; i<=N; i++){
        cin >> clr[i];
    }
    dfs(1);
    cout << dp[1][1] << endl;
}