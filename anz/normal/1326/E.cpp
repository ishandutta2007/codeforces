#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 300001;
int n;
int p[N];
int pi[N];
int q[N];

int segTree[N * 4];
int lazy[N * 4];

void setLazy(int ptr, int l, int r)
{
	int val = lazy[ptr]; lazy[ptr] = 0;
	segTree[ptr] += val;

	if (l != r)
	{
		lazy[ptr * 2] += val;
		lazy[ptr * 2 + 1] += val;
	}
}

void update(int ptr, int l, int r, int i, int j, int val)
{
	if (lazy[ptr]) setLazy(ptr, l, r);
	if (j < l || r < i) return;
	if (i <= l && r <= j)
	{
		segTree[ptr] += val;

		if (l != r)
		{
			lazy[ptr * 2] += val;
			lazy[ptr * 2 + 1] += val;
		}

		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, j, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j, val);

	segTree[ptr] = max(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

int getVal(int ptr, int l, int r, int i, int j)
{
	if (lazy[ptr]) setLazy(ptr, l, r);
	if (j < l || r < i) return -987654321;
	if (i <= l && r <= j) return segTree[ptr];

	return max(
		getVal(ptr * 2, l, (l + r) / 2, i, j),
		getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j)
	);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		pi[p[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> q[i];
	}

	int ans = n;
	cout << ans;
	update(1, 1, n, 1, pi[n], 1);

	for (int i = 1; i < n; i++)
	{
		update(1, 1, n, 1, q[i], -1);
		while (true)
		{
			if (segTree[1] > 0) break;
			update(1, 1, n, 1, pi[--ans], 1);
		}

		cout << ' ' << ans;
	}
}