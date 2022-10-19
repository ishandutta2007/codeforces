#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Test_num,n,m,edge_t,mx,now;
int ans[500002];
struct aaa
{
	int to,nx;
}edge[2000002];
struct bbb
{
	int la,dep,fa,num;
	bool u;
}p[2000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(bbb a,bbb b)
{
	return a.dep<b.dep? 1:0;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,p[x].la},p[x].la=edge_t;
	edge[++edge_t]=(aaa){x,p[y].la},p[y].la=edge_t;
}
inline void init()
{
	edge_t=mx=0,read(n),read(m);
	for(int i=1;i<=n;++i)p[i].num=i,p[i].la=p[i].u=0;
	for(int i=1,x,y;i<=m;++i)read(x),read(y),add_edge(x,y);
}
inline void dfs(int x,int f,int d)
{
	if(d>mx)mx=d,now=x;
	p[x].u=1,p[x].dep=d,p[x].fa=f;
	for(int i=p[x].la,j;i;i=edge[i].nx)
		if(!p[j=edge[i].to].u)dfs(j,x,d+1);
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		init(),dfs(1,0,1);
		if(mx>=((n+1)/2))
		{
			printf("PATH\n%d\n",mx);
			while(now)printf("%d ",now),now=p[now].fa;
			puts("");
		}
		else
		{
			sort(p+1,p+n+1,cmp),mx=0;
			for(int i=1;i<=n;++i)
			{
				now=i;
				while(now<n && p[now].dep==p[now+1].dep)ans[++mx]=p[now++].num,ans[++mx]=p[now++].num;
				i=now;
			}
			printf("PAIRING\n%d\n",mx/2);
			for(int i=1;i<=mx;i+=2)
				printf("%d %d\n",ans[i],ans[i+1]);
		}
	}
	return 0;
}