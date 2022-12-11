#include <bits/stdc++.h>

using namespace std;

int N, K;
string s;
long long dp[200005];
vector<pair<int, int>> pos[200005];
long long BIT[200005];

void upd(int n, long long v){
    n = N-n+2;
    for(int i = n; i<=N+1; i+=i&-i){
        BIT[i] = min(BIT[i], v);
    }
}

long long query(int n){
    n = N-n+2;
    long long ret = LLONG_MAX;
    for(int i = n; i; i-=i&-i){
        ret = min(BIT[i], ret);
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    cin >> s;
    for(int i = 1; i<=N; i++){
        if(s[i-1] == '1'){
            pos[min(N, i+K)].push_back({max(i-K, 1), i});
        }
        BIT[i] = LLONG_MAX;
    }
    BIT[N+1] = LLONG_MAX;
    for(int i = 1; i<=N; i++){
        dp[i] = dp[i-1] + i;
        for(auto p : pos[i]){
            dp[i] = min(dp[i], query(p.first-1) + p.second);
        }
        upd(i, dp[i]);
    }
    cout << dp[N] << endl;
}