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

int n, m;
int a[N];
pii hero[N];

int segTree[N * 4];
void update(int ptr, int v, int l, int r, int i)
{
	if (l > i || r < i) return;
	if (l == r)
	{
		segTree[ptr] = v; return;
	}

	update(ptr * 2, v, l, (l + r) / 2, i);
	update(ptr * 2 + 1, v, (l + r) / 2 + 1, r, i);
	segTree[ptr] = max(segTree[ptr * 2], segTree[ptr * 2 + 1]);
}

int getVal(int ptr, int l, int r, int i, int j)
{
	if (l > j || r < i) return 0;
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

	int T; cin >> T;
	while (T--)
	{
		int mm = -1;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i], mm = max(mm, a[i]);
		cin >> m;
		for (int i = 0; i < m; i++) cin >> hero[i].first >> hero[i].second;

		sort(hero, hero + m);

		if (hero[m - 1].first < mm)
		{
			cout << "-1\n";
			continue;
		}

		for (int i = 0; i < m; i++)
		{
			update(1, hero[i].second, 0, m - 1, i);
		}

		int ans = 1;

		int curM = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			curM = max(curM, a[i]);
			cnt++;
			pii tmp = { curM,0 };
			int idx = lower_bound(hero, hero + m, tmp) - hero;

			int maxE = getVal(1, 0, m - 1, idx, m - 1);
			if (maxE >= cnt)
				continue;

			ans++;
			curM = a[i], cnt = 1;

		}

		cout << ans << '\n';
	}
}