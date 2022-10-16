#include<cstdio>
#include<algorithm>
typedef long long ll;
int a[1111111];
bool vis[1111111],lst[1111111];
void fill(int p,int r)
{
	register int i;
	for(i=p;i&&i>p-r;i--)vis[i]=1;
	for(i=p;i<=1000&&i<p+r;i++)vis[i]=1;
}
int stk[1111111],top;
void exec()
{
	int n,m;
	scanf("%d%d",&n,&m);
	register int i,ii;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i])stk[++top]=i;
	}
	int l=0,t=1,ans=0;
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			for(ii=top;ii;ii--)
				if(stk[ii]-m<i){ans++;fill(stk[ii],m);goto R;}
			goto FL;
			R:;
		}
	}
	for(i=1;i<=n;i++)if(!vis[i])goto FL;
	printf("%d\n",ans);
	return;
	FL:puts("-1");
}
int main()
{
	int T;
	//scanf("%d",&T);
	T=1;
	while(T--)exec();
}