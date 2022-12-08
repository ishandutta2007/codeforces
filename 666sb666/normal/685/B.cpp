#include<cstdio>
#include<cstring>
const int maxn=300001;
struct E
{
	int to,next;
}edge[maxn];
int n,m,fa[maxn],head[maxn],size[maxn],ans[maxn],tot=0;
char ch[maxn];
inline int read()
{
    int x=0;
    char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
inline void write(int k)
{
	int num=0;
	while(k)ch[++num]=k%10,k/=10;
	while(num)putchar(ch[num--]+'0');
	putchar('\n');
}
inline void dfs(int u)
{
	int son=0,mx=0;
	size[u]=1;
	for(int i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].to;
		dfs(v);
		size[u]+=size[v];
		if(size[v]>mx)mx=size[v],son=v;
	}
	if(son)
	{
		int p=ans[son];
		while(size[p]*2<size[u])p=fa[p];
		ans[u]=p;
	}
	else ans[u]=u;
}
int main()
{
	n=read(),m=read();
	memset(head,-1,sizeof(head));
	for(int i=2;i<=n;i++)
	{
		fa[i]=read();
		edge[++tot]=(E){i,head[fa[i]]};
		head[fa[i]]=tot;
	}
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		int x;
		x=read();
		write(ans[x]);
	}
	return 0;
}