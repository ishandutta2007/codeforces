#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define Mod 1000000007
#define Inv2 500000004

int n, ans, A[N], Size[N][2];
vector <int> Vec[N];

void dfs(int z, int fa, int dep)
{
	Size[z][dep] = 1;
	for (int d : Vec[z])
		if (d != fa)
		{
			dfs(d, z, dep ^ 1);
			Size[z][0] += Size[d][0];
			Size[z][1] += Size[d][1];
		}
}

void DFS(int z, int fa, int dep)
{
	ans = (ans + 1LL * A[z] * n % Mod) % Mod;
	for (int x : Vec[z])
		if (x != fa)
		{
			DFS(x, z, dep ^ 1);
			int pos = dep, neg = dep ^ 1, tot = n - (Size[x][0] + Size[x][1]);
			ans = (ans + 1LL * Size[x][pos] * A[z] % Mod * tot % Mod) % Mod;
			ans = (ans - 1LL * Size[x][neg] * A[z] % Mod * tot % Mod + Mod) % Mod;
		}
	int pos = dep, neg = dep ^ 1, tot = Size[z][0] + Size[z][1];
	ans = (ans + 1LL * (Size[1][pos] - Size[z][pos]) * A[z] % Mod * tot % Mod) % Mod;
	ans = (ans - 1LL * (Size[1][neg] - Size[z][neg]) * A[z] % Mod * tot % Mod + Mod) % Mod;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		A[i] = (A[i] + Mod) % Mod;
	}
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	dfs(1, 0, 0);
	DFS(1, 0, 0);
	printf("%d\n", ans);
	return 0;
}