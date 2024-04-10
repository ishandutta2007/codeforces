#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	vector<int> op(n);
	vector<bool> is_rec(n);
	set<int> c;
	for (int i = 0; i < n; ++i) {
		if (c.size() >= 1) {
			if (c.size() == 1) {
				auto it = c.end();
				it--;
				if (v[i] < (*it))
					op[*it - 1]++;
				else
					is_rec[v[i] - 1] = true;
			} else {
				auto it1 = c.end();
				it1--;
				auto it2 = c.end();
				it2--; it2--;
				if (v[i] < (*it1) && v[i] > (*it2))
					op[*it1 - 1]++;
				if (v[i] > (*it1))
					is_rec[v[i] - 1] = true;
			}
		} else {
			is_rec[v[i] - 1] = true;
		}
		c.insert(v[i]);
	}
	int maxx = -1;
	int ans = 2e9;
	for (int i = 0; i < n; ++i) {
		op[i] -= is_rec[i];
		if (op[i] > maxx) {
			maxx = op[i];
			ans = i;
		} else if (op[i] == maxx) {
			ans = min(ans, i);
		}
	}
	cout << ans + 1 << endl;
}