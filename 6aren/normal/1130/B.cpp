#include <bits/stdc++.h>

using namespace std;

int n;

pair<int, int> a[200005];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	//freopen("in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a + 1, a + 1 + 2 * n, cmp);

	int cur = 1;
	long long ans = 0;
	for (int i = 1; i <= 2 * n; i += 2) {
		ans += abs(a[i].second - cur);
		cur = a[i].second;
	}
	cur = 1;
	for (int i = 2; i <= 2 * n; i += 2) {
		ans += abs(a[i].second - cur);
		cur = a[i].second;
	}
	cout << ans;

	return 0;
}
//g++ online.cpp -o online.exe