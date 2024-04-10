#include<cstdio>
#include<algorithm>
using namespace std;
int v[100001][18][13],head[100001],cnt,f[100001][18],m,n,q,a,b,c,ct[100001],dep[100001];
struct edge{
	int t,next;
}ed[200003];
void adde(int f,int t)
{
	ed[++cnt].t=t;
	ed[cnt].next=head[f];
	head[f]=cnt;
	ed[++cnt].t=f;
	ed[cnt].next=head[t];
	head[t]=cnt;
}
void uni(int a[],int b[],int c[])
{
	int h1=1,h2=1;
	for(int i=1;i<=10&&(a[h1]||b[h2]);i++)
	{
		if(!a[h1])
		c[i]=b[h2],h2++;
		else
		if(!b[h2])
		c[i]=a[h1],h1++;
		else
		if(a[h1]<b[h2])
		c[i]=a[h1],h1++;
		else
		c[i]=b[h2],h2++;
	}
}
void uni2(int a[],int b[])
{
	int c[11]={0};
	uni(a,b,c);
	for(int i=1;i<=10;i++)
	a[i]=c[i];
}
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=17;i++)
	f[u][i]=f[f[u][i-1]][i-1],uni(v[u][i-1],v[f[u][i-1]][i-1],v[u][i]);
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	dfs(ed[i].t,u);
}
int query(int x,int y,int c1[])
{
	if(dep[x]<dep[y])
	x^=y^=x^=y;
	for(int i=17;i>=0;i--)
	if(dep[x]-(1<<i)>=dep[y])
	uni2(c1,v[x][i]),x=f[x][i];
	if(x==y)
	{
		uni2(c1,v[x][0]);
		int tmp=0;
		for(int i=1;i<=10;i++)
		if(c1[i])tmp++;
		return tmp;
	}
	for(int i=17;i>=0;i--)
	if(f[x][i]!=f[y][i])
	uni2(c1,v[x][i]),uni2(c1,v[y][i]),x=f[x][i],y=f[y][i];
	uni2(c1,v[x][0]),uni2(c1,v[y][1]);
	{
		int tmp=0;
		for(int i=1;i<=10;i++)
		if(c1[i])tmp++;
		return tmp;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++)
	scanf("%d%d",&a,&b),adde(a,b);
	for(int i=1;i<=m;i++)
	{
	scanf("%d",&a);
	if(ct[a]<10)
	v[a][0][++ct[a]]=i;
	}
	dfs(1,0);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		int s1[11]={0};
		int s=query(a,b,s1);
		int s2=min(s,c);
		printf("%d ",s2);
		for(int i=1;i<=s2;i++)
		printf("%d ",s1[i]);
		printf("\n");
	}
}