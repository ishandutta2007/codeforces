#include<cstdio>
#include<algorithm>
#define LL long long
#define mod 1000000007
using namespace std;
int n,n2,edge_t=0,dfn_t=0,t=1,Mx=0;LL ans=0,res=1,res1=0;
int l[100002],r[100002],len[100002],la[100002]={},fa[100002],dep[100002],dfn[100002],son[100002]={},siz[100002],top[100002];
LL inv[100002];
struct aaa
{
	int to,nx;
}edge[200002];
struct bbb
{
	int x,y,z;
}a[200002];
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
	LL arr[400002],laz[400002];
	inline void pushdown(int k,int l,int r,int ls,int rs)
	{
		laz[ls]=(laz[ls]+laz[k])%mod,laz[rs]=(laz[rs]+laz[k])%mod,arr[k]=(arr[k]+laz[k]*(r-l+1))%mod,laz[k]=0;
	}
	inline void modify(int k,int l,int r,int l1,int r1,LL d)
	{
		if(l>=l1 && r<=r1){laz[k]=(laz[k]+d)%mod;return ;}
		int ls=lson(k),rs=rson(k),mid=((l+r)>>1);
		pushdown(k,l,r,ls,rs),arr[k]=(arr[k]+d*(r1-l1+1))%mod;
		if(r1<=mid)modify(ls,l,mid,l1,r1,d);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1,d);
		else modify(ls,l,mid,l1,mid,d),modify(rs,mid+1,r,mid+1,r1,d);
	}
	inline LL query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return (arr[k]+laz[k]*(r1-l1+1))%mod;
		int ls=lson(k),rs=rson(k),mid=((l+r)>>1);pushdown(k,l,r,ls,rs);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return (query(ls,l,mid,l1,mid)+query(rs,mid+1,r,mid+1,r1))%mod;
	}
}S,S1,S2;
inline bool cmp(bbb a,bbb b)
{
	return (a.x==b.x)? (a.y>b.y):(a.x<b.x);
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	dep[x]=d,siz[x]=1,fa[x]=f;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x,d+1),siz[x]+=siz[v];
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int f,int t)
{
	dfn[x]=(++dfn_t),top[x]=t;
	if(son[x])dfs1(son[x],x,t);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
			dfs1(v,x,v);
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	scanf("%d",&n),n2=(n<<1);
	for(int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]),res=(res*(len[i]=r[i]-l[i]+1))%mod,a[(i<<1)-1]=(bbb){l[i],1,i},a[i<<1]=(bbb){r[i],-1,i},Mx=max(Mx,r[i]);
	for(int i=1;i<=Mx;++i)inv[i]=Pow(i,mod-2);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0,0),dfs1(1,0,1),sort(a+1,a+(n<<1)+1,cmp);
	for(int i=1;i<=n;++i)ans=(ans+((inv[len[i]]*dep[i])%mod)*S1.query(1,1,Mx,l[i],r[i])+inv[len[i]]*S2.query(1,1,Mx,l[i],r[i]))%mod,S1.modify(1,1,Mx,l[i],r[i],inv[len[i]]),S2.modify(1,1,Mx,l[i],r[i],inv[len[i]]*dep[i]);
	for(int i=1;i<=Mx;++i)
	{
		for(;t<=n2 && a[t].x==i && a[t].y>0;++t)
		{
			res1=(res1+(S.query(1,1,n,1,1)*inv[len[a[t].z]]<<1))%mod;
			for(int j=a[t].z;j;j=fa[top[j]])res1=(res1-(S.query(1,1,n,dfn[top[j]],dfn[j])*inv[len[a[t].z]]<<1))%mod,S.modify(1,1,n,dfn[top[j]],dfn[j],inv[len[a[t].z]]);
		}
		for(ans=(ans+res1)%mod;t<=n2 && a[t].x==i;++t)
		{
			for(int j=a[t].z;j;j=fa[top[j]])S.modify(1,1,n,dfn[top[j]],dfn[j],-inv[len[a[t].z]]),res1=(res1+(S.query(1,1,n,dfn[top[j]],dfn[j])*inv[len[a[t].z]]<<1))%mod;
			res1=(res1-(S.query(1,1,n,1,1)*inv[len[a[t].z]]<<1))%mod;
		}
	}
	return 0&printf("%lld",((ans*res)%mod+mod)%mod);
}