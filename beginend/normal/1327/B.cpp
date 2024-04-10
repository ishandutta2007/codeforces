#include<bits/stdc++.h>
#define pb push_back

const int N=100005;

int n,match[N];
bool vis[N];
std::vector<int> e[N];

void solve()
{
	for (int i=1;i<=n;i++) vis[i]=0,match[i]=0;
	int tot=0;
	for (int i=1;i<=n;i++)
	{
		for (int j:e[i])
			if (!vis[j])
			{
				vis[j]=1;
				match[i]=j;
				tot++;
				break;
			}
	}
	if (tot==n) puts("OPTIMAL");
	else
	{
		puts("IMPROVE");
		for (int i=1;i<=n;i++)
			if (!match[i])
			{
				for (int j=1;j<=n;j++)
					if (!vis[j])
					{
						printf("%d %d\n",i,j);
						return;
					}
			}
	}
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			int x,y;scanf("%d",&x);
			e[i].clear();
			while (x) scanf("%d",&y),e[i].pb(y),x--;
		}
		solve();
	}
	return 0;
}