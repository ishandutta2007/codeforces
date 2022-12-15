#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli MOD=998244353;

lli dp[200001][3];
int n;
vector<int> adj[200001];

lli power(lli a,lli p) {
    lli ret=1;
    while(p) {
        if(p&1) ret = ret*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ret;
}
lli inv(lli a){ return power(a,MOD-2);}

void dfs(int cur) {
    if(adj[cur].empty()) {
        dp[cur][2]=1;
        return;
    }

    for(auto &it:adj[cur]) {
        dfs(it);
    }
    dp[cur][0]=1;
    for(auto &it:adj[cur]) {
        dp[cur][0] = dp[cur][0] * ((dp[it][0]+dp[it][2])%MOD) % MOD;
    }
    for(auto &it:adj[cur]) {
        dp[cur][1] = (dp[cur][1] + dp[cur][0]*inv((dp[it][0]+dp[it][2])%MOD)%MOD*(dp[it][1]+dp[it][2])%MOD)%MOD;
    }
    dp[cur][2]=1;
    for(auto &it:adj[cur]) {
        dp[cur][2] = dp[cur][2]*((dp[it][0]+dp[it][1]+2*dp[it][2])%MOD)%MOD;
    }
    dp[cur][2] = (dp[cur][2]-dp[cur][1]+MOD-dp[cur][0]+MOD)%MOD;
 //   printf("%d : %lld %lld %lld\n",cur,dp[cur][0],dp[cur][1],dp[cur][2]);
}
        
int main() {
    scanf("%d",&n);
    for(int i=2,p;i<=n;i++) scanf("%d",&p),adj[p].push_back(i);

    dfs(1);
    printf("%lld\n",(dp[1][0]+dp[1][2])%MOD);
    
    return 0;
}