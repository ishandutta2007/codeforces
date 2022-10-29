#include <iostream>
#include <string.h>
using namespace std;
int n,m,cnt[1000005],dp[2][8][8][8];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	int ans=0;
	for (int i=1;i<=m;i++)
	{
		if (cnt[i]<=7)
		continue;
		ans+=cnt[i]/3;
		cnt[i]%=3;
		while (cnt[i]<=4)
		{
			cnt[i]+=3;
			ans--;
		}
	}
	dp[0][cnt[1]][cnt[2]][cnt[3]]=ans;
	for (int i=1;i<=m;i++)
	{
		for (int v1=cnt[i];v1>=0;v1--)
		{
			for (int v2=cnt[i+1];v2>=0;v2--)
			{
				for (int v3=cnt[i+2];v3>=0;v3--)
				{
					if (v1 && v2 && v3)
					dp[0][v1-1][v2-1][v3-1]=max(dp[0][v1-1][v2-1][v3-1],dp[0][v1][v2][v3]+1);
					if (v1>=3)
					dp[0][v1-3][v2][v3]=max(dp[0][v1-3][v2][v3],dp[0][v1][v2][v3]+1);
					dp[1][v2][v3][cnt[i+3]]=max(dp[1][v2][v3][cnt[i+3]],dp[0][v1][v2][v3]);
				}
			}
		}
		for (int v1=0;v1<=7;v1++)
		{
			for (int v2=0;v2<=7;v2++)
			{
				for (int v3=0;v3<=7;v3++)
				{
					dp[0][v1][v2][v3]=dp[1][v1][v2][v3];
					dp[1][v1][v2][v3]=0;
					ans=max(ans,dp[0][v1][v2][v3]);
				}
			}
		}
	}
	printf("%d",ans);
}