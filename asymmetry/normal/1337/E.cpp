#include <bits/stdc++.h>

using namespace std;

int ns, nt;
long long dp[3001][3001], mod=998244353, odp;
char s[3001];
char t[3001];

int main()
{
	scanf("%s", s+1);
	scanf("%s", t+1);
	ns=strlen(s+1);
	nt=strlen(t+1);
	for(int i=1; i<=ns; ++i)
	{
		if(i<=nt)
		{
			if(s[1]==t[i])
			{
				dp[i][i]=2;
			}
		}
		else
		{
			dp[i][i]=2;
		}
	}
	for(int i=1; i<ns; ++i)
	{
		for(int j=1; j<=ns-i+1; ++j)
		{
			int a=j+i-1;
			if(j-1>0)
			{
				if(j-1<=nt)
				{
					if(s[i+1]==t[j-1])
					{
						dp[j-1][a]+=dp[j][a];
						dp[j-1][a]%=mod;
					}
				}
				else
				{
					dp[j-1][a]+=dp[j][a];
					dp[j-1][a]%=mod;
				}
			}
			if(a+1<=ns)
			{
				if(a+1<=nt)
				{
					if(s[i+1]==t[a+1])
					{
						dp[j][a+1]+=dp[j][a];
						dp[j][a+1]%=mod;
					}
				}
				else
				{
					dp[j][a+1]+=dp[j][a];
					dp[j][a+1]%=mod;
				}
			}
		}
	}
	for(int i=nt; i<=ns; ++i)
	{
		odp+=dp[1][i];
		odp%=mod;
	}
	printf("%lld\n", odp);
	return 0;
}