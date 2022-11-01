#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,a[N];
char s[N];

int main()
{
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++) a[i]=s[i]=='('?1:-1;
	int tot=0,pos=0;
	for (int i=1;i<=n;i++)
	{
		tot+=a[i];
		if (tot<0) {pos=i;break;}
	}
	if (!pos)
	{
		if (!tot) puts("Yes");
		else puts("No");
		return 0;
	}
	else
	{
		for (int i=pos;i<n;i++) a[i]=a[i+1];
		a[n]=-1;
	}
	tot=0;
	for (int i=1;i<=n;i++)
	{
		tot+=a[i];
		if (tot<0) {puts("No");return 0;}
	}
	if (!tot) puts("Yes");
	else puts("No");
	return 0;
}