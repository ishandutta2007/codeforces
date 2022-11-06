#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

vector<int> f(vector<int> &v, const int k) {
	vector<int> res;
	deque<int> dq;
	for (int i = 0; i < (int) v.size(); ++i) {
		if (i - k >= 0 && !dq.empty() && dq.front() == i - k)
			dq.pop_front();
		while (!dq.empty() && v[dq.back()] >= v[i])
			dq.pop_back();
		dq.push_back(i);
		if (i >= k - 1) {
			assert(!dq.empty());
			res.push_back(v[dq.front()]);
		}
	}
	assert((int )res.size() == (int )v.size() - k + 1);
	return move(res);
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, li, lj;
	cin >> n >> m >> li >> lj;
	vector<vector<int>> a(n, vector<int>(m, 0));

	{
		ll g, x, y, z;
		cin >> g >> x >> y >> z;
		for (int i = 0; i < n * m; ++i) {
			a[i / m][i % m] = g;
			g = (g * x + y) % z;
		}
	}

	for (vector<int> &v : a) {
		v = f(v, lj);
	}

	ll ans = 0;
	for (int j = 0; j < (int) a[0].size(); ++j) {
		vector<int> v;
		for (int i = 0; i < n; ++i)
			v.push_back(a[i][j]);
		v = f(v, li);
		ans += accumulate(v.begin(), v.end(), 0LL);
	}
	cout << ans;
	return 0;
}