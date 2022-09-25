#include<cstdio>
using namespace std;
int mp[1001][1001],f[1001][1001],m,n,k,cnt[11],mod=1e9+7;
int as(int a)
{
	int ans=0;
	while(a)
	{
		ans+=a&1;
		a>>=1;
	}
	return ans;
}
int dfs(int x,int y)
{
	int fg=-100,ans=0;
	if(y>n)
	x++,y=1;
	if(x>m)
	return 1;
	int st=f[x][y-1]|f[x-1][y];
	if(m+n-x-y+1>k-as(st))
	return 0;
	for(int i=1;i<=k;i++)
	if((!(st>>(i-1)&1))&&(mp[x][y]==0||mp[x][y]==i))
	{
		if(!mp[x][y])
		cnt[i]++;
		f[x][y]=st|(1<<(i-1));
		if(cnt[i]==1)
		{
			if(fg==-100)
			fg=dfs(x,y+1);
			ans=(fg+ans)%mod;
		}
		else
		ans=(ans+dfs(x,y+1))%mod;
		if(!mp[x][y])
		cnt[i]--;
	}
	return ans;
}
int main()
{
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&mp[i][j]),cnt[mp[i][j]]++;
	printf("%d",dfs(1,1));
}