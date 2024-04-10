#include <bits/stdc++.h>
using namespace std;

#define MAXN 512345

int p[MAXN];
int sz[MAXN];

int find(int a)
{
	if (p[a] == a)	return a;
	return p[a] = find(p[a]);
}

void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		p[a] = b;
		sz[b] += sz[a];
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		p[i] = i, sz[i] = 1;
	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		if (k == 0)	continue;
		int prev, a;
		scanf("%d", &prev);
		for (int i = 1; i < k; i++)
		{
			scanf("%d", &a);
			unite(prev, a);
			prev = a;
		}
	}
	printf("%d", sz[find(1)]);
	for (int i = 2; i <= n; i++)
		printf(" %d", sz[find(i)]);
	printf("\n");
}