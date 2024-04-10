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

using namespace std;
typedef long long ll;


int f(ll a, int d) {
	int res = 0;
	while (a%d == 0) {
		a /= d;
		++res;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector < pair<pair<int, int>, ll>> v;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		v.push_back({ { -f(a, 3), f(a, 2) }, a });
	}
	sort(v.begin(), v.end());
	for (auto &&x : v)
		cout << x.second << ' ';
	return 0;
}