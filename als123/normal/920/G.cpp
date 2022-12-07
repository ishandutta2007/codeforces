#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL T;
LL x,p,k;
LL q[20],tot;
LL lalal;
LL lim;
void dfs (LL x,LL y,LL z)
{
	if (x>tot)
	{
		lalal=lalal+z*(lim/y);
		return ;
	}
	dfs(x+1,y,z);
	dfs(x+1,y*q[x],-z);
}
int main()
{
	scanf("%I64d",&T);
	while (T--)
	{
		scanf("%I64d%I64d%I64d",&x,&p,&k);
		tot=0;
		for (LL u=2;u*u<=p;u++)
			if (p%u==0)
			{
				q[++tot]=u;
				while (p%u==0)
				{
					p/=u;
				}
			}
		if (p!=1) q[++tot]=p;
		lim=x;lalal=0;
		dfs(1,1,1);
		LL now=lalal;
		//printf("%I64d\n",now);
		LL l=1,r=1000000000000000;
		LL ans;
		while (l<=r)
		{
			LL mid=(l+r)>>1;
			lalal=0;lim=mid;dfs(1,1,1);
			if (lalal-now>=k) {r=mid-1;ans=mid;}
			else l=mid+1;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}