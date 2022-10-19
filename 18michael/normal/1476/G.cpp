#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,sq,t=0,l=1,r=0,qry_t=0,mdf_t=0;
int a[100002],bl[100002],ans[100002],cnt[100002],cnt2[100002],la[100002],nx[100002];
bool o[100002];
struct aaa
{
	int t,l,r,k;
}qry[100002];
struct bbb
{
	int t,p,x;
}mdf[100002];
inline bool cmp(aaa a,aaa b)
{
	return bl[a.l]==bl[b.l]? (bl[a.r]==bl[b.r]? (a.t<b.t):(bl[a.r]<bl[b.r])):(bl[a.l]<bl[b.l]);
}
inline void add(int x,int o)
{
	if(!cnt2[cnt[x]+o])
	{
		if(~o)la[cnt[x]+o]=cnt[x],nx[cnt[x]+o]=nx[cnt[x]],nx[cnt[x]]=la[nx[cnt[x]]]=cnt[x]+o;
		else nx[cnt[x]+o]=cnt[x],la[cnt[x]+o]=la[cnt[x]],la[cnt[x]]=nx[la[cnt[x]]]=cnt[x]+o;
	}
	if(!(--cnt2[cnt[x]]))nx[la[cnt[x]]]=nx[cnt[x]],la[nx[cnt[x]]]=la[cnt[x]];
	++cnt2[cnt[x]+=o];
}
inline int query(int k)
{
	int res=inf;
	for(int i=nx[0],j=nx[0],x=0;i<=n;i=nx[i])for(x+=cnt2[i];x>=k;x-=cnt2[j],j=nx[j])res=min(res,i-j);
	return res<inf? res:-1;
}
int main()
{
	scanf("%d%d",&n,&m),sq=pow(n,2.0/3),nx[0]=n+1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),bl[i]=(i-1)/sq+1;
	for(int i=1,x;i<=m;++i)
	{
		scanf("%d",&x);
		if(o[i]=(x==1))qry[++qry_t].t=i,scanf("%d%d%d",&qry[qry_t].l,&qry[qry_t].r,&qry[qry_t].k);
		else mdf[++mdf_t].t=i,scanf("%d%d",&mdf[mdf_t].p,&mdf[mdf_t].x);
	}
	sort(qry+1,qry+qry_t+1,cmp);
	for(int i=1;i<=qry_t;++i)
	{
		while(t<mdf_t && mdf[t+1].t<qry[i].t)
		{
			++t,swap(a[mdf[t].p],mdf[t].x);
			if(l<=mdf[t].p && mdf[t].p<=r)add(a[mdf[t].p],1),add(mdf[t].x,-1);
		}
		while(t && mdf[t].t>qry[i].t)
		{
			if(l<=mdf[t].p && mdf[t].p<=r)add(a[mdf[t].p],-1),add(mdf[t].x,1);
			swap(a[mdf[t].p],mdf[t].x),--t;
		}
		while(l>qry[i].l)--l,add(a[l],1);
		while(r<qry[i].r)++r,add(a[r],1);
		while(l<qry[i].l)add(a[l],-1),++l;
		while(r>qry[i].r)add(a[r],-1),--r;
		ans[qry[i].t]=query(qry[i].k);
	}
	for(int i=1;i<=m;++i)if(o[i])printf("%d\n",ans[i]);
	return 0;
}