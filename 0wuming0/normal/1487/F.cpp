#include"bits/stdc++.h"
using namespace std;
char s[105];
int dp[301][301][71];
int save[301][301][71];
int temp[301][301];
int main()
{
    cin>>s;
    int n=strlen(s);
    for(int i=0,j=n-1;i<j;i++,j--)swap(s[i],s[j]);
    for(int i=0;i<n;i++)s[i]-='0';
    for(int i=n;i<105;i++)s[i]=0;
    for(int i=0;i<301;i++)for(int j=0;j<301;j++)for(int k=0;k<71;k++)
    {
        if(k==35)dp[i][j][k]=0;
        else dp[i][j][k]=10000000;
    }
    for(int now=0;now<60;now++)
    {
        for(int i=0;i<301;i++)for(int j=0;j<301;j++)for(int k=0;k<71;k++)save[i][j][k]=10000000;
        for(int i=0;i<301;i++)for(int j=0;j<301;j++)for(int k=(1005+j-i-s[now])%10;k<71;k+=10)
        {
            int kk=(k-35+i-j+s[now])/10+35;
            if(kk<0||kk>70)continue;
            save[i][j][kk]=min(save[i][j][kk],dp[i][j][k]+i+j);
        }
        for(int i=0;i<301;i++)for(int j=0;j<301;j++)for(int k=0;k<71;k++)dp[i][j][k]=save[i][j][k];
        for(int i=300;i>=0;i--)for(int j=300;j>=0;j--)
        {
            if(i!=300)for(int k=0;k<71;k++)dp[i][j][k]=min(dp[i][j][k],dp[i+1][j][k]);
            if(j!=300)for(int k=0;k<71;k++)dp[i][j][k]=min(dp[i][j][k],dp[i][j+1][k]);
        }
    }
    cout<<dp[0][0][35]<<endl;
    return 0;
}