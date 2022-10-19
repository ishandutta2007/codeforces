#include<cstdio>
int n,edge_t,Test_num,mn,num1,num2;
int la[100002],siz[100002],mx[100002],from[100002];
struct aaa
{
	int to,nx;
}edge[200002];
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	siz[x]=1,mx[x]=0;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x),siz[x]+=siz[v];
			if(siz[v]>mx[x])mx[x]=siz[v],from[x]=v;
		}
	if(n-siz[x]>mx[x])mx[x]=n-siz[x],from[x]=f;
	if(mx[x]<mn)mn=mx[x],num1=x,num2=0;
	else if(mx[x]==mn)num2=x;
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d",&n),edge_t=0,mn=n;
		for(int i=1;i<=n;++i)la[i]=0;
		for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
		dfs(1,1);
		if(!num2)printf("%d %d\n%d %d\n",num1,from[num1],num1,from[num1]);
		else
		{
			for(int i=la[num1];i;i=edge[i].nx)
				if(edge[i].to!=num2)
				{
					printf("%d %d\n%d %d\n",num1,edge[i].to,edge[i].to,num2);
					break;
				}
		}
	}
	return 0;
}