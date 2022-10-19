#include<bits/stdc++.h>
using namespace std;
int n,t,cnt,edge_t,Test_num;
char ch;
int la[2000002],deg[2000002];
vector<int> vec;
struct aaa
{
	int to,nx;
}edge[4000002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t,++deg[y];
}
inline void dfs(int x,int f,int c)
{
	if(x==vec[1])return (void)(puts(c? "Draw":"White"));
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dfs(v,x,c^1);
}
inline void solve()
{
	scanf("%d",&n),t=n,edge_t=0,vec.clear();
	for(int i=1;i<=n;++i)la[i]=deg[i]=0;
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;++i)
	{
		do ch=getchar();while(ch!='N' && ch!='W');
		if(ch=='W')la[t+1]=la[t+2]=la[t+3]=deg[t+1]=deg[t+2]=deg[t+3]=0,add_edge(i,t+1),add_edge(t+1,t+2),add_edge(t+1,t+3),t+=3;
	}
	for(int i=1;i<=t;++i)if(deg[i]>3)return (void)(puts("White"));
	for(int i=1;i<=t;++i)
		if(deg[i]==3)
		{
			vec.push_back(i),cnt=0;
			for(int j=la[i];j;j=edge[j].nx)cnt+=(deg[edge[j].to]>1);
			if(cnt>1)return (void)(puts("White"));
		}
	if(vec.size()==2)return dfs(vec[0],0,0);
	puts("Draw");
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)solve();
	return 0;
}