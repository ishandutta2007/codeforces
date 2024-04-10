#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
typedef long double db;
struct pii
{int p;db v;};
bool operator<(cpnst pii x,cpnst pii y)
{return x.v<y.v;}
#include<queue>
std::priority_queue<pii>q;
db a[1111111];
int k,n,m;
db maxn[1111111];
int maxp[1111111];
#include<vector>
std::vector<pii>delta[1111111];
bool dec(pii x,pii y)
{return y<x;}
bool u[1111111];
int o[1111111];
#include<algorithm>
int main()
{
	scanf("%d%d%d",&k,&n,&m);
	register int i;
	for(i=1;i<=k;i++)scanf("%Lf",&a[i]);
	for(i=1;i<=n;i++)
	{
		int x,b;
		scanf("%d%d%d",o+i,&x,&b);
		if(o[i]==1){if(maxn[x]<b)maxn[x]=b,maxp[x]=i;}
		else if(o[i]==2)delta[x].push_back(pii{i,b*1.0});
		else q.push(pii{i,1.0*b});
	}for(i=1;i<=k;i++)
		if(maxn[i]>a[i])delta[i].push_back(pii{maxp[i],1.0*(maxn[i]-a[i])});
	for(i=1;i<=k;i++)std::sort(delta[i].begin(),delta[i].end(),dec);
	for(i=1;i<=k;i++)
		for(auto v:delta[i])
			q.push(pii{v.p,(v.v+a[i])/a[i]}),a[i]+=v.v;
	int ans=0;
	for(;ans<m&&q.size();)
	{
		pii g=q.top();q.pop();
		u[g.p]=1,ans++;
	}printf("%d\n",ans);
	for(i=1;i<=n;i++)
		if(o[i]==1&&u[i])printf("%d ",i);
	for(i=1;i<=n;i++)
		if(o[i]==2&&u[i])printf("%d ",i);
	for(i=1;i<=n;i++)
		if(o[i]==3&&u[i])printf("%d ",i);
	puts("");
}
/*
Just go for it.
*/