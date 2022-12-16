#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,m,vis[300100][4];
lli arr[3001000],dp[300100][4];

lli DP(int idx,int f) {
    if(idx==n) return 0;
    else if(vis[idx][f]) return dp[idx][f];
    
    lli &ret=dp[idx][f];
    vis[idx][f]=1;
    if(f==0) ret = max({0ll, DP(idx+1,0), DP(idx+1,1),DP(idx+1,2)});
    else if(f==1) ret = max({0ll, arr[idx], DP(idx+1,1)+arr[idx],DP(idx+1,2)+arr[idx]});
    else if(f==2) ret = max({0ll, arr[idx]*m, DP(idx+1,2)+arr[idx]*m,DP(idx+1,3)+arr[idx]*m});
    else ret = max({0ll, arr[idx], DP(idx+1,3)+arr[idx]});
    return ret;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%lld",arr+i);
    printf("%lld\n",max({0ll,DP(0,0),DP(0,1),DP(0,2)}));
    return 0;
}