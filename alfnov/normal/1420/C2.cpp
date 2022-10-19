#include<bits/stdc++.h>
using namespace std;
int a[300005],d[300005],b[300005],n,q;
long long ans;
void update(int x)
{
	if(x<=0||x>=n+1)return;
	if(d[x]==1)ans-=b[x];
	else if(d[x]==2)ans+=b[x];
	d[x]=0;
	b[x]=a[x];
	if(a[x]>a[x-1]&&a[x]>a[x+1])ans+=a[x],d[x]=1;
	if(a[x]<a[x-1]&&a[x]<a[x+1])ans-=a[x],d[x]=2;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		for(int i=1;i<=n;i++)cin>>a[i],d[i]=0,b[i]=a[i];
		a[0]=a[n+1]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1])ans+=a[i],d[i]=1;
			else if(a[i]<a[i-1]&&a[i]<a[i+1])ans-=a[i],d[i]=2;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=q;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			swap(a[u],a[v]);
			update(u-1);
			update(u);
			update(u+1);
			update(v-1);
			update(v);
			update(v+1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}