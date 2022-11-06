#include <stdio.h>
#include <string.h>
#include <algorithm>

int par[1000010];
int rnk[1000010];
bool chk[1000010];
int deg[1000010];
int loop[1000010];

int root(int x)
{
	return x==par[x] ? x : (par[x] = root(par[x]));
}

bool merge(int x, int y)
{
	x = root(x);
	y = root(y);
	if(x==y)
		return 0;
	if(rnk[x]<rnk[y])
		par[x] = y;
	else
	{
		par[y] = x;
		if(rnk[x] == rnk[y])
			rnk[x]++;
	}
	return 1;
}

int main()
{
	int n, m, x, y, c1 = 0, c2 = 0, l = 0, i;
	scanf("%d%d", &n, &m);

	for(i = 1; i<=n; i++)
		par[i] = i;

	for(i = 0; i<m; i++)
	{
		scanf("%d%d", &x, &y);
		if(x == y)
			l++;
		else
		{
			deg[x]++;
			deg[y]++;
		}
		chk[x] = chk[y] = 1;
		if(merge(x, y))
			c1++;
	}

	for(i = 1; i<=n; i++)
		if(chk[i])
			c2++;

	if(c1 != c2 - 1)
		printf("0");
	else
	{
		long long r = 0;

		for(i = 1; i<=n; i++)
			r += 1LL*deg[i]*(deg[i]-1)/2;
		
		r += 1LL*l*(m-l);
		r += 1LL*l*(l-1)/2;

		printf("%lld", r);
	}
	return 0;
}