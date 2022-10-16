#include<bits/stdc++.h>
struct nod{int v,k;}d[1111111];
struct edg{int x,y,l;}e[1111111];
bool operator<(const edg x,const edg y){return x.l<y.l;}
nod operator+(nod x,nod y){x.v+=y.v,x.k+=y.k;return x;}
int n,fa[1111111];
int rt(int x){return fa[x]?fa[x]=rt(fa[x]):x;}
int main()
{
	scanf("%d",&n);
	if(n==1)return puts("0"),0;
	register int i;
	for(i=1;i<n;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].l);
	std::sort(e+1,e+n);
	int S=0;
	for(i=1;i<=n;i++)
		scanf("%d",&d[i].v),d[i].k=1,S+=d[i].v;
	for(i=1;i<n;i++)
	{
		int a=rt(e[i].x),b=rt(e[i].y);
		fa[a]=b,d[b]=d[a]+d[b];
		if(d[b].k+d[b].v>S)return printf("%d\n",e[i].l),0;
	}
}