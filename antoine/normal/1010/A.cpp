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

	int n, m;
	cin >> n >> m;
	double limit = m;
	for (int i = 0; i < n + n; ++i) {
		int x;
		cin >> x;
		if (x == 1) {
			cout << -1;
			return 0;
		}
		limit /= 1 - 1.0 / x;
	}
	cout << fixed << setprecision(10) << limit - m;
	return 0;
}