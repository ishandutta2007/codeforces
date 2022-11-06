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

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

set<int> merge(set<int> s, set<int> t) {
	for (auto &&x : s)
		t.insert(x);
	return t;
}

set<int> getDivisors(int x) {
	set<int> s;
	for (int i = 2; i*i <= x; ++i)
		while (x%i == 0) {
			s.insert(i);
			x /= i;
		}
	if (x != 1)
		s.insert(x);
	return s;
}

int n;
int a[(int)15e4];
int b[(int)15e4];

bool f(int x) {
	assert(x > 1);
	for (int i = 0; i < n; ++i)
		if (a[i] % x && b[i] % x)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];

	const set<int> s = merge(getDivisors(a[0]), getDivisors(b[0]));

	for (auto &&x : s)
		if (f(x)) {
			cout << x << '\n';
			return 0;
		}

	cout << -1;
	return 0;
}