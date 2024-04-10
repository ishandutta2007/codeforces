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
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	int diff = 0;
	for (; !a.empty(); ++ans) {
		do {
			if (diff < 0) {
				diff += a.back();
				a.pop_back();
			}
			else {
				diff -= b.back();
				b.pop_back();
			}
		} while (diff);
	}
	cout << ans;
	return 0;
}