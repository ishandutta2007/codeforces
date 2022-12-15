#include <bits/stdc++.h>
using namespace std;

int n,dp[501][501],arr[501];
int DP(int l,int r) {
    if(l>=r) return 0;

    int &ret=dp[l][r];
    if(ret!=-1) return ret;

    ret = DP(l+1,r)+1;
    for(int i=l+1;i<=r;i++) if(arr[l]==arr[i]) {
        ret = min(ret, DP(l+1,i-1) + DP(i+1,r) + (i<r));
    }
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    memset(dp,-1,sizeof(dp));
    printf("%d\n",DP(0,n-1)+1);
    
    return 0;
}