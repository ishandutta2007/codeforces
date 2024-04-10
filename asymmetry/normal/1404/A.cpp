#include <bits/stdc++.h>

using namespace std;

int gh, n, k;
int g[2];
char s[300001];
queue <int> que;

void solve()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s+1);
	for(int i=1; i<=k; ++i)
	{
		g[0]=0;
		g[1]=0;
		for(int j=i; j<=n; j+=k)
		{
			if(s[j]=='0')
			{
				++g[0];
			}
			if(s[j]=='1')
			{
				++g[1];
			}
		}
		if(g[0] && g[1])
		{
			printf("NO\n");
			return;
		}
		if(g[0])
		{
			for(int j=i; j<=n; j+=k)
			{
				s[j]='0';
			}
		}
		if(g[1])
		{
			for(int j=i; j<=n; j+=k)
			{
				s[j]='1';
			}
		}
	}
	g[0]=0;
	g[1]=0;
	for(int i=1; i<=k; ++i)
	{
		if(s[i]=='0')
		{
			++g[0];
		}
		if(s[i]=='1')
		{
			++g[1];
		}
	}
	if(g[0]>k/2 || g[1]>k/2)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		solve();
	}
	return 0;
}