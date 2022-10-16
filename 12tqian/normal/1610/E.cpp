#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<long long> a(n);
	map<int, int> num;
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; 	
		++num[a[i]];
	}
	a.erase(unique(a.begin(), a.end()), a.end());
	int on = n;
	n = (int)a.size();
	int ans = 1;
	for (auto x : num) {
		ans = max(ans, x.second);
	}
	for (int i = 0; i < n - 1; ++i) {
		int cur = i + 1;
		int take = 1 + num[a[i]];
		long long diff = a[cur] - a[i];
		while (cur != n - 1) {
			long long least = diff + a[cur];
			int loc = lower_bound(a.begin() + cur + 1, a.end(), least) - a.begin();
			if (loc < n) {
				assert(loc > cur);
				cur = loc;
				++take;
				diff = a[cur] - a[i];
			} else {
				break;
			}
		}
		ans = max(ans, take);
	}
	cout << on - ans << '\n';
}

/**
 * let's say we have a, b, c
 * then we must have b <= (a + c) / 2
 * every element is at most average
 * a, b, c, d, 
 * let's say a = 0
 * 0, x, 2x, 4x, 8x, 16x
 * case work on the starting position
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}