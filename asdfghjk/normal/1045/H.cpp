#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005,md=1000000007;
int a,b,c,d,i,j,k,ans,l1,l2,jc[N],rjc[N],inv[N];
char s1[N],s2[N];
inline int C(int n,int m)
{
	if(m<0)
		return n==-1;
	return 1ll*jc[n]*rjc[m]%md*rjc[n-m]%md;
}
int dfs1(int x,int last,int a,int b,int c,int d)
{
	if(!s1[x]||a<0||b<0||c<0||d<0)
		return 0;
	if(s1[x]=='0')
	{
		if(last)
			--d;
		else
			--b;
		int rtn=(a+b+c+d==l1-x?1ll*C(a+c-1,c-1)*C(d+b,b)%md:0);
		//printf("%d %d %d %d %d %d\n",x,a,b,c,d,rtn);
		if(last)
			++d;
		else
			++b;
		if(!last)
			--a;
		else
			--c;
		return (rtn+dfs1(x+1,0,a,b,c,d))%md;
	}
	else
	{
		if(!last)
			--b;
		else
			--d;
		return dfs1(x+1,1,a,b,c,d);
	}
}
int dfs2(int x,int last,int a,int b,int c,int d)
{
	if(!s2[x]||a<0||b<0||c<0||d<0)
		return 0;
	if(s2[x]=='0')
	{
		if(last)
			--d;
		else
			--b;
		int rtn=(a+b+c+d==l2-x?1ll*C(a+c-1,c-1)*C(d+b,b)%md:0);
		//printf("%d %d %d %d %d %d\n",x,a,b,c,d,rtn);
		if(last)
			++d;
		else
			++b;
		if(!last)
			--a;
		else
			--c;
		return (rtn+dfs2(x+1,0,a,b,c,d))%md;
	}
	else
	{
		if(!last)
			--b;
		else
			--d;
		return dfs2(x+1,1,a,b,c,d);
	}
}
int main()
{
	scanf("%s%s",s1+1,s2+1);
	l1=strlen(s1+1),l2=strlen(s2+1);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	inv[1]=1;
	for(i=2;i<=l2;++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	jc[0]=rjc[0]=1;
	for(i=1;i<=l2;++i)
		jc[i]=1ll*jc[i-1]*i%md,rjc[i]=1ll*rjc[i-1]*inv[i]%md;
	if(b!=c&&b+1!=c)
	{
		printf("0");
		return 0;
	}
	ans=(((a+b+c+d+1<=l2?1ll*C(a+c-1,c-1)*C(d+b,b)%md:0)-dfs2(2,1,a,b,c,d)+md)%md-((a+b+c+d+1<=l1?1ll*C(a+c-1,c-1)*C(d+b,b)%md:0)-dfs1(2,1,a,b,c,d)+md)%md+md)%md;
	for(i=1;i<l1;++i)
		if(s1[i]=='0')
		{
			if(s1[i+1]=='0')
				--a;
			else
				--b;
		}
		else
		{
			if(s1[i+1]=='0')
				--c;
			else
				--d;
		}
	if(a==0&&b==0&&c==0&&d==0)
		ans=(ans+1)%md;
	printf("%d",ans);
	return 0;
}