#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>
#include <ctime>
#include <random>
#include <functional>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;
const int INF = 987654321;
int n;
int a[N];
vector <pii> graph[N];
int par[N];
int dp[N];

int maxDiff(int v, int p)
{
	par[v] = p;
	if (a[v] == 1) dp[v] = 1;
	else dp[v] = -1;

	for (auto& it : graph[v])
	{
		if (it.first == p) continue;
		int res = maxDiff(it.first, v);

		if (res >= 0)
		{
			dp[v] += res;
			it.second = 1;
		}
	}

	return dp[v];
}

int ans[N];
void solve(int v, int flag)
{
	int& res = ans[v];
	res = dp[v];
	for (auto& it : graph[v])
	{
		if (it.first == par[v])
		{
			if (flag)
			{
				res = max(res, ans[it.first]);
			}
			else
			{
				res = max(res, res + ans[it.first]);
			}
			break;
		}
	}

	for (auto it : graph[v])
	{
		if (it.first == par[v]) continue;
		solve(it.first, it.second);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fill(dp, dp + N, -INF);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back({ v,0 });
		graph[v].push_back({ u,0 });
	}

	maxDiff(1, 0);
	solve(1, 0);

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}