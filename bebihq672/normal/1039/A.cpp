#include<bits/stdc++.h>
using namespace std;
long long a[202020],b[202020],x[202020];
long long d[202020],gg[202020];
int main()
{
	int n;
	long long t;
	scanf("%d%I64d",&n,&t);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&x[i]);
	for(int i=1;i<n;i++)
	if(x[i]>x[i+1])
	{
		puts("No");
		return 0;
	}
	for(int i=1;i<=n;i++)
	if(x[i]<i)
	{
		puts("No");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		d[i]++;
		d[x[i]]--;
	}
	for(int i=2;i<=n;i++)
		d[i]+=d[i-1];
	for(int i=1;i<=n;i++)
	{
		if(d[i]>0)
			b[i]=a[i+1]+t;
		else
			b[i]=a[i]+t;
		if(i>1)
		{
			if(b[i]<=b[i-1])
				b[i]=b[i-1]+1;
		}
	}
	for(int i=1;i<n;i++)
	if(b[i]>=a[i+1]+t)
		gg[i]=1;
	for(int i=2;i<=n;i++)
		gg[i]+=gg[i-1];
	for(int i=1;i<=n;i++)
	if(gg[x[i]]-gg[i-1]==x[i]-i+1)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=n;i++)
		printf("%I64d ",b[i]);
	return 0;
}