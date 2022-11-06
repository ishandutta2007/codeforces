#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001], b[200001];
vector <pii> idx[200001];

int cache[200001];
vector <int> stk;
int ans[200001];
void DFS(int v, int c)
{
	if (cache[v]) return;

	cache[v] = 1;
	stk.push_back(v);

	ans[v] = c;

	int ca = a[v], cb = b[v];
	for (int i = 0; i < 2; i++)
	{
		if (idx[ca][i].first != v)
		{
			if (idx[ca][i].second == 0) DFS(idx[ca][i].first, 1 - c);
			else DFS(idx[ca][i].first, c);
		}

		if (idx[cb][i].first != v)
		{
			if (idx[cb][i].second == 1) DFS(idx[cb][i].first, 1 - c);
			else DFS(idx[cb][i].first, c);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			idx[i].clear();
			cache[i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			idx[a[i]].push_back({ i,0 });
		}

		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			idx[b[i]].push_back({ i,1 });
		}

		bool hasAns = true;
		for (int i = 1; i <= n; i++)
		{
			if (idx[i].size() != 2) hasAns = false;
		}

		if (!hasAns)
		{
			cout << "-1\n";
			continue;
		}

		vector <int> res;
		for (int i = 1; i <= n; i++)
		{
			if (cache[i]) continue;

			stk.clear();
			DFS(i, 0);

			int cnt = 0;
			for (int v : stk)
			{
				if (ans[v] == 0) cnt++;
			}

			if (cnt * 2 > stk.size())
			{
				for (int v : stk) if (ans[v] == 1) res.push_back(v);
			}
			else
			{
				for (int v : stk) if (ans[v] == 0) res.push_back(v);
			}
		}

		cout << res.size() << '\n';
		for (int v : res) cout << v << ' ';
		cout << '\n';
	}
}