#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> get_bits(int n) {
	vector<int> ans;
	for (int i = 0; i <= 30; ++i)
		if (n & ((int)1 << i))
			ans.push_back(i);
	return ans;
}

bool solve(int u, int v) {
	auto bits1 = get_bits(u);
	auto bits2 = get_bits(v);
	// for (int i : bits1)
	// 	cout << i << ' ';
	// cout << endl;
	// for (int i : bits2)
	// 	cout << i << ' ';
	// cout << endl;
	while (bits1.size() >= 1 && bits2.size() >= 1 && bits1.back() == bits2.back()) {
		bits1.pop_back();
		bits2.pop_back();
	}
	if (bits1.size() == 0 && bits2.size() == 0)
		return 1;
	if (bits1.size() != 0 && bits2.size() == 0)
		return 0;
	if (bits1.size() == 0 && bits2.size() != 0)
		return 0;
	if (bits1.back() > bits2.back())
		return 0;
	if (bits1.size() < bits2.size())
		return 0;
	for (int i = 0; i < bits2.size(); ++i)
		if (bits2[i] < bits1[i])
			return 0;
	return 1;
}

signed main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int u, v;
		cin >> u >> v;
		cout << (solve(u, v) ? "YES\n" : "NO\n");
	}
}