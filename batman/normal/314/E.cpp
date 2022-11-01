#include <bits/stdc++.h>
using namespace std;
const int N=(100*1000+10);

int n,num,dp[N/2];
char s[N];


int main()
{
    scanf("%d %s",&n,&s);
    if(n%2){printf("0");return 0;}
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
    	int ex=min(n/2,i/2);
    	if(s[i-1]=='?')
		{
			num++;
			if((i&1))for(int j=0;j<=ex;j++)dp[j]+=dp[j+1];
			else for(int j=ex;j>0;j--)dp[j]+=dp[j-1];
		}
		else if(!(i&1))
		{
			for(int j=ex;j>0;j--)dp[j]=dp[j-1];
			dp[0]=0;
		}
	}
	num-=n/2;
	for(int i=0;i<num;i++)dp[0]*=25;
	printf("%u",dp[0]);
	return 0;
}