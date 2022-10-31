#include<bits/stdc++.h>

const int N=2005;

int n,m,a[N][15],ned[N][15],ans[N];
bool f[N][N*7+5];
int shape[10][7]={{1,1,1,0,1,1,1},
{0,0,1,0,0,1,0},
{1,0,1,1,1,0,1},
{1,0,1,1,0,1,1},
{0,1,1,1,0,1,0},
{1,1,0,1,0,1,1},
{1,1,0,1,1,1,1},
{1,0,1,0,0,1,0},
{1,1,1,1,1,1,1},
{1,1,1,1,0,1,1}};

int get_need(char* str,int j)
{
	int ans=0;
	for (int i=0;i<7;i++)
	{
		int c=str[i]-'0';
		if (!shape[j][i]&&c==1) return -1;
		if (shape[j][i]==1&&!c) ans++;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		char str[10];scanf("%s",str);
		for (int j=0;j<=7;j++) a[i][j]=-1;
		for (int j=0;j<=9;j++)
		{
			ned[i][j]=get_need(str,j);
			if (ned[i][j]==-1) continue;
			a[i][ned[i][j]]=std::max(a[i][ned[i][j]],j);
		}
	}
	f[n+1][0]=1;
	for (int i=n+1;i>1;i--)
		for (int j=0;j<=(n+1-i)*7;j++)
		{
			if (!f[i][j]) continue;
			for (int k=0;k<=7;k++)
				if (a[i-1][k]>-1) f[i-1][j+k]=1;
		}
	if (!f[1][m])
	{
		puts("-1");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		int mx=-1;
		for (int j=9;j>=0;j--)
			if (ned[i][j]>-1&&m>=ned[i][j]&&f[i+1][m-ned[i][j]])
			{
				mx=j;
				break;
			}
		if (mx==-1)
		{
			puts("-1");
			return 0;
		}
		ans[i]=mx;
		m-=ned[i][mx];
	}
	for (int i=1;i<=n;i++) printf("%d",ans[i]);
	return 0;
}