#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
	int x, y;
	bool operator<(const Point &other) const {
		if (x != other.x)
			return x < other.x;
		return y > other.y;
	}
};

ll dist(Point p1, Point p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	map<int, vector<Point>> mp;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		mp[max(x, y)].push_back( { x, y });
	}

	vector<array<Point, 2>> a;

	for (auto &&x : mp) {
		auto &&v = x.second;
		Point p1 = *min_element(v.begin(), v.end());
		Point p2 = *max_element(v.begin(), v.end());
		a.push_back(array<Point, 2> { p1, p2 });
	}

	n = (int) a.size();
	vector<array<ll, 2>> dp(2, { 0, 0 });

	for (int i = n - 1; i >= 0; --i) {
		ll d = dist(a[i][0], a[i][1]);
		for (int j = 0; j < 2; ++j) {
			ll &res = dp[i & 1][j];
			if (i == n - 1)
				res = d;
			else {
				const ll res1 = d + dist(a[i][!j], a[i + 1][j]) + dp[~i & 1][j];
				const ll res2 = d + dist(a[i][!j], a[i + 1][!j])
						+ dp[~i & 1][!j];
				res = min(res1, res2);
			}
		}
	}

	ll ans = 1LL << 60;
	for(int j = 0; j < 2; ++j) {
		ans = min(ans, a[0][j].x + a[0][j].y + dp[0][j]);
	}
	cout << ans;
	return 0;
}