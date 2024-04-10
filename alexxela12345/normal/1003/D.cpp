#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

signed main() {
	int n, q;
	cin >> n >> q;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		m[x] += 1;
	}
	for (int i = 0; i < q; i++) {
		int b;
		cin >> b;
		int cnt = 0;
		int cur = 1LL << 32;
		map<int, int> m2;
		m2 = m;
		while (b && cur >= 1) {
			cnt += min(b / cur, m2[cur]);
			b -= cur * min(b / cur, m2[cur]);
			cur = cur / 2;
		}
		if (b) {
			cout << -1 << endl;
		} else {
			cout << cnt << endl;
		}
	}
	return 0;
}




/* #include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

struct Edge {
	int a, b;

	Edge(int _a, int _b) : a(_a), b(_b) {}

	friend ostream& operator<<(ostream &s, const Edge &e) {
		s << e.a << " " << e.b << endl;
		return s;
	}
};

signed main() {
	int n, d, k;
	cin >> n >> d >> k;
	if (d >= n || d < 2) {
		cout << "NO" << endl;
		return 0;
	}
	vector<Edge> ans;
	for (int i = 1; i <= d; i++) {
		ans.push_back(Edge(i, i + 1));
	}
	for (auto el : ans) {
		cout << el;	
	}
	return 0;
}
*/