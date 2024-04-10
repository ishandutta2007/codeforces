#include <bits/stdc++.h>
using namespace std;

int dp[51][51][51][51],n,arr[51][51];
char str[51];
int sum(int r1,int c1,int r2,int c2) {
    return arr[r2][c2] - arr[r2][c1-1] - arr[r1-1][c2] + arr[r1-1][c1-1];
}

int DP(int r1,int c1,int r2,int c2) {
    if(r1>r2 || c1>c2) return 0;

    int &ret=dp[r1][c1][r2][c2];
    if(ret!=-1) return ret;
    
    if(!sum(r1,c1,r2,c2)) return ret=0;

    ret = max(r2-r1+1, c2-c1+1);
    for(int i=r1;i<=r2;i++) if(sum(i,c1,i,c2)==0) {
        ret = min(ret, DP(r1,c1,i-1,c2) + DP(i+1,c1,r2,c2));
    }
    for(int i=c1;i<=c2;i++) if(sum(r1,i,r2,i)==0) {
        ret = min(ret, DP(r1,c1,r2,i-1) + DP(r1,i+1,r2,c2));
    }
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%s",str+1);
        for(int j=1;j<=n;j++) arr[i][j] = str[j]=='#';
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];

    memset(dp,-1,sizeof(dp));
    printf("%d\n",DP(1,1,n,n));
    
    return 0;
}