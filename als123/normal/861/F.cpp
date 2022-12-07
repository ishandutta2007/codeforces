#include<cstdio>
#include<cstdlib>
#include<cstring>
const int N=200005*2;
int n,m;
struct qq
{
	int x,y;
	int last;
}e[N];int num=0,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int f[N];
bool vis[N];
int find (int x)
{
	return f[x]==x?f[x]:f[x]=find(f[x]);
}
bool ok[N];//
int du[N];//
bool shen[N];//
int ans=0;
qq s[N];int num1,last1[N];
void Init (int x,int y)
{
	num1++;
	s[num1].x=x;s[num1].y=y;
	s[num1].last=last1[x];
	last1[x]=num1;
}
void dfs (int x,int fa)
{
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		if (ok[u]==false) continue;//
		int y=e[u].y;
		if (y==fa) continue;
		dfs(y,x);
		if (du[y]%2==1) {du[y]++;Init(y,x);}
		else {du[x]++;Init(x,y);}
	}
}
void prepare ()
{
	memset(ok,false,sizeof(ok));
	for (int u=1;u<=n;u++)
		f[u]=u;
	for (int u=1;u<=num;u+=2)
	{
		int x=e[u].x,y=e[u].y;
		int fx=find(x),fy=find(y);
		if (fx==fy) continue;
		f[fx]=fy;
		ok[u]=ok[u+1]=true;
	}
	for (int u=1;u<=num;u+=2)
	{
		if (ok[u]) continue;
		Init(e[u].y,e[u].x);
		du[e[u].y]++;
	}
	memset(shen,false,sizeof(shen));
	for (int u=1;u<=n;u++)
	{
		int fx=find(u);
		if (shen[fx]==true) continue;
		shen[fx]=true;
		dfs(fx,0);
	}
}
int main()
{
	num1=0;memset(last1,-1,sizeof(last1));
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);init(y,x);
	}
	prepare();
	/*for (int u=1;u<=num1;u++) printf("%d %d %d\n",s[u].x,s[u].y,s[u].last);
	system("pause");*/
	for (int u=1;u<=n;u++) ans=ans+du[u]/2;
	printf("%d\n",ans);
	for (int u=1;u<=n;u++)
	{
		int X=-1;
		for (int i=last1[u];i!=-1;i=s[i].last)
		{
		/*	printf("%d %d %d %d\n",i,s[i].x,s[i].y,s[i].last);
			system("pause");*/
			int y=s[i].y;
			if (X==-1) X=y;
			else
			{
				printf("%d %d %d\n",X,u,y);
				X=-1;
			}
		}
	}
	return 0;
}