#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],fa[100005],vist[100005];
long long c[100005],ans[100005];
int findfather(int x)
{
	return x==fa[x]?x:fa[x]=findfather(fa[x]);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=0;i<=n+1;i++)fa[i]=i;
	long long aa=0;
	for(int i=n;i>=1;i--)
	{
		ans[i]=aa;
		vist[b[i]]=1;
		long long tt=a[b[i]];
		int wz=b[i];
		if(vist[b[i]-1])
		{
			fa[b[i]-1]=b[i];
			tt+=c[b[i]-1];
		}
		if(vist[b[i]+1])
		{
			fa[b[i]]=b[i]+1;
			tt+=c[findfather(b[i]+1)];
			wz=findfather(b[i]+1);
		}
		c[wz]=tt;
		aa=max(aa,c[wz]);
	}
	for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
	return 0;
}