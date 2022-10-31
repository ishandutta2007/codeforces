#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,i,j,m,T,ans,p,k;
int a[N],ch[N*31][2],dp[N*31];
void dfs(int i)
{
	if(i==0)
		return;
	if(!ch[i][0]&&!ch[i][1])
	{
		dp[i]=1;
		return;
	}
	dfs(ch[i][0]);
	dfs(ch[i][1]);
	dp[i]=max(min(dp[ch[i][0]],1)+dp[ch[i][1]],min(dp[ch[i][1]],1)+dp[ch[i][0]]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	k=1;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		p=1;
		for(j=30;j>=0;--j)
		{
			if(!ch[p][a[i]>>j&1])
				ch[p][a[i]>>j&1]=++k;
			p=ch[p][a[i]>>j&1];
		}
	}
	dfs(1);
	cout<<n-dp[1];
}