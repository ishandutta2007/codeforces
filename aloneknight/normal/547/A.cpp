#include<cstdio>
using namespace std;
#define ll long long
ll m,h1,h2,a1,a2,x1,x2,y1,y2,r1=-1,r2=-1,p1=-1,p2=-1;
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&m,&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
	for(int i=1;i<=2*m;i++)
	{
		h1=(h1*x1+y1)%m;h2=(h2*x2+y2)%m;
		if(h1==a1){if(p1==-1)p1=i;else if(r1==-1)r1=i-p1;}
		if(h2==a2){if(p2==-1)p2=i;else if(r2==-1)r2=i-p2;}
	}
 	if(p1==-1||p2==-1){puts("-1");return 0;}
	for(int i=1;i<=2*m;i++)
	{
		if(p1==p2){printf("%lld\n",p1);return 0;}
		if(p1<p2)p1+=r1;else p2+=r2;
	}
	puts("-1");return 0;
}