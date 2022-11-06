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


int f(const vector<int> &a) {
	return accumulate(a.begin(), a.end(), 0, [](const int acc, const int x) {
		return acc ^ x;
	});
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	if (f(a) != f(b)) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j)
			cout << 0 << ' ';
		cout << a[i] << '\n';
	}
	for (int j = 0; j < m - 1; ++j)
		cout << b[j] << ' ';
	b.pop_back();
	cout << (a.back() ^ f(b)) << '\n';
	return 0;
}