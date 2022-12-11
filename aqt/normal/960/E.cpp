#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[200005];
pair<int, int> dp[200005];
pair<int, int> tot;
long long val[200005];
long long MOD = 1e9+7;
int clr[200005];
int par[200005];

long long mult(long long a, long long b){
    return a*b%MOD;
}

long long add(long long a, long long b){
    return (a+b)%MOD;
}

void dfs(int n){
    if(clr[n]){
        dp[n].second++;
        tot.second++;
    }
    else{
        dp[n].first++;
        tot.first++;
    }
    for(int e : graph[n]){
        if(e != par[n]){
            par[e] = n;
            clr[e] = clr[n]^1;
            dfs(e);
            dp[n].first += dp[e].first;
            dp[n].second += dp[e].second;
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        cin >> val[i];
        ans = add(ans, mult(val[i], N));
    }
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for(int n = 1; n<=N; n++){
        for(int e : graph[n]){
            if(e == par[n]){
                continue;
            }
            if(clr[n]){
                ans = add(ans, mult(val[n], mult(dp[e].second, N-(dp[e].first+dp[e].second))));
                ans = add(ans, mult(-val[n], mult(dp[e].first, N-(dp[e].first+dp[e].second))));
            }
            else{
                ans = add(ans, mult(-val[n], mult(dp[e].second, N-(dp[e].first+dp[e].second))));
                ans = add(ans, mult(val[n], mult(dp[e].first, N-(dp[e].first+dp[e].second))));
            }
        }
        if(clr[n]){
            ans = add(ans, mult(val[n],
                            mult(tot.second-dp[n].second, dp[n].first + dp[n].second)));
            ans = add(ans, mult(-val[n],
                            mult(tot.first-dp[n].first, dp[n].first + dp[n].second)));
        }
        else{
            ans = add(ans, mult(-val[n],
                            mult(tot.second-dp[n].second, dp[n].first + dp[n].second)));
            ans = add(ans, mult(val[n],
                            mult(tot.first-dp[n].first, dp[n].first + dp[n].second)));
        }
    }
    while(ans < 0){
        ans += MOD;
    }
    cout << ans << endl;
}