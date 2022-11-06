#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

int arr[1001];
std::vector<int> adj[1001];
bool chk[1001];
int cnt[1001];

void f(int x, int p, int o)
{
	chk[x] = 1;
	cnt[o]++;
	for(int y : adj[x])
	{
		if(y == p || chk[y])
			continue;
		f(y, x, o);
	}
}

int main()
{
	int n, m, k, c, mx, x, y, i, j;
	long long t, r = 0;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 0; i<k; i++)
		scanf("%d", &arr[i]);
	for(i = 0; i<m; i++)
	{
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	mx = 0;
	r = -m;
	c = n;
	for(i = 0; i<k; i++)
	{
		f(arr[i], arr[i], i);
		t = cnt[i];
		c -= t;
		mx = std::max(0LL+mx, t);

		r += t*(t-1)/2;
	}

	r += c*(c-1)/2;
	r += c * mx;

	printf("%lld", r);

	return 0;
}