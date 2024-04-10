#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,cnt;
int X[300002],Y[300002],Z[300002],mx[400002],siz[400002],siz2[400002],fa[400002],val[400002];
int son[400002][2];
bool laz[400002];
struct aaa
{
	int id;
	inline bool operator < (const aaa &a) const
	{
		return Z[id]==Z[a.id]? (id>a.id):(Z[id]>Z[a.id]);
	}
};
multiset<aaa> ms;
multiset<aaa>::iterator it;
inline bool Odd(int x)
{
	return (((siz[x]+1)>>1)&1);
}
inline bool IsRoot(int x)
{
	return (!x || (x!=son[fa[x]][0] && x!=son[fa[x]][1]));
}
inline bool Get(int x)
{
	return x==son[fa[x]][1];
}
inline void PushUp(int x)
{
	if(x)
	{
		siz[x]=siz[son[x][0]]+siz[son[x][1]]+siz2[x]+1,mx[x]=x;
		if(son[x][0] && val[mx[son[x][0]]]>val[mx[x]])mx[x]=mx[son[x][0]];
		if(son[x][1] && val[mx[son[x][1]]]>val[mx[x]])mx[x]=mx[son[x][1]];
	}
}
inline void PushDown(int x)
{
	if(x && laz[x])swap(son[x][0],son[x][1]),laz[son[x][0]]^=1,laz[son[x][1]]^=1,laz[x]=0;
}
inline void Update(int x)
{
	if(!IsRoot(x))Update(fa[x]);
	PushDown(x);
}
inline void Rotate(int x)
{
	int y=fa[x],w=fa[y],gx=Get(x),gy=Get(y),z=son[x][gx^1];
	if(!IsRoot(y))son[w][gy]=x;
	fa[x]=w,fa[y]=x,son[x][gx^1]=y,fa[z]=y,son[y][gx]=z,PushUp(y),PushUp(x);
}
inline void Splay(int x)
{
	for(Update(x);!IsRoot(x);Rotate(x))if(!IsRoot(fa[x]))Rotate(Get(x)==Get(fa[x])? fa[x]:x);
}
inline int Access(int x)
{
	int p;
	for(p=0;x;p=x,x=fa[x])Splay(x),siz2[x]+=siz[son[x][1]]-siz[p],son[x][1]=p,PushUp(x);
	return p;
}
inline void MakeRoot(int x)
{
	laz[Access(x)]^=1,Splay(x);
}
inline void Cut(int x,int y,int id)
{
	MakeRoot(x),cnt-=Odd(x);
	MakeRoot(x),Access(id+n),Splay(id+n),son[id+n][0]=fa[x]=0,PushUp(id+n);
	MakeRoot(y),Access(id+n),Splay(id+n),son[id+n][0]=fa[y]=0,PushUp(id+n);
	MakeRoot(x),cnt+=Odd(x);
	MakeRoot(y),cnt+=Odd(y);
}
inline int FindRoot(int x)
{
	for(PushDown(x);;x=son[x][0],PushDown(x))
		if(!son[x][0])
		{
			Splay(x);
			return x;
		}
}
inline void Link(int x,int y,int z,int id)
{
	MakeRoot(x),Access(y),Splay(y);
	if(FindRoot(y)==x)
	{
		Splay(y);
		if(val[mx[y]]<=z)
		{
			ms.erase(ms.lower_bound((aaa){id}));
			return ;
		}
		ms.erase(ms.lower_bound((aaa){mx[y]-n})),Cut(X[mx[y]-n],Y[mx[y]-n],mx[y]-n);
	}
	MakeRoot(x),cnt-=Odd(x);
	MakeRoot(y),cnt-=Odd(y);
	MakeRoot(x),MakeRoot(id+n),fa[x]=id+n,siz2[id+n]+=siz[x],PushUp(id+n);
	MakeRoot(y),MakeRoot(id+n),fa[y]=id+n,siz2[id+n]+=siz[y],PushUp(id+n);
	MakeRoot(x),cnt+=Odd(x);
}
int main()
{
	scanf("%d%d",&n,&m),cnt=n;
	for(int i=1;i<=n;++i)val[i]=-inf;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&X[i],&Y[i],&Z[i]),val[n+i]=Z[i],ms.insert((aaa){i}),Link(X[i],Y[i],Z[i],i);
		for(it=ms.begin();it!=ms.end();it=ms.erase(it))
		{
			Cut(X[(*it).id],Y[(*it).id],(*it).id);
			if(cnt)
			{
				Link(X[(*it).id],Y[(*it).id],Z[(*it).id],(*it).id);
				break;
			}
		}
		printf("%d\n",cnt? -1:Z[(*ms.begin()).id]);
	}
	return 0;
}