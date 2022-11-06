#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define K 100 + 5

int n, m, k, s, Col[N], Dis[K][N], q[N], T[K];
vector <int> Vec[N];

void BFS(int col)
{
	int l = 1, r = 0;
	for (int i = 1; i <= n; i ++)
	{
		Dis[col][i] = n;
		if (Col[i] == col)
		{
			Dis[col][i] = 0;
			q[++ r] = i;
		}
	}
	while (l <= r)
	{
		int z = q[l ++];
		for (int d : Vec[z])
			if (Dis[col][d] == n)
			{
				Dis[col][d] = Dis[col][z] + 1;
				q[++ r] = d;
			}
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 1; i <= n; i ++)
		scanf("%d", Col + i);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	for (int i = 1; i <= k; i ++)
		BFS(i);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= k; j ++)
			T[j] = Dis[j][i];
		sort(T + 1, T + k + 1);
		int sum = 0;
		for (int j = 1; j <= s; j ++)
			sum += T[j];
		printf("%d%c", sum, i == n ? '\n' : ' ');
	}
	return 0;
}