#include<bits/stdc++.h>

const int N=100005;

int n,m;
bool vis[2][N];

int main()
{
	scanf("%d%d",&n,&m);
	int s=0;
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		x--;
		vis[x][y]^=1;
		if (vis[x][y]&&vis[x^1][y]) s++;
		if (y>1&&vis[x][y]&&vis[x^1][y-1]) s++;
		if (y<n&&vis[x][y]&&vis[x^1][y+1]) s++;
		if (!vis[x][y]&&vis[x^1][y]) s--;
		if (y>1&&!vis[x][y]&&vis[x^1][y-1]) s--;
		if (y<n&&!vis[x][y]&&vis[x^1][y+1]) s--;
		puts(s?"No":"Yes");
	}
	return 0;
}