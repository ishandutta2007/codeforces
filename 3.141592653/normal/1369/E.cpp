#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
#include<queue>
std::queue<int>q;
int n,m,w[1111111];
bool vis[1111111];
bool dec(int x,int y)
{
	if((!w[x])&&(!w[y]))return 0;
	if(w[x]){w[x]--;if(!w[x])q.push(x);}
	if(w[y]){w[y]--;if(!w[y])q.push(y);}
	return 1;
}
#include<vector>
struct pii
{int v,t;};
std::vector<pii>v[1111111];
int x[1111111],y[1111111];
int ans[1111111],dd[1111111];
int main()
{
	scanf("%d%d",&n,&m);
	register int i;
	for(i=1;i<=n;i++)
		scanf("%d",w+i);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		v[x[i]].push_back(pii{y[i],i}),
		v[y[i]].push_back(pii{x[i],i});
		dd[x[i]]++,dd[y[i]]++;
	}int tot=m;
	for(i=1;i<=n;i++)
		if(dd[i]<=w[i])q.push(i);
	for(i=1;i<=n;i++)
	{
		if(!q.size())return puts("Dead"),0;
		int t=q.front();q.pop();
		//printf("%d\n",t);
		for(auto gg:v[t])
		{
			//printf("%d\n",gg.v);
			if(vis[gg.t])continue;
			ans[tot--]=gg.t;
			vis[gg.t]=1,dd[gg.v]--;
			if(dd[gg.v]==w[gg.v])q.push(gg.v);
		}
	}
	puts("Alive");
	for(i=1;i<=m;i++)
		printf("%d ",ans[i]);puts("");
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/