#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
typedef pair<int,int> PI; 
const int M=505;
const int N=5005;
int d,s; 
queue<PI> q;
PI from[M][N];
int f[M][N];
bool vis[M][N];
vector<int> ans;
int main()
{
	memset(vis,false,sizeof(vis));
	scanf("%d%d",&d,&s);
	q.push({0,0});vis[0][0]=true;
	while (!q.empty())
	{
		PI now=q.front();q.pop();
	//	printf("%d %d\n",now.first,now.second);
		for (int u=0;u<=9;u++)
		{
			int dd=(now.first*10+u)%d,ss=now.second+u;
			if (ss>s) continue;
			if (vis[dd][ss]) continue;
			vis[dd][ss]=true;
			from[dd][ss]=now;
			f[dd][ss]=u;
			q.push({dd,ss});
		}
	}
	if (vis[0][s]==false) printf("-1\n");
	else
	{
		
		int x=0,y=s;
		while (x!=0||y!=0)
		{
			ans.push_back(f[x][y]);
			int xx,yy;
			xx=from[x][y].first;
			yy=from[x][y].second;
			x=xx;y=yy;
		}
		while (!ans.empty())
		{
			printf("%d",ans.back());
			ans.pop_back();
		}
	} 
	return 0;
}