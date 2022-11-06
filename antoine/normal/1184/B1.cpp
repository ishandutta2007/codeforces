#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v)  << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	vector<pair<int, int>> b(m);
	for (auto &&e : b)
		cin >> e.first >> e.second;
	sort(b.begin(), b.end());

	{
		int sum = 0;
		for(auto &&e : b)
			e.second = (sum += e.second);
	}

	for (int x : a) {
		auto it = lower_bound(b.begin(), b.end(), pair<int, int>{ x +1, 0 });
		int res = it == b.begin() ? 0 : prev(it)->second;
		cout << res << ' ';
	}
	return 0;
}