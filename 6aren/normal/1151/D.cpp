#include<bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[100005];

bool cmp(pair<int, int> x, pair<int, int> y) {
	return (x.first - y.first) > (x.second - y.second);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + 1 + n, cmp);
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		res += 1LL * (i - 1) * a[i].first + 1LL * (n - i) * a[i].second;
	}
	cout << res;
	return 0;
}