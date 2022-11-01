#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n,sta[N];
struct data{LL x,y;}a[N];

bool cmp(data a,data b)
{
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		LL x,y;scanf("%lld%lld",&x,&y);
		a[i].x=x;a[i].y=y-x*x;
	}
	std::sort(a+1,a+n+1,cmp);
	int top=0;
	for (int i=1;i<=n;i++)
	{
		while (top&&a[sta[top]].x==a[i].x) top--;
		while (top>1&&(a[i].y-a[sta[top]].y)*(a[sta[top]].x-a[sta[top-1]].x)>=(a[sta[top]].y-a[sta[top-1]].y)*(a[i].x-a[sta[top]].x)) top--;
		sta[++top]=i;
	}
	printf("%d\n",top-1);
	return 0;
}