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

using namespace std;

const int MaxN = 1e6;
int spf[MaxN + 1] = { 0 };

auto getPrimes(int x) {
	vector<int> res;
	while (x != 1) {
		res.push_back(spf[x]);
		do {
			x /= spf[x];
		} while (spf[x] == res.back());
	}
	return res;
}

void incExc(int i, int temp, const vector<int> &v, vector<int> &res) {
	if (i == v.size())
		res.push_back(temp);
	else {
		incExc(i + 1, temp, v, res);
		incExc(i + 1, -temp * v[i], v, res);
	}
}

auto incExc(vector<int> v) {
	vector<int> res;
	incExc(0, 1, v, res);
	return res;
}

auto f(const long long x, const vector<int> &ie) {
	long long count = 0;
	for (auto &&y : ie)
		if (y > 0)
			count += x / y;
		else
			count -= x / (-y);
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 2; i <= MaxN; ++i)
		if (!spf[i]) {
			for (int j = i; j <= MaxN; j += i)
				if (!spf[j])
					spf[j] = i;
		}

	int t;
	cin >> t;
	while (t-- > 0) {
		int x, p, k;
		cin >> x >> p >> k;
		auto ie = incExc(getPrimes(p));
		long long lo = 1;
		long long hi = 1e18;
		while (lo < hi) {
			auto mid = (lo + hi) >> 1;
			auto count = f(mid, ie) - f(x, ie);
			if (count >= k)
				hi = mid;
			else
				lo = mid + 1;
		}
		cout << lo << '\n';
	}

	return 0;
}