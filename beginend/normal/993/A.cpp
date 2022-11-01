#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int inf=100000;

struct data{int x,y;}a[5],b[5];

bool check1(int x,int y)
{
	int mx1=-inf,mx2=-inf,mn1=inf,mn2=inf;
	for (int i=1;i<=4;i++)
	{
		mx1=std::max(mx1,a[i].x);
		mn1=std::min(mn1,a[i].x);
		mx2=std::max(mx2,a[i].y);
		mn2=std::min(mn2,a[i].y);
	}
	return x>=mn1&&x<=mx1&&y>=mn2&&y<=mx2;
}

bool check2(int x,int y)
{
	int p=x,q=y;
	x=p+q;y=p-q;
	int mx1=-inf,mx2=-inf,mn1=inf,mn2=inf;
	for (int i=1;i<=4;i++)
	{
		mx1=std::max(mx1,b[i].x);
		mn1=std::min(mn1,b[i].x);
		mx2=std::max(mx2,b[i].y);
		mn2=std::min(mn2,b[i].y);
	}
	return x>=mn1&&x<=mx1&&y>=mn2&&y<=mx2;
}

int main()
{
	for (int i=1;i<=4;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=4;i++) scanf("%d%d",&b[i].x,&b[i].y);
	for (int i=1;i<=4;i++)
	{
		int x=b[i].x,y=b[i].y;
		b[i].x=x+y;b[i].y=x-y;
	}
	for (int i=-100;i<=100;i++)
		for (int j=-100;j<=100;j++)
		{
			if (check1(i,j)&&check2(i,j)) {puts("YES");return 0;}
		}
	puts("NO");
	return 0;
}