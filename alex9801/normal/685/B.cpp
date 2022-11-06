#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

std::vector<int> adj[300010];
int par[300010];
int cen[300010];
int siz[300010];
int def[300010];
int num[300010];

void f(int x)
{
	siz[x] = 1;
	def[x] = 0;

	for(int y : adj[x])
	{
		if(y != par[x])
		{
			f(y);
			siz[x] += siz[y];
			if(siz[y]>def[x])
			{
				def[x] = siz[y];
				num[x] = y;
			}
		}
	}
}

void g(int x)
{
	if(siz[x]==1)
	{
		cen[x] = x;
		return;
	}

	for(int y : adj[x])
		if(y != par[x])
			g(y);

	if(2*def[x] <= siz[x])
	{
		cen[x] = x;
		return;
	}

	int p, v;
	p = cen[num[x]];
	while(1)
	{
		v = std::max(def[p], siz[x]-siz[p]);
		if(2*v<=siz[x])
		{
			cen[x] = p;
			return;
		}
		p = par[p];
	}

}

int main()
{
	int n, a, q, p, i;
	scanf("%d%d", &n, &q);
	for(i = 2; i<=n; i++)
	{
		scanf("%d", &p);
		par[i] = p;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}

	f(1);
	g(1);

	for(i = 0; i<q; i++)
	{
		scanf("%d", &a);
		printf("%d\n", cen[a]);
	}
	return 0;
}