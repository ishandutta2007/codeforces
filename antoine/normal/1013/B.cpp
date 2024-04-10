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

	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i] & x;
	}
	if (set<int>(a.begin(), a.end()).size() < n) {
		cout << 0;
		return 0;
	}

	multiset<int> ms(b.begin(), b.end());
	for (int i = 0; i < n; ++i) {
		ms.erase(ms.find(b[i]));
		if (ms.count(a[i])) {
			cout << 1;
			return 0;
		}
		ms.insert(b[i]);
	}

	if (set<int>(b.begin(), b.end()).size() < n) {
		cout << 2;
		return 0;
	}
	cout << -1;
	return 0;
}