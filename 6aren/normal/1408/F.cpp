#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

vector<ii> ans;

void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	for (int i = l; i <= mid; i++) {
		ans.push_back(ii(i, l + r - i));
	}
	solve(l, mid);
	solve(mid + 1, r);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int range = 1;
	while (2 * range <= n)
		range *= 2;

	solve(1, range);
	if (range != n)	solve(n - range + 1, n);

	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';

	for (ii e : ans) {
		cout << e.first << ' ' << e.second << '\n';
	}

	return 0;
}