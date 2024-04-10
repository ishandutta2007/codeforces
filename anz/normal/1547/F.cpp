#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;

int n;
int a[N];

int segTree[N * 2 * 4];
void update(int ptr, int l, int r, int i, int val)
{
	if (i < l || r < i) return;
	if (l == r)
	{
		segTree[ptr] = val;
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	segTree[ptr] = gcd(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

int getVal(int ptr, int l, int r, int i, int j)
{
	if (j < l || r < i) return 0;
	if (i <= l && r <= j) return segTree[ptr];

	return gcd(
		getVal(ptr * 2, l, (l + r) / 2, i, j),
		getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j)
	);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		fill(segTree, segTree + n * 2 * 4 + 1, 0);

		int g = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			g = gcd(g, a[i]);
		}

		for (int i = 0; i < n; i++)
		{
			a[i] /= g;
			update(1, 0, 2 * n - 1, i, a[i]);
			update(1, 0, 2 * n - 1, n + i, a[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int l = i - 1, r = i + n;
			while (l + 1 < r)
			{
				int m = (l + r) / 2;
				int res = getVal(1, 0, 2 * n - 1, i, m);

				if (res == 1) r = m;
				else l = m;
			}

			int res = r - i;
			ans = max(ans, res);
		}

		cout << ans << '\n';
	}
}