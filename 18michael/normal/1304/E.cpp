#include<cstdio>
#define Mx 18
int n,edge_t=0,Test_num;
int la[100002]={},dep[100002]={};
int fa[100002][20]={};
struct aaa
{
	int to,nx;
}edge[200002];
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	fa[x][0]=f,dep[x]=d;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1);
}
inline void getfa()
{
	for(int i=1;i<=Mx;++i)
		for(int j=1;j<=n;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)
		if(dep[fa[x][i]]>dep[y])
			x=fa[x][i];
	if(dep[x]>dep[y])x=fa[x][0];
	if(x==y)return x;
	for(int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline int dis(int a,int b)
{
	int c=LCA(a,b);
	return dep[a]+dep[b]-2*dep[c];
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,1,1),getfa(),scanf("%d",&Test_num);
	for(int x,y,a,b,k,D;Test_num--;)
	{
		scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		if(((D=dis(a,b))&1)==(k&1) && D<=k)puts("YES");
		else if(((D=dis(a,x)+1+dis(y,b))&1)==(k&1) && D<=k)puts("YES");
		else if(((D=dis(a,y)+1+dis(x,b))&1)==(k&1) && D<=k)puts("YES");
		else puts("NO");
	}
	return 0;
}