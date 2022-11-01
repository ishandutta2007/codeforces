#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int inf=1000000000;

int n,t[1005];

int main()
{
	scanf("%d",&n);
	for (int i=0;i<=1000;i++) t[i]=inf;
	for (int i=0;i<=49;i++)
		for (int j=0;j<=49;j++)
		{
			int w=(4*i+9*j)%49;
			t[w]=std::min(t[w],i+j);
		}
	for (int i=1;i<=1000;i++)
	{
		if (t[i]==inf) continue;
		for (int j=i-49;j>=0;j-=49)
			if (t[j]<inf) {t[i]=inf;break;}
	}
	LL ans=0;
	for (int i=0;i<=1000;i++)
	{
		if (t[i]==inf) continue;
		if (t[i]<=n) ans+=n-t[i]+1;
	}
	printf("%lld",ans);
	return 0;
}