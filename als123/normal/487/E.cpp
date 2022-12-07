#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int MAX=1<<30;
const int N=1e6+5;
int n,m,Q;
int w[N];
struct qq
{
	int x,y,last;
}e[N],E[N];int num,Last[N],last[N];
struct H
{
	priority_queue<int> d,s;
	void upd ()
	{
		while (!s.empty()&&!d.empty()&&s.top()==d.top()) s.pop(),d.pop();
	}
	void push (int x)	{s.push(-x);}
	void del (int x) {d.push(-x);}
	int top () {upd();return -s.top();}
}q[N];
void init (int x,int y)
{
	num++;
	//if (num&1) printf("OZY:%d %d\n",x,y);
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
void Init (int x,int y)
{
	num++;
	E[num].x=x;E[num].y=y;
	E[num].last=Last[x];
	Last[x]=num;
}
int dfn[N],low[N],id;
int sta[N],Top;
int cnt;
void dfs (int x)
{
	low[x]=dfn[x]=++id;
	sta[++Top]=x;
	for (int u=Last[x];u!=-1;u=E[u].last)
	{
		int y=E[u].y;
		if (dfn[y]==-1)
		{
			dfs(y);
			low[x]=min(low[x],low[y]);
			if (low[y]>=dfn[x])
			{
				cnt++;int i;
				do
				{
					i=sta[Top--];
					init(cnt,i);init(i,cnt);
				}while (i!=y);
				init(cnt,x);init(x,cnt);
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
}
int dep[N],tot[N],top[N],son[N],ys[N],f[N];
void dfs1 (int x,int fa)
{
    f[x]=fa;tot[x]=1;dep[x]=dep[fa]+1;
    for (int u=last[x];u!=-1;u=e[u].last)
    {
        int y=e[u].y;
        if (y==fa) continue;
        if (x>n) q[x].push(w[y]);
        dfs1(y,x);
        tot[x]+=tot[y];
        if (tot[y]>tot[son[x]]) son[x]=y;
    }
}
int ooo=0;
void dfs2 (int x,int tp)
{
    ys[x]=++ooo;top[x]=tp;
    if (son[x]!=0) dfs2(son[x],tp);
    for (int u=last[x];u!=-1;u=e[u].last)
    {
        int y=e[u].y;
        if (y==f[x]||y==son[x]) continue;
        dfs2(y,y);
    }
}
struct qt
{
	int l,r;
	int s1,s2;
	int c;
}tr[N*2];
void bt (int l,int r)
{
	int a=++num;
	tr[a].l=l;tr[a].r=r;
	if (l==r) 
	{
		tr[a].c=0;
		return ;
	}
	int mid=(l+r)>>1;
	tr[a].s1=num+1;bt(l,mid);
	tr[a].s2=num+1;bt(mid+1,r);
}
void change (int now,int x,int y)
{
	if (tr[now].l==tr[now].r)	{tr[now].c=y;return ;}
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (x<=mid) change(s1,x,y);
	else change(s2,x,y);
	tr[now].c=min(tr[s1].c,tr[s2].c);
}
int find (int now,int l,int r)
{
	if (tr[now].l==l&&tr[now].r==r)
		return tr[now].c;
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) return find(s1,l,r);
	else if (l>mid) return find(s2,l,r);
	else return min(find(s1,l,mid),find(s2,mid+1,r));
}
int solve (int x,int y)
{
    int ans=MAX;
    int tx=top[x],ty=top[y];
    if (dep[tx]>dep[ty]) {swap(x,y);swap(tx,ty);}
    while (tx!=ty)
	{
		ans=min(ans,find(1,ys[ty],ys[y]));
		y=f[ty];ty=top[y];
		if (dep[tx]>dep[ty]) {swap(x,y);swap(tx,ty);}
	}
	if (dep[x]>dep[y]) swap(x,y);
	ans=min(ans,find(1,ys[x],ys[y]));
	if (x>n) ans=min(ans,w[f[x]]);
	return ans;
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	memset(Last,-1,sizeof(Last));
	scanf("%d%d%d",&n,&m,&Q);cnt=n;
	for (int u=1;u<=n;u++) scanf("%d",&w[u]);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Init(x,y);Init(y,x);
	}
	memset(dfn,-1,sizeof(dfn));
	dfs(1);
	dfs1(1,0);
	dfs2(1,1);
	for (int u=n+1;u<=cnt;u++) w[u]=q[u].top();
	num=0;bt(1,ooo);
	for (int u=1;u<=cnt;u++)
		change(1,ys[u],w[u]);
	while (Q--)
	{
		char ss[5];
		scanf("%s",ss);
		if (ss[0]=='C')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (x!=1) 
			{
				q[f[x]].del(w[x]);
				q[f[x]].push(y);
				w[f[x]]=q[f[x]].top();
				change(1,ys[f[x]],w[f[x]]);
			}
			w[x]=y;change(1,ys[x],y);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",solve(x,y));
		}
	}
	return 0;
}