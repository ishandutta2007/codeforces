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
#undef NDEBUG
#include <assert.h>
#include <random>

using namespace std;
typedef long long ll;

struct FT {
	vector<int> v;
	FT(int n) : v(vector<int>(n + 1, 0)) {}
	void update(int i, const int a) {
		for (++i; i < v.size(); i += i & -i)
			v[i] += a;
	}
	int query(int i) const {
		assert(i >= -1 && i < (int)v.size() - 1);
		int sum = 0;
		for (++i; i; i -= i & -i)
			sum += v[i];
		return sum;
	}
	int query(int i, int j) const {
		return query(j) - query(i - 1);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	FT ft(n + 5);
	ll cnt = 0;
	for (int i = n - 1; i >= 0; --i) {
		cnt += ft.query(a[i] - 1);
		ft.update(a[i], 1);
	}
	cnt += n & 1;
	cout << ((cnt & 1) ? "Um_nik" : "Petr");
	return 0;
}