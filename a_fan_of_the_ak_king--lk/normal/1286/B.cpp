#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=100005,M=1000000007;
int n,p,i,c[N],a[N],head[N],Next[N*2],adj[N*2],k,rt;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
int ind[N];
void Get(int i)
{
	int j;
	ind[++k]=i;
	for(j=head[i];j!=0;j=Next[j])
		Get(adj[j]);
}
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
void dfs(int i)
{
	int j;
	for(j=head[i];j!=0;j=Next[j])
		dfs(adj[j]);
	k=-1;
	Get(i);
	if(k<c[i])
	{
		puts("NO");
		exit(0);
	}
	if(k==0)
		a[i]=1;
	else
	{
		sort(ind+1,ind+1+k,cmp);
		a[i]=a[ind[c[i]]]+1;
		for(j=c[i]+1;j<=k;++j)
			a[ind[j]]+=2;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&p,&c[i]);
		if(p)
			Push(p,i);
		else
			rt=i;
	}
	dfs(rt);
	puts("YES");
	for(i=1;i<=n;++i)
		printf("%d ",a[i]);
}