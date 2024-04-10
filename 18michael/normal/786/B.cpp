#include<cstdio>
#include<queue>
#include<vector>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,q,s,v,u,l,r,Mx,opt,edge_t=0;LL w;
int la[800002],num[800002];LL dis[800002];
typedef pair<LL,int> P;
priority_queue<P,vector<P>,greater<P> > pq;
struct aaa
{
	int to,nx;
	LL val;
}edge[3200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch;do ch=getchar(),f|=(ch=='-');while(ch<'0' || ch>'9');
	do x=(x<<3)+(x<<1)+(ch^48),ch=getchar();while(ch>='0' && ch<='9');
	x=f? -x:x;
}
inline void add_edge(int x,int y,LL w)
{
	edge[++edge_t]=(aaa){y,la[x],w},la[x]=edge_t;
}
inline void build(int k,int l,int r)
{
	add_edge(k,k+Mx,0);if(l==r){num[l]=k;return ;}
	int mid=((l+r)>>1),lson=(k<<1),rson=((k<<1)|1);
	add_edge(k,lson,0),add_edge(k,rson,0),add_edge(lson+Mx,k+Mx,0),add_edge(rson+Mx,k+Mx,0),build(lson,l,mid),build(rson,mid+1,r);
}
inline void add1(int k,int l,int r,int l1,int r1,int v,LL w)
{
	if(l>=l1 && r<=r1){add_edge(num[v]+Mx,k,w);return ;}
	int mid=((l+r)>>1),lson=(k<<1),rson=((k<<1)|1);
	if(r1<=mid)add1(lson,l,mid,l1,r1,v,w);
	else if(l1>mid)add1(rson,mid+1,r,l1,r1,v,w);
	else add1(lson,l,mid,l1,mid,v,w),add1(rson,mid+1,r,mid+1,r1,v,w);
}
inline void add2(int k,int l,int r,int l1,int r1,int v,LL w)
{
	if(l>=l1 && r<=r1){add_edge(k+Mx,num[v],w);return ;}
	int mid=((l+r)>>1),lson=(k<<1),rson=((k<<1)|1);
	if(r1<=mid)add2(lson,l,mid,l1,r1,v,w);
	else if(l1>mid)add2(rson,mid+1,r,l1,r1,v,w);
	else add2(lson,l,mid,l1,mid,v,w),add2(rson,mid+1,r,mid+1,r1,v,w);
}
inline void dijkstra(int s)
{
	fill(dis+1,dis+(Mx<<1)+1,inf),pq.push(P(dis[s]=0,s));
	while(!pq.empty())
	{
		P p=pq.top();pq.pop();int v=p.second;
		if(p.first>dis[v])continue;
		for(int i=la[v],u;i;i=edge[i].nx)
			if(dis[v]+edge[i].val<dis[u=edge[i].to])
				pq.push(P(dis[u]=dis[v]+edge[i].val,u));
	}
}
int main()
{
	read(n),read(q),read(s),Mx=(n<<2),build(1,1,n);
	for(int i=1;i<=q;++i)
	{
		read(opt);
		switch(opt)
		{
			case 1:read(v),read(u),read(w),add_edge(num[v]+Mx,num[u],w);break;
			case 2:read(v),read(l),read(r),read(w),add1(1,1,n,l,r,v,w);break;
			case 3:read(v),read(l),read(r),read(w),add2(1,1,n,l,r,v,w);break;
		}
	}
	dijkstra(num[s]);
	for(int i=1;i<=n;++i)printf("%lld%c",dis[num[i]+Mx]==inf? -1:dis[num[i]+Mx],i==n? '\n':' ');
	return 0;
}