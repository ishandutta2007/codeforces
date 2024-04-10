#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	vector<int> v;

	int n;
	cin >> n;

	vector<int> ans(2 * n + 1);
	vector<char> q(2 * n + 1);
	vector<int> a(2 * n + 1);

	for (int i = 1; i <= 2 * n; i++) {
		cin >> q[i];

		if (q[i] == '-') {
			int u;
			cin >> u;

			a[i] = u;

			if (v.size() == 0) {
				return cout << "NO\n", 0;
			}

			ans[v.back()] = u;
			v.pop_back();
		} else {
			v.push_back(i);
		}
	}

	set<int> s;

	
	for (int i = 1; i <= 2 * n; i++) {
		if (q[i] == '-') {
			int u = *s.begin();
			if (u != a[i])
				return cout << "NO\n", 0;
			s.erase(s.begin());
		} else {
			s.insert(ans[i]);
		}
	}

	cout << "YES\n";

	for (int i = 1; i <= 2 * n; i++) {
		if (ans[i] > 0)
			cout << ans[i] << ' ';
	}

	cout << endl;

	return 0;
}