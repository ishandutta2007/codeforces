#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<int, int> occ;

vector<int> f(const int m) {
	vector<int> res;
	for (auto &&p : occ)
		for (int rep = p.second / m; rep > 0; --rep)
			res.push_back(p.first);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++occ[x];
	}


	int lo = 1, hi = n;
	while (lo < hi) {
		const int mid = (lo + hi + 1) >> 1;
		if ((int)f(mid).size() >= k)
			lo = mid;
		else
			hi = mid - 1;
	}
	auto res = f(lo);
	assert((int)res.size() >= k);
	res.resize(k);
	for (auto &&x : res)
		cout << x << ' ';
	return 0;
}