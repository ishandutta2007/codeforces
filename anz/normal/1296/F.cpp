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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 5001;
int n, m;
vector <int> tree[N];
vector <pair<pii, int> > query;

int par[N];
int lv[N];
int ans[N];

void DFS(int s, int p, int l)
{
	par[s] = p;
	lv[s] = l;
	for (auto it : tree[s])
	{
		if (it == p) continue;
		DFS(it, s, l + 1);
	}
}

vector <pii> edge;
int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b;
		edge.push_back({ a,b });
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1, -1, 1);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, s; cin >> a >> b >> s;
		query.push_back({ {a,b},s });

		while (a != b)
		{
			if (lv[a] > lv[b])
			{
				ans[a] = max(ans[a], s);
				a = par[a];
			}
			else
			{
				ans[b] = max(ans[b], s);
				b = par[b];
			}
		}
	}

	bool isValid = true;
	for (auto it : query)
	{
		int a = it.first.first, b = it.first.second;
		int s = it.second;

		int res = 987654321;
		while (a != b)
		{
			if (lv[a] > lv[b])
			{
				res = min(res, ans[a]);
				a = par[a];
			}
			else
			{
				res = min(res, ans[b]);
				b = par[b];
			}
		}

		if (res != s)
		{
			isValid = false;
			break;
		}
	}

	if (!isValid)
	{
		cout << "-1";
		return 0;
	}

	for (auto it : edge)
	{
		int a = it.first, b = it.second;

		int res = -1;
		if (par[a] == b) res = ans[a];
		else res = ans[b];

		if (res == 0) cout << "1 ";
		else cout << res << ' ';
	}
}