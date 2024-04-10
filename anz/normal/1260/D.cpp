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

const int N = 200001;
ll m, n, k, t;
ll a[N];

vector <pair<ll, pll> > v;
multiset <ll> s;

int segTree[N * 4], cnt[N * 4];
void update(int idx, ll val, int l, int r, int i, int j)
{
	if (r < i || l > j) return;
	if (i <= l && r <= j)
		cnt[idx] += val;
	else
	{
		update(idx * 2, val, l, (l + r) / 2, i, j);
		update(idx * 2 + 1, val, (l + r) / 2 + 1, r, i, j);
	}

	if (cnt[idx]) segTree[idx] = r - l + 1;
	else
	{
		if (l == r) segTree[idx] = 0;
		else segTree[idx] = segTree[idx * 2] + segTree[idx * 2 + 1];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> m >> n >> k >> t;
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < k; i++)
	{
		ll l, r, d; cin >> l >> r >> d;
		v.push_back({ d, {l,r} });
		s.insert(d);
	}
	sort(a, a + m);
	sort(v.rbegin(), v.rend());

	ll md = *(--s.end());
	int idx = lower_bound(a, a + m, md) - a;
	ll ans = m - idx;

	for (int i = 0; i < k; i++)
	{
		ll l = v[i].second.first, r = v[i].second.second;
		ll d = v[i].first;

		update(1, 1, 1, n, l, r);

		ll ct = n + 1 + segTree[1] * 2;
		if (ct > t) break;

		s.erase(s.find(d));

		md = 0;
		if (s.size() > 0) md = *(--s.end());

		idx = lower_bound(a, a + m, md) - a;
		ll res = m - idx;

		ans = max(ans, res);
	}

	cout << ans;
}