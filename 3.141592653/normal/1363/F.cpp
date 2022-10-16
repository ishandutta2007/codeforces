#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
char s1[11111],s2[11111];
int dp[2222][2222];
int cnt1[1111],cnt2[1111],n;
int min(int x,int y){return(x<y)?x:y;}
void exec()
{
	scanf("%d%s%s",&n,s1+1,s2+1);
	register int i,ii;
	for(i=97;i<=122;i++)cnt1[i]=cnt2[i]=0;
	for(i=1;i<=n;i++)cnt1[s1[i]]++,cnt2[s2[i]]++;
	for(i=97;i<=122;i++)if(cnt1[i]^cnt2[i]){puts("-1");return;}
	for(i=0;i<=n;i++,cnt1[s1[i]]--,cnt2[s2[i]]--)
	{
		for(ii=i;ii<=n;ii++,cnt2[s2[ii]]--)
		{
			dp[i][ii]=n;
			if(!(i|ii)){dp[i][ii]=0;continue;}
			if(s1[i]==s2[ii])dp[i][ii]=dp[i-1][ii-1];
			if(i)dp[i][ii]=min(dp[i][ii],dp[i-1][ii]+1);
			if(cnt2[s2[ii]]<cnt1[s2[ii]])
				dp[i][ii]=min(dp[i][ii-1],dp[i][ii]);
		}for(ii=i;ii<=n;ii++,cnt2[s2[ii]]++);
	}printf("%d\n",dp[n][n]);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Please don't let me down.
*/