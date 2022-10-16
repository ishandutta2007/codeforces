#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n;
#include<vector>
std::vector<int>v[1111111];
int fa[1111111],dep[1111111];
void dfs(int p,int f=0)
{
	fa[p]=f;
	dep[p]=dep[f]+1;
	for(auto t:v[p])
	{
		if(t==f)continue;
		dfs(t,p);
	}
}
int sizx[1111111],sizy[1111111];
bool vis[1111111];
int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}int rt;
	for(i=1;i<=n;i++)
		if(v[i].size()!=1)
		{
			rt=i,dfs(i);
			break;
		}
	int ax=1,ay=-1;
	for(i=1;i<=n;i++)
	{
		if(v[i].size()==1)
			vis[fa[i]]|=1;
		else ay++;
	}bool t1=0,t2=0;
	for(i=1;i<=n;i++)ay+=vis[i];
	for(i=1;i<=n;i++)
	{
		if(v[i].size()==1)
		{
			if(dep[i]&1)t1=1;
			else t2=1;
		}
	}if(t1&&t2)ax=3;
	printf("%d %d\n",ax,ay);
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/