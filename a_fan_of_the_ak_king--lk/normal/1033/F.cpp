#include<bits/stdc++.h>
using namespace std;
int n,a,p[4096],w,m;
long long f[4096][4096],ans;
char c[15];
void dfs(int i,int a,int b,int aa,int bb)
{
	if(i==w)
	{
		f[a][b]+=p[aa]*p[bb];
		return;
	}
	dfs(i+1,a|(1<<i),b,aa,bb);
	dfs(i+1,a,b|(1<<i),aa|(1<<i),bb|(1<<i));
	dfs(i+1,a,b,aa|(1<<i),bb);
	dfs(i+1,a,b,aa,bb|(1<<i));
}
void dfs2(int i,int a,int b)
{
	if(i==w)
	{
		ans+=f[a][b];
		return;
	}
	if(c[i]=='A')
	{
		dfs2(i+1,a|(1<<i),b);
		dfs2(i+1,a,b);
	}
	if(c[i]=='a')
		dfs2(i+1,a,b|(1<<i));
	if(c[i]=='x')
		dfs2(i+1,a,b);
	if(c[i]=='X')
	{
		dfs2(i+1,a|(1<<i),b);
		dfs2(i+1,a,b|(1<<i));
	}
	if(c[i]=='O')
		dfs2(i+1,a|(1<<i),b);
	if(c[i]=='o')
	{
		dfs2(i+1,a,b);
		dfs2(i+1,a,b|(1<<i));
	}
}
int main()
{
	scanf("%d %d %d",&w,&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		++p[a];
	}
	dfs(0,0,0,0,0);
	while(m--)
	{
		scanf("%s",c);
		reverse(c,c+w);
		ans=0;
		dfs2(0,0,0);
		printf("%lld\n",ans);
	}
}