#include<cstdio>
#include<vector>
using namespace std;
int n,m,edge_t=1,cnt=0,cnt1,s,q_t,ok;
int la[3008]={},la1[3008],deg[3008]={},d[3008],q[3008];
vector<int> ans;
struct aaa
{
	int to,nx,vis;
}edge[6008];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x],0},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t,++deg[y];
}
inline void dfs(int x)
{
	for(int i=la1[x],v;i;i=edge[i].nx)
		if(!edge[i].vis && d[v=edge[i].to])
			la1[x]=edge[i].nx,--d[x],--d[v],edge[i].vis=edge[(i^1)].vis=1,dfs(v);
	q[q_t]=x,--q_t;
}
inline void copy(int i)
{
	int v;
	for(int j=1;j<=edge_t;++j)edge[j].vis=0;
	for(int j=1;j<=n;++j)d[j]=deg[j],la1[j]=la[j];
	ok=(d[i]&1),cnt1=cnt-ok;
	for(int j=la[i];j;j=edge[j].nx)
		if(d[v=edge[j].to]&1)
			--d[i],--d[v],--cnt1,edge[j].vis=edge[(j^1)].vis=2;
}
inline bool work(int i)
{
	int v,w;s=i;
	for(int j=1;j<=n;++j)
		if(d[j] && j!=i)
		{
			s=j;
			if(d[j]&1)break;
		}
	if(!(d[s]&1))
	{
		for(int j=la[i];j;j=edge[j].nx)
			if(d[v=edge[j].to])
			{
				s=v;
				break;
			}
	}
	q_t=m,dfs(s);
	if(q_t+1==cnt-ok-cnt1)
	{
		ans.clear();
		for(int j=q_t+1;j<=m;++j)ans.push_back(q[j]);
		if((w=q[m])!=i)
		{
			q_t=0,ans.push_back(i);
			for(int j=la[w];j;j=edge[j].nx)
				if((v=edge[j].to)==i)
				{
					if(edge[j].vis==1)return 0;
					edge[j].vis=edge[(j^1)].vis=1;
					break;
				}
		}
		ans.push_back(-1);
		for(int j=la[i];j;j=edge[j].nx)
			if(edge[j].vis==2)
				ans.push_back(edge[j].to),ans.push_back(i);
		printf("%d\n",ans.size());
		for(int j=0;j<ans.size();++j)printf("%d ",ans[j]);
		return 1;
	}
	return 0;
}
int main()
{
	read(n),read(m);
	for(int i=1,x,y;i<=m;++i)read(x),read(y),add_edge(x,y);
	for(int i=1;i<=n;++i)if(deg[i]&1)++cnt;
	if(cnt<=2)
	{
		for(int i=1;i<=n;++i)d[i]=deg[i],la1[i]=la[i];
		for(int i=1;i<=n;++i)
			if(d[i])
			{
				s=i;
				if(d[i]&1)break;
			}
		q_t=m,dfs(s),printf("%d\n",m+1);
		for(int i=0;i<=m;++i)printf("%d ",q[i]);
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		copy(i);
		if(cnt1<=1)
		{
			if(work(i))return 0;
			for(int j=la[i];j;j=edge[j].nx)
				if(deg[edge[j].to]&1)
				{
					copy(i),++cnt1,edge[j].vis=edge[(j^1)].vis=0;
					++d[i],++d[edge[j].to];
					if(work(i))return 0;
				}
		}
	}
	return 0&puts("0");
}