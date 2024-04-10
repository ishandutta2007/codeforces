#include<bits/stdc++.h>
using namespace std;
int n,las,edge_t,Test_num;
int la[100002],rt[100002];
int dp[100002][2],top[100002][2];
struct aaa
{
	int to,nx;
	bool u;
}edge[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void init()
{
	edge_t=1,las=2;
	for(int i=1;i<=n;++i)la[i]=0,rt[i]=top[i][0]=top[i][1]=i;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x],0},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs(int x,int f)
{
	int mx=0,mx1=0,num=0,num1=0,res=0;dp[x][0]=dp[x][1]=0;
	for(int i=la[x],v,t;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x),res+=dp[v][0],t=dp[v][1]-dp[v][0]+1;
			if(t>mx)mx1=mx,num1=num,mx=t,num=v;else if(t>mx1)mx1=t,num1=v;
		}
	dp[x][1]=res+mx,dp[x][0]=res+mx+mx1;
	for(int i=la[x],v,t;i;i=edge[i].nx)
		if(((v=edge[i].to)!=f) && (v==num || v==num1))
		{
			edge[i].u=edge[i^1].u=1,getroot(x),getroot(v);
			if(top[rt[x]][0]==x)
			{
				if(top[rt[v]][0]==v)top[rt[v]][0]=top[rt[x]][1];
				else top[rt[v]][1]=top[rt[x]][1];
			}
			else
			{
				if(top[rt[v]][0]==v)top[rt[v]][0]=top[rt[x]][0];
				else top[rt[v]][1]=top[rt[x]][0];
			}
			rt[rt[x]]=rt[v];
		}
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),init();
		for(int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
		dfs(1,0),printf("%d\n",n-1-dp[1][0]),getroot(1);
		for(int i=2;i<=edge_t;i+=2)
			if(!edge[i].u)
			{
				printf("%d %d ",edge[i^1].to,edge[i].to);
				while(1)
				{
					getroot(las);
					if(rt[las]!=rt[1])break;
					++las;
				}
				printf("%d %d\n",top[rt[las]][0],top[rt[1]][0]),top[rt[1]][0]=top[rt[las]][1],rt[rt[las]]=rt[1];
			}
	}
	return 0;
}