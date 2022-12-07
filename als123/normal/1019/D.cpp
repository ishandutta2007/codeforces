#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const LL N=2005;
LL n,S;
struct qq
{
	LL x,y;
	qq () {};
	qq (LL _x,LL _y)	{x=_x;y=_y;}
	void print ()	{printf("%I64d %I64d\n",x,y);}
}s[N];
qq operator - (qq x,qq y)	{return qq(x.x-y.x,x.y-y.y);}
LL operator * (qq x,qq y)	{return x.x*y.y-x.y*y.x;}
bool cmp (qq x,qq y)	{return x.y==y.y?x.x<y.x:x.y<y.y;}
LL pos[N];
struct qt
{
	LL x,y;
	double angle;
	qt () {};
	qt (LL _x,LL _y,double _angle)	{x=_x;y=_y;angle=_angle;}
}a[N*N];
bool cmp1 (qt x,qt y)	{return x.angle<y.angle;}
int main()
{
	scanf("%I64d%I64d",&n,&S);S*=2;
	for (LL u=1;u<=n;u++)	scanf("%I64d%I64d",&s[u].x,&s[u].y);
	sort(s+1,s+1+n,cmp);
	/*printf("\n");
	for (int u=1;u<=n;u++)	printf("%I64d %I64d\n",s[u].x,s[u].y);*/
	LL nn=0;
	for (LL u=1;u<=n;u++) pos[u]=u;
	for (LL u=1;u<=n;u++)
		for (LL i=u+1;i<=n;i++)
			a[++nn]=qt(u,i,atan2((int)s[i].y-s[u].y,(int)s[i].x-s[u].x));
	//for (int u=1;u<=nn;u++)printf("OZY:%I64d %I64d %lf\n",a[u].x,a[u].y,a[u].angle);
	sort(a+1,a+1+nn,cmp1);
	for (LL u=1;u<=nn;u++)
	{
		LL l=1,r=n;
		qq x=s[pos[a[u].x]],y=s[pos[a[u].y]];
		LL lalal=0;
		while (l<=r)
		{
			LL mid=(l+r)>>1;
			if ((y-x)*(s[mid]-x)<=S)	{l=mid+1;lalal=mid;}
			else r=mid-1;
		}
		//printf("OZY:%I64d %I64d %lf\n",a[u].x,a[u].y,a[u].angle);
		/*x.print();y.print();
		if (lalal!=0)   printf("%I64d %I64d\n",u,lalal);*/
		if (lalal!=0&&(y-x)*(s[lalal]-x)==S)
		{
			printf("Yes\n");x.print();y.print();s[lalal].print();
			return 0;
		}
		l=1;r=n;
		lalal=0;
		while (l<=r)
		{
			LL mid=(l+r)>>1;
			if ((y-x)*(s[mid]-x)<=-S)	{l=mid+1;lalal=mid;}
			else r=mid-1;
		}
		 // if (lalal!=0)   printf("%I64d %I64d\n",u,lalal);
		if (lalal!=0&&(y-x)*(s[lalal]-x)==-S)
		{
			printf("Yes\n");x.print();y.print();s[lalal].print();
			return 0;
		}
		swap(s[pos[a[u].x]],s[pos[a[u].y]]);
		swap(pos[a[u].x],pos[a[u].y]);
		/*if (n==20)
		{
			for (LL u=1;u<=n;u++)
			s[u].print();
		}*/
		/*system("pause");*/
	}
	printf("No\n");
	return 0;
}