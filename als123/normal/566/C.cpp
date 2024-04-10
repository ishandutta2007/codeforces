#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define double long double
typedef pair<int,int> PI;
typedef long long LL;
const int N=200005;
int n;
int w[N];
vector<PI> vec[N];
double sum=0;
double ans1;
int ans;
double val[N];
double sumd;
void dfs (int x,int rt,int fa,LL dep)
{
	sum=sum+w[x]*pow(dep,1.5);
	val[rt]+=w[x]*sqrt(dep)*3/2;
	sumd+=w[x]*sqrt(dep)*3/2;
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u].first,z=vec[x][u].second;
		if (y==fa) continue;
		dfs(y,rt,x,dep+z);
	}
}
bool vis[N];
int tot[N];
int tmp,tmp1;
void get_root (int x,int fa,int nn)
{
	tot[x]=1;int mx=0;
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u].first;
		if (y==fa||vis[y]) continue;
		get_root(y,x,nn);
		tot[x]=tot[x]+tot[y];
		mx=max(mx,tot[y]);
	}
	mx=max(mx,nn-tot[x]);
	if (mx<tmp1)	{tmp1=mx;tmp=x;}
}
void solve (int x,int nn)
{
	tmp1=nn+1;get_root(x,0,nn);
	x=tmp;
	get_root(x,0,nn);
	int siz=vec[x].size();
	sum=0;sumd=0;
	vis[x]=true;
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u].first;
		val[y]=0;dfs(y,y,x,vec[x][u].second);
	}
	if (sum<ans1)	{ans1=sum;ans=x;}
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u].first;
		if (vis[y]) continue;
		if (sumd-2*val[y]<0)	{solve(y,tot[y]);return ;}
	}
}
int read()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}
int main()
{
	n=read();
	for (int u=1;u<=n;u++) w[u]=read();
	for (int u=1;u<n;u++)
	{
		int x,y,l;
		x=read();y=read();l=read();
		vec[x].push_back({y,l});
		vec[y].push_back({x,l});
	}
	sum=0;dfs(1,0,0,0);ans1=sum;ans=1;
	memset(vis,false,sizeof(vis));
	solve(1,n); 
	printf("%d %Lf\n",ans,ans1);
	return 0;
}