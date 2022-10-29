#include <iostream>
using namespace std;
int n,k;
string a,b;
long long dp[500005][2][2];
int main()
{
	cin >> n >> k >> a >> b;
	dp[0][1][1]=1;
	for (int i=0;i<n;i++)
	{
		for (int f1=0;f1<=1;f1++)
		{
			for (int f2=0;f2<=1;f2++)
			{
				dp[i][f1][f2]=min(dp[i][f1][f2],1LL*k);
				for (char c='a';c<='b';c++)
				{
					if ((c<a[i] && f1) || (c>b[i] && f2))
					continue;
					dp[i+1][(f1 && c==a[i])][(f2 && c==b[i])]+=dp[i][f1][f2];
				}
			}
		}
	}
	long long ans=0;
	for (int i=1;i<=n;i++)
	ans+=min(dp[i][0][0]+dp[i][0][1]+dp[i][1][0]+dp[i][1][1],1LL*k);
	printf("%I64d",ans);
}