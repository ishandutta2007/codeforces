#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,b[N];
struct data{int x,id;}a[N];

bool cmp(data a,data b)
{
	return a.x<b.x;
}

void check(int p)
{
	int m=0;
	for (int i=1;i<=n;i++)
		if (i!=p) b[++m]=a[i].x;
	for (int i=2;i<=m;i++)
		if (b[i]-b[i-1]!=b[2]-b[1]) return;
	printf("%d\n",a[p].id);
	exit(0);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].id=i;
	if (n<=3) {printf("%d\n",1);return 0;}
	std::sort(a+1,a+n+1,cmp);
	int d=a[2].x-a[1].x;
	for (int i=2;i<=n;i++)
		if (a[i].x-a[i-1].x!=d) {check(i);break;}
	check(2);
	check(1);
	printf("%d\n",-1);
	return 0;
}