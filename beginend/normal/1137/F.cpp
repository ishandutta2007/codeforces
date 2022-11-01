#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

const int N=200005;
const int maxn=200000;

int n,q,cnt,last[N],deg[N],rk[N],c1[N],c2[N],tim;
struct edge{int to,next;}e[N*2];
struct tree{int l,r,fa,s,col;bool rev;}t[N];
std::priority_queue<int> que;

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void pre()
{
	for (int i=1;i<=n;i++) if (deg[i]==1) que.push(-i),deg[i]=-1;
	for (int i=1;i<=n;i++)
	{
		int x=-que.top();que.pop();
		rk[x]=i;
		for (int j=last[x];j;j=e[j].next) if (deg[e[j].to]>0)
		{
			deg[e[j].to]--;
			if (deg[e[j].to]<=1) que.push(-e[j].to),deg[e[j].to]=-1;
		}
	}
}

void dfs(int x,int fa)
{
	t[x].s=1;
	for (int i=last[x];i;i=e[i].next) if (e[i].to!=fa) t[e[i].to].fa=x,dfs(e[i].to,x);
}

int find(int *c,int x)
{
	int ans=0;
	while (x) ans+=c[x],x-=x&(-x);
	return ans+c[0];
}

void ins(int *c,int x,int y)
{
	if (!x) c[0]+=y;
	else while (x<=maxn) c[x]+=y,x+=x&(-x);
}

bool is_root(int x)
{
	return x!=t[t[x].fa].l&&x!=t[t[x].fa].r;
}

void updata(int x)
{
	t[x].s=t[t[x].l].s+t[t[x].r].s+1;
}

void remove(int x)
{
	if (!is_root(x)) remove(t[x].fa);
	if (!t[x].rev) return;
	std::swap(t[x].l,t[x].r);t[x].rev=0; 
	if (t[x].l) t[t[x].l].rev^=1;
	if (t[x].r) t[t[x].r].rev^=1;
}

void rttl(int x)
{
	int y=t[x].r;t[y].col=t[x].col;
	t[x].r=t[y].l;t[t[y].l].fa=x;
	if (x==t[t[x].fa].l) t[t[x].fa].l=y;
	else if (x==t[t[x].fa].r) t[t[x].fa].r=y;
	t[y].fa=t[x].fa;
	t[y].l=x;t[x].fa=y;
	updata(x);updata(y);
}

void rttr(int x)
{
	int y=t[x].l;t[y].col=t[x].col;
	t[x].l=t[y].r;t[t[y].r].fa=x;
	if (x==t[t[x].fa].l) t[t[x].fa].l=y;
	else if (x==t[t[x].fa].r) t[t[x].fa].r=y;
	t[y].fa=t[x].fa;
	t[y].r=x;t[x].fa=y;
	updata(x);updata(y);
}

void splay(int x)
{
	remove(x);
	while (!is_root(x))
	{
		int p=t[x].fa,q=t[p].fa;
		if (is_root(p))
		{
			if (x==t[p].l) rttr(p);
			else rttl(p);
			break;
		}
		if (x==t[p].l)
			if (p==t[q].l) rttr(q),rttr(p);
			else rttr(p),rttl(q);
		else
			if (p==t[q].r) rttl(q),rttl(p);
			else rttl(p),rttr(q);
	}
}

void access(int x)
{
	int y=0;
	while (x)
	{
		splay(x);
		if (t[x].r) t[t[x].r].col=t[x].col;
		ins(c1,t[x].col,-t[x].s+t[t[x].r].s);
		if (!t[x].col) ins(c2,rk[x],1);
		t[x].r=y;updata(x);
		y=x;x=t[x].fa;
	}
	t[y].col=tim;
	ins(c1,tim,t[y].s);
}

void make_root(int x)
{
	access(x);splay(x);t[x].rev^=1;
}

int query(int x)
{
	splay(x);
	if (!t[x].col) return rk[x]-find(c2,rk[x]);
	else return find(c1,t[x].col-1)+t[t[x].r].s+1;
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
		deg[x]++;deg[y]++;
	}
	pre();
	dfs(n,0);
	c1[0]=n;
	while (q--)
	{
		char ch[10];scanf("%s",ch);
		if (ch[0]=='u')
		{
			int x;scanf("%d",&x);
			tim++;
			make_root(x);
		}
		else if (ch[0]=='w')
		{
			int x;scanf("%d",&x);
			printf("%d\n",query(x));
		}
		else
		{
			int x,y;scanf("%d%d",&x,&y);
			printf("%d\n",query(x)<query(y)?x:y);
		}
	}
	return 0;
}