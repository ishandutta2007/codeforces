#include<cstdio>
#include<ctime>
#include<cstdlib>
#define R register
#define Mx 18
#define LL long long
const LL mod=(1LL<<60);
int n,q,edge_t=0,t=0;
int a[300002],la[300002]={},rt[300002],dep[300002];
LL val[300002];
int fa[300002][22];
struct aaa
{
	int to,nx;
}edge[600002];
struct bbb
{
	int lson,rson;
	LL val;
}arr[9600002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void write(int x)
{
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
inline bool cmp(int x,int y)
{
	return a[x]<a[y]? 1:0;
}
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline LL RND()
{
	LL res=rand();
	res*=rand(),res+=rand(),res*=rand(),res+=rand(),res*=rand(),res+=rand(),res%=mod;
	return (res+mod)%mod;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline int build(int l,int r)
{
	if(l==r){arr[++t]=(bbb){0,0,0};return t;}
	int mid=((l+r)>>1),k=(++t);
	arr[k]=(bbb){build(l,mid),build(mid+1,r),0};
	return k;
}
inline int modify(int now,int l,int r,int x)
{
	if(l==r){arr[++t]=(bbb){0,0,(arr[now].val^val[x])};return t;}
	int mid=((l+r)>>1),k=(++t),ls,rs;
	if(x<=mid)ls=arr[k].lson=modify(arr[now].lson,l,mid,x),rs=arr[k].rson=arr[now].rson;
	else ls=arr[k].lson=arr[now].lson,rs=arr[k].rson=modify(arr[now].rson,mid+1,r,x);
	arr[k].val=(arr[ls].val^arr[rs].val);return k;
}
inline LL query(int now,int l,int r,int l1,int r1)
{
	if(!now)return 0;
	if(l>=l1 && r<=r1)return arr[now].val;
	int mid=((l+r)>>1);
	if(r1<=mid)return query(arr[now].lson,l,mid,l1,r1);
	if(l1>mid)return query(arr[now].rson,mid+1,r,l1,r1);
	return (query(arr[now].lson,l,mid,l1,mid)^query(arr[now].rson,mid+1,r,mid+1,r1));
}
inline void dfs(int x,int f,int d)
{
	rt[x]=modify(rt[f],1,n,a[x]),fa[x][0]=f,dep[x]=d;
	for(R int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1);
}
inline void init()
{
	for(R int i=1;i<=Mx;++i)
		for(R int j=1;j<=n;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(R int i=Mx;~i;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(R int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline bool check(int u,int v,int l,int r)
{
	int w=LCA(u,v);LL res=(query(rt[u],1,n,l,r)^query(rt[v],1,n,l,r));
	if(a[w]>=l && a[w]<=r)res^=val[a[w]];return res? 1:0;
}
int main()
{
	srand(time(NULL)),read(n),read(q);
	for(R int i=1;i<=n;++i)read(a[i]),val[i]=RND();
	for(R int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
	rt[0]=build(1,n),dfs(1,0,1),init();
	for(R int u,v,l,r,mid;q--;)
	{
		read(u),read(v),read(l),read(r);
		if(!check(u,v,l,r)){puts("-1");continue;}
		while(l<r)
		{
			mid=((l+r)>>1);
			if(check(u,v,l,mid))r=mid;
			else l=mid+1;
		}
		write(l),putchar('\n');
	}
	return 0;
}