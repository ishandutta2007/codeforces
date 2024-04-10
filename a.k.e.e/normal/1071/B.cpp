#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=2005;

int n,m,f[MAXN][MAXN];
char s[MAXN][MAXN];
int cnt=0,x[MAXN],y[MAXN];
int tot=0,a[MAXN],b[MAXN];
bool v[MAXN][MAXN];

void dfs(int i,int j)
{
	if(f[i][j]<=m)
	{
		for(int k=1;k<i+j;k++)putchar('a');
		return;
	}
	if(v[i-1][j])dfs(i-1,j);
	else dfs(i,j-1);
	putchar(s[i][j]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)f[0][i]=f[i][0]=1<<30;
	f[1][0]=f[0][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=min(f[i][j-1],f[i-1][j])+(s[i][j]!='a');
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			//cout<<f[i][j]<<" ";
			if(f[i][j]<=m)
			{
				if(i+j>x[1]+y[1])cnt=1,x[1]=i,y[1]=j;
				else if(i+j==x[1]+y[1])++cnt,x[cnt]=i,y[cnt]=j;
			}
		}
		//cout<<endl;
	}
	for(int i=1;i<=cnt;i++)
		v[x[i]][y[i]]=1;
	if(!m && f[1][1]>0)
		v[1][1]=x[1]=y[1]=1;
	for(int d=x[1]+y[1]+1;d<=2*n;d++)
	{
		tot=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=max(1,d-n);i<=n && i<d;i++)
		{
			int j=d-i;
			if(!v[i-1][j] && !v[i][j-1])continue;
			if(!tot || s[i][j]<s[a[1]][b[1]])tot=1,a[1]=i,b[1]=j;
			else if(s[i][j]==s[a[1]][b[1]])++tot,a[tot]=i,b[tot]=j;
		}
		for(int i=1;i<=tot;i++)
			v[a[i]][b[i]]=1;
		cnt=tot;
		memcpy(x,a,sizeof(x));
		memcpy(y,b,sizeof(y));
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}*/
	dfs(n,n);
	return 0;
}