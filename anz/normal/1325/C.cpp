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
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <pii> edge;
vector <pii> graph[100001];

int ans[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(ans, -1, sizeof ans);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		edge.push_back({ u,v });
		graph[u].push_back({ v,i });
		graph[v].push_back({ u,i });
	}

	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		if (graph[i].size() >= 3)
		{
			flag = true;
			ans[graph[i][0].second] = 0;
			ans[graph[i][1].second] = 1;
			ans[graph[i][2].second] = 2;
			break;
		}
	}

	int res = 0;
	if (flag) res = 3;

	for (int i = 0; i < n - 1; i++)
	{
		if (ans[i] != -1) continue;
		ans[i] = res++;
	}

	for (int i = 0; i < n - 1; i++) cout << ans[i] << '\n';
}