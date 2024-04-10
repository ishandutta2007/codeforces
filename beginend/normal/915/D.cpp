#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=505;

int n,m,cnt,last[N],tim,dfn[N],low[N],deg[N],a[N],top,stack[N],flag,col[N],tot;
struct edge{int to,next,from;bool del;}e[100005];
bool ins[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int u,int v)
{
	e[++cnt].from=u;e[cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void tarjan(int x)
{
	dfn[x]=low[x]=++tim;
	stack[++top]=x;ins[x]=1;
	for (int i=last[x];i;i=e[i].next)
		if (!dfn[e[i].to])
		{
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if (ins[e[i].to])
		{
			low[x]=min(low[x],dfn[e[i].to]);
			if (flag) continue;
			for (int j=top;stack[j]!=e[i].to;j--) col[stack[j]]=++tot;
			col[e[i].to]=++tot;
			flag=1;
		}
	if (dfn[x]==low[x])
	{
		while (stack[top]!=x) ins[stack[top]]=0,top--;
		ins[x]=0;top--;
	}
}

bool check()
{
	memset(deg,0,sizeof(deg));
	for (int i=1;i<=m;i++) if (!e[i].del) deg[e[i].to]++;
	int a1=0;
	for (int i=1;i<=n;i++) if (!deg[i]) a[++a1]=i;
	for (int i=1;i<=a1;i++)
		for (int j=last[a[i]];j;j=e[j].next)
		{
			if (e[j].del) continue;
			deg[e[j].to]--;
			if (!deg[e[j].to]) a[++a1]=e[j].to;
		}
	return a1==n;
}

int main()
{
	n=read();m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	if (!flag) {puts("YES");return 0;}
	for (int i=1;i<=m;i++)
		if (col[e[i].from]&&col[e[i].to]&&col[e[i].from]==col[e[i].to]+1||col[e[i].from]==1&&col[e[i].to]==tot)
		{
			e[i].del=1;
			if (check()) {puts("YES");return 0;}
			e[i].del=0;
		}
	puts("NO");
	return 0;
}