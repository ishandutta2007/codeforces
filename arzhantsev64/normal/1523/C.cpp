#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		vector<int> cur;
		for (int i = 0; i < n; ++i) {
			if (v[i] == 1)
				cur.push_back(1);
			else {
				while (v[i] != cur.back() + 1)
					cur.pop_back();
				cur[cur.size() - 1]++;
			}
			cout << cur[0];
			for (int i = 1; i < cur.size(); ++i)
				cout << '.' << cur[i];
			cout << '\n';
		}
	}

	return 0;
}