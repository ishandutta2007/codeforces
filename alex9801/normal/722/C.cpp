#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[100010];
int sor[100010];
bool chk[100010];
int par[100010];
int rnk[100010];

long long sum[100010];
long long res[100010];

int root(int x)
{
	return x==par[x] ? x : (par[x] = root(par[x]));
}

void merge(int x, int y)
{
	x = root(x);
	y = root(y);
	if(x==y)
		return;

	if(rnk[x]<rnk[y])
	{
		par[x] = y;
		sum[y] += sum[x];
	}
	else
	{
		par[y] = x;
		sum[x] += sum[y];
		if(rnk[x]==rnk[y])
			rnk[x]++;
	}
}

int main()
{
	int n, i;
	long long r = 0;
	scanf("%d", &n);
	for(i = 1; i<=n; i++)
		scanf("%d", &arr[i]);
	for(i = 1; i<=n; i++)
		scanf("%d", &sor[i]);

	for(i = 1; i<=n; i++)
		par[i] = i;

	for(i = n; i>1; i--)
	{
		sum[root(sor[i])] += arr[sor[i]];
		if(chk[sor[i]-1])
			merge(sor[i], sor[i]-1);
		if(chk[sor[i]+1])
			merge(sor[i], sor[i]+1);

		r = std::max(r, sum[root(sor[i])]);
		res[i] = r;
		chk[sor[i]] = 1;
	}

	for(i = 2; i<=n; i++)
		printf("%lld\n", res[i]);
	printf("0\n");
	return 0;
}