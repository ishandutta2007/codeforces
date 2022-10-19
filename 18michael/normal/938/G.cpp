#include<bits/stdc++.h>
#define Mx 29
using namespace std;
int n,m,q,tot;
int O[200002],X[200002],Y[200002],rt[200002],siz[200002],val[400002],fa[400002],sum[400002];
bool laz[400002];
int son[400002][2];
typedef pair<int,int> P;
map<P,P> mp;
map<P,P>::iterator it;
struct aaa
{
	int x,y,z;
};
vector<aaa> vec[800002];
struct bbb
{
	int x,y,rx,ry;
};
vector<bbb> Vec[22];
struct ccc
{
	int a[32];
	inline void ins(int x)
	{
		for(int i=Mx;~i;--i)
			if((x>>i)&1)
			{
				if(!a[i])return (void)(a[i]=x);
				x^=a[i];
			}
	}
	inline int query(int x)
	{
		for(int i=Mx;~i;--i)if((x>>i)&1)x^=a[i];
		return x;
	}
}V[22];
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
	if(x)sum[x]=(sum[son[x][0]]^sum[son[x][1]]^val[x]);
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
	laz[Access(x)]^=1;
}
inline void Link(int x,int y)
{
	MakeRoot(x),Splay(x),fa[x]=y;
}
inline void Cut(int x,int y)
{
	MakeRoot(x),Access(y),Splay(y),fa[x]=son[y][0]=0,PushUp(y);
}
inline int Query(int x,int y)
{
	return MakeRoot(x),Access(y),Splay(y),sum[y];
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void ins(int k,int l,int r,int l1,int r1,aaa a)
{
	if(l>=l1 && r<=r1)return vec[k].push_back(a);
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	if(l1<=mid)ins(ls,l,mid,l1,r1,a);
	if(r1>mid)ins(rs,mid+1,r,l1,r1,a);
}
inline int getroot(int x)
{
	return x==rt[x]? x:getroot(rt[x]);
}
inline void undo(int d)
{
	for(;Vec[d].size();Vec[d].pop_back())Cut(Vec[d].back().x,tot),Cut(Vec[d].back().y,tot),--tot,siz[Vec[d].back().ry]-=siz[Vec[d].back().rx],rt[Vec[d].back().rx]=Vec[d].back().rx;
}
inline void solve(int k,int l,int r,int d)
{
	V[d]=V[d-1];
	for(int i=0,x,y,rx,ry;i<vec[k].size();++i)
	{
		if((rx=getroot(x=vec[k][i].x))==(ry=getroot(y=vec[k][i].y)))V[d].ins(Query(x,y)^vec[k][i].z);
		else
		{
			if(siz[rx]>siz[ry])swap(rx,ry);
			val[++tot]=vec[k][i].z,Link(x,tot),Link(y,tot),siz[ry]+=siz[rx],rt[rx]=ry,Vec[d].push_back((bbb){x,y,rx,ry});
		}
	}
	if(l==r)
	{
		if(O[l]==3)printf("%d\n",V[d].query(Query(X[l],Y[l])));
		return undo(d);
	}
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	solve(ls,l,mid,d+1),solve(rs,mid+1,r,d+1),undo(d);
}
int main()
{
	scanf("%d%d",&n,&m),tot=n;
	for(int i=1;i<=n;++i)rt[i]=i,siz[i]=1;
	for(int i=1,x,y,z;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x>y)swap(x,y);
		mp[P(x,y)]=P(z,1);
	}
	scanf("%d",&q);
	for(int i=1,x;i<=q;++i)
	{
		scanf("%d%d%d",&O[i],&X[i],&Y[i]);
		if(X[i]>Y[i])swap(X[i],Y[i]);
		if(O[i]==1)scanf("%d",&x),mp[P(X[i],Y[i])]=P(x,i);
		else if(O[i]==2)ins(1,1,q,mp[P(X[i],Y[i])].second,i,(aaa){X[i],Y[i],mp[P(X[i],Y[i])].first}),mp.erase(P(X[i],Y[i]));
	}
	for(it=mp.begin();it!=mp.end();++it)ins(1,1,q,(*it).second.second,q,(aaa){(*it).first.first,(*it).first.second,(*it).second.first});
	return solve(1,1,q,1),0;
}