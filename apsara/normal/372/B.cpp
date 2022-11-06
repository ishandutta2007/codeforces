#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=50;
char mp[V][V];
int s[V][V];
int cor[V][V][V][V],n,m,Q;
int sm[V][V][V][V];
int main()
{
	while(~scanf("%d%d%d",&n,&m,&Q))
	{
		for(int i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		s[i][j]=s[i-1][j]+s[i][j-1]+mp[i][j]-'0'-s[i-1][j-1];
		memset(cor,0,sizeof(cor));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			for(int x=1;x<=i;x++)
			for(int y=1;y<=j;y++)
			{
				int ct=s[i][j]+s[x-1][y-1]-s[i][y-1]-s[x-1][j];
				if(!ct)cor[x][y][i][j]++;
			}
		}
		memset(sm,0,sizeof(sm));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		for(int x=1;x<=i;x++)
		for(int y=1;y<=j;y++)
		sm[x][y][i][j]=sm[x][y][i-1][j]+sm[x][y][i][j-1]+cor[x][y][i][j]-sm[x][y][i-1][j-1];
		for(int x=n;x>0;x--)
		for(int y=m;y>0;y--)
		for(int i=x;i<=n;i++)
		for(int j=y;j<=m;j++)
		sm[x][y][i][j]=sm[x+1][y][i][j]+sm[x][y+1][i][j]+sm[x][y][i][j]-sm[x+1][y+1][i][j];
		while(Q--)
		{
			int x,y,i,j;
			scanf("%d%d%d%d",&x,&y,&i,&j);
			int ct=sm[x][y][i][j];//+s[x-1][y-1]-s[i][y-1]-s[x-1][j];
			printf("%d\n",ct);
		}
	}
	return 0;
}