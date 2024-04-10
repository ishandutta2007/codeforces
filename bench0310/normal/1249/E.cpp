#include <iostream>

using namespace std;

int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    int a[n],b[n];
    for(int i=1;i<n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++) scanf("%d",&b[i]);
    int dp[n][3];
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(int i=1;i<n;i++)
    {
        dp[i][0]=a[i]+min(dp[i-1][0],dp[i-1][2]);
        dp[i][1]=b[i]+min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
        dp[i][2]=c+b[i]+min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
    }
    for(int i=0;i<n;i++) printf("%d%c",min(dp[i][0],dp[i][2])," \n"[i==n-1]);
    return 0;
}