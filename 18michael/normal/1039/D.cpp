#include<cstdio>
#include<cstring>
#include<cmath>
#define R register
int n,edge_t=0,sq;
int la[100002]={},ans[100002],mx[100002];
struct aaa
{
	int to,nx;
}edge[200002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch;do ch=getchar(),f|=(ch=='-');while(ch<'0' || ch>'9');
	do x=(x<<3)+(x<<1)+(ch^48),ch=getchar();while(ch>='0' && ch<='9');
	x=f? -x:x;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int y,int &r)
{
	mx[x]=0;
	for(R int i=la[x],d;i;i=edge[i].nx)
	{
		d=edge[i].to;
		if(d!=f)
		{
			dfs(d,x,y,r);
			if(mx[x]!=-1)
			{
				if(mx[x]+mx[d]+1>=y)++r,mx[x]=-1;
				else mx[x]=max(mx[x],mx[d]);
			}
		}
	}
	if((++mx[x])>=y)++r,mx[x]=0;
}
inline void Solve(int x)
{
	if(ans[x]==-1)dfs(1,0,x,(ans[x]=0));
}
inline void Binary_work(int l,int r,int l1,int r1)
{
	if(l+1>=r)return ;
	if(l1==r1){for(int i=l+1;i<r;++i)ans[i]=ans[l];return ;}
	int mid=((l+r)>>1);
	Solve(mid),Binary_work(l,mid,l1,ans[mid]),Binary_work(mid,r,ans[mid],r1);
}
int main()
{
	memset(ans,-1,sizeof(ans)),read(n),sq=sqrt(n);
	for(R int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
	for(R int i=1;i<=sq;++i)Solve(i);
	Solve(n),Binary_work(1,n,(ans[1]=n),ans[n]);
	for(R int i=1,j;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}