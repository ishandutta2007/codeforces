#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=600005;
struct node
{
	int id,num,ty;
}a[N];
int n,i,j,k,lt[N],rt[N],m,head[N],adj[N],nxt[N],l,p[N],cnt,ans[N],d[N];
bool v[N],vis[N];
bool cmp(node a,node b)
{
	return a.num<b.num;
}
void addedge(int u,int v)
{
	adj[++l]=v;
	nxt[l]=head[u];
	head[u]=l;
	adj[++l]=u;
	nxt[l]=head[v];
	head[v]=l;
}
void dfs(int x)
{
	v[x]=true;
	for(;head[x];head[x]=nxt[head[x]])
		if(!vis[(head[x]+1)/2])
		{
			vis[(head[x]+1)/2]=true;
			if(head[x]&1)
				ans[(head[x]+1)/2]=1;
			else
				ans[(head[x]+1)/2]=-1;
			dfs(adj[head[x]]);
		}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&a[2*i-1].num,&a[2*i].num);
		a[2*i].num++;
		a[2*i-1].id=a[2*i].id=i;
		a[2*i-1].ty=0,a[2*i].ty=1;
	}
	sort(a+1,a+1+2*n,cmp);
	for(i=1;i<=2*n;i=j)
	{
		++m;
		for(j=i;j<=2*n&&a[i].num==a[j].num;++j)
			if(a[j].ty==0)
				lt[a[j].id]=m;
			else
				rt[a[j].id]=m;
	}
	for(i=1;i<=n;++i)
	{
		addedge(lt[i],rt[i]);
		++d[lt[i]],++d[rt[i]];
	}
	cnt=0;
	for(i=1;i<=m;++i)
		if(d[i]&1)
			p[++cnt]=i;
	for(i=1;i<=cnt;i+=2)
		addedge(p[i],p[i+1]);
	for(i=1;i<=m;++i)
		if(!v[i])
			dfs(i);
	for(i=1;i<=n;++i)
		if(ans[i]==1)
			printf("0 ");
		else
			printf("1 ");
	return 0;
}