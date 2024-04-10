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

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int ans = n + 2;
	while (m-- > 0) {
		int l, r;
		cin >> l >> r;
		ans = min(ans, r - l + 1);
	}
	cout << ans << '\n';
	for (int i = 0; i < n; ++i) {
		if (i)
			cout << ' ';
		cout << (i %ans);
	}
	return 0;
}