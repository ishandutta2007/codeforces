#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=55;

int n,a[N][N],s[N][N],r[N][N],c[N][N],f[N][N][N][N];
bool vis[N][N][N][N];
char str[N];

int solve(int x1,int y1,int x2,int y2)
{
	if (x1>x2||y1>y2) return 0;
	if (vis[x1][y1][x2][y2]) return f[x1][y1][x2][y2];
	vis[x1][y1][x2][y2]=1;
	if (s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]==(x2-x1+1)*(y2-y1+1)) return f[x1][y1][x2][y2]=std::max(x2-x1+1,y2-y1+1);
	if (s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]==0) return 0;
	int ans=std::max(x2-x1+1,y2-y1+1);
	for (int i=x1;i<=x2;i++)
		if (r[i][y2]-r[i][y1-1]==0) ans=std::min(ans,solve(i+1,y1,x2,y2)+solve(x1,y1,i-1,y2));
	for (int i=y1;i<=y2;i++)
		if (c[x2][i]-c[x1-1][i]==0) ans=std::min(ans,solve(x1,i+1,x2,y2)+solve(x1,y1,x2,i-1));
	return f[x1][y1][x2][y2]=ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for (int j=1;j<=n;j++) if (str[j]=='#') a[i][j]=1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			r[i][j]=r[i][j-1]+a[i][j],c[i][j]=c[i-1][j]+a[i][j],s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	printf("%d\n",solve(1,1,n,n));
	return 0;
}