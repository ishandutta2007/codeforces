#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

struct rob {
	int x;
	char dir;
	int id;
};

bool operator<(rob a, rob b) {
	return a.x < b.x;
}

int solve() {
	int n, m;
	cin >> n >> m;
	vector<int> ans(n, -1);
	vector<rob> v(n);
	vector<rob> v1;
	vector<rob> v2;
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x;
		v[i].id = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> v[i].dir;
	}
	for (int i = 0; i < n; ++i) {
		if (v[i].x % 2 == 1)
			v1.push_back(v[i]);
		else
			v2.push_back(v[i]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());


	vector<rob> L;
	vector<rob> R;
	for (auto r : v1) {
		if (r.dir == 'L') {
			if (!R.empty()) {
				rob r2 = R[R.size() - 1];
				R.pop_back();
				int dist = r.x - r2.x;
				ans[r.id] = dist / 2;
				ans[r2.id] = dist / 2;
			} else {
				L.push_back(r);
			}
		} else {
			R.push_back(r);
		}
	}
	// cout << v1.size() << ' ' << v2.size() << endl;
	for (int i = 0; i + 1 < L.size(); i += 2) {
		rob r1 = L[i];
		rob r2 = L[i + 1];
		int dist = r1.x + r2.x;
		ans[r1.id] = dist / 2;
		ans[r2.id] = dist / 2;
	}

	for (int i = R.size() - 1; i >= 1; i -= 2) {
		rob r1 = R[i];
		rob r2 = R[i - 1];
		int dist = m - r1.x + m - r2.x;
		ans[r1.id] = dist / 2;
		ans[r2.id] = dist / 2;
	}

	if (L.size() % 2 == 1 && R.size() % 2 == 1) {
		rob r1 = L[L.size() - 1];
		rob r2 = R[0];
		int dist = m + r1.x + m - r2.x;
		ans[r1.id] = dist / 2;
		ans[r2.id] = dist / 2;
	}
	// cout << "KEKE" << endl;
	L.clear();
	R.clear();
	for (auto r : v2) {
		if (r.dir == 'L') {
			if (!R.empty()) {
				rob r2 = R[R.size() - 1];
				R.pop_back();
				int dist = r.x - r2.x;
				ans[r.id] = dist / 2;
				ans[r2.id] = dist / 2;
			} else
				L.push_back(r);
		} else
			R.push_back(r);
	}
	for (int i = 0; i + 1 < L.size(); i += 2) {
		rob r1 = L[i];
		rob r2 = L[i + 1];
		int dist = r1.x + r2.x;
		ans[r1.id] = dist / 2;
		ans[r2.id] = dist / 2;
	}

	for (int i = R.size() - 1; i - 1 >= 0; i -= 2) {
		rob r1 = R[i];
		rob r2 = R[i - 1];
		int dist = m - r1.x + m - r2.x;
		ans[r1.id] = dist / 2;
		ans[r2.id] = dist / 2;
	}

	if (L.size() % 2 == 1 && R.size() % 2 == 1) {
		rob r1 = L[L.size() - 1];
		rob r2 = R[0];
		int dist = m + r1.x + m - r2.x;
		ans[r1.id] = dist / 2;
		ans[r2.id] = dist / 2;
	}

	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}