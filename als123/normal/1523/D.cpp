#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
int n,m,p;
char ss[N][65];
int ans[65],mx=0;
int id[20];
int lb (int x)	{return x&(-x);}
int h[N],f[N],f1[N];
void check (int x)
{
	int nn=0;
	for (int u=1;u<=m;u++) if (ss[x][u]=='1') 
	{
		//printf("YES:%d\n",u);
		nn++;id[nn]=u;
	}
	//for (int u=1;u<=nn;u++) printf("%d:%d ",u,id[u]);printf("\n");
	for (int u=0;u<(1<<nn);u++) {f[u]=0;f1[u]=0;}
	for (int u=1;u<=n;u++)
	{
		int now=0;
		for (int i=1;i<=nn;i++) if (ss[u][id[i]]=='1') now|=(1<<i-1);
		//printf("%d\n",now);
		f[now]++;
	}
	for (int u=0;u<(1<<nn);u++)
	for (int i=u;i!=0;i=(i-1)&u)
	f1[i]=f1[i]+f[u];
	/*for (int u=(1<<nn)-1;u>=1;u--)
	f[u^lb(u)]+=f[u];*/
	/*printf("f:");for (int u=0;u<(1<<nn);u++) printf("%d ",f1[u]);
	printf("\n");*/
	int l=0;
	for (int u=0;u<(1<<nn);u++)
	if (f1[u]>=(n+1)/2) 
	{
		//printf("YES:%d %d\n",u,h[u]);
		l=h[l]>h[u]?l:u;
	}
//	printf("%d %d\n",l,h[l]);
	if (h[l]>mx)
	{
		mx=h[l];
		memset(ans,0,sizeof(ans));
		for (int u=1;u<=nn;u++)
		if (l&(1<<u-1))
		ans[id[u]]=1;
	}
}
int main()
{
	srand(200815147);
	h[0]=0;for (int u=1;u<=100000;u++) h[u]=h[u>>1]+(u&1);
	scanf("%d%d%d",&n,&m,&p);
	for (int u=1;u<=n;u++) scanf("%s",ss[u]+1);
	for (int u=1;u<=10;u++)
	{
		int x=rand()*rand()%n+1;
		check(x);
	}
	//check(1);
	//printf("%d\n",mx);
	for (int u=1;u<=m;u++) printf("%d",ans[u]);
	return 0;
}