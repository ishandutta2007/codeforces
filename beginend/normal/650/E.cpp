#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#define mp(x,y) make_pair(x,y)
using namespace std;

typedef pair<int,int> pi;

const int N=500005;

int n,cnt,last[N],ans,stack[20],f[N];
struct edge{int to,next;bool del;}e[N*2];
struct data{int x1,y1,x2,y2;}ANS[N];
set<pi> se[N];
set<pi>::iterator it;

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void pri(int x)
{
	if (!x) {putchar('0');return;}
	int top=0;
	while (x) stack[++top]=x%10,x/=10;
	while (top) putchar(stack[top]+'0'),top--;
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

void merge(int p,int q)
{
	p=find(p);q=find(q);
	if (se[p].size()<se[q].size()) swap(p,q);
	f[q]=p;
	for (it=se[q].begin();it!=se[q].end();it++) se[p].insert(*it);
	se[q].clear();
}

void dfs(int x,int fa)
{
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x);
	if (!fa) return;
	int p=x,q=fa;
	if (p>q) swap(p,q);
	if (se[find(x)].count(mp(p,q)))
	{
		se[find(p)].erase(mp(p,q));se[find(q)].erase(mp(p,q));
		merge(p,q);
	}
	else
	{
		p=find(x);pi u=*se[p].begin();
		q=find(u.first)==p?find(u.second):find(u.first);
		ANS[++ans]=(data){x,fa,u.first,u.second};
		se[p].erase(u);se[q].erase(u);
		merge(p,q);
	}
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("tart.in","r",stdin);freopen("tart.out","w",stdout);
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		if (x>y) swap(x,y);
		se[x].insert(mp(x,y));
		se[y].insert(mp(x,y));
	}
	for (int i=1;i<=n;i++) f[i]=i;
	dfs(1,0);
	pri(ans);puts("");
	for (int i=1;i<=ans;i++)
	{
		int x1=ANS[i].x1,y1=ANS[i].y1,x2=ANS[i].x2,y2=ANS[i].y2;
		pri(x1);putchar(' ');pri(y1);putchar(' ');
		pri(x2);putchar(' ');pri(y2);puts("");
	}
	return 0;
}