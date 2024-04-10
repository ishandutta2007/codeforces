#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=100005,M=998244353;
int n,i,t,a[105],k,vis[55],j;
long long m,dp[55],fac[55];
int Find(int x)
{
	return vis[x]?vis[x]=Find(vis[x]):x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin>>t;
	fac[0]=fac[1]=dp[0]=1;
	for(i=2;i<=51;++i)
	{
		fac[i]=fac[i-1]*(i-1);
		if(fac[i]>inf||log(fac[i-1])+log(i-1)>log(2*inf))
			fac[i]=inf+1;
	}
	for(i=1;i<=50;++i)
		for(j=1;j<=i;++j)
			if(log(fac[j-1])+log(dp[i-j])>log(inf*2))
				dp[i]=inf+1;
			else
			{
				dp[i]+=fac[j-1]*dp[i-j];
				if(dp[i]>inf)
					dp[i]=inf+1;
			}
	while(t--)
	{
		cin>>n>>m;
		if(dp[n]<m)
		{
			puts("-1");
			continue;
		}
		int s=1;
		--m;
		k=0;
		while(s<=n)
		{
			for(i=1;i<=n;++i)
				if(log(m*2+7)>log(dp[n+1-s-i])+log(fac[i-1])&&m>=dp[n+1-s-i]*fac[i-1])
					m-=dp[n+1-s-i]*fac[i-1];
				else
					break;
			a[++k]=s+i-1;
			long long t=m/dp[n+1-s-i];
			m%=dp[n+1-s-i];
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			for(j=2;j<=i;++j)
			{
				int o;
				for(o=1;t>=fac[i-j];++o)
					t-=fac[i-j];
				int y;
				for(y=1;y<i;++y)
				{
					if(j==i)
						if(vis[y]==0)
							break;
					o-=(Find(y)!=Find(j)&&vis[y]==0);
					if(!o)
						break;
				}
				vis[y]=j;
				a[++k]=s+y-1;
			}
			s+=i;
		}
		for(i=1;i<=k;++i)
			printf("%d ",a[i]);
		printf("\n");
	}
}