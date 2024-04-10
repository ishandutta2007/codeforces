#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=105;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int s1=a[1],s2=a[1],tot=0;
	for (int i=2;i<=n;i++)
	{
		s1+=a[i];
		if (a[i]*2<=a[1]) s2+=a[i],tot++;
	}
	if (s2*2<=s1) puts("0");
	else
	{
		printf("%d\n",tot+1);
		printf("%d ",1);
		for (int i=2;i<=n;i++) if (a[i]*2<=a[1]) printf("%d ",i);
	}
	return 0;
}