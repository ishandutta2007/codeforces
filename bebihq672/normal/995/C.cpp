#include<bits/stdc++.h>
using namespace std;
struct Point{
	int x,y,num;
	double ang;
}p[101010];
long long sqr(long long x)
{
	return x*x;
}
bool cmp(const Point &A,const Point &B)
{
	return A.ang<B.ang;
}
int ans[101010];
int main()
{
	srand(85935396);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].num=i;
		if(p[i].x==0&&p[i].y==0)
			p[i].ang=0;
		else
		{
			p[i].ang=atan2(p[i].y,p[i].x);
			if(p[i].ang<0)
				p[i].ang+=3.1415926535;
		}
	} 
	//random_shuffle(p+1,p+n+1);
	sort(p+1,p+n+1,cmp);
	long long x=0,y=0;
	for(int i=n;i>=1;i--)
	{
		if(sqr(x+p[i].x)+sqr(y+p[i].y)<sqr(x-p[i].x)+sqr(y-p[i].y))
		{
			ans[p[i].num]=1;
			x+=p[i].x;
			y+=p[i].y;
		}
		else
		{
			ans[p[i].num]=-1;
			x-=p[i].x;
			y-=p[i].y;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}