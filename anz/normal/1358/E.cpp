#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 500001;
const ll INF = 987654321987654321;

ll n, x;
ll a[N];
ll psum[N];

ll segTree[N * 4];
ll lazy[N * 4];

void setLazy(int ptr, int l, int r)
{
	ll val = lazy[ptr];
	lazy[ptr] = 0;

	segTree[ptr] += val;
	if (l != r)
	{
		lazy[ptr * 2] += val;
		lazy[ptr * 2 + 1] += val;
	}
}

void update(int ptr, int l, int r, int i, int j, ll val)
{
	if (lazy[ptr]) setLazy(ptr, l, r);

	if (l > j || r < i) return;
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

ll getVal(int ptr, int l, int r, int i, int j)
{
	if (lazy[ptr]) setLazy(ptr, l, r);

	if (l > j || r < i) return -INF;
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
	ll m = (n + 1) / 2;

	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}

	cin >> x;

	ll sum = psum[m] + x * (n / 2);
	//if (sum > 0)
	//{
	//	cout << n;
	//	return 0;
	//}

	for (int i = 0; i <= m; i++)
	{
		update(1, 0, m, i, i, psum[i]);
	}

	for (int i = 0; i <= n / 2; i++)
	{
		update(1, 0, m, i, i, -sum);
		update(1, 0, m, 0, i - 1, x);

		ll res = getVal(1, 0, m, 0, i);
		if (res < 0)
		{
			cout << n - i;
			return 0;
		}
	}

	cout << -1;
}