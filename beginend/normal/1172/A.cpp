#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,a[N],b[N];

void check(int x)
{
	int mx=0;
	for (int i=1;i<=n-x;i++) if (b[i]) mx=std::max(mx,i-(b[i]-(x+1)));
	if (mx>0) return;
	printf("%d\n",n-x);
	exit(0);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	int x=b[n];bool flag=0;
	for (int i=0;i<x;i++) if (b[n-i]!=x-i) {flag=1;break;}
	if (!flag) check(x);
	int mx=0;
	for (int i=1;i<=n;i++) if (b[i]) mx=std::max(mx,i-(b[i]-1));
	printf("%d\n",mx+n);
	return 0;
}