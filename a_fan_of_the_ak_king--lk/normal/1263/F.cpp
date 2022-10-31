#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=500005;
int head[N],Next[N*2],adj[N*2],n,i,a,b,p,x[N],y[N],f[N],k,mn[N],mx[N],s[N],m;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
struct str{
	int l,r,x;
}e[N];
void dfs(int i)
{
	mn[i]=1<<30;
	mx[i]=0;
	if(x[i])
		mn[i]=mx[i]=x[i];
	y[i]=1;
	for(int j=head[i];j!=0;j=Next[j])
	{
		dfs(adj[j]);
		y[i]+=y[adj[j]];
		mn[i]=min(mn[i],mn[adj[j]]);
		mx[i]=max(mx[i],mx[adj[j]]);
	}
		//cout<<i<<' '<<mn[i]<<' '<<mx[i]<<' '<<y[i]<<endl;
	if(i!=1)
		e[++m]=(str){mn[i],mx[i],y[i]};
}
bool cmp(str a,str b)
{
	return a.r<b.r;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%d",&a);
	for(i=2;i<=a;++i)
	{
		scanf("%d",&p);
		Push(p,i);
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",&p);
		x[p]=i;
	}
	dfs(1);
	memset(head,0,sizeof(head));
	memset(x,0,sizeof(x));
	k=0;
	scanf("%d",&a);
	for(i=2;i<=a;++i)
	{
		scanf("%d",&p);
		Push(p,i);
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",&p);
		x[p]=i;
	}
	dfs(1);
	int l=1;
	sort(e+1,e+1+m,cmp);
	//for(i=1;i<=m;++i)
	//	cout<<e[i].l<<' '<<e[i].r<<' '<<e[i].x<<endl;
	for(i=1;i<=n;++i)
	{
		for(;e[l].r==i&&l<=m;++l)
			f[i]=max(f[i],f[e[l].l-1]+e[l].x);
		f[i]=max(f[i],f[i-1]);
	}
	cout<<f[n]<<endl;
}