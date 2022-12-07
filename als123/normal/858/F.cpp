#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int x,y,next;
}b[500010],a[500010];int len=0,last[200010];
struct ANS{
	int x,y,z;
}ans[1000010];int num=0;
int Len=0,Last[200010];
bool vis[200010];
int n,m,f[200010];
int cd[200010]; 
int findfa(int x)
{
	if(f[x]!=x) f[x]=findfa(f[x]);
	return f[x];
}
void ins(int x,int y)
{
	a[++len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
void insert(int x,int y)
{
	b[++Len].x=x;b[Len].y=y;
	b[Len].next=Last[x];Last[x]=Len;
}
void dfs(int x,int fa)
{
	//printf("vis:%d\n",x);
	vis[x]=true;
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y!=fa) dfs(y,x);
	}
	if(cd[x]%2==1)
	{
		if(fa==0) Last[x]=b[Last[x]].next;
		else
		{
			//printf("add:%d %d\n",x,fa);
			insert(x,fa);
			cd[x]++;
		}
	}
	else
		if(fa!=0) insert(fa,x),cd[fa]++;
	int i=Last[x];
	while(i)
	{
		int X=b[i].y;
		i=b[i].next;
		int Y=b[i].y;
		//printf("fyc:%d %d %d\n",cd[x],X,Y);
		i=b[i].next;
		num++;
		ans[num].x=X;ans[num].y=x;ans[num].z=Y;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) f[i]=i;
	memset(last,0,sizeof(last));
	memset(Last,0,sizeof(Last));
	memset(cd,0,sizeof(cd));
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%d %d",&x,&y);
		int tx=findfa(x),ty=findfa(y);
		if(tx!=ty)
		{
			f[ty]=tx;
			ins(x,y);
			ins(y,x);
			//fa[y]=x;
		}
		else insert(x,y),cd[x]++;
	}
	memset(vis,false,sizeof(vis));
	//for(int i=1;i<=len;i++) printf("a:%d %d\n",a[i].x,a[i].y);
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0);
	printf("%d\n",num);
	for(int i=1;i<=num;i++) printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
}