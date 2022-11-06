#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	map<int, vector<int>> occ;
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		occ[--x].push_back(i);
	}

	ll ans = n - (int) occ.size();
	for (int x = 0; x < n; ++x)
		for (int y : { x - 1, x + 1 }) {
			if (y >= 0 && y < n)
				ans += !occ.count(x) || !occ.count(y) || occ[x].front() > occ[y].back();
		}
	cout << ans;
	return 0;
}