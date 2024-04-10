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
	cin.tie(0), cout.tie(0);

	cout << "YES\n";

	ll l, r;
	cin >> l >> r;
	for (; l <= r; l += 2) {
		cout << l << ' ' << l + 1 << '\n';
	}
	return 0;
}