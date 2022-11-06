#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v;
	vector<int> a(n + 5, 0); // 0: > 		1: <=

	for (int i = 0; i < m; ++i) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 0)
			v.push_back( { l, r });
		else {
			assert(t == 1);
			a[l]++;
			a[r]--;
		}
	}

	partial_sum(a.begin(), a.end(), a.begin());
	for (int &x : a)
		x = min(1, x);
	partial_sum(a.begin(), a.end(), a.begin());

	for (auto e : v)
		if (a[e.second - 1] - a[e.first - 1] == e.second - e.first) {
			cout << "NO";
			return 0;
		}

	adjacent_difference(a.begin(), a.end(), a.begin());

	int prev = (int) 1e5;
	cout << "YES\n" << prev;

	for (int i = 1; i < n; ++i)
		cout << ' ' << (a[i] ? ++prev : --prev);
	return 0;
}