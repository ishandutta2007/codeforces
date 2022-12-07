#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double eps=1e-7;
const int N=100005;
int n;
double p,q;
struct qq
{
	double x,y;
	qq (){}
	qq (double _x,double _y){x=_x;y=_y;}
}s[N];
int tot;
double mx=0,my=0;
double mul(qq x,qq y,qq z)
{
	double x1=x.x-z.x,y1=x.y-z.y;
    double x2=y.x-z.x,y2=y.y-z.y;
    return x1*y2-x2*y1;
}
double dis (qq x,qq y){return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);}
bool cmp (qq x,qq y)
{
    if (abs(mul(x,y,s[1]))<eps) return dis(x,s[1])<dis(y,s[1]);
    return mul(x,y,s[1])>eps;
}
int sta[N],top;
void get ()// 
{
	sta[1]=1;sta[2]=2;top=2;
    for (int u=3;u<=tot;u++)
    {
        while (top>2&&mul(s[u],s[sta[top]],s[sta[top-1]])>eps) top--;
        sta[++top]=u;
    }
	tot=top;
	for (int u=1;u<=top;u++)	s[u]=s[sta[u]];
}
bool check (int x)//0,0 
{
	return s[x].y*p<=s[x].x*q;
}
qq get (qq a,qq b,qq c,qq d)// 
{
	double A=mul(b,c,d),B=mul(c,a,d);
	double xx,yy;
	xx=b.x+(double)(a.x-b.x)*(double)A/(A+B);
	yy=b.y+(double)(a.y-b.y)*(double)A/(A+B);
	return qq(xx,yy);
}
int main()
{
	scanf("%d%lf%lf",&n,&p,&q);
	tot=1;s[tot]=qq(0,0);
	for (int u=1;u<=n;u++)	
	{
		tot++;
		scanf("%lf%lf",&s[tot].x,&s[tot].y);
		mx=max(mx,s[tot].x);my=max(my,s[tot].y);
	}
	tot++;s[tot]=qq(mx,0);
	tot++;s[tot]=qq(0,my);
	sort(s+2,s+1+tot,cmp);
	int ToT=tot;	tot=1;
for (int u=2;u<=ToT;u++)
		if (s[tot].x!=s[u].x||s[tot].y!=s[u].y)
			s[++tot]=s[u];	
		/*	for (int u=1;u<=tot;u++)
		printf("%lf %lf\n",s[u].x,s[u].y);*/
	get();

	int l=1,r=tot-1;
	int lalal;// 
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid))	{lalal=mid;l=mid+1;}
		else r=mid-1;
	}
	if (s[lalal].y*p==s[lalal].x*q)//
	{
		if (s[lalal].x==0) printf("%.8lf\n",(double)q/s[lalal].y);
		else printf("%.8lf\n",(double)p/s[lalal].x);
	}
	else
	{
		qq x=get(s[lalal],s[lalal+1],qq(p,q),qq(0,0));
	//	printf("%lf %lf\n",s[lalal].x,s[lalal].y);
	//	printf("%lf %lf\n",s[lalal+1].x,s[lalal+1].y);
		if (x.x>eps)	printf("%.8lf\n",p/x.x);
		else printf("%.8lf\n",q/x.y);
	} 
	return 0;
}