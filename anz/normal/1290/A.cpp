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

const ll INF = 1000000000;
const int N = 5001;
int n, m, k;
ll a[N];
ll mx[N];

ll segTree[N * 4];
void update(int ptr, int l, int r, int i, ll val)
{
	if (l > i || r < i) return;
	if (i <= l && r <= i)
	{
		segTree[ptr] = val;
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);
	segTree[ptr] = min(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

ll getVal(int ptr, int l, int r, int i, int j)
{
	if (l > j || r < i) return INF;
	if (i <= l && r <= j) return segTree[ptr];

	return min(
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
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) cin >> a[i];

		k = min(k, m - 1);

		fill(segTree, segTree + N * 4, INF);
		int d = n - m;
		for (int i = 0; i + d < n; i++)
		{
			mx[i] = max(a[i], a[i + d]);
			update(1, 0, n - 1, i, mx[i]);
		}

		ll ans = 0;
		for (int i = 0; i <= k; i++)
		{
			ll res = getVal(1, 0, n - 1, i, n - 1 - k + i - d);
			ans = max(ans, res);
		}

		cout << ans << '\n';
	}
}