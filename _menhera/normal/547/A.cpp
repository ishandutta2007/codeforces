#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int M;
	scanf("%d",&M);
	int h1,a1,h2,a2,x1,y1,x2,y2;
	scanf("%d%d",&h1,&a1);
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&h2,&a2);
	scanf("%d%d",&x2,&y2);
	int cnt1=0;
	int cnt2=0;
	int cyc1=0;
	int cyc2=0;
	int nh1=h1;
	int nh2=h2;
	for(int cnt=1;cnt<5*M;cnt++)
	{
		nh1=(1LL*x1*nh1+y1)%M;
		nh2=(1LL*x2*nh2+y2)%M;
		if(nh1==a1 && nh2==a2)
		{
			printf("%d",cnt);
			return 0;
		}
	}
	while(h1!=a1 && cnt1 < 5*M)
	{
		cnt1++;
		h1=(1LL*x1*h1+y1)%M;
	}
	if(h1!=a1)
	{
		puts("-1");
		return 0;
	}
	do
	{
		cyc1++;
		h1=(1LL*x1*h1+y1)%M;
	}while(h1!=a1 && cyc1 < 5*M);
	if(h1!=a1)
	{
		puts("-1");
		return 0;
	}
	while(h2!=a2 && cnt2 < 10*M)
	{
		cnt2++;
		h2=(1LL*x2*h2+y2)%M;
	}
	if(h2!=a2)
	{
		puts("-1");
		return 0;
	}
	do
	{
		cyc2++;
		h2=(1LL*x2*h2+y2)%M;
	}while(h2!=a2 && cyc2 < 5*M);
	if(h2!=a2)
	{
		puts("-1");
		return 0;
	}
	int g=__gcd(cyc1,cyc2);
	if(abs(cnt1-cnt2)%g!=0)
	{
		puts("-1");
		return 0;
	}
	long long c1=cnt1;
	long long c2=cnt2;
	while(c1!=c2)
	{
		if(c1<c2) c1+=cyc1;
		else c2+=cyc2;
	}
	printf("%I64d",c1);
	return 0;
}