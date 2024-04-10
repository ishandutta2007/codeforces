#include <bits/stdc++.h>

using namespace std;

int gh, n;
int t[1000];
char s[102][100];

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", &t[i+1]);
		}
		for(int i=1; i<=60; ++i)
		{
			s[0][i]='a';
		}
		for(int i=1; i<=n+1; ++i)
		{
			for(int j=1; j<=t[i]; ++j)
			{
				s[i][j]=s[i-1][j];
			}
			for(int j=t[i]+1; j<=60; ++j)
			{
				if(s[i-1][j]=='z')
				{
					s[i][j]='a';
				}
				else
				{
					s[i][j]=s[i-1][j]+1;
				}
			}
		}
		for(int i=1; i<=n+1; ++i)
		{
			for(int j=1; j<=60; ++j)
			{
				printf("%c", s[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}