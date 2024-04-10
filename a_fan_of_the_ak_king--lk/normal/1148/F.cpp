#include<bits/stdc++.h>
using namespace std;
int n,t,v[1000005],top[1000005],i,j;
long long m[1000005];
long long val,ans;
long long lowbit(long long x)
{
	return -x&x;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %lld",&v[i],&m[i]);
		val+=v[i];
		long long t=m[i];
		while(t-lowbit(t)!=0)
			t-=lowbit(t);
		while(t>0)
		{
			t>>=1;
			top[i]++;
		}
	}
	if(val<0)
		for(i=1;i<=n;i++)
			v[i]=-v[i];
	for(i=0;i<62;i++)
	{
		val=0;
		for(j=1;j<=n;j++)
			if(top[j]-1==i)
				val+=v[j];
		if(val>0)
		{
			ans|=(1ll<<i);
			for(j=1;j<=n;j++)
				if((m[j]>>i)&1)
					v[j]=-v[j];
		}
	}
	cout<<ans;
}