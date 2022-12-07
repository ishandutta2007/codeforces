#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int N=300005*2;
vector<int> vec[N];
int fa[N];
int n,k;
int find_fa (int x)	{return fa[x]==x?x:fa[x]=find_fa(fa[x]);}
int X[N],Y[N];
void Merge (int x,int y)
{
	x=find_fa(x);y=find_fa(y);
	int siz=vec[x].size(),siz1=vec[y].size();
	if (siz>siz1) {swap(x,y);swap(siz,siz1);}
	for (int u=0;u<siz;u++) vec[y].push_back(vec[x][u]);
	fa[x]=y;
}
int d[N];
struct qq
{
	int x,y,last;
}e[N*2];int num,last[N];
void init (int x,int y)
{
	if (x==y) return ;
	e[++num].x=x;e[num].y=y;e[num].last=last[x];
	last[x]=num;d[y]++;
}
vector<int> h[N];
int nxt[N],lst[N];
vector<int> ans;
bool in[N];
int p[N];
void solve (int x)
{
	//printf("x:%d\n",x);
	int siz=h[x].size();
	int now;
	for (int u=0;u<siz;u++) if (lst[h[x][u]]==-1) now=h[x][u]; 
	while (now!=-1)
	{
		//printf("%d %d\n",now,p[now]);
		if (in[p[now]]==true) {printf("0\n");exit(0);}
		ans.push_back(now);in[now]=false;
		now=nxt[now];
	}
}
queue<int> q;
int main()
{
	scanf("%d%d",&n,&k);in[0]=false;
	for (int u=1;u<=n;u++)
	{
		fa[u]=u;d[u]=0;in[u]=true;
		nxt[u]=-1;lst[u]=-1;
		int x;
		scanf("%d",&x);p[u]=x;
		if (x==0) continue;
		vec[u].push_back(x);
	}
	for (int u=1;u<=k;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (nxt[x]!=-1) {printf("0\n");return 0;}
		if (lst[y]!=-1) {printf("0\n");return 0;}
		Merge(x,y);
		nxt[x]=y;lst[y]=x;
	}
	num=0;memset(last,-1,sizeof(last));
	for (int u=1;u<=n;u++)
	{
		if (fa[u]!=u) continue;
		int siz=vec[u].size();
		for (int i=0;i<siz;i++) init(find_fa(vec[u][i]),u);
	}
	for (int u=1;u<=n;u++) h[find_fa(u)].push_back(u);
	for (int u=1;u<=n;u++) if (d[u]==0&&fa[u]==u) q.push(u); 
	while (!q.empty())
	{
		int x=q.front();q.pop();solve(x);
		for (int u=last[x];u!=-1;u=e[u].last)
		{
			int y=e[u].y;
			d[y]--;
			if (d[y]==0) q.push(y);
		}
	}
	if (ans.size()!=n) {printf("0\n");return 0;}
	int siz=ans.size();
	for (int u=0;u<siz;u++) printf("%d ",ans[u]);
	return 0;
}