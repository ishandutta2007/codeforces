#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=505;
char a[N][N];
int n,m;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int u=1;u<=m;u++) a[0][u]='0';
		for (int u=1;u<=n;u++) scanf("%s",a[u]+1);
		int i=1;
		if (n%3==0) i=2;
		int cnt=0;
		for (;i<=n;i++)
		{
			if (cnt==0)
			{
				for (int j=1;j<=m;j++) a[i][j]='X';
				int id=1;
				for (int j=1;j<=m;j++) 
				{
					if ((i-1>=1&&a[i-1][j]=='X')||(i-2>=1&&a[i-2][j]=='X'))
					{
						id=j;break;
					}	
				}
				if (i-1>=1)	a[i-1][id]='X';
				if (i-2>=1) a[i-2][id]='X';				
			}
			cnt++;if (cnt>=3) cnt=0;
		}
		for (int u=1;u<=n;u++)
		{
			for (int  i=1;i<=m;i++)
			printf("%c",a[u][i]);
			printf("\n");
		}
	}
	return 0;
}