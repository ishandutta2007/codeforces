#include<bits/stdc++.h>
using std::min;
using std::max;

int n,a[1<<20],b[1<<20];
int c[1<<20],d[1<<20];
void exec()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	int sa=0,sb=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i])c[++sa]=b[i];
		else d[++sb]=b[i];
	}
	std::sort(c+1,c+sa+1,std::greater<int>());
	std::sort(d+1,d+sb+1,std::greater<int>());
	long long sum=0; 
	for(int i=1;i<=sa;i++)
	{
		if(i<=sb)sum+=c[i]*2;
		else sum+=c[i];
	}
	for(int i=1;i<=sb;i++)
	{
		if(i<=sa)sum+=d[i]*2;
		else sum+=d[i];
	}
	if(sa==sb)sum-=min(c[sa],d[sb]);
	printf("%lld\n",sum);
}

int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}