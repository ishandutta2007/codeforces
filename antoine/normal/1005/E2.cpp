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


struct FT {
	int n;
	vector<int> v;
	FT(int n) : n(n), v(vector<int>(n + 1, 0)) {}
	void update(int i, const int a) {
		for (++i; i < v.size(); i += i & -i)
			v[i] += a;
	}
	int query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n);
		int sum = 0;
		for (++i; i; i -= i & -i)
			sum += v[i];
		return sum;
	}
};

ll f(vector<int> a, const int m) {
	for (int &x : a)
		x = x >= m ? 1 : -1;
	
	a.insert(a.begin(), a.size());
	partial_sum(a.begin(), a.end(), a.begin());
	
	FT ft(a.size() << 1 | 1);
	
	ll res = 0;
	for (int i = 0; i < a.size(); ++i) {
		assert(a[i] >= 0 && a[i] < ft.n);
		res += ft.query(a[i] - 1);
		ft.update(a[i], 1);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cout << f(a, m) - f(a, m + 1);

	return 0;
}