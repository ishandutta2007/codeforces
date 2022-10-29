#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,p[2005],o[2005];
bool best()
{
	if (count(p+1,p+1+2*n,0)==2*n)
	return 0;
	int b=1;
	for (int i=1;i<=2*n;i++)
	{
		if (p[i]>p[b])
		b=i;
		if (p[i] && o[i] && p[i]>=p[o[i]])
		{
			b=i;
			break;
		}
	}
	p[b]=0;
	printf("%d\n",b);
	fflush(stdout);
	if (count(p+1,p+1+2*n,0)==2*n)
	return 0;
	int ans;
	scanf("%d",&ans);
	p[ans]=0;
	return 1;
}
int main()
{
	int m,t;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=2*n;i++)
	scanf("%d",&p[i]);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		o[a]=b;
		o[b]=a;
	}
	scanf("%d",&t);
	if (t==2)
	{
		int ans;
		scanf("%d",&ans);
		p[ans]=0;
		while (o[ans])
		{
			printf("%d\n",o[ans]);
			fflush(stdout);
			p[o[ans]]=0;
			if (count(p+1,p+1+2*n,0)==2*n)
			return 0;
			scanf("%d",&ans);
			p[ans]=0;
		}
	}
	while (best());
}