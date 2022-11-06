#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool isPrime(const int x) {
	static map<int, bool> mp;
	if (mp.count(x))
		return mp.at(x);
	bool &res = mp[x];
	if (x < 2)
		return res = false;
	for (int i = 2; i < x; ++i)
		if (x % i == 0)
			return res = false;
	return res = true;
}

vector<pair<int, int>> f(const int n) {
	vector<pair<int, int>> res;
	for (int i = 1; i <= n; ++i)
		res.push_back( { i, i % n + 1 });
	for (int i = 1; !isPrime(res.size()); ++i)
		if (i % 4 == 1 || i % 4 == 2) {
			assert(i + 2 <= n);
			res.push_back( { i, i + 2 });
		}
	return res;

}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int n = 3; n <= 1000; ++n)
		f(n);

	int n;
	cin >> n;
	auto res = f(n);
	cout << res.size() << '\n';
	for (auto p : res)
		cout << p.first << ' ' << p.second << '\n';
	return 0;
}