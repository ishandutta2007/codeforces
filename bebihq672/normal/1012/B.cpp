#include<bits/stdc++.h>
using namespace std;
struct Point{
	int x,y;
}p[202020];
int anc[404040];
int find(int x)
{
	if(anc[anc[x]]!=anc[x])
		find(anc[x]);
	anc[x]=anc[anc[x]]; 
}
void link(int u,int v)
{
	find(u);
	find(v);
	anc[anc[u]]=anc[v];
}
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n+m;i++)
		anc[i]=i;
	
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		link(p[i].x,p[i].y+n);
	}
	int ans=0;
	for(int i=1;i<=n+m;i++)
	{
		find(i);
		if(anc[i]==i)
			ans++;
	} 
	printf("%d\n",ans-1);
	return 0;
}