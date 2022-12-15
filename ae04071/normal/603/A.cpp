#include <bits/stdc++.h>
using namespace std;

int n,dp[100001][3][2];
char str[100001];

int DP(int idx,int f,int v) {
    int &ret=dp[idx][f][v];
    if(ret!=-1) return ret;

    if(idx==n) return ret=0;

    if( ((f&1) ^ (str[idx]-'0'))==v) {
        ret = DP(idx+1,f,v^1);
        if(f<2) ret = max(ret, DP(idx+1,f+1,v^1));
        ret += 1;
    } else {
        ret = DP(idx+1,f,v);
        if(f<2) ret = max(ret, DP(idx+1,f+1,v));
    }
    return ret;
}
int main() {
    scanf("%d%s",&n,str);
    memset(dp,-1,sizeof(dp));

    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<2;j++)for(int k=0;k<2;k++) 
            ans = max(ans,DP(i,j,k));
    }
    printf("%d\n",ans);
    return 0;
}