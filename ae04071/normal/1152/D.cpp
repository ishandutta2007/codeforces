#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
int dp[2001][1001],n;

int DP(int idx,int cnt) {
    if(idx==2*n) return cnt==0;
    
    int &ret=dp[idx][cnt];
    if(ret!=-1) return ret;

    ret=0;
    if(cnt+1<=n) ret |= DP(idx+1,cnt+1);
    if(cnt-1>=0) ret |= DP(idx+1,cnt-1);
    return ret;
}
int dp2[2001][1001][2];
int get(int idx,int cnt,int f) {
    if(idx==2*n) return 0;
    
    int &ret=dp2[idx][cnt][f];
    if(ret!=-1) return ret;

    ret=0;
    int f1=(cnt+1<=n && DP(idx+1,cnt+1)),f2=(cnt-1>=0 && DP(idx+1,cnt-1));
    if(f1) {
        if(!f) ret = (ret+get(idx+1,cnt+1,1)+1)%MOD,f=1;
        else ret= (ret+get(idx+1,cnt+1,0))%MOD;
    }
    if(f2) {
        if(!f) ret = (ret+get(idx+1,cnt-1,1)+1)%MOD,f=1;
        else ret = (ret+get(idx+1,cnt-1,0))%MOD;
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    memset(dp2,-1,sizeof(dp2));

    DP(0,0);
    printf("%d\n",get(0,0,0));
    return 0;
}