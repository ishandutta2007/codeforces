#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=10005;

int n,l,r,f[N];
struct data{int x,y;}a[N];

bool cmp(data a,data b)
{
	return a.y<b.y||a.y==b.y&&a.x>b.x;
}

int main()
{
	scanf("%d%d%d",&n,&l,&r);
	int s=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i].x),s+=a[i].x;
	for (int i=1;i<=n;i++) scanf("%d",&a[i].y);
	std::sort(a+1,a+n+1,cmp);
	f[0]=1;
	for (int i=1;i<=n;i++)
		for (int j=s;j>=a[i].x;j--)
			if (f[j-a[i].x]) f[j]=std::max(f[j],f[j-a[i].x]+a[i].y*(j>=s-r&&j<=s-l));
	int ans=0;
	for (int i=0;i<=s;i++) ans=std::max(ans,f[i]);
	printf("%d",ans-1);
	return 0;
}