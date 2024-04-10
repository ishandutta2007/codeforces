#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <set>
using namespace std;
int arr[105],dp[105][10005],ncr[105][105],cnt[105],Mod[]={982451579,982451581,982451609,982451629,982451653};
int main()
{
	srand(time(0));
	int mod=Mod[rand()%5];
	ncr[0][0]=1;
	for (int i=1;i<=100;i++)
	{
		ncr[i][0]=1;
		for (int j=1;j<=i;j++)
		ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
	}
	set<int> s;
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		s.insert(arr[i]);
		cnt[arr[i]]++;
	}
	if (s.size()<3)
	{
		printf("%d",n);
		return 0;
	}
	dp[0][0]=1;
	for (int i=0;i<n;i++)
	{
		for (int j=n;j>0;j--)
		{
			for (int m=10000;m>=arr[i];m--)
			dp[j][m]=(dp[j][m]+dp[j-1][m-arr[i]])%mod;
		}
	}
	int ans=0;
	for (int i=1;i<=100;i++)
	{
		for (int j=1;j<=cnt[i];j++)
		{
			if (dp[j][i*j]==ncr[cnt[i]][j])
			ans=max(ans,j);
		}
	}
	printf("%d",ans);
}