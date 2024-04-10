#include <bits/stdc++.h>
using namespace std;
const int N=102;

int n;
char a[N][2];

int dp[N][3];

char s[3][N];

int main()
{
    cin>>s[1]>>s[2];
    n=strlen(s[1]);
    for(int i=0;i<n;++i)
        for(int j=1;j<=2;++j)
            a[i][j]=s[j][i];
    a[n][1]='X';
    a[n][2]='X';
    for(int i=0;i<n;++i)
    {
        dp[i][1]=max(dp[i][1],dp[i][0]);
        dp[i][2]=max(dp[i][2],dp[i][0]);
        if(a[i][1]!='X' && a[i][2]!='X' && a[i+1][1]!='X')
            dp[i+1][1]=max(dp[i+1][1],dp[i][0]+1);
        if(a[i][1]!='X' && a[i][2]!='X' && a[i+1][2]!='X')
            dp[i+1][2]=max(dp[i+1][2],dp[i][0]+1);
        ////////////////////////////////////////////////////
        if(a[i][1]!='X' && a[i+1][1]!='X' && a[i+1][2]!='X')
            dp[i+2][0]=max(dp[i+2][0],dp[i][2]+1);
        ////////////////////////////////////////////////////
        if(a[i][2]!='X' && a[i+1][1]!='X' && a[i+1][2]!='X')
            dp[i+2][0]=max(dp[i+2][0],dp[i][1]+1);
        dp[i+1][0]=max(max(dp[i][0],dp[i][1]),max(dp[i+1][0],dp[i][2]));
    }
    int ans=0;
    for(int i=0;i<=n;++i)
        for(int j=0;j<3;++j)
            ans=max(ans,dp[i][j]);
    cout<<ans<<endl;
    return 0;
}
/*
X0X0X
X000X
*/