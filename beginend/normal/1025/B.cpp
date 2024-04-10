#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=150005;

int n,a[N],b[N];

void check(int x)
{
	for (int i=1;i<=n;i++)
		if (a[i]%x!=0&&b[i]%x!=0) return;
	printf("%d\n",x);
	exit(0);
}

void divi(int x)
{
	for (int i=2;i*i<=x;i++)
		if (x%i==0)
		{
			check(i);
			while (x%i==0) x/=i;
		}
	if (x>1) check(x);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	divi(a[1]);divi(b[1]);
	puts("-1");
	return 0;
}