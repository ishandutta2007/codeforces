#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (s.count(x))
			s.erase(x);
		else
			s.insert(x);
	}
	cout << n - s.size() / 2;
	return 0;
}