#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, c;
int a[200001];
int b[200001];

int ans[200001][2];

int ev[200001];

ll segTree[800001];
ll lazy[800001];

int left(int n) { return n << 1; }
int right(int n) { return (n << 1) + 1; }
void setLazy(int n, int l, int r)
{
	segTree[n] += (r - l + 1) * lazy[n];
	if (l != r)
	{
		lazy[left(n)] += lazy[n];
		lazy[right(n)] += lazy[n];
	}
	lazy[n] = 0;
}
void update(int n, ll v, int l, int r, int i, int j)
{
	if (lazy[n]) setLazy(n, l, r);
	if (j < l || r < i) return;
	if (i <= l && r <= j)
	{
		segTree[n] += (r - l + 1) * v;
		if (l != r)
		{
			lazy[left(n)] += v;
			lazy[right(n)] += v;
		}
		return;
	}
	update(left(n), v, l, (l + r) / 2, i, j);
	update(right(n), v, (l + r) / 2 + 1, r, i, j);

	segTree[n] = min(segTree[left(n)], segTree[right(n)]);
}

ll getVal(int n, int l, int r, int i, int j)
{
	if (lazy[n]) setLazy(n, l, r);
	if (j < l || r < i) return 9876543210;
	if (i <= l && r <= j)
	{
		return segTree[n];
	}
	ll lSum = getVal(left(n), l, (l + r) / 2, i, j);
	ll rSum = getVal(right(n), (l + r) / 2 + 1, r, i, j);

	return min(lSum, rSum);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> c;
	for (int i = 1; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) cin >> b[i];

	ans[1][0] = a[1];
	ans[1][1] = b[1] + c;
	ev[1] = min(ans[1][0] + c, ans[1][1]);
	update(1, ev[1], 1, 200000, 1, 1);

	for (int i = 2; i < n; i++)
	{
		ans[i][0] = min(ans[i - 1][0], ans[i - 1][1]) + a[i];
		ans[i][1] = getVal(1, 1, 200000, 1, i - 1) + b[i];

		update(1, b[i], 1, 200000, 1, i - 1);
		ev[i] = min(ans[i][0] + c, ans[i][1]);
		update(1, ev[i], 1, 200000, i, i);
	}

	for (int i = 0; i < n; i++) cout << min(ans[i][0], ans[i][1]) << ' ';
}