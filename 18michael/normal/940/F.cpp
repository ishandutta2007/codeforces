#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,q,mdf_t=0,qry_t=0,b_t=0,t=0,siz,l=1,r=0;
int a[100002],cnt[200002],tim[100002],id[100002],ans[100002],bl[100002];
struct aaa
{
	int x,y,t;
}mdf[100002],qry[100002];
struct bbb
{
	int x,y;
}b[200002];
inline bool cmp(bbb a,bbb b)
{
	return a.x<b.x? 1:0;
}
inline bool cmp1(int a,int b)
{
	return (bl[qry[a].x]==bl[qry[b].x])? ((bl[qry[a].y]==bl[qry[b].y])? (qry[a].t<qry[b].t):(bl[qry[a].y]<bl[qry[b].y])):(bl[qry[a].x]<bl[qry[b].x]);
}
inline void add(int x,int y)
{
	tim[cnt[x]]-=cnt[x],cnt[x]+=y,tim[cnt[x]]+=cnt[x];
}
int main()
{
	scanf("%d%d",&n,&q),siz=pow(n,2.0/3);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[++b_t]=(bbb){a[i],i},bl[i]=(i-1)/siz+1;
	for(int i=1,o;i<=q;++i)
	{
		scanf("%d",&o);
		if(o==1)++qry_t,scanf("%d%d",&qry[qry_t].x,&qry[qry_t].y),qry[qry_t].t=i,id[qry_t]=qry_t;
		else ++mdf_t,scanf("%d%d",&mdf[mdf_t].x,&mdf[mdf_t].y),mdf[mdf_t].t=i,b[++b_t]=(bbb){mdf[mdf_t].y,n+mdf_t};
	}
	sort(b+1,b+b_t+1,cmp),sort(id+1,id+qry_t+1,cmp1);
	for(int i=1;i<=b_t;++i)
	{
		t+=(i==1 || b[i].x!=b[i-1].x);
		if(b[i].y<=n)a[b[i].y]=t;
		else mdf[b[i].y-n].y=t;
	}
	t=0;
	for(int i=1;i<=qry_t;++i)
	{
		while(t<mdf_t && mdf[t+1].t<qry[id[i]].t)
		{
			++t;
			if(mdf[t].x>=l && mdf[t].x<=r)add(a[mdf[t].x],-1),add(mdf[t].y,1);
			swap(a[mdf[t].x],mdf[t].y);
		}
		while(t && mdf[t].t>qry[id[i]].t)
		{
			swap(a[mdf[t].x],mdf[t].y);
			if(mdf[t].x>=l && mdf[t].x<=r)add(mdf[t].y,-1),add(a[mdf[t].x],1);
			--t;
		}
		while(l>qry[id[i]].x)--l,add(a[l],1);
		while(l<qry[id[i]].x)add(a[l],-1),++l;
		while(r<qry[id[i]].y)++r,add(a[r],1);
		while(r>qry[id[i]].y)add(a[r],-1),--r;
		for(ans[id[i]]=1;tim[ans[id[i]]];++ans[id[i]]);
	}
	for(int i=1;i<=qry_t;++i)printf("%d\n",ans[i]);
	return 0;
}