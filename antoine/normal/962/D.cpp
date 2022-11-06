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
#include <stack>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<ll, vector<ll>> occ;
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		occ[a[i]].push_back(i);
	}
	while (occ.size()) {
		auto &v = occ.begin()->second;
		sort(v.begin(), v.end());
		for (ll i = 0; i + 1 < v.size(); i += 2) {
			a[v[i]] = 0;
			occ[a[v[i + 1]] <<= 1].push_back(v[i + 1]);
		}
		occ.erase(occ.begin());
	}
	a.erase(remove(a.begin(), a.end(), 0), a.end());
	cout << a.size() << '\n';
	for (auto &&x : a)
		cout << x << ' ';
	return 0;
}