#include<cstdio>
int p[1111111],m[1111111],r[1111111],n;
long long S;
bool vis[1111111],typ[1111111];
void dfs(int x)
{
	if(vis[x])return;
	S+=x,typ[x]=vis[x]=1;
	int y=x+n;if(y>n*2)y-=n*2;
	vis[y]=1,dfs(r[y]);
}
int main()
{
	scanf("%d",&n);
	register int i;
	if(n%2==0)
	{
		puts("First");
		for(i=1;i<=n*2;i++)
		{
			printf("%d ",i%n+1);
		}puts(""),fflush(stdout);
		return 0;
	}puts("Second"),fflush(stdout);
	for(i=1;i<=n*2;i++)
	{
		scanf("%d",p+i);
		if(m[p[i]])r[i]=m[p[i]],r[m[p[i]]]=i;
		else m[p[i]]=i;
	}for(i=1;i<=n*2;i++)if(!vis[i])dfs(i);
	if(S&1){for(i=1;i<=n*2;i++)if(!typ[i])printf("%d ",i);}
	else{for(i=1;i<=n*2;i++)if(typ[i])printf("%d ",i);}
	puts(""),fflush(stdout);
}
/*
Please don't let me down.
*/