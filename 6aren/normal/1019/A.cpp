#include<bits/stdc++.h>

using namespace std;

int n, m;
priority_queue<int, vector<int>, greater<int>> a[3005], s;
long long ans = 1e18;

void check(int k) {
	long long res = 0;
	int t = a[1].size();
	stack<int> st1;
	for (int i = 2; i <= m; i++) {
		while (a[i].size() > k - 1) {
			int u = a[i].top();
			a[i].pop();
			st1.push(u);
			res += u;
			t++;
		}
		while (!a[i].empty()) {
			int u = a[i].top();
			st1.push(u);
			s.push(u);
			a[i].pop();
		}
		while (!st1.empty()) {
			a[i].push(st1.top());
			st1.pop();
		}
	}
	while (t < k) {
		if (s.empty()) break;
		res += s.top();
		s.pop();
		t++;
	}
	while (!s.empty()) s.pop();
	if (t >= k) ans = min(ans, res);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push(v);
	}
	for (int i = 1; i <= n; i++) {
		check(i);
	}
	cout << ans;
	return 0;
}