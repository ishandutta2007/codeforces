#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n, k;
set <int> graph[100001];

int cnt = 1;
int dfs_num[100001];
int dfs_low[100001];
int visited[100001];

vector <int> S;
int scc = 0;
void DFS(int s)
{
	dfs_low[s] = dfs_num[s] = cnt++;
	S.push_back(s);
	visited[s] = 1;
	for (auto i = graph[s].begin(); i != graph[s].end(); i++)
	{
		int v = *i;
		if (dfs_num[v] == 0)
			DFS(v);
		if (visited[v])
			dfs_low[s] = min(dfs_low[s], dfs_low[v]);
	}

	if (dfs_low[s] == dfs_num[s])
	{
		scc++;
		while (true)
		{
			int v = S.back(); S.pop_back(); visited[v] = 0;
			if (v == s) break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b; cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (graph[i].size())
		{
			ans++;
			if (!dfs_num[i]) DFS(i);
		}
	}

	cout << k - (ans - scc);
}