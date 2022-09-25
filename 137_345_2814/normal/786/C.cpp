#include<cstdio>
using namespace std;
#define N 105000
int n,v[N],is[N],as[N];
int sol(int s)
{
	int ct1=0,ct=0,ls=1;
	while(ls<=n)
	{
		int rb=ls;ct=0;
		while(rb<=n&&ct<=s){ct+=!is[v[rb]],is[v[rb]]=1,rb++;if(ct>s){rb--;continue;}}
		for(int i=ls;i<=rb;i++)is[v[i]]=0;ct1++;ls=rb;
	}
	return ct1;
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=500;i++)as[i]=sol(i);
	for(int i=200;i>=1;i--)
	{
		int lb=1,rb=n,as1=n;
		while(lb<=rb)
		{
			int mid=(lb+rb)>>1;
			if(sol(mid)<=i)as1=mid,rb=mid-1;
			else lb=mid+1;
		}
		for(int j=as1;j<=n;j++)as[j]=i;
	}
	for(int i=1;i<=n;i++)printf("%d ",as[i]);
}