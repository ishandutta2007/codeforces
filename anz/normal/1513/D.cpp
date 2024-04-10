#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll N = 200001;
const ll INF = 1e9 + 7;

ll n, p;
ll a[200001];

pll seg_min[N * 4];
ll seg_gcd[N * 4];

void update(int ptr, int l, int r, int i, ll val)
{
	if (i < l || r < i) return;
	if (l == r)
	{
		seg_min[ptr] = { val, l };
		seg_gcd[ptr] = val;
		return;
	}

	update(ptr * 2, l, (l + r) / 2, i, val);
	update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, val);

	seg_min[ptr] = min(seg_min[ptr * 2], seg_min[ptr * 2 + 1]);
	seg_gcd[ptr] = gcd(seg_gcd[ptr * 2], seg_gcd[ptr * 2 + 1]);
}

pll getMin(int ptr, int l, int r, int i, int j)
{
	if (j < l || r < i) return { INF, -1 };
	if (i <= l && r <= j) return seg_min[ptr];

	return min(getMin(ptr * 2, l, (l + r) / 2, i, j), getMin(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j));
}

ll getGcd(int ptr, int l, int r, int i, int j)
{
	if (j < l || r < i) return 0;
	if (i <= l && r <= j) return seg_gcd[ptr];

	return gcd(getGcd(ptr * 2, l, (l + r) / 2, i, j), getGcd(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j));
}

ll solve(int l, int r)
{
	if (l == r) return 0;

	pii it = getMin(1, 0, n - 1, l, r);
	ll val = it.first;
	int idx = it.second;

	ll res = 0;

	int pl = l - 1, pr = idx;
	while (pl + 1 < pr)
	{
		int m = (pl + pr) / 2;
		if (getGcd(1, 0, n - 1, m, idx) == val) pr = m;
		else pl = m;
	}

	ll nl = pr;

	pl = idx, pr = r + 1;
	while (pl + 1 < pr)
	{
		int m = (pl + pr) / 2;
		if (getGcd(1, 0, n - 1, idx, m) == val) pl = m;
		else pr = m;
	}

	ll nr = pl;
	
	res += min(p, val) * (nr - nl);

	if (l <= nl)
	{
		if (nl == idx && l <= nl - 1) res += solve(l, nl - 1) + p;
		else res += solve(l, nl);
	}

	if (nr <= r)
	{
		if (nr == idx && nr + 1 <= r) res += solve(nr + 1, r) + p;
		else res += solve(nr, r);
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> p;
		for (int i = 0; i < n * 4; i++)
		{
			seg_min[i] = { INF, -1 };
			seg_gcd[i] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			update(1, 0, n - 1, i, a[i]);
		}

		ll ans = solve(0, n - 1);
		cout << ans << '\n';
	}
}