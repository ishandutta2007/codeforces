#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
bool ok[705][705],dp[705][705][2];
int arr[705];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
	    ok[0][i]=1;
	    ok[i][0]=1;
	    ok[n+1][i]=1;
	    ok[i][n+1]=1;
		scanf("%d",&arr[i]);
		for (int x=1;x<i;x++)
		{
			if (__gcd(arr[i],arr[x])>1)
			{
				ok[i][x]=1;
				ok[x][i]=1;
			}
		}
	}
	for (int i=1;i<=n+1;i++)
	{
	    dp[i][i-1][0]=1;
	    dp[i][i-1][1]=1;
	}
	for (int len=0;len<n;len++)
	{
	    for (int l=1;l<=n-len;l++)
	    {
	        int r=l+len;
	        for (int m=l;m<=r;m++)
	        {
	            if (ok[m][r+1])
	            dp[l][r][0]|=(dp[l][m-1][0]&dp[m+1][r][1]);
	            if (ok[m][l-1])
	            dp[l][r][1]|=(dp[l][m-1][0]&dp[m+1][r][1]);
	        }
	    }
	}
	printf(dp[1][n][0]? "Yes":"No");
}