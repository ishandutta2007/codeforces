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

const int N = 200001;
const ll INF = 987654321987654321;
int n, m, p;
pll weapon[N];
pll armor[N];

pair<pll, ll> monster[N];

ll segTree[N * 4];
ll lazy[N * 4];

void setLazy(int ptr, int l, int r)
{
	ll val = lazy[ptr];
	segTree[ptr] += val;
	if (l != r)
	{
		lazy[ptr * 2] += val;
		lazy[ptr * 2 + 1] += val;
	}

	lazy[ptr] = 0;
}

void update(int ptr, int l, int r, int i, int j, ll val)
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

ll getVal(int ptr, int l, int r, int i, int j)
{
	if (lazy[ptr]) setLazy(ptr, l, r);

	if (j < l || r < i) return -INF;
	if (i <= l && r <= j) return segTree[ptr];

	return max(
		getVal(ptr * 2, l, (l + r) / 2, i, j),
		getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j)
	);
}

vector <int> aIdx;
int getIdx(ll x) { return lower_bound(aIdx.begin(), aIdx.end(), x) - aIdx.begin(); }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> weapon[i].first >> weapon[i].second;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> armor[i].first >> armor[i].second;
	}
	for (int i = 0; i < p; i++)
	{
		cin >> monster[i].first.first >> monster[i].first.second
			>> monster[i].second;
	}
	sort(monster, monster + p);

	for (int i = 0; i < m; i++)
		aIdx.push_back(armor[i].first);

	sort(aIdx.begin(), aIdx.end());
	aIdx.erase(unique(aIdx.begin(), aIdx.end()), aIdx.end());

	sort(armor, armor + m);
	for (int i = 0; i < m; i++)
	{
		if (i && armor[i].first == armor[i - 1].first) continue;
		int idx = getIdx(armor[i].first);
		update(1, 0, aIdx.size() - 1, idx, idx, -armor[i].second);
	}

	m = aIdx.size();

	sort(weapon, weapon + n);
	
	ll ans = -INF;

	int ptr = 0;
	for (int i = 0; i < n; i++)
	{
		ll atk = weapon[i].first;
		ll cost = weapon[i].second;

		while (ptr < p && monster[ptr].first.first < atk)
		{
			ll m_def = monster[ptr].first.second;
			ll m_coin = monster[ptr].second;

			int idx = upper_bound(aIdx.begin(), aIdx.end(), m_def) - aIdx.begin();
			update(1, 0, m - 1, idx, m - 1, m_coin);

			ptr++;
		}

		ll res = getVal(1, 0, m - 1, 0, m - 1) - cost;

		ans = max(ans, res);
	}

	cout << ans;
}