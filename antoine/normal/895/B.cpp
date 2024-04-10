#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>
#include <queue>

using namespace std;

int n, x, K;
int a[(int)1e5];

int countInRange(const int i, const int j) {
	if (a[i] > a[j]) return -1;
	return a[j] / x - (a[i] - 1) / x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> x >> K;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	long long ans = 0;

	
	for (int i = 0, j = 0, k = 0; i < n; ++i) {
		while (j < n && countInRange(i, j) < K)
			++j;
		while (k < n && countInRange(i, k) <= K)
			++k;
		ans += k - j;
	}
	cout << ans;
	return 0;
}