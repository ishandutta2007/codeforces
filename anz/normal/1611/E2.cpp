#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
vector <int> graph[200001];
int fri[200001];
int dist[200001];

vector <pii> vec;
void DFS(int v, int p, int l)
{
	dist[v] = l;
	if (fri[v]) vec.push_back({ l, v });
	for (int nv : graph[v])
	{
		if (nv == p) continue;
		DFS(nv, v, l + 1);
	}
}

int cnt = 0;
int cache[200001];
void solve(int v, int p, int l)
{
	cache[v] = 1;
	if (v != 1 && graph[v].size() == 1) --cnt;

	for (int nv : graph[v])
	{
		if (nv == p) continue;
		if (cache[nv]) continue;
		if (l + 1 > dist[nv]) continue;

		solve(nv, v, l + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			fri[i] = 0;
			dist[i] = -1;
			cache[i] = 0;
		}

		queue <int> q;
		for (int i = 0; i < k; i++)
		{
			int x; cin >> x;
			fri[x] = 1;
		}

		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vec.clear();
		DFS(1, 0, 0);
		sort(vec.begin(), vec.end());

		cnt = 0;
		for (int i = 2; i <= n; i++)
			if (graph[i].size() == 1) cnt++;

		int ans = 0;
		bool flag = false;
		for (int i = 0; i < vec.size(); i++)
		{
			int v = vec[i].second;
			if (cache[v]) continue;

			solve(v, 0, 0);
			ans++;

			if (cnt == 0)
			{
				flag = true;
				break;
			}
		}

		if (flag) cout << ans << '\n';
		else cout << "-1\n";
	}
}