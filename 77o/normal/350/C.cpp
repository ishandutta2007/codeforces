#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> b(n);
	int ans = 0;
	for (auto& p : b) {
		cin >> p.first >> p.second;
		if (p.first) {
			ans += 2;
		}
		if (p.second) {
			ans += 2;
		}
		ans += 2;
	}
	sort(b.begin(), b.end(), [](auto a, auto b) {
		return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
	});
	cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		if (b[i].first) {
			cout << "1 " << abs(b[i].first) << ' ' << "LR"[b[i].first > 0] << '\n'; 
		}
		if (b[i].second) {
			cout << "1 " << abs(b[i].second) << ' ' << "DU"[b[i].second > 0] << '\n'; 
		}
		cout << "2\n";
		if (b[i].first) {
			cout << "1 " << abs(b[i].first) << ' ' << "RL"[b[i].first > 0] << '\n'; 
		}
		if (b[i].second) {
			cout << "1 " << abs(b[i].second) << ' ' << "UD"[b[i].second > 0] << '\n'; 
		}
		cout << "3\n";
	}
	return 0;
}