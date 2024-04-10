#include<cstdio>
#define inf 0x3f3f3f3f
int n,edge_t=0,num,Mx,Mx1,s1,s2;
int la[200002]={},dep[200002],deg[200002]={};
struct aaa
{
	int to,nx;
}edge[400002];
struct bbb
{
	int val,num;
}mx[200002],se[200002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t,++deg[y];
}
inline void dfs(int x,int f,int d)
{
	dep[x]=d,mx[x].val=-inf,se[x].val=-inf;
	if(deg[x]>=3 && dep[x]>Mx)Mx=dep[x],num=x,Mx1=0;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x,d+1),++mx[v].val,++se[v].val;
			if(mx[v].val>mx[x].val)
			{
				if(mx[x].val>se[x].val)se[x]=mx[x];
				if(se[v].val>se[x].val)se[x]=se[v];
				mx[x]=mx[v];
			}
			else if(mx[v].val>se[x].val)se[x]=mx[v];
		}
	if(deg[x]>=2 && dep[x]==Mx && mx[x].val+se[x].val>Mx1)num=x,Mx1=mx[x].val+se[x].val;
	if(mx[x].val==-inf)mx[x].val=0,mx[x].num=x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0,Mx=0),s1=mx[num].num,s2=se[num].num,dfs(num,0,Mx=0),printf("%d %d\n%d %d\n",s1,mx[num].num,s2,se[num].num);
	return 0;
}