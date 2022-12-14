#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000 + 10;
const int mod = 998244353;

int dis(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
	int x1 = 0, y1 = 0;
	int x2, y2;
	cin >> x2 >> y2;
	for (int i = 0; i <= 50; i++)
		for (int j = 0; j <= 50; j++)
			if (2 * dis(i, j, x1, y1) == dis(x1, y1, x2, y2) && 2 * dis(i, j, x2, y2) == dis(x1, y1, x2, y2)) {
				cout << i << " " << j << endl;
				return;
			}
	cout << -1 << " " << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}