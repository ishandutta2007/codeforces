#include <bits/stdc++.h>
using namespace std;

int dp[501][10][2],arr[500][500],pr[501][10][2];
int n,m;

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    
    for(int j=0;j<10;j++) dp[n][j][0]=1;
    
    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<m;j++)for(int k=0;k<10;k++) {
            int v=arr[i][j]>>k&1;
            for(int t=0;t<2;t++) if(!dp[i][k][t] && dp[i+1][k][t^v]) {
                dp[i][k][t]=1;
                pr[i][k][t]=j;
            }
        }
    }
    
    for(int j=0;j<10;j++) if(dp[0][j][1]) {
        puts("TAK");
        int i=0,idx=pr[0][j][1],v=1;
        for(;i<n;) {
            printf("%d ",idx+1);
            v^=arr[i][idx]>>j&1;
            i++; idx=pr[i][j][v];
        }
        return 0;
    }
    puts("NIE");

    return 0;
}