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

void f() {
	ll n, k, s;
	cin >> n >> k >> s;
	if (s > (n - 1) * k || s < k) {
		cout << "NO";
		return;
	}

	cout << "YES\n";

	int first = 1;
	int last = n;
	int direction = 1;

	int extra = k - ((s + n - 2) / (n - 1));
	assert(extra >= 0);

	for (; s > 0;) {
		if (abs(last - first) > s) {
			if (first == 1) {
				last = 1 + s;
			}
			else {
				last = n - s;
			}
		}
		s -= abs(last - first);
		for (int curr = first; curr + direction != last && extra; extra--) {
			curr += direction;
			cout << curr << ' ';
		}
		cout << last << ' ';
		direction *= -1;
		swap(first, last);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	f();
	return 0;
}