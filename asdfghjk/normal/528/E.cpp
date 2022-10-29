#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=10005;
struct node
{
	double x,y;
}s;
struct mode
{
	double a,b,c;
}g[N];
int n,i,j,k;
double ans;
node operator +(node a,node b)
{
	return (node){a.x+b.x,a.y+b.y};
}
bool cmp(mode a,mode b)
{
	return -a.a/a.b<-b.a/b.b;
}
double mult(node a,node b)
{
	return a.x*b.y-a.y*b.x;
}
node jiaodian(mode p1,mode p2)
{
	return (node){(p1.c*p2.b-p2.c*p1.b)/(p1.a*p2.b-p2.a*p1.b),(p1.c*p2.a-p2.c*p1.a)/(p2.a*p1.b-p1.a*p2.b)};
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%lf%lf%lf",&g[i].a,&g[i].b,&g[i].c);
	sort(g+1,g+1+n,cmp);
	for(i=1;i<=n;++i)
	{
		s=(node){0,0};
		for(j=(i==n?1:i+1);j!=i;j=(j==n?1:j+1))
		{
			ans+=mult(jiaodian(g[i],g[j]),s);
			s=s+jiaodian(g[i],g[j]);
		}
	}
	printf("%.10lf",fabs(ans)*3/n/(n-1)/(n-2));
	return 0;
}