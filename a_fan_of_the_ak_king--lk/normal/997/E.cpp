#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,a[N],i,j,k,lu,lv,l,p[N];
int lazy[N*4],lazy2[N*4],mn[N*4],mnn[N*4];
long long sum[N*4],ans[N];
struct str{
	int l,r,x;
}b[N];
struct seg{
	int l,r;
}u[N],v[N];
bool cmp(str a,str b)
{
	return a.r<b.r;
}
bool cmp1(seg a,seg b)
{
	return a.l<b.l;
}
bool cmp2(seg a,seg b)
{
	return a.r<b.r;
}
void Build(int i,int l,int r)
{
	mnn[i]=r-l+1;
	if(l==r)
		return;
	int mid=l+r>>1;
	Build(i<<1,l,mid);
	Build(i<<1|1,mid+1,r);
}
void pushdown(int i)
{
	lazy[i<<1]+=lazy[i];
	lazy[i<<1|1]+=lazy[i];
	mn[i<<1]+=lazy[i];
	mn[i<<1|1]+=lazy[i];
	lazy[i]=0;
	if(mn[i]==mn[i<<1])
	{
		lazy2[i<<1]+=lazy2[i];
		sum[i<<1]+=mnn[i<<1]*lazy2[i];
	}
	if(mn[i]==mn[i<<1|1])
	{
		lazy2[i<<1|1]+=lazy2[i];
		sum[i<<1|1]+=mnn[i<<1|1]*lazy2[i];
	}
	lazy2[i]=0;
}
void pushup(int i)
{
	mn[i]=min(mn[i<<1],mn[i<<1|1]);
	mnn[i]=0;
	if(mn[i]==mn[i<<1])
		mnn[i]+=mnn[i<<1];
	if(mn[i]==mn[i<<1|1])
		mnn[i]+=mnn[i<<1|1];
}
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
	 	mn[i]+=x;
	 	lazy[i]+=x;
	 	return;
	}
	int mid=l+r>>1;
	pushdown(i);
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,x);
	pushup(i);
}
long long Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return sum[i];
	int mid=l+r>>1;
	pushdown(i);
	long long ans=0;
	if(mid>=ll)
		ans+=Query(i<<1,l,mid,ll,rr);
	if(mid<rr)
		ans+=Query(i<<1|1,mid+1,r,ll,rr);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}
	for(i=0;i<=n;++i)
	{
		++k;
		u[k]=v[k]=(seg){min(p[i],p[i+1]),max(p[i],p[i+1])};
	}
	sort(u+1,u+1+k,cmp1);
	sort(v+1,v+1+k,cmp2);
	scanf("%d",&q);
	for(i=1;i<=q;++i)
	{
		scanf("%d %d",&b[i].l,&b[i].r);
		b[i].x=i;
	}
	sort(b+1,b+1+q,cmp);
	Build(1,1,n);
	modify(1,1,n,1,n,N);
	lu=lv=l=1;
	while(u[lu].l==0)
		++lu;
	for(i=1;i<=n;++i)
	{
		modify(1,1,n,i,i,-N);
		while(lu<=k&&u[lu].l==i)
		{
			modify(1,1,n,1,u[lu].l,1);
			++lu;
		}
		while(lv<=k&&v[lv].r==i)
		{
			if(v[lv].l)
				modify(1,1,n,1,v[lv].l,-1);
			modify(1,1,n,v[lv].l+1,v[lv].r,1);
			++lv;
		}
		++lazy2[1],sum[1]+=mnn[1];
		while(l<=q&&b[l].r==i)
		{
			ans[b[l].x]=Query(1,1,n,b[l].l,b[l].r);
			++l;
		}
	}
	for(i=1;i<=q;++i)
		printf("%lld\n",ans[i]);
}