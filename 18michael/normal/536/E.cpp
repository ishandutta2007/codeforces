#include<bits/stdc++.h>
using namespace std;
int n,q;
int X[100002],Y[100002],Z[100002],id[100002],fa[200002],ans[100002],f[200002];
bool laz[200002],val[200002];
int son[200002][2];
struct aaa
{
	int x,y,z,id;
}a[200002];
struct bbb
{
	int l,r,sum;
	bool o;
}b[200002];
inline bool cmp(aaa a,aaa b)
{
	return a.z==b.z? (a.id<b.id):(a.z<b.z);
}
inline bbb merge(bbb a,bbb b,bool x)
{
	bbb c;
	c.sum=a.sum+b.sum;
	if(c.o=(a.o&b.o))
	{
		if(c.o&=x)c.l=c.r=a.l+b.l+1;
		else c.l=a.l,c.r=b.l;
	}
	else if(a.o)c.l=(x? a.l+1+b.l:a.l),c.r=b.r,c.sum+=(x? 0:f[b.l]);
	else if(b.o)c.l=a.l,c.r=(x? a.r+1+b.r:b.r),c.sum+=(x? 0:f[a.r]);
	else c.l=a.l,c.r=b.r,c.sum+=(x? f[a.r+b.l+1]:f[a.r]+f[b.l]);
	return c;
}
inline bool IsRoot(int x)
{
	return x!=son[fa[x]][0] && x!=son[fa[x]][1];
}
inline bool Get(int x)
{
	return x==son[fa[x]][1];
}
inline void PushUp(int x)
{
	if(x)b[x]=merge(b[son[x][0]],b[son[x][1]],val[x]);
}
inline void Reverse(int x)
{
	if(x)laz[x]^=1,swap(b[x].l,b[x].r);
}
inline void PushDown(int x)
{
	if(x && laz[x])Reverse(son[x][0]),Reverse(son[x][1]),swap(son[x][0],son[x][1]),laz[x]=0;
}
inline void Update(int x)
{
	if(!IsRoot(x))Update(fa[x]);
	PushDown(x);
}
inline void Rotate(int x)
{
	int y=fa[x],gx=Get(x),gy=Get(y),z=son[x][gx^1],w=fa[y];
	if(!IsRoot(y))son[w][gy]=x;
	fa[x]=w,son[x][gx^1]=y,fa[y]=x,son[y][gx]=z,fa[z]=y,PushUp(y),PushUp(x);
}
inline void Splay(int x)
{
	for(Update(x);!IsRoot(x);Rotate(x))if(!IsRoot(fa[x]))Rotate(Get(x)==Get(fa[x])? fa[x]:x);
}
inline int Access(int x)
{
	int p;
	for(p=0;x;x=fa[p=x])Splay(x),son[x][1]=p,PushUp(x);
	return p;
}
inline void MakeRoot(int x)
{
	Reverse(Access(x)),Splay(x);
}
inline void Link(int x,int y)
{
	MakeRoot(x),fa[x]=y;
}
int main()
{
	scanf("%d%d",&n,&q),b[0].o=1;
	for(int i=1;i<=n;++i)val[i]=val[n+i]=1;
	for(int i=1;i<n;++i)scanf("%d",&f[(i<<1)+1]);
	for(int i=1;i<n;++i)scanf("%d%d%d",&a[q+i].x,&a[q+i].y,&a[q+i].z),Link(a[q+i].x,n+i),Link(a[q+i].y,n+i),a[q+i].id=q+i;
	for(int i=1;i<=q;++i)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),a[i].id=i;
	sort(a+1,a+n+q,cmp);
	for(int i=1,x,y;i<n+q;++i)
	{
		x=a[i].x,y=a[i].y;
		if(a[i].id<=q)MakeRoot(x),Access(y),Splay(y),ans[a[i].id]=(b[y].o? f[b[y].l]:b[y].sum+f[b[y].l]+f[b[y].r]);
		else a[i].id+=n-q,MakeRoot(a[i].id),val[a[i].id]=0,PushUp(a[i].id);
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}