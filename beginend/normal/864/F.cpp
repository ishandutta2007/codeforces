#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=3005;

int n,m,q,cnt,last[N],val[N],now,tag,ans[400005],stack[N],top;
struct data{int x,y;}a[N];
vector<data> vec[N][N];
struct edge{int to,next;}e[N*2];
bool vis[N],ins[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

bool cmp(data a,data b) {return a.y<b.y;}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void dfs(int x)
{
	vis[x]=1;stack[++top]=x;ins[x]=1;
	for (int i=0;i<vec[now][x].size();i++) ans[vec[now][x][i].y]=tag||vec[now][x][i].x>top?-1:stack[vec[now][x][i].x];
	for (int i=last[x];i;i=e[i].next)
		if (!vis[e[i].to]) dfs(e[i].to);
		else if (ins[e[i].to]) tag++,val[e[i].to]--;
	tag+=val[x];ins[x]=0;top--;
}

int main()
{
	n=read();m=read();q=read();
	for (int i=1;i<=m;i++) a[i].x=read(),a[i].y=read();
	sort(a+1,a+m+1,cmp);
	for (int i=m;i>=1;i--) addedge(a[i].x,a[i].y);
	for (int i=1;i<=q;i++)
	{
		int x=read(),y=read(),k=read();
		vec[x][y].push_back((data){k,i});
	}
	for (int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(val,0,sizeof(val));
		tag=0;now=i;dfs(i);
	}
	for (int i=1;i<=q;i++) printf("%d\n",!ans[i]?-1:ans[i]);
	return 0;
}