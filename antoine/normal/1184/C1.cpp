#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v)  << #v << " = " << (v) << endl;

bool f(vector<pair<int, int>> pts) {
	int mnX = +100000;
	int mxX = -100000;
	int mnY = +100000;
	int mxY = -100000;

	for (auto p : pts) {
		mnX = min(mnX, p.first);
		mxX = max(mxX, p.first);
		mnY = min(mnY, p.second);
		mxY = max(mxY, p.second);
	}

	if (mxX - mnX != mxY - mnY)
		return false;

	for (auto p : pts) {
		if (mnX < p.first && p.first < mxX && mnY < p.second && p.second < mxY)
			return false;
	}
	return true;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	n = 4 * n + 1;
	vector<pair<int, int>> pts(n);
	for (auto &&e : pts)
		cin >> e.first >> e.second;
	for (int rep = 0; rep < n; ++rep) {
		auto p = pts.back();
		pts.pop_back();
		if (f(pts)) {
			cout << p.first << ' ' << p.second << endl;
			return 0;
		}
		pts.push_back(p);
		rotate(pts.begin(), pts.begin() + 1, pts.end());
	}
	assert(false);
	return 0;
}