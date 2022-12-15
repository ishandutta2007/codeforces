#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int MOD=1e9+7;
int n,k,arr[201];
int dp[2][101][1001];

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);
    sort(arr+1,arr+n+1);
    arr[0]=arr[1];

    dp[0][0][0]=1;

    int cur=1,pr=0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n/2;j++)for(int s=0;s<=k;s++) dp[cur][j][s]=0;
        for(int j=0;j<=n/2;j++)for(int s=0;s<=k;s++) if(dp[pr][j][s]) {
            if((arr[i]-arr[i-1])*j+s>k) continue;
            int ns=(arr[i]-arr[i-1])*j+s;
            
            if(n-i>=j) dp[cur][j][ns] = (dp[cur][j][ns] + dp[pr][j][s])%MOD;
            if(j && n-i>=j) dp[cur][j][ns] = (dp[cur][j][ns] + 1ll*dp[pr][j][s]*j%MOD)%MOD;
            if(n-i>=j+1) dp[cur][j+1][ns] = (dp[cur][j+1][ns] + dp[pr][j][s])%MOD;
            if(j) dp[cur][j-1][ns] = (dp[cur][j-1][ns] + 1ll*dp[pr][j][s]*j%MOD)%MOD;
        }
        swap(cur,pr);
    }

    int ans=0;
    for(int i=0;i<=k;i++) ans = (ans+dp[pr][0][i])%MOD;
    printf("%d\n",ans);
    
    return 0;
}