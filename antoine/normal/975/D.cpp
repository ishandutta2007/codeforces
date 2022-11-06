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
#include <numeric>

using namespace std;
typedef long long ll;

int n, a, b;

struct Ghost {
	int x, vx, vy;

	ll group() {
		// a*x - y + b = 0
		return (ll)a * (x + vx) + -1ll * ((ll)a * x + b + vy);
	}
};

ll f(vector<Ghost> &v) {
	ll res = 0;
	map<int, map<int, ll>> mp;
	for (auto &&x : v)
		++mp[x.vx][x.vy];
	for (auto &&x : mp)
		for (auto&&y : x.second)
			res += (y.second * (y.second - 1)) >> 1;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b;
	map<ll, vector<Ghost>> groups;
	for (int i = 0; i < n; ++i) {
		Ghost g;
		cin >> g.x >> g.vx >> g.vy;
		groups[g.group()].push_back(g);
	}

	ll ans = 0;
	for (auto &&x : groups)
		ans += ((x.second.size()* ((ll)x.second.size() - 1)) >> 1) - f(x.second);
	cout << 2*ans;
	return 0;
}