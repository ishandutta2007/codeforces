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

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, x;
	cin >> n >> k >> x;
	int ans = 0;
	while (n-- > 0) {
		int a;
		cin >> a;
		ans += n < k ? min(a, x) : a;
	}
	cout << ans;

	return 0;
}