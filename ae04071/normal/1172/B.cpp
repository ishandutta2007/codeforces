#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;
using pdd = pair<double,double>;

const int MOD=998244353;
int n;
vector<int> adj[200001];
lli dp[200001],fact[200001];

void dfs(int cur,int p) {
    dp[cur]=1;
    for(auto &it:adj[cur]) if(it!=p)  {
        dfs(it,cur);
        dp[cur]=dp[cur]*dp[it]%MOD;
    }
    
    int s=sz(adj[cur]);
    dp[cur] = dp[cur] * fact[s-1]%MOD * s%MOD;
}
lli power(lli a, lli p) {
    lli ret=1;
    while(p) {
        if(p&1) ret = ret*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ret;
}
lli inv(lli a) {
    return power(a,MOD-2);
}
lli ans=0;
void get(int cur,int p,lli d) {
    lli v=dp[cur];;
    int s=sz(adj[cur]);
    v = v * inv(fact[s-1])%MOD * inv(s)%MOD;
    v = v*d%MOD;
    
    ans = (ans+v*fact[s]%MOD)%MOD;
    for(auto &it:adj[cur]) if(it!=p) {
        lli lv=v*inv(dp[it])%MOD;
        lv = lv * fact[s-1]%MOD * s%MOD;
        get(it,cur,lv);
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fact[0]=1;
    for(int i=1;i<+n;i++) fact[i]=fact[i-1]*i%MOD;
    
    dfs(1,0);
    get(1,0,1);
    printf("%lld\n",ans);
    
    return 0;
}