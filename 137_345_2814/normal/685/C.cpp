#include<cstdio>
#include<algorithm>
using namespace std;
long long T,s[5][2],n,a,b,c,a1,b1,c1,a2,b2,c2,s2[5][2],fg,t[10][3];
bool solve2(long long l)
{
	long long r1mn=s2[1][0]-l,r1mx=l-s2[4][0],r2mn=s2[2][0]-l,r2mx=l-s2[3][0];
	if((r1mn+r2mn)&1)
	if(r1mn<r1mx)r1mn++;
	else r2mn++;
	if(r1mn>r1mx||r2mn>r2mx)return 0;
	long long r1mn1=l-s2[4][1],r1mx1=s2[1][1]-l,r2mn1=l-s2[3][1],r2mx1=s2[2][1]-l;
	if(r1mn1>r1mn)r1mn=r1mn1;
	if(r1mx1<r1mx)r1mx=r1mx1;
	if(r2mn1>r2mn)r2mn=r2mn1;
	if(r2mx1<r2mx)r2mx=r2mx1;
	if((r1mn+r2mn)&1)
	if(r1mn<r1mx)r1mn++;
	else r2mn++;
	a2=l,b2=(r1mn+r2mn)/2,c2=r1mn-b2;
	return 1;
}
bool solve3(long long l)
{
	long long r1mn=s2[1][0]-l,r1mx=l-s2[4][0],r2mn=s2[2][0]-l,r2mx=l-s2[3][0];
	if((r1mn+r2mn)&1)
	if(r2mn<r2mx)r2mn++;
	else r1mn++;
	if(r1mn>r1mx||r2mn>r2mx)return 0;
	long long r1mn1=l-s2[4][1],r1mx1=s2[1][1]-l,r2mn1=l-s2[3][1],r2mx1=s2[2][1]-l;
	if(r1mn1>r1mn)r1mn=r1mn1;
	if(r1mx1<r1mx)r1mx=r1mx1;
	if(r2mn1>r2mn)r2mn=r2mn1;
	if(r2mx1<r2mx)r2mx=r2mx1;
	if((r1mn+r2mn)&1)
	if(r2mn<r2mx)r2mn++;
	else r1mn++;
	a2=l,b2=(r1mn+r2mn)/2,c2=r1mn-b2;
	return 1;
}
long long Abs(long long a){return a>0?a:-a;}
long long solve(long long x,long long y,long long z)
{
	return max(max(
	max(Abs(x+y+z-s[1][0]),Abs(x+y+z-s[1][1])),
	max(Abs(x+y-z-s[2][0]),Abs(x+y-z-s[2][1]))
	),max(
	max(Abs(x-y+z-s[3][0]),Abs(x-y+z-s[3][1])),
	max(Abs(x-y-z-s[4][0]),Abs(x-y-z-s[4][1]))
	));
}
bool solve(long long l)
{
	for(int i=1;i<=4;i++)s2[i][0]=s[i][1]-l,s2[i][1]=s[i][0]+l;
	for(int i=1;i<=4;i++)if(s2[i][0]>s2[i][1])return 0;
	long long tp=max(s2[4][0]+s2[1][0],s2[3][0]+s2[2][0])/2;
	if(!solve2(tp-1))if(!solve2(tp))if(!solve2(tp+1))return 0;
	if(solve(a2,b2,c2)>l)solve2(tp+1);
	if(solve(a2,b2,c2)<=l){a1=a2,b1=b2,c1=c2;return 1;}
	if(!solve3(tp-1))if(!solve3(tp))if(!solve3(tp+1))return 0;
	if(solve(a2,b2,c2)>l)solve3(tp+1);
	if(solve(a2,b2,c2)<=l){a1=a2,b1=b2,c1=c2;return 1;}
	return 0;
}
void doit(int x,int y,int z){if(solve(a1,b1,c1)>solve(a1+x,b1+y,c1+z))a1+=x,b1+=y,c1+=z;}
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		s[1][0]=s[2][0]=s[3][0]=s[4][0]=4e18;
		s[1][1]=s[2][1]=s[3][1]=s[4][1]=-4e18;
		int ct=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			if(fg)t[++ct][0]=a,t[ct][1]=b,t[ct][2]=c;
			if(s[1][0]>a+b+c)s[1][0]=a+b+c;
			if(s[1][1]<a+b+c)s[1][1]=a+b+c;
			if(s[2][0]>a+b-c)s[2][0]=a+b-c;
			if(s[2][1]<a+b-c)s[2][1]=a+b-c;
			if(s[3][0]>a-b+c)s[3][0]=a-b+c;
			if(s[3][1]<a-b+c)s[3][1]=a-b+c;
			if(s[4][0]>a-b-c)s[4][0]=a-b-c;
			if(s[4][1]<a-b-c)s[4][1]=a-b-c;
		}
		long long lb=0,rb=4e18;
		while(lb<=rb)
		{
			long long mid=(lb+rb)>>1;
			if(solve(mid))rb=mid-1;
			else lb=mid+1;
		}
		for(int t1=1;t1<=3;t1++)
		for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
		for(int k=-1;k<=1;k++)
		doit(i,j,k);
		printf("%lld %lld %lld\n",a1,b1,c1);
	}
}//