#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,m,t[N],a[105];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&t[i]);
	int now=0;
	for (int i=1;i<=n;i++)
	{
		now+=t[i];
		int tmp=now,ans=0,j;
		for (j=100;j>=1&&tmp-j*a[j]>m;ans+=a[j],tmp-=j*a[j],j--);
		ans+=std::max(tmp-m+j-1,0)/j;
		printf("%d ",ans);
		a[t[i]]++;
	}
	return 0;
}