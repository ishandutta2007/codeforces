#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    vector<vector<int>> dp(n,vector<int>(5,-1));
    for(int i=0;i<5;i++) dp[0][i]=0;
    for(int o=0;o<n-1;o++)
    {
        for(int i=0;i<5;i++)
        {
            if(dp[o][i]==-1) continue;
            if(a[o]<a[o+1]) for(int j=i+1;j<5;j++) dp[o+1][j]=i;
            else if(a[o]>a[o+1]) for(int j=i-1;j>=0;j--) dp[o+1][j]=i;
            else for(int j=0;j<5;j++) if(j!=i) dp[o+1][j]=i;
        }
    }
    int t=-1;
    for(int i=0;i<5;i++) if(dp[n-1][i]>=0) t=i;
    if(t!=-1)
    {
        vector<int> b(n);
        b[n-1]=t;
        for(int i=n-1;i>=1;i--) b[i-1]=(t=dp[i][t]);
        for(int i=0;i<n;i++) printf("%d%c",b[i]+1," \n"[i==n-1]);
    }
    else printf("-1\n");
    return 0;
}