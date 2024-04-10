#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,n1,p,edge_t=0;
int a[10000002],b[10000002],la[10000002]={},dis[10000002],from[10000002];
typedef pair<int,int> P;P pr;
priority_queue<P,vector<P>,greater<P> > pq;
vector<int> vec;
struct aaa
{
	int to,nx,val;
}edge[20000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y,int z)
{
	//printf("ADD %d %d %d\n",x,y,z);
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
}
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void build(int k,int l,int r)
{
	if(l==r){add_edge(2*n1+k,l,0);return ;}
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	add_edge(2*n1+k,2*n1+ls,0),add_edge(2*n1+k,2*n1+rs,0),build(ls,l,mid),build(rs,mid+1,r);
}
inline void add(int x,int k,int l,int r,int y,int z)
{
	if(l>=y && r<=z){add_edge(x,2*n1+k,1);return ;}
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	if(z<=mid)add(x,ls,l,mid,y,z);
	else if(y>mid)add(x,rs,mid+1,r,y,z);
	else add(x,ls,l,mid,y,mid),add(x,rs,mid+1,r,y,z);
}
inline bool dijkstra()
{
	for(int i=0;i<=6*n1;++i)dis[i]=inf;
	dis[n+n1]=0,pq.push(P(0,n+n1));
	while(!pq.empty())
	{
		pr=pq.top(),pq.pop();
		if(dis[p=pr.second]<pr.first)continue;
		//printf("dis[%d]=%d\n",p,dis[p]);
		for(int i=la[p],v;i;i=edge[i].nx)
			if(dis[v=edge[i].to]>dis[p]+edge[i].val)
				dis[v]=dis[p]+edge[i].val,from[v]=p,pq.push(P(dis[v],v));
	}
	return dis[0]!=inf;
}
int main()
{
	read(n),n1=n+1,build(1,0,n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(b[i]),add_edge(i,i+b[i]+n1,0);
	for(int i=1;i<=n;++i)add(i+n1,1,0,n,i-a[i],i);
	if(!dijkstra())puts("-1");
	else
	{
		printf("%d\n",dis[0]);
		for(int now=0;now!=n+n1;)
		{
			//while(dis[now]==dis[from[now]])now=from[now];
			if(now<=n1)vec.push_back(now);
			now=from[now];
		}
		for(int i=vec.size()-1;~i;--i)printf("%d ",vec[i]);
		//while(n)printf("%d ",n=from[n]);
	}
	return 0;
}