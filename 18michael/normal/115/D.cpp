#include<bits/stdc++.h>
#define mod 1000003
using namespace std;
int n,st_t=0;
int st[2002];
int dp[2002][2002];
char s[2002];
inline void upd(int &x,int y)
{
	if((x+=y)>=mod)x-=mod;
}
int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;++i)
		if(s[i]<'0' || s[i]>'9')
		{
			if(s[i]=='+' || s[i]=='-')st[++st_t]=(s[i-1]>='0' && s[i-1]<='9');
			else
			{
				if(s[i-1]<'0' || s[i-1]>'9')return 0&puts("0");
				st[++st_t]=1;
			}
		}
	if(s[n]<'0' || s[n]>'9')return 0&puts("0");
	dp[0][0]=1;
	for(int i=0;i<=st_t;++i)
		for(int j=0;j<=st_t;++j)
		{
			upd(dp[i][j+1],dp[i][j]);
			if(j>=st[i+1])upd(dp[i+1][j-st[i+1]],dp[i][j]);
		}
	return 0&printf("%d",dp[st_t][0]);
}