#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int _2[1010101];
int not_prime[1010101],prime[1010101];
int tot=0;
int cnt[1010101],sum[1010101];
int mmp;
int pp[101];
void dfs(int x,int y)
{
	if(y>mmp)
	{
		cnt[x]++;
		return;
	}
	if(x<pp[y])
	{
		cnt[x]++;
		return;
	}
	dfs(x,y+1);
	while(x%pp[y]==0)
	{
		x/=pp[y];
		dfs(x,y+1);
	}
}
int main()
{
	_2[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		_2[i]=_2[i-1]*2;
		if(_2[i]>=mod)
			_2[i]-=mod;
	}
	for(int i=2;i<=1000;i++)
	{
		if(!not_prime[i])
			prime[++tot]=i;
		for(int j=1;j<=tot;j++)
		{
			if(i*prime[j]>1000)
				break;
			not_prime[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;
		}
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		int xx=x;
		mmp=0;
		for(int j=1;j<=tot;j++)
		if(x%prime[j]==0)
		{
			mmp++;
			pp[mmp]=prime[j];
			while(x%prime[j]==0)
				x/=prime[j];
		}
		if(x>1)
		{
			mmp++;
			pp[mmp]=x;
		}
		dfs(xx,1);
	}
	int ans=0;
	for(int i=1000000;i>=2;i--)
	if(cnt[i]==0)
		sum[i]=0;
	else
	{
		sum[i]=1ll*cnt[i]*_2[cnt[i]-1]%mod;
		for(int j=i+i;j<=1000000;j+=i)
		{
			sum[i]-=sum[j];
			if(sum[i]<0)
				sum[i]+=mod;
		}
		ans+=1ll*sum[i]*i%mod;
		if(ans>=mod)
			ans-=mod;
	}
	printf("%d\n",ans);
	return 0;
}