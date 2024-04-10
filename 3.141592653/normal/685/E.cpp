#include<cstdio>
#include<cstring>
int n,m,q;
int d[1111][1111],x[1111111],y[1111111],ans[1111111];
void updata(int a,int b,int l)
{
	for(register int i=1;i<=n;i++)
	{
		if(d[a][i]>d[b][i])d[a][i]=d[b][i];
		else d[b][i]=d[a][i];
	}d[a][b]=d[b][a]=l;
}
struct qry{int l,r,s,t,Id;}a[1111111];
#include<vector>
std::vector<qry>v[1111111];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	memset(d,0x3f,sizeof d);
	register int i;
	for(i=1;i<=m;i++)scanf("%d%d",x+i,y+i);
	for(i=1;i<=q;i++)scanf("%d%d%d%d",&a[i].l,&a[i].r,&a[i].s,&a[i].t),
		a[i].Id=i,v[a[i].l].push_back(a[i]);
	for(i=m;i;i--)
	{
		updata(x[i],y[i],i);
		for(auto&t:v[i])ans[t.Id]=(t.r>=d[t.s][t.t]);
	}for(i=1;i<=q;i++)puts(ans[i]?"Yes":"No");
}
/*
Please don't let me down.
*/