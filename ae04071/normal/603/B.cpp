#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli MOD=1e9+7;
lli power(lli a,lli p) {
    lli ret=1;
    while(p) {
        if(p&1) ret= ret*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ret;
}

int vis[1000000],p,k;
void dfs(int val) {
    if(vis[val]) return;
    vis[val]=1;
    dfs(1ll*val*k%p);
}
int main() {
    scanf("%d%d",&p,&k);
    if(k==0) {
        printf("%lld\n",power(p,p-1));
    } else if(k==1) {
        printf("%lld\n",power(p,p));
    } else {
        lli ans=1;
        for(int i=1;i<p;i++) if(!vis[i]) {
            dfs(i); ans = ans*p%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}