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
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int g(int x) {
	int res = 1;
	for (int i = 2; i*i <= x; ++i)
		if (x%i == 0) {
			int cnt = 0;
			do {
				cnt++;
				x /= i;
			} while (x%i == 0);
			if (cnt & 1)
				res *= i;
		}
	return res *= x;
}

int f(int x) {
	return !x ? 0 : x > 0 ? g(x) : -g(-x);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), ans(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] = f(a[i]);
	}
	vector<int> prev(n, -1);
	for(int i = 0; i < n; ++i)
		for(int j = i + 1 ; j<n;++j)
			if (a[i] == a[j]) {
				prev[j] = i;
				break;
			}


	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = i; j < n; ++j) {
			cnt += a[j] && prev[j] < i;
			++ans[max(1, cnt)];
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	return 0;
}