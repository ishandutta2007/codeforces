#include<cstdio>
int n,m,q,t=0;
int rt[1000002];
int col[12][100002];
struct aaa
{
	int cnt,l,r;
	int L[12],R[12];
}arr[400002];
inline int num(int x,int y)
{
	return (x-1)*m+y;
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void create_point(int k,int l)
{
	arr[k].cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(i>1 && col[i][l]==col[i-1][l])arr[k].L[i]=arr[k].R[i]=arr[k].L[i-1];
		else arr[k].L[i]=arr[k].R[i]=(++t),++arr[k].cnt;
	}
}
inline aaa merge(aaa a,aaa b)
{
	aaa c;c.l=a.l,c.r=b.r,c.cnt=a.cnt+b.cnt;
	for(int i=1;i<=n;++i)rt[a.L[i]]=a.L[i],rt[a.R[i]]=a.R[i],rt[b.L[i]]=b.L[i],rt[b.R[i]]=b.R[i];
	for(int i=1,x,y;i<=n;++i)
		if(col[i][a.r]==col[i][b.l])
		{
			getroot(x=a.R[i]),getroot(y=b.L[i]);
			if(rt[x]!=rt[y])rt[rt[x]]=rt[y],--c.cnt;
		}
	for(int i=1,x,y;i<=n;++i)getroot(x=a.L[i]),getroot(y=b.R[i]),c.L[i]=rt[x],c.R[i]=rt[y];
	return c;
}
inline void build(int k,int l,int r)
{
	if(l==r){create_point(k,l),arr[k].l=l,arr[k].r=r;return ;}
	int ls=lson(k),rs=rson(k),mid=((l+r)>>1);
	build(ls,l,mid),build(rs,mid+1,r),arr[k]=merge(arr[ls],arr[rs]);
}
inline aaa query(int k,int l,int r,int l1,int r1)
{
	if(l>=l1 && r<=r1)return arr[k];
	int ls=lson(k),rs=rson(k),mid=((l+r)>>1);
	if(r1<=mid)return query(ls,l,mid,l1,r1);
	if(l1>mid)return query(rs,mid+1,r,l1,r1);
	return merge(query(ls,l,mid,l1,mid),query(rs,mid+1,r,mid+1,r1));
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&col[i][j]);
	build(1,1,m);
	for(int x,y;q--;)scanf("%d%d",&x,&y),printf("%d\n",query(1,1,m,x,y).cnt);
	return 0;
}