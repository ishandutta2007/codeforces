#include<cstdio>
#include<cstring>
#define lowbit(x) ((x)&(-(x)))
#define errlog(...) fprintf(stderr,__VA_ARGS__)
typedef long long ll;
typedef double db;
inline int min(int x,int y)
{return(x<y)?x:y;}
inline int max(int x,int y)
{return(x>y)?x:y;}
inline int abs(int x)
{return(x>0)?x:-x;}
int fa[222222];
inline int ass(int x)
{return(fa[x]^x)?fa[x]=ass(fa[x]):x;}
int n,m,a,b;
int x,y;
int u[555555],v[555555];
void exec()
{
	register int i;
	x=y=0;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++)scanf("%d%d",&u[i],&v[i]);
	for(i=1;i<=m;i++)
	{
		if(v[i]==a||u[i]==a)continue;
		fa[ass(v[i])]=ass(u[i]);
	}for(i=1;i<=n;i++)if(i!=a)if(i!=b)if(ass(i)!=ass(b))x++;
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++)
	{
		if(v[i]==b||u[i]==b)continue;
		fa[ass(v[i])]=ass(u[i]);
	}for(i=1;i<=n;i++)if(i!=a)if(i!=b)if(ass(i)!=ass(a))y++;
	printf("%lld\n",x*1ll*y);
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)exec();
	
}