#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int N=200005;
int n,S;
struct qq
{
    int x,y,last;
}e[N*2];int num,last[N];
void init (int x,int y)
{
    e[++num].x=x;e[num].y=y;
    e[num].last=last[x];
    last[x]=num;
}
int a[N];
bool vis[N];
int tot[N];
int tmp1,tmp;
int f[N],pri[N],TOT=0;
void Init (int n)
{
	memset(vis,false,sizeof(vis));
	for (int u=2;u<=n;u++)
	{
		if (vis[u]==false)	{f[u]=u;pri[++TOT]=u;}
		for (int i=1;i<=TOT;i++)
		{
			int j=pri[i];
			if (j*u>n) break;
			vis[j*u]=true;
			f[j*u]=j;
			if (u%j==0) break;
		}
	}
}
void dfs1 (int x,int nn,int fa)
{
    tot[x]=1;int mx=0;
    for (int u=last[x];u!=-1;u=e[u].last)
    {
        int y=e[u].y;
        if (y==fa||vis[y]) continue;    
        dfs1(y,nn,x);
        tot[x]=tot[x]+tot[y];
        mx=max(mx,tot[y]);
    }
    mx=max(mx,nn-tot[x]);
    if (mx<=tmp1)    {tmp1=mx;tmp=x;}
}
int g[N];//
int h[N];
vector<int> vec;
void add (int x,int y)// 
{
	while (x!=1)
	{
		int t=f[x];
		g[t]=max(g[t],y);
		while (x%t==0) x/=t;
	}
}
int gcd (int x,int y)	{return x==0?y:gcd(y%x,x);}
void solve (int x,int ff,int xx,int dep)
{	
	xx=gcd(xx,a[x]);
	//if (xx==1) return ;
	add(xx,dep);
	tot[x]=1;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (vis[y]||y==ff) continue;
		solve(y,x,xx,dep+1);
		tot[x]=tot[x]+tot[y];
	}
}
void get (int x)
{
	vec.clear();
	while (x!=1)
	{
		int t=f[x];
		vec.push_back(t);
		while (x%t==0) x/=t;
	}
}
int ans=0;
void dfs (int x,int nn)
{
    tmp1=nn;dfs1(x,nn,0);
    int rt=tmp;
    get(a[rt]);	int siz=vec.size();
    if (a[rt]!=1) ans=max(ans,1);
    for (int u=0;u<siz;u++) h[vec[u]]=0;
    for (int u=last[rt];u!=-1;u=e[u].last)
    {
    	int y=e[u].y;
    	if (vis[y]) continue;
    	//printf("vis:%d\n",y);
    	solve(y,rt,a[rt],1);
    	for (int i=0;i<siz;i++)
    	{
    		ans=max(ans,h[vec[i]]+g[vec[i]]+1);
    		h[vec[i]]=max(h[vec[i]],g[vec[i]]);
    		g[vec[i]]=0;
		}
	}
    vis[rt]=true;
    for (int u=last[rt];u!=-1;u=e[u].last)
    {
        int y=e[u].y;
        if (vis[y]) continue;
        dfs(y,tot[y]);
    }
}
int main()
{
	Init(200000);
    num=0;memset(last,-1,sizeof(last));
    scanf("%d",&n);
    for (int u=1;u<=n;u++) scanf("%d",&a[u]);
    for (int u=1;u<n;u++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        init(x,y);init(y,x);
    }
    memset(g,0,sizeof(g));
    memset(vis,false,sizeof(vis));
    dfs(1,n);
    printf("%d\n",ans);
    return 0;
}