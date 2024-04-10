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

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

pair<int, int> h(int a, int b) {
	const int g = gcd(a, b);
	a /= g;
	b /= g;
	if (a < 0 || (!a && b < 0)) {
		a = -a;
		b = -b;
	}
	return{ a, b };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x0, y0;
	cin >> n >> x0 >> y0;

	set<pair<int, int>> s;
	while (n--) {
		int x, y;
		cin >> x >> y;
		s.insert(h(x - x0, y - y0));
	}
	cout << s.size();

	return 0;
}