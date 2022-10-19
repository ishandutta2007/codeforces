#include<bits/stdc++.h>
using namespace std;

int n, k, l[200005], r[200005];
set<pair<int, int>> s;
vector<int> res, vl[200005], vr[200005];
int bit[200005];

void update(int k, int val) {
	for (int i = k; i < 200004; i += (i & (-i))) {
		bit[i] += val;
	}
}

int get(int k) {
	int res = 0;
	for (int i = k; i > 0; i -= (i & (-i))) {
		res += bit[i];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		vl[l[i]].push_back(i);
		vr[r[i]].push_back(i);
		update(l[i], 1);
		update(r[i] + 1, - 1);
	}
	for (int i = 1; i <= 200000; i++) {
		for (auto u : vr[i - 1]) {
			s.erase({-r[u], u});
		}
		for (auto u : vl[i]) {
			s.insert({-r[u], u});
		}
		int t = get(i);
		//cout << i << ' ' << t << endl;
		while (t > k) {
			t--;
			auto it = s.begin();
			auto u = (*(it)).second;
			res.push_back(u);
			update(l[u], - 1);
			update(r[u] + 1, 1);
			s.erase(it);
		}
	}
	cout << res.size() << '\n';
	for (auto u : res) cout << u << ' ';
	return 0;
}