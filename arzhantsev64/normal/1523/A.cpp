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
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		m = min(m, n);
		char c;
		for (int i = 0; i < n; ++i) {
			cin >> c;
			v[i] = (c == '1' ? 1 : 0);
		}
		vector<int> to_update;
		for (int i = 0; i < n; ++i) 
			if (v[i] == 0 && ((i >= 1 && v[i - 1]) + (i + 1 < n && v[i + 1]) == 1))
				to_update.push_back(i);
		for (int k = 0; k < m; ++k) {
			for (int i : to_update) 
				v[i] = 1;
			to_update.clear();
			v = v;
			for (int i = 0; i < n; ++i) 
				if ((v[i] == 0) && ((i >= 1 && v[i - 1]) + (i + 1 < n && v[i + 1]) == 1))
					to_update.push_back(i);
		}
		for (int i : v)
			cout << i;
		cout << '\n';
	}

	return 0;
}