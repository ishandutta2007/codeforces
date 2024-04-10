#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int f(int x) {
	x--;
	int cnt = 0;
	while (x > 0) {
		cnt++;
		x >>= 1;
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, I;
	cin >> n >> I;
	map<int, int> occ;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++occ[x];
	}

	I *= 8;

	vector<int> a = { 0 };
	for (auto e : occ)
		a.push_back(e.second);

	vector<int> b = a;
	partial_sum(b.begin(), b.end(), b.begin());

	int ans = n;
	for (int i = 0, j = 0; j < (int) a.size(); ++j) {
		while (f(j - i + 1) * 1LL * n > I)
			++i;
		assert(i <= j);
		ans = min(ans, n - (b[j] - (i ? b[i - 1] : 0)));
	}
	cout << ans;
	return 0;
}