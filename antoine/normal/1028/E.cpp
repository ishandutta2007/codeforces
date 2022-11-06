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

	int n;
	cin >> n;
	vector<ll> b(n);
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	b.insert(b.end(), b.begin(), b.end());
	auto it = max_element(b.begin() + n, b.end());
	if (*it == *min_element(b.begin(), b.end())) {
		if (*it)
			cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 0; i < n; ++i)
				cout << "1 ";
		}
		return 0;
	}
	while (*it == *prev(it))
		assert(--it != b.begin());
	if (it + n < b.end()) it += n;
	*prev(it) += *it;
	it -= n - 1;
	vector<ll> a(it, it + n);
	partial_sum(a.rbegin(), a.rend(), a.rbegin());
	copy(a.begin(), a.end(), it);
	copy(b.begin() + n, it + n, b.begin());
	b.resize(n);
	cout << "YES\n";
	for (auto &&x : b)
		cout << x << ' ';
	return 0;
}