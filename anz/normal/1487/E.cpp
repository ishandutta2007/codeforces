#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;
const ll INF = 1e9;

ll n[4];
ll a[4][N];

vector <int> graph[4][N];

ll segTree[4][N * 4];

ll ans[4][N];

void update(ll* segTree, int ptr, int l, int r, int i, ll val)
{
	if (i < l || r < i) return;
	if (l == r)
	{
		segTree[ptr] = val;
		return;
	}

	update(segTree, ptr * 2, l, (l + r) / 2, i, val);
	update(segTree, ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	segTree[ptr] = min(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

ll getVal(ll* segTree, int ptr, int l, int r, int i, int j)
{
	if (j < l || r < i) return INF;
	if (i <= l && r <= j) return segTree[ptr];

	return min(getVal(segTree, ptr * 2, l, (l + r) / 2, i, j),
		getVal(segTree, ptr * 2 + 1, (l + r) / 2 + 1, r, i, j));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 4; i++) for (int j = 0; j < N * 4; j++) segTree[i][j] = INF;

	for (int i = 0; i < 4; i++) cin >> n[i];

	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < n[k]; i++)
		{
			cin >> a[k][i];
		}
	}

	for (int k = 0; k < 3; k++)
	{
		int m; cin >> m;
		for (int i = 0; i < m; i++)
		{
			int x, y; cin >> x >> y;
			x--, y--;

			graph[k][y].push_back(x);
		}
	}

	for (int i = 0; i < n[0]; i++)
	{
		ans[0][i] = a[0][i];
		update(segTree[0], 1, 0, n[0] - 1, i, ans[0][i]);
	}

	for (int k = 1; k < 4; k++)
	{
		for (int i = 0; i < n[k]; i++)
		{
			for (int j : graph[k - 1][i])
			{
				update(segTree[k - 1], 1, 0, n[k - 1] - 1, j, INF);
			}

			ans[k][i] = segTree[k - 1][1] + a[k][i];

			for (int j : graph[k - 1][i])
			{
				update(segTree[k - 1], 1, 0, n[k - 1] - 1, j, ans[k - 1][j]);
			}

			update(segTree[k], 1, 0, n[k] - 1, i, ans[k][i]);
		}
	}

	ll res = INF;
	for (int i = 0; i < n[3]; i++) res = min(res, ans[3][i]);

	if (res == INF) cout << -1;
	else cout << res;
}