// Time: 2021-7-14 22:57 
#include<bits/stdc++.h>
int n,k;
int dp[1<<17];
int nxt[200002][18];
int cnt[127];
char str[200002];
std::vector<int>v[200002];
bool check(int Md)
{
	memset(dp,0x3f,sizeof dp);
	memset(nxt,0x3f,sizeof nxt);
	memset(cnt,0,sizeof cnt);
	register int i=n;
	for(;i>n-Md;i--)cnt[str[i]]++;
	for(;~i;i--)
	{
		for(register int ii=97;ii<97+k;ii++)
		{
			if(cnt['?']+cnt[ii]==Md)nxt[i][ii-97]=i+Md;
			else nxt[i][ii-97]=nxt[i+1][ii-97];
			//printf("%d %d %d\n",i,ii,nxt[i][ii-97]);
		}
		cnt[str[i]]++,cnt[str[i+Md]]--;
	}
	for(i=0;i<=n;i++)v[i].clear();
	dp[0]=0,v[0].push_back(0);
	for(i=0;i<=n;i++)
		for(int S:v[i])
		{
			//printf("%d %d %d\n",S,dp[S],i);
			if(dp[S]!=i)continue;
			if(S==(1<<k)-1)return 1;
			for(register int ii=0;ii<k;ii++)
				if((S&(1<<ii))==0)
				{
					int T=S|(1<<ii);
					//printf("? %d\n",nxt[i][ii]);
					if(nxt[i][ii]<dp[T])
						dp[T]=nxt[i][ii],
						v[dp[T]].push_back(T);
				}
		}
	return 0;
}
int main()
{
	scanf("%d%d%s",&n,&k,str+1);
	int L=0,R=n/k+1;
	while(L+1<R)
	{
		int M=(L+R)>>1;
		if(check(M))L=M;
		else R=M;
	}
	printf("%d\n",L);
}