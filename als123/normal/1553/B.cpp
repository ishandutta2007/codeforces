#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1005;
char s[N],t[N];
bool f[N][N];
bool g[N][N];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s%s",s+1,t+1);
		int n=strlen(s+1),m=strlen(t+1);
		for (int u=0;u<=n;u++)
		for (int i=1;i<=m;i++)
		{
			f[u][i]=false;g[u][i]=false;
			f[u][0]=true;g[u][m+1]=true;
		}
		for (int u=1;u<=n;u++) if (s[u]==t[1])
		{
			f[u][1]=true;
			for (int i=2;i<=m;i++)
			{
				//if (u+i-1==2&&i==3) printf("") 
				if (s[u+i-1]==t[i])	f[u+i-1][i]=true;
				else break;
			}
		}
		for (int u=1;u<=n;u++) if (s[u]==t[m])
		{
			g[u][m]=true;int now=u+1;
			for (int i=m-1;i>=1;i--)
			{
				if (s[now]==t[i])	g[now][i]=true;
				else break;
				now++;
			}
		}
		bool tf=false;
		for (int u=1;u<=n;u++)
		for (int i=1;i<=m;i++)
		if (f[u][i]==true&&g[u-1][i+1]==true) 
		{
			tf=true;
			//printf("%d %d\n",u,i);
		}
		if (tf) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}