#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	map<int, int> occ;
	while (n--) {
		int x;
		cin >> x;
		++occ[x];
	}

	int ans = 0;
	for (int i = 1; i < (int) 2e5; ++i)
		for (int x : { i - 1, i, i + 1 })
			if (occ[x]) {
				--occ[x];
				++ans;
				break;
			}
	cout << ans;
	return 0;
}