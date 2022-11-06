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

const int N = 400001;
const int INF = 987654321;
int q, x;
int segTree[N * 4];
int val[N];
void update(int idx, int l, int r, int i, int val)
{
	if (l > i || r < i) return;
	if (l == r)
	{
		segTree[idx] = val;
		return;
	}

	update(idx * 2, l, (l + r) / 2, i, val);
	update(idx * 2 + 1, (l + r) / 2 + 1, r, i, val);

	segTree[idx] = min(segTree[idx * 2], segTree[idx * 2 + 1]);
}

int getMin(int idx, int l, int r, int i, int j)
{
	if (l > j || r < i) return INF;
	if (i <= l && r <= j) return segTree[idx];

	return min(
		getMin(idx * 2, l, (l + r) / 2, i, j),
		getMin(idx * 2 + 1, (l + r) / 2 + 1, r, i, j)
	);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fill(segTree, segTree + N * 4, INF);
	cin >> q >> x;
	for (int i = 0; i < x; i++) update(1, 0, x - 1, i, 0);
	while (q--)
	{
		int y; cin >> y;
		y %= x;
		val[y]++;
		update(1, 0, x - 1, y, val[y]);

		int ans = segTree[1];

		int l = -1, r = x;
		while (l + 1 < r)
		{
			int mid = (l + r) / 2;
			int res = getMin(1, 0, x - 1, 0, mid);
			if (res > ans) l = mid;
			else r = mid;
		}

		cout << ans * x + l + 1 << '\n';
	}
}