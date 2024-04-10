#include<bits/stdc++.h>
using namespace std;
const int sq=173;
int n,m,q,l=1,r=0;
int a[30002],id[30002],bl[30002],to[30002],ans[30002],cnt[30002],val[30002],f[30002];
struct aaa
{
	int l,r,id;
}qry[30002];
inline int Add(int x,int y)
{
	if((x+=y)>=m)x-=m;
	if(x<=-m)x+=m;
	return x;
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
struct SegTree
{
	int cnt[120002],laz[120002],pre[120002],now[120002];
	inline void pushdown(int k,int ls,int rs)
	{
		if(!laz[k])return ;
		int x,y;
		if(laz[k]>0)
		{
			x=pre[ls],y=now[ls],pre[ls]=(x*(laz[k]>1? f[laz[k]-2]:0)+y*f[laz[k]-1])%m,now[ls]=(x*f[laz[k]-1]+y*f[laz[k]])%m;
			x=pre[rs],y=now[rs],pre[rs]=(x*(laz[k]>1? f[laz[k]-2]:0)+y*f[laz[k]-1])%m,now[rs]=(x*f[laz[k]-1]+y*f[laz[k]])%m;
		}
		else
		{
			x=pre[ls],y=now[ls],pre[ls]=(y*f[-laz[k]-1]-x*f[-laz[k]])%m,now[ls]=(x*f[-laz[k]-1]-y*(-laz[k]>1? f[-laz[k]-2]:0))%m;
			x=pre[rs],y=now[rs],pre[rs]=(y*f[-laz[k]-1]-x*f[-laz[k]])%m,now[rs]=(x*f[-laz[k]-1]-y*(-laz[k]>1? f[-laz[k]-2]:0))%m;
			if(!(laz[k]&1))pre[ls]=-pre[ls],now[ls]=-now[ls],pre[rs]=-pre[rs],now[rs]=-now[rs];
		}
		laz[ls]+=laz[k],laz[rs]+=laz[k],laz[k]=0;
	}
	inline void pushup(int k,int ls,int rs)
	{
		cnt[k]=cnt[ls]+cnt[rs],pre[k]=Add(pre[ls],pre[rs]),now[k]=Add(now[ls],now[rs]);
	}
	inline void modify(int k,int l,int r,int x,int t,int o)
	{
		if(l==r)
		{
			cnt[k]+=o;
			if(~o)now[k]=(val[x]*f[t])%m,pre[k]=(val[x]*(t? f[t-1]:0))%m;
			else now[k]=pre[k]=0;
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(x<=mid)modify(ls,l,mid,x,t,o);
		else modify(rs,mid+1,r,x,t,o);
		pushup(k,ls,rs);
	}
	inline void modify2(int k,int l,int r,int l1,int r1,int t,int o)
	{
		if(l1>r1)return ;
		if(l>=l1 && r<=r1)
		{
			laz[k]+=o;
			if(~o)swap(now[k],pre[k]),now[k]=Add(now[k],pre[k]);
			else now[k]=Add(now[k],-pre[k]),swap(now[k],pre[k]);
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)modify2(ls,l,mid,l1,r1,t,o);
		else if(l1>mid)modify2(rs,mid+1,r,l1,r1,t,o);
		else modify2(ls,l,mid,l1,mid,t,o),modify2(rs,mid+1,r,mid+1,r1,t,o);
		pushup(k,ls,rs);
	}
	inline int query(int k,int l,int r,int l1,int r1)
	{
		if(l1>r1)return 0;
		if(l>=l1 && r<=r1)return cnt[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		pushdown(k,ls,rs);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return query(ls,l,mid,l1,mid)+query(rs,mid+1,r,mid+1,r1);
	}
}S;
inline bool cmp(int x,int y)
{
	return a[x]<a[y]? 1:0;
}
inline bool cmp1(aaa a,aaa b)
{
	return bl[a.l]==bl[b.l]? (a.r<b.r):(bl[a.l]<bl[b.l]);
}
inline void add(int x,int o)
{
	int t=S.query(1,1,n,1,x-1);
	S.modify(1,1,n,x,t,o),S.modify2(1,1,n,x+1,n,t,o);
}
int main()
{
	scanf("%d%d",&n,&m),f[0]=f[1]=1;
	for(int i=2;i<=n;++i)f[i]=Add(f[i-1],f[i-2]),bl[i]=(i-1)/sq+1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp),scanf("%d",&q);
	for(int i=1;i<=q;++i)scanf("%d%d",&qry[i].l,&qry[i].r),qry[i].id=i;
	sort(qry+1,qry+q+1,cmp1);
	for(int i=1;i<=n;++i)val[to[id[i]]=to[id[i-1]]+(a[id[i]]!=a[id[i-1]])]=a[id[i]];
	for(int i=1;i<=n;++i)val[i]%=m;
	for(int i=1;i<=q;++i)
	{
		while(r<qry[i].r)
		{
			++r;
			if(!cnt[to[r]])add(to[r],1);
			++cnt[to[r]];
		}
		while(l>qry[i].l)
		{
			--l;
			if(!cnt[to[l]])add(to[l],1);
			++cnt[to[l]];
		}
		while(r>qry[i].r)
		{
			--cnt[to[r]];
			if(!cnt[to[r]])add(to[r],-1);
			--r;
		}
		while(l<qry[i].l)
		{
			--cnt[to[l]];
			if(!cnt[to[l]])add(to[l],-1);
			++l;
		}
		ans[qry[i].id]=S.now[1];
	}
	for(int i=1;i<=q;++i)printf("%d\n",Add(ans[i],m));
	return 0;
}