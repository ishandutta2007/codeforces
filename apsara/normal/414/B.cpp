#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=2100;
const int P=1000000007;
int dp[V][V],n,K;
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        memset(dp,0,sizeof(dp));
        dp[0][1]=1;
        for(int i=0;i<K;i++)
        for(int j=1;j<=n;j++)
        if(dp[i][j]!=0)
        {
            for(int k=j;k<=n;k+=j)
            {
                dp[i+1][k]+=dp[i][j];
                dp[i+1][k]%=P;
            }
        }
        int ret=0;
        for(int i=1;i<=n;i++)ret=(ret+dp[K][i])%P;
        printf("%d\n",ret);
    }
}