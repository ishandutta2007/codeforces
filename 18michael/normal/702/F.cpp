#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int c[200002],q[200002],id[200002],fa[200002],mx[200002],lazval[200002],lazans[200002];
int son[200002][2];
struct aaa
{
	int val,id,ans;
}b[200002];
inline bool cmp(int x,int y)
{
	return q[x]==q[y]? (c[x]<c[y]):(q[x]>q[y]);
}
inline bool cmp1(aaa a,aaa b)
{
	return a.val==b.val? (a.id<b.id):(a.val<b.val);
}
inline bool cmp2(aaa a,aaa b)
{
	return a.id<b.id;
}
inline bool Get(int x)
{
	return x==son[fa[x]][1];
}
inline void add(int x,int v,int a)
{
	if(x)b[x].val+=v,b[x].ans+=a,lazval[x]+=v,lazans[x]+=a,mx[x]+=v;
}
inline void PushDown(int x)
{
	if(x)add(son[x][0],lazval[x],lazans[x]),add(son[x][1],lazval[x],lazans[x]),lazval[x]=lazans[x]=0;
}
inline void Update(int x)
{
	if(x && fa[x])Update(fa[x]);
	PushDown(x);
}
inline void PushUp(int x)
{
	if(x)
	{
		mx[x]=b[x].val;
		if(son[x][0])mx[x]=max(mx[x],mx[son[x][0]]);
		if(son[x][1])mx[x]=max(mx[x],mx[son[x][1]]);
	}
}
inline void Rotate(int x)
{
	int y=fa[x],gx=Get(x),gy=Get(y),z=son[x][gx^1],w=fa[y];
	fa[x]=w,son[w][gy]=x,fa[y]=x,son[x][gx^1]=y,fa[z]=y,son[y][gx]=z,PushUp(y),PushUp(x);
}
inline void Splay(int x)
{
	for(Update(x);x && fa[x];Rotate(x))if(fa[x] && fa[fa[x]])Rotate(Get(x)==Get(fa[x])? fa[x]:x);
}
inline int Build(int l,int r)
{
	if(l>r)return 0;
	if(l==r)return PushUp(l),l;
	int mid=((l+r)>>1);
	return PushUp(fa[son[mid][0]=Build(l,mid-1)]=fa[son[mid][1]=Build(mid+1,r)]=mid),mid;
}
inline int Find(int x,int y)
{
	for(Splay(x);x;)
	{
		PushDown(x);
		if(mx[son[x][0]]>=y)x=son[x][0];
		else if(b[x].val>=y)return Splay(x),x;
		else x=son[x][1];
	}
	return 0;
}
inline int ins(int x,int y)
{
	if(!x)return son[y][0]=son[y][1]=0,PushUp(y),y;
	PushDown(x);
	if(cmp1(b[y],b[x]))fa[son[x][0]=ins(son[x][0],y)]=x;
	else fa[son[x][1]=ins(son[x][1],y)]=x;
	return PushUp(x),x;
}
inline void dfs(int x,int z)
{
	if(!x)return ;
	PushDown(x),dfs(son[x][0],z),dfs(son[x][1],z),b[x].val-=z,++b[x].ans,Splay(t),fa[ins(t,x)]=0,Splay(t=x);
}
inline void dfs1(int x)
{
	if(!x)return ;
	PushDown(x),dfs1(son[x][0]),dfs1(son[x][1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&c[i],&q[i]),id[i]=i;
	scanf("%d",&m);
	for(int i=1;i<=m;++i)scanf("%d",&b[i].val),b[i].id=i;
	sort(id+1,id+n+1,cmp),sort(b+1,b+m+1,cmp1),Build(1,m);
	for(int i=1,x,z;i<=n;++i)
	{
		if(!(x=Find(1,c[id[i]])))continue;
		t=son[x][0],son[x][0]=fa[t]=0,PushUp(x);
		if(z=Find(x,c[id[i]]<<1))x=son[z][0],son[z][0]=fa[x]=0,PushUp(z),add(z,-c[id[i]],1);
		dfs(x,c[id[i]]),Splay(t),Update(z),PushUp(fa[son[z][0]=t]=z);
	}
	Splay(1),dfs1(1),sort(b+1,b+m+1,cmp2);
	for(int i=1;i<=m;++i)printf("%d ",b[i].ans);
	return 0;
}