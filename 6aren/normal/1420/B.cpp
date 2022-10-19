#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define ii pair<int, int>
#define bit(x, y) ((x >> y) & 1)
#define all(a) ((a).beign(), (a).end())

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n; cin >> n;
		vector<int> cnt(32, 0);

		while (n--) {
			int u; cin >> u;
			int id = -1;
			for (int i = 31; i >= 0; i--) if (bit(u, i)) {
				id = i;
				break;
			}
			cnt[id]++;
		}

		long long ans = 0;

		for (int e : cnt) {
			ans += 1LL * e * (e - 1) / 2;
		}

		cout << ans << '\n';
	}

	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << endl;
}