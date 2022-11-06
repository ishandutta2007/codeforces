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

void No() {
	cout << "NO\n";
	exit(0);
}

ll n, m, k;

bool ok(ll x, ll y) {
	return x <= n && y <= m;
}


void _yes(const ll x, const ll y) {
	assert(ok(x, y));
	cout << "YES\n";
	cout << 0 << ' ' << 0 << '\n';
	cout << x << ' ' << 0 << '\n';
	cout << 0 << ' ' << y << '\n';
	exit(0);
}

void yes(const ll x, const ll y) {
	if (ok(x, y))
		_yes(x, y);
	else if (ok(y, x))
		_yes(y, x);
	else
		assert(false);
}

void getDivisorsHelper(int i, ll curr, const vector<pair<ll, int>> &v, vector<ll> &res) {
	if (i == v.size())
		res.push_back(curr);
	else {
		for (int j = 0; j <= v[i].second; ++j) {
			getDivisorsHelper(i + 1, curr, v, res);
			curr *= v[i].first;
		}
	}
}


map<ll, int> getFact(ll x) {
	map<ll, int> mp;
	for (ll i = 2; i*i <= x; ++i)
		if (x%i == 0) {
			mp[i] = 1;
			for (x /= i; x%i == 0; x /= i)
				++mp[i];
		}
	mp[x] = 1;
	return mp;
}

map<ll, int> merge(map<ll, int> mp1, map<ll, int> mp2) {
	for (auto &&x : mp1)
		mp2[x.first] += x.second;
	return mp2;
}

vector<ll> getDivisors(map<ll, int> mp) {
	vector<pair<ll, int>> v(mp.begin(), mp.end());

	vector<ll> res;
	getDivisorsHelper(0, 1, v, res);
	return res;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;

	if (2 * n * m % k != 0) No();
	const ll prod = 2 * n * m / k;

	for (auto &&x : getDivisors(merge(merge(getFact(n), getFact(m)), getFact(2))))
		if (x <= prod && prod%x == 0 && (ok(x, prod / x) || ok(prod / x, x)))
			yes(x, prod / x);

	No();
	return 0;
}