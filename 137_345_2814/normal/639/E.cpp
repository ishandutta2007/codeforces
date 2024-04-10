#include<cstdio>
#include<algorithm>
using namespace std;
#define N 150050
struct pt{int x,y;double mn,mx;}s[N];
long long su;
int n;
bool cmp1(pt a,pt b){return 1ll*a.x*b.y>1ll*b.x*a.y;}
bool cmp2(pt a,pt b){return a.x>b.x;}
bool check(double t)
{
	sort(s+1,s+n+1,cmp1);
	int lb=1;
	long long s1=0;
	while(lb<=n)
	{
		int rb=lb;long long su1=s[lb].y;
		while(1ll*s[lb].x*s[rb+1].y==1ll*s[rb+1].x*s[lb].y&&rb<n)rb++,su1+=s[rb].y;
		for(int i=lb;i<=rb;i++)s[i].mx=s[i].x*(1-t*(s1+s[i].y)/su),s[i].mn=s[i].x*(1-t*(su1+s1)/su);
		lb=rb+1,s1+=su1;
	}
	sort(s+1,s+n+1,cmp2);
	double mn=1e9;
	lb=1;
	while(lb<=n)
	{
		int rb=lb;
		while(rb<n&&s[rb+1].x==s[lb].x)rb++;
		for(int i=lb;i<=rb;i++)if(s[i].mx>mn)return 0;
		for(int i=lb;i<=rb;i++)if(mn>s[i].mn)mn=s[i].mn;
		lb=rb+1;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&s[i].x);
	for(int i=1;i<=n;i++)scanf("%d",&s[i].y),su+=s[i].y;
	double lb=0,rb=1,as=0;
	for(int i=1;i<=60;i++)
	{
		double mid=(lb+rb)/2;
		if(check(mid))as=mid,lb=mid;
		else rb=mid;
	}
	printf("%.15lf\n",as);
}