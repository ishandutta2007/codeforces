#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n;
struct pii
{
	int M,L;
}p[11111];
bool operator<(cpnst pii x,cpnst pii y)
{return x.M<y.M;}
#include<algorithm>
int stk[11111],top;
#include<map>
std::map<int,int>mp;
int dp[111][444];
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
int main()
{
	scanf("%d",&n);
	register int i,ii,iii;
	for(i=1;i<=n;i++)
		scanf("%d%d",&p[i].M,&p[i].L);
	std::sort(p+1,p+n+1);
	for(i=1;i<=n;i++)
		stk[++top]=p[i].M,stk[++top]=p[i].M-p[i].L,stk[++top]=p[i].M+p[i].L;
	stk[0]=-2e8;
	std::sort(stk+1,stk+top+1);
	for(i=1;i<=top;i++)mp[stk[i]]=i;
	for(i=1;i<=n;i++)
	{
		int P=mp[p[i].M-p[i].L],L=mp[p[i].M],R=mp[p[i].M+p[i].L];
		int Rm=p[i].M;
		for(ii=i-1;ii;ii--)
		{
			if(Rm<p[ii].M+p[ii].L)Rm=p[ii].M+p[ii].L;
			int pp=mp[Rm],ls=mp[p[i].M-p[i].L];
			if(dp[i][pp]<dp[ii-1][ls]+Rm-p[i].M+p[i].L)
				dp[i][pp]=dp[ii-1][ls]+Rm-p[i].M+p[i].L;
		}
		for(ii=P;ii<=L;ii++)
			for(iii=P;iii<=L;iii++)
				if(dp[i][ii]<dp[i-1][iii]+stk[ii]-stk[iii])dp[i][ii]=dp[i-1][iii]+stk[ii]-stk[iii];
		for(ii=L;ii<=R;ii++)
			for(iii=L;iii<=R;iii++)
				if(dp[i][ii]<dp[i-1][iii]+stk[ii]-stk[iii])dp[i][ii]=dp[i-1][iii]+stk[ii]-stk[iii];
		for(ii=0;ii<=top;ii++)if(dp[i][ii]<dp[i-1][ii])dp[i][ii]=dp[i-1][ii];
		for(ii=1;ii<=top;ii++)if(dp[i][ii]<dp[i][ii-1])dp[i][ii]=dp[i][ii-1];
	}int ans=0;
	for(i=1;i<=n;i++)
		for(ii=1;ii<=top;ii++)
			ans=max(ans,dp[i][ii]);
	printf("%d\n",ans);
}
/*
Just go for it.
*/