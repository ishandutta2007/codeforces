#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <int> graph[200001];
vector <int> rev_graph[200001];

const int INF = 987654321;

bool hasCycle = 0;
int cache[200001];
void DFS(int v)
{
	cache[v] = 1;
	for (auto nv : graph[v])
	{
		if (cache[nv] == 1)
			hasCycle = 1;
		if (cache[nv] == 0)
			DFS(nv);
	}
	cache[v] = 2;
}

int dp1[200001];
int dp2[200001];

int solve(int v, vector <int>* graph, int* dp)
{
	int& ret = dp[v];
	if (ret != -1) return ret;
	ret = v;
	for (auto nv : graph[v])
	{
		ret = min(ret, solve(nv, graph, dp));
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		rev_graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		if (cache[i] == 0) DFS(i);
	}

	if (hasCycle)
	{
		cout << -1;
		return 0;
	}

	int ans = 0;
	string str;

	memset(dp1, -1, sizeof dp1);
	memset(dp2, -1, sizeof dp2);
	for (int i = 1; i <= n; i++)
	{
		if (solve(i, graph, dp1) == i && solve(i, rev_graph, dp2) == i)
		{
			ans++;
			str += 'A';
		}
		else str += 'E';
	}

	cout << ans << '\n';
	cout << str;
}