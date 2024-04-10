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


	int n, k;
	cin >> n >> k;


	vector<ll> p10(11, 1);
	for (int i = 1; i <= 10; ++i) {
		p10[i] = p10[i - 1] * 10 % k;
	}



	vector<ll> a(n);
	unordered_map<ll, ll> occ[11];
	for (int i = 1; i <= 10; ++i)
		occ[i].reserve(n << 1);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 1; j <= 10; ++j)
			++occ[j][a[i] * p10[j] % k];
	}


	ll res = 0;
	for (auto &&x : a) {
		const int j = to_string(x).size();
		const ll y = ((-x) % k + k) % k;
		auto it = occ[j].find(y);
		res += it == occ[j].end() ? 0 : it->second;
		res -= x * p10[j] % k == y;
	}


	cout << res << '\n';
	return 0;
}