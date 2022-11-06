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


void f(const int i, int temp, const vector<pair<int, int>> &v, vector<int> &res) {
	if (i == v.size())
		res.push_back(temp);
	else {
		for (int j = 0; j <= v[i].second; ++j) {
			f(i + 1, temp, v, res);
			temp *= v[i].first;
		}
	}
}

vector<int> getDivisors(int x) {
	vector<pair<int, int>> v;
	for (int i = 2; i*i <= x; ++i)
		if(x%i == 0) {
			v.emplace_back(i, 1);
			x /= i;
			while (x%i == 0) {
				v.back().second++;
				x /= i;
			}
		}
	if (x > 1)
		v.emplace_back(x, 1);

	vector<int> res;
	f(0, 1, v, res);
	return res;
}

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int l, r, x, y;
	cin >> l >> r >> x >> y;

	if (y%x != 0) {
		cout << 0;
		return 0;
	}
	
	y /= x;
	l = (l + x - 1) / x;
	r /= x;

	auto divisors = getDivisors(y);
	int res = 0;
	for (auto &&d : divisors) {
		assert(y%d == 0);
		if (l <= d && d <= r &&
			l <= y / d && y / d <= r &&
			gcd(d, y/d) == 1)
			res++;
	}
	cout << res;
	return 0;
}