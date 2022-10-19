#include<bits/stdc++.h>
#define Mx 16
#define sq 316
#define eps 1e-9
using namespace std;
int n,w,q;
int a[100002],k[100002],id[100002],fa[100002],siz[100002],mx[100002],ans[100002],to[100002],ed[100002];
int mna[18][100002],mxa[18][100002],son[100002][2];
vector<int> vec[100002];
inline bool cmp(int x,int y)
{
	return k[x]<k[y];
}
inline int get(int x,int y)
{
	int len=log2(y-x+1)+eps;
	return max(mxa[len][x],mxa[len][y-(1<<len)+1])-min(mna[len][x],mna[len][y-(1<<len)+1]);
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
	if(x)siz[x]=siz[son[x][0]]+siz[son[x][1]]+1,mx[x]=max(x,max(mx[son[x][0]],mx[son[x][1]]));
}
inline void Rotate(int x)
{
	int y=fa[x],gx=Get(x),gy=Get(y),z=son[x][gx^1],w=fa[y];
	if(!IsRoot(y))son[w][gy]=x;
	fa[x]=w,son[x][gx^1]=y,fa[y]=x,son[y][gx]=z,fa[z]=y,PushUp(y),PushUp(x);
}
inline void Splay(int x)
{
	for(;!IsRoot(x);Rotate(x))if(!IsRoot(fa[x]))Rotate(Get(x)==Get(fa[x])? fa[x]:x);
}
inline int Access(int x)
{
	int p;
	for(p=0;x;x=fa[p=x])Splay(x),son[x][1]=p,PushUp(x);
	return p;
}
inline int FindRoot(int x)
{
	for(Splay(x);son[x][0];x=son[x][0]);
	return Splay(x),x;
}
inline void Link(int x,int y)
{
	Access(x),Splay(x),fa[x]=y;
}
inline void Cut(int x,int y)
{
	Access(x),Splay(y),son[y][1]=fa[x]=0,PushUp(y);
}
inline int findk(int x)
{
	int l=1,r=q,mid;
	for(;l<=r;)
	{
		mid=((l+r)>>1);
		if(k[id[mid]]<x)l=mid+1;
		else r=mid-1;
	}
	return l;
}
inline int find(int x,int y)
{
	int l=x,r=n,mid;
	for(;l<=r;)
	{
		mid=((l+r)>>1);
		if(get(x,mid)<=y)l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main()
{
	scanf("%d%d%d",&n,&w,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),mna[0][i]=mxa[0][i]=a[i];
	for(int i=1;i<=q;++i)scanf("%d",&k[i]),k[i]=w-k[i],id[i]=i;
	sort(id+1,id+q+1,cmp);
	for(int i=1;i<=Mx;++i)for(int j=1;j+(1<<i)-1<=n;++j)mna[i][j]=min(mna[i-1][j],mna[i-1][j+(1<<(i-1))]),mxa[i][j]=max(mxa[i-1][j],mxa[i-1][j+(1<<(i-1))]);
	for(int i=1,x,y;i<=n;++i)
	{
		x=y=a[i],Link(i,to[i]=i+1),ed[i]=min(i+sq,n);
		for(int j=i+1;j<=ed[i];++j)x=max(x,a[j]),y=min(y,a[j]),vec[findk(x-y)].push_back(i);
	}
	for(int i=1,x;i<=q;++i)
	{
		for(int j=0;j<vec[i].size();++j)
		{
			Cut(vec[i][j],to[vec[i][j]]);
			if((++to[vec[i][j]])<=ed[vec[i][j]])Link(vec[i][j],to[vec[i][j]]);
		}
		for(int j=1;j<=n;)
		{
			if(to[j]<=ed[j])Access(j),x=FindRoot(j),ans[id[i]]+=siz[j=x]-1;
			else j=find(j,k[id[i]]),++ans[id[i]];
		}
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]-1);
	return 0;
}