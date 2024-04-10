#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int n,m,deg[105];
struct data{int x,y;}a[105],b[105];

int get(int i,int j)
{
	int s=0;
	s+=(a[i].x==b[j].y);
	s+=(a[i].x==b[j].x);
	s+=(a[i].y==b[j].y);
	s+=(a[i].y==b[j].x);
	if (s!=1) return 0;
	if (a[i].x==b[j].x||a[i].x==b[j].y) return a[i].x;
	else return a[i].y;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=m;i++) scanf("%d%d",&b[i].x,&b[i].y);
	int s=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			int x=get(i,j);
			if (!x) continue;
			if (!deg[i]) deg[i]=x;
			else if (deg[i]!=x) {puts("-1");return 0;}
			if (!deg[j+n]) deg[j+n]=x;
			else if (deg[j+n]!=x) {puts("-1");return 0;}
			if (s==0) s=x;
			else if (s!=x) s=-1;
		}
	if (s>0) {printf("%d",s);return 0;}
	else puts("0");
	return 0;
}