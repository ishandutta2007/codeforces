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
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, h, k;
	cin >> n >> h >> k;

	int curr = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		const int dt = max(0, (curr - (h - x) + k - 1) / k);
		curr = max(0, curr - dt * k);
		ans += dt;
		curr += x;
	}
	ans += (curr + k - 1) / k;
	cout << ans;
	return 0;
}