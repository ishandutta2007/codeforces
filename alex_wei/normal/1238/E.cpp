#include<bits/stdc++.h>
#define ll long long
using namespace std;
int N,M,id[21],cnt;
ll G[21][21];
char s[100005];
ll dp[1049000];

int main()
{
	scanf("%d%d",&N,&M);
	scanf("%s",s);
	memset(id,-1,sizeof(id));
	for(int i=0;i<N;i++){
		if(id[s[i]-'a']==-1)id[s[i]-'a']=cnt++;
		if(i) G[id[s[i-1]-'a']][id[s[i]-'a']]++;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int s=0;s<(1<<M);s++)
	{
		ll K=dp[s];
		for(int i=0;i<M;i++)
			if((s>>i)&1)
				for(int j=0;j<M;j++)
					if(!((s>>j)&1))
						K+=G[i][j]+G[j][i]; 
		for(int i=0;i<M;i++)
			if(!((s>>i)&1))
				dp[s|(1<<i)]=min(dp[s|(1<<i)],K);
	}
	cout<<dp[(1<<M)-1];
}