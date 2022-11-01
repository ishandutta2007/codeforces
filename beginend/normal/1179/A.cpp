#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n,m,a[N*2],ans[N][2];

int main()
{
	scanf("%d%d",&n,&m);
	int mx=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>=a[mx]) mx=i;
	}
	for (int i=1;i<mx;i++)
	{
		ans[i][0]=a[i];ans[i][1]=a[i+1];
		a[n+i]=std::min(a[i],a[i+1]);
		a[i+1]=std::max(a[i],a[i+1]);
	}
	while (m--)
	{
		LL x;scanf("%lld",&x);
		if (x<mx) printf("%d %d\n",ans[x][0],ans[x][1]);
		else
		{
			x=(x-(mx-1)-1)%(n-1)+1;
			printf("%d %d\n",a[mx],a[mx+x]);
		}
	}
	return 0;
}