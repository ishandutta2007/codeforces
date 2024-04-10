// wtf??? 
#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n,m;
int a[1111111],b[1111111],c[1111111],d[1111111];
bool vis[1111111];
int h[1111111],tot;
struct edg
{int p,t;}e[1111111];
inline void ins(int x,int y)
{e[++tot]=(edg){h[x],y},h[x]=tot;}
inline void build(int x,int y)
{d[x]++,d[y]++,ins(x,y),ins(y,x);}
int stk[1111111],top;
inline void dfs(int p)
{
	vis[p]=1,stk[++top]=p;
	for(register int i=h[p];i;i=e[i].p)
		if(!vis[e[i].t])dfs(e[i].t);
}
int col[1111111];
inline bool color(int p,int cl=1)
{
	if(col[p])
	{if(col[p]^cl)return 0;return 1;}
	col[p]=cl;
	for(register int i=h[p];i;i=e[i].p)
		if(!color(e[i].t,-cl))return 0;
	return 1;
}
inline bool solve(int p)
{
	top=0;dfs(p);
	long long sm=0;
	register int i;
	for(i=1;i<=top;i++)sm+=c[stk[i]];
	if(color(p))
	{
		sm=0;
		for(i=1;i<=top;i++)sm+=c[stk[i]]*col[stk[i]];
		return!sm;
	}return!(sm&1);
}
inline int rd()
{
	int x;
	scanf("%d",&x);
	return x;
}
void exec()
{
	n=rd(),m=rd();
	register int i;
	int tn=n;
	for(i=1;i<=n+m;i++)h[i]=c[i]=d[i]=vis[i]=col[i]=0;
	tot=0;
	for(i=1;i<=n;i++)a[i]=rd();
	for(i=1;i<=n;i++)b[i]=rd(),c[i]=a[i]-b[i];
	for(i=1;i<=m;i++)
	{
		int t=1,x,y;
		x=rd(),y=rd();
		if(t&1)build(x,y);
		else tn++,build(x,tn),build(tn,y);
	}for(i=1;i<=tn;i++)
		if(!vis[i])
			if(!solve(i))return(void)puts("NO");
	puts("YES");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}