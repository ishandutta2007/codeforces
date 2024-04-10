#include<bits/stdc++.h>

const int N=1005;

int n,a[N][N][2],dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
char ans[N][N],str[4]={'R','L','U','D'};
bool vis[N][N];

char rev(char c)
{
	if (c=='D') return 'U';
	else if (c=='U') return 'D';
	else if (c=='L') return 'R';
	else if (c=='R') return 'L';
}

void dfs(int x,int y)
{
	vis[x][y]=1;
	for (int k=0;k<4;k++)
	{
		int p=x+dx[k],q=y+dy[k];
		if (p<1||p>n||q<1||q>n) continue;
		if (!vis[p][q]&&a[p][q][0]==a[x][y][0]&&a[p][q][1]==a[x][y][1])
			ans[p][q]=rev(str[k]),dfs(p,q);
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d%d",&a[i][j][0],&a[i][j][1]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (a[i][j][0]==-1)
			{
				bool flag=0;
				for (int k=0;k<4;k++)
				{
					int p=i+dx[k],q=j+dy[k];
					if (p<1||p>n||q<1||q>n) continue;
					if (a[p][q][0]==-1) {ans[i][j]=str[k];flag=1;break;}
				}
				if (!flag) {puts("INVALID");return 0;}
			}
			else
			{
				if (!vis[a[i][j][0]][a[i][j][1]]) ans[a[i][j][0]][a[i][j][1]]='X',dfs(a[i][j][0],a[i][j][1]);
				if (!vis[i][j]) {puts("INVALID");return 0;}
			}
	puts("VALID");
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) putchar(ans[i][j]);
		puts("");
	}
	return 0;
		
}