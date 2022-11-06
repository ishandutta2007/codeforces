#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;
const ll INF = 1e18;

ll n, s;
ll a[N];

ll segTree[N * 4];
void update(int ptr, int l, int r, int i, ll val)
{
	if (i < l || r < i) return;
	if (l == r)
	{
		segTree[ptr] = val;
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	segTree[ptr] = min(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

int findLast(int ptr, int l, int r, ll val)
{
	if (segTree[ptr] >= val) return r + 1;

	if (l == r) return l;

	if (segTree[ptr * 2] >= val) return findLast(ptr * 2 + 1, (l + r) / 2 + 1, r, val);
	return findLast(ptr * 2, l, (l + r) / 2, val);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> s;
		fill(segTree, segTree + n * 4, INF);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			a[i] += a[i - 1];
		}

		for (int i = 1; i <= n; i++)
			update(1, 1, n, i, a[i]);

		int ans = 0;
		int l = -1, r = -1;

		for (int i = 1; i <= n; i++)
		{
			if (a[i] - a[i - 1] < -s) continue;
			int res = findLast(1, 1, n, a[i - 1] - s);
			if (res - i > ans)
			{
				ans = res - i;
				l = i, r = res - 1;
			}
		}

		if (!ans) cout << "-1\n";
		else cout << l << ' ' << r << '\n';
	}
}