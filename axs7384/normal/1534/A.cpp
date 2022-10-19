#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,t;
int w[10],r[10];
char s[N][N],c[10];
inline bool check(int p)
{
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			if (s[i][j]=='R')
			{
				if ((i+j+p)%2==0)
					return false;
			}
			if (s[i][j]=='W')
			{
				if ((i+j+p)%2==1)
					return false;
			}
		}
	return true;
}
inline void sc(int p)
{
	puts("YES");
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
			putchar((i+j+p)%2?'R':'W');
		putchar('\n');
	}
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			scanf("%s",s[i]+1);
		if (check(0))
		{
			sc(0);
			continue;
		}
		if (check(1))
		{
			sc(1);
			continue;
		}
		puts("NO");
		// w[0]=w[1]=r[0]=r[1]=0;
		// for (int i=1;i<=n;++i)
		// 	for (int j=1;j<=m;++j)
		// 	{
		// 		if (s[i][j]=='W')
		// 			w[(i+j)%2]=1;
		// 		if (s[i][j]=='R')
		// 			r[(i+j)%2]=1;
		// 	}
		// if ((w[0]&&r[0])||(w[1]&&r[1]))
		// {
		// 	puts("NO");
		// 	continue;
		// }
		// if (w[0])
		// {
		// 	c[0]='W';
		// 	c[1]='R';
		// }
		// else
		// {
		// 	c[0]='R';
		// 	c[1]='W';
		// }
		// puts("YES");
		// for (int i=1;i<=n;++i)
		// 	for (int j=1;j<=m;++j)
		// 		s[i][j]=c[(i+j)%2];
		// for (int i=1;i<=n;++i)
		// 	printf("%s\n",s[i]+1);
	}
	return 0;
}