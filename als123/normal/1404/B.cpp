#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
vector<int> vec[N];
int n,a,b,da,db;
int d,xx;
int dist;
void dfs (int x,int dep,int fa)
{
	if (x==b) dist=dep;
	if (dep>d)	{d=dep;xx=x;}
	for (auto y:vec[x])
	{
		if (y==fa) continue;
		dfs(y,dep+1,x);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for (int u=1;u<=n;u++) vec[u].clear();
		for (int u=1;u<n;u++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		d=-1;
		dfs(a,0,0);
		if (dist<=da) printf("Alice\n");
		else
		{
			dfs(xx,0,0);
			db=min(db,d);
			if (da*2<db) printf("Bob\n");
			else 		 printf("Alice\n");
		}
	}
	return 0;
}