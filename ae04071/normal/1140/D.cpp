#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli dp[500][500];
int n;
lli DP(int l,int r) {
    lli &ret=dp[l][r];
    if(ret!=-1) return ret;
    
    if((l+1)%n==r) return ret=0;

    ret = 1000000000000000ll;
    for(int i=(l+1)%n;i!=r;i=(i+1)%n) {
        ret = min(ret, DP(l,i) + DP(i,r) + 1ll*(i+1)*(l+1)*(r+1));
    }
    return ret;
}

int main() {
    scanf("%d",&n);
    
    memset(dp,-1,sizeof(dp));

    lli ans=1000000000000000ll;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
        ans = min(ans, DP(i,j) + DP(j,i));
    }
    printf("%lld\n",ans);
    return 0;
}