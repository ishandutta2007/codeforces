#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <numeric>

using namespace std;
typedef long long ll;

ll f(vector<int> a) {
	int count = a[0];
	a[0] = 0;
	for (int i = 1; count % 14; i = (i + 1) % 14) {
		a[i]++;
		count--;
	}
	ll ans = 0;
	for (int i = 0; i < 14; ++i) {
		a[i] += count / 14;
		if (!(a[i] & 1))
			ans += a[i];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> a(14);
	for (int i = 0; i < 14; ++i)
		cin >> a[i];
	ll ans = 0;
	for (int i = 0; i < 14; ++i) {
		rotate(a.begin(), a.begin() + 1, a.end());
		ans = max(ans, f(a));
	}
	cout << ans;
	return 0;
}