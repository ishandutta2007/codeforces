#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int l,r,aa;
	bool operator<(const apple &other)const
	{
		return r<other.r;
	}
}e[300005];
int n,m,a[100005],b[100005],c[100005],cc[100005],ans[300005];
int tot=0,id[100005],sm[400005*25],ls[400005*25],rs[400005*25];
void add(int x,int y,int l,int r,int u,int v)
{
	if(l==r)
	{
		sm[y]=v;
		return;
	}
	int mid=l+r>>1;
	ls[y]=ls[x],rs[y]=rs[x];
	if(u<=mid)add(ls[x],ls[y]=++tot,l,mid,u,v);
	else add(rs[x],rs[y]=++tot,mid+1,r,u,v);
	sm[y]=min(sm[ls[y]],sm[rs[y]]);
}
int query(int x,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)return sm[x];
	int mid=l+r>>1,ans=INT_MAX;
	if(mid>=ll)ans=min(ans,query(ls[x],l,mid,ll,rr));
	if(mid<rr)ans=min(ans,query(rs[x],mid+1,r,ll,rr));
	return ans;
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sm[x]=INT_MAX;
		return;
	}
	int mid=l+r>>1;
	build(ls[x]=++tot,l,mid);
	build(rs[x]=++tot,mid+1,r);
	sm[x]=min(sm[ls[x]],sm[rs[x]]);
}
vector<int>g[100005];
void add2(int x,int s)
{
	while(x<=n)
	{
		cc[x]=min(cc[x],s);
		x+=x&-x;
	}
}
int query2(int x)
{
	int ans=INT_MAX;
	while(x)
	{
		ans=min(ans,cc[x]);
		x-=x&-x;
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)c[i]=lower_bound(b+1,b+n+1,a[i])-b;
	build(id[n+1]=++tot,1,n);
	for(int i=n;i>=1;i--)add(id[i+1],id[i]=++tot,1,n,c[i],i);
	cin>>m;
	for(int i=1;i<=m;i++)scanf("%d%d",&e[i].l,&e[i].r),e[i].aa=i;
	sort(e+1,e+m+1);
	for(int i=1;i<n;i++)
	{
		int wz;
		wz=query(id[i+1],1,n,c[i],n);
		while(wz<=1e9)
		{
			g[wz].push_back(i);
			if(wz==n||a[wz]==a[i])break;
			int a1=c[i],a2=upper_bound(b+1,b+n+1,(a[i]+a[wz]-1)/2)-b-1;
			if(a1>a2)break;
			wz=query(id[wz+1],1,n,a1,a2);
		}
		wz=query(id[i+1],1,n,1,c[i]);
		while(wz<=1e9)
		{
			g[wz].push_back(i);
			if(wz==n||a[wz]==a[i])break;
			int a1=lower_bound(b+1,b+n+1,(a[i]+a[wz])/2+1)-b,a2=c[i];
			if(a1>a2)break;
			wz=query(id[wz+1],1,n,a1,a2);
		}
	}
	for(int i=1;i<=n;i++)
	{
		g[i].push_back(0);
		sort(g[i].begin(),g[i].end());
	}
	memset(cc,63,sizeof(cc));
	int wz=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<g[i].size();j++)
		{
			int cu=g[i][j];
			if(cu==g[i][j-1])continue;
			add2(n-cu+1,abs(a[i]-a[cu]));
		}
		while(wz<=m&&e[wz].r==i)
		{
			ans[e[wz].aa]=query2(n-e[wz].l+1);
			if(ans[e[wz].aa]>1e9)ans[e[wz].aa]=0;
			wz++;
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}