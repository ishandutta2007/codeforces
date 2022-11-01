#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1005;

int n,deg[N],cnt,last[N],lef1,lef2,lef3,lef4,tot;
struct edge{int to,next,w;}e[N*2];
struct data{int x,y,w;}ans[N*4];

void addedge(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

void get_lef(int x,int fa)
{
	if (deg[x]==1) {lef1=x;return;}
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa) get_lef(e[i].to,x);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y,w;scanf("%d%d%d",&x,&y,&w);
		addedge(x,y,w);
		deg[x]++;deg[y]++;
	}
	for (int i=1;i<=n;i++) if (deg[i]==2) {puts("NO");return 0;}
	puts("YES");
	if (n==2) {printf("1\n%d %d %d\n",1,2,e[1].w);return 0;}
	for (int i=1;i<n;i++)
	{
		int u=e[i*2-1].to,v=e[i*2].to,w=e[i*2].w/2;
		if (!w) continue;
		lef1=lef2=lef3=lef4=0;
		for (int j=last[u];j;j=e[j].next)
			if (e[j].to!=v) lef2=lef1,get_lef(e[j].to,u);
		lef3=lef1;lef4=lef2;lef1=lef2=0;
		for (int j=last[v];j;j=e[j].next)
			if (e[j].to!=u) lef2=lef1,get_lef(e[j].to,v);
		if (deg[u]==1) ans[++tot]=(data){u,lef1,w},ans[++tot]=(data){u,lef2,w},ans[++tot]=(data){lef1,lef2,-w};
		else if (deg[v]==1) ans[++tot]=(data){v,lef3,w},ans[++tot]=(data){v,lef4,w},ans[++tot]=(data){lef3,lef4,-w};
		else ans[++tot]=(data){lef1,lef3,w},ans[++tot]=(data){lef2,lef4,w},ans[++tot]=(data){lef1,lef2,-w},ans[++tot]=(data){lef3,lef4,-w};
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].w);
	return 0;
}