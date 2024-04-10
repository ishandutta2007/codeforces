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

int n, h, a, b, k;

int f(int &x) {
	int res = 0;
	if (x > b) {
		res += x - b;
		x = b;
	}
	else if (x < a) {
		res += a - x;
		x = a;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> h >> a >> b >> k;
	for (int i = 0; i < k; ++i) {
		int t1, f1, t2, f2;
		cin >> t1 >> f1 >> t2 >> f2;
		if (t1 == t2) {
			cout << abs(f1 - f2) << '\n';
			continue;
		}
		int res = f(f1) + f(f2);
		res += abs(f1 - f2) + abs(t1 - t2);
		cout << res << '\n';
	}
	return 0;
}