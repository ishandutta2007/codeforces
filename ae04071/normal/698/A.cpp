#include <bits/stdc++.h>
using namespace std;

int n,arr[101],dp[101][4];
int DP(int idx,int s) {
    if(idx==n) return 0;

    int &ret=dp[idx][s];
    if(ret!=-1) return ret;
    
    ret = DP(idx+1,0)+1;
    for(int i=0;i<2;i++) if((arr[idx]>>i&1) && !(s>>i&1)) ret = min(ret, DP(idx+1,1<<i));
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",DP(0,0));
    return 0;
}