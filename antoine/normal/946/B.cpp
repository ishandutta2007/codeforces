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

	ll a, b;
	cin >> a >> b;
	for (;;) {
		const ll n = a, m = b;
		if (!a) break;
		b %= 2 * a;
		if (!b) break;
		a %= 2 * b;
		if (n == a && m == b)
			break;
	}
	cout << a << ' ' << b;
	return 0;
}