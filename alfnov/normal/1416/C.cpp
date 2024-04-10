#include<bits/stdc++.h>
using namespace std;
long long c1[35],c2[35];
int a[300005],b[300005],c[300005],d[300005],n;
void add(int x)
{
	while(x<=n)
	{
		c[x]++;
		x+=x&-x;
	}
}
int query(int x)
{
	int ans=0;
	while(x)
	{
		ans+=c[x];
		x-=x&-x;
	}
	return ans;
}
int ds(int l,int r)
{
	int R=upper_bound(b+1,b+n+1,r)-b-1;
	int L=lower_bound(b+1,b+n+1,l)-b;
	return query(R)-query(L-1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)d[i]=lower_bound(b+1,b+n+1,a[i])-b;
	for(int i=1;i<=n;i++)
	{
		for(int j=30;j>=0;j--)
		{
			int x=a[i]&(1<<j),tt=(a[i]>>j+1)<<j+1;
			if(x)c2[j]+=ds(tt,tt+(1<<j)-1);
			else c1[j]+=ds(tt+(1<<j),tt+(1<<j+1)-1);
		}
		add(d[i]);
	}
	int x=0;
	long long ans=0;
	for(int i=30;i>=0;i--)
	{
		if(c1[i]<=c2[i])ans+=c1[i];
		else ans+=c2[i],x|=(1<<i);
	}
	printf("%lld %d\n",ans,x);
	return 0;
}