#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100050
int T,n,ls[3],dp[N];
char s[2][N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ls[0]=ls[1]=0;
		scanf("%d%s%s",&n,s[0]+1,s[1]+1);
		for(int i=1;i<=n;i++)dp[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<2;j++)if(s[0][i]=='0'+j||s[1][i]=='0'+j)ls[j]=i;
			int mn=i;
			for(int j=0;j<2;j++)
			{
				if(mn>ls[j])mn=ls[j];
				if(mn)dp[i]=max(dp[i],dp[mn-1]+j+1);
			}
		}
		printf("%d\n",dp[n]);
	}
}