#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int n, m, k;
vector<int> A[200000];
vector<int> R;
int d[2][200000];

void bfs(int s, int k)
{
	int queue[200000]; queue[0] = s;
	int qs = 0, qe = 1;
	bool vis[200000] = { 0 };
	vis[s] = true;
	d[k][s] = 0;
	while (qe > qs)
	{
		int u = queue[qs++];
		for (int v : A[u])
		{
			if (!vis[v])
			{
				vis[v] = true;
				d[k][v] = d[k][u] + 1;
				queue[qe++] = v;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	Loop(i, 0, k)
	{
		int u;
		cin >> u;
		u--;
		R.push_back(u);
	}
	Loop(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	bfs(0, 0);
	bfs(n - 1, 1);
	sort(R.begin(), R.end(), [&](int a, int b)
		{
			return d[0][a] - d[1][a] < d[0][b] - d[1][b];
		});
	int maxd = d[0][R[0]];
	int ans = 1;
	Loop(i, 1, k)
	{
		ans = max(ans, maxd + d[1][R[i]] + 1);
		maxd = max(maxd, d[0][R[i]]);
	}
	ans = min(d[0][n - 1], ans);
	cout << ans << '\n';
}