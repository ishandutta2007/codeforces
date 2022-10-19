#include<bits/stdc++.h>
using namespace std;
int n,m,d,a[1000005],aa[2000005],b[1000005],mn[4000005];
int lz[4000005],c[2000005];
vector<int>g[2000005];
void ad(int x,int s)
{
	while(x<=d)
	{
		c[x]+=s;
		x+=x&-x;
	}
}
int quer(int x)
{
	int ans=0;
	while(x)
	{
		ans+=c[x];
		x-=x&-x;
	}
	return ans;
}
void build(int l,int r,int o)
{
	mn[o]=lz[o]=0;
	if(l==r)
	{
		mn[o]=l;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,o<<1);
	build(mid+1,r,o<<1|1);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void pushdown(int l,int r,int o)
{
	if(!lz[o])return;
	mn[o<<1]+=lz[o],mn[o<<1|1]+=lz[o];
	lz[o<<1]+=lz[o],lz[o<<1|1]+=lz[o];
	lz[o]=0;
}
void add(int l,int r,int o,int ll,int rr,int v)
{
	if(l>=ll&&r<=rr)
	{
		mn[o]+=v,lz[o]+=v;
		return;
	}
	pushdown(l,r,o);
	int mid=l+r>>1;
	if(mid>=ll)add(l,mid,o<<1,ll,rr,v);
	if(mid<rr)add(mid+1,r,o<<1|1,ll,rr,v);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		d=n+m;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),aa[i]=a[i];
		for(int i=1;i<=m;i++)scanf("%d",&b[i]),aa[n+i]=b[i];
		sort(b+1,b+m+1);
		sort(aa+1,aa+d+1);
		for(int i=1;i<=d;i++)g[i].clear();
		for(int i=1;i<=n;i++)a[i]=lower_bound(aa+1,aa+d+1,a[i])-aa;
		for(int i=1;i<=m;i++)b[i]=lower_bound(aa+1,aa+d+1,b[i])-aa;
		for(int i=1;i<=d;i++)c[i]=0;
		for(int i=1;i<=n;i++)g[a[i]].push_back(i);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=i-1-quer(a[i]);
			ad(a[i],1);
		}
		b[0]=0;
		build(1,n,1);
		int S=n,ls=0;
		for(int i=1;i<=m;i++)
		{
			if(b[i]==b[i-1])
			{
				ans+=ls;
				continue;
			}
			for(int j=b[i-1];j<b[i];j++)
				for(int k=0;k<g[j].size();k++)
				{
					int cu=g[j][k];
					S--,add(1,n,1,cu,n,-2);
				}
			for(int j=0;j<g[b[i]].size();j++)
			{
				int cu=g[b[i]][j];
				add(1,n,1,cu,n,-1);
			}
			ls=n-S+min(0,mn[1]),ans+=ls;
			for(int j=0;j<g[b[i]].size();j++)
			{
				int cu=g[b[i]][j];
				add(1,n,1,cu,n,1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}