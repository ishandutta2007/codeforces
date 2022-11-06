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

int n, m;
ll x[200001];

vector <ll> segTree(1000000);
vector <ll> lazy(1000000);

void setLazy(int idx, int l, int r)
{
	segTree[idx] += lazy[idx];
	if (l != r)
	{
		lazy[idx * 2] += lazy[idx];
		lazy[idx * 2 + 1] += lazy[idx];
	}
	lazy[idx] = 0;
}

void update(int idx, int l, int r, int i, int j, ll val)
{
	if (lazy[idx]) setLazy(idx, l, r);
	if (r < i || l > j) return;
	if (i <= l && r <= j)
	{
		segTree[idx] += val;
		if (l != r)
		{
			lazy[idx * 2] += val;
			lazy[idx * 2 + 1] += val;
		}

		return;
	}

	update(idx * 2, l, (l + r) / 2, i, j, val);
	update(idx * 2 + 1, (l + r) / 2 + 1, r, i, j, val);
	segTree[idx] = segTree[idx * 2] + segTree[idx * 2 + 1];
}

ll getVal(int idx, int l, int r, int i)
{
	if (lazy[idx]) setLazy(idx, l, r);
	if (r < i || l > i) return 0;
	if (i <= l && r <= i)
	{
		return segTree[idx];
	}

	ll lv = getVal(idx * 2, l, (l + r) / 2, i);
	ll rv = getVal(idx * 2 + 1, (l + r) / 2 + 1, r, i);
	return lv + rv;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> x[i];

	for (int i = 0; i < m - 1; i++)
	{
		int a = x[i], b = x[i + 1];
		if (a > b) swap(a, b); // now a < b
		if (a == b) continue;

		update(1, 1, n, 1, a - 1, b - a);
		update(1, 1, n, a, a, b - 1);
		update(1, 1, n, a + 1, b - 1, b - a - 1);
		update(1, 1, n, b, b, a);
		update(1, 1, n, b + 1, n, b - a);
	}

	for (int i = 1; i <= n; i++)
		cout << getVal(1, 1, n, i) << ' ';
}