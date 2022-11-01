#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int c, int c1, const vector<int>& a) {
	int n = a.size();
	vector<int> foc(2 * n + 1, -1);
	foc[n] = 0;
	int sum = n;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		sum += (a[i] == c) - (a[i] == c1);
		if (foc[sum] == -1) {
			foc[sum] = i + 1;
		}
		else {
			ret = max(ret, i - foc[sum] + 1);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), cnt(n);
	for (auto& x : a) {
		cin >> x;
		cnt[--x]++;
	}
	int c = max_element(cnt.begin(), cnt.end()) - cnt.begin();
	int ans = 0;
	for (int c1 = 0; c1 < min(n, 100); c1++) {
		if (c1 != c) {
			ans = max(ans, solve(c, c1, a));
		}
	}
	cout << ans << '\n';
}