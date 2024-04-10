#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int> (n, 0));

	bool done1 = 0;
	bool done2 = 0;

	int cnt1 = 0;
	int cnt2 = 0;

	int aim1 = (n * n - 1) / 2 + 1;
	int aim2 = n * n / 2;

	for (int t = 0; t < n * n; ++t) {
		int x;
		cin >> x;

		if (!done1 && !done2) {
			int c = 0;
			if (x == 1)
				c = 2;
			else
				c = 1;

			if (c == 1) {
				bool done = false;
				for (int i = 0; !done && i < n; ++i)
				for (int j = 0; !done && j < n; ++j)
					if ((i + j) % 2 == 0 && v[i][j] == 0) {
						v[i][j] = 1;
						cout << 1 << ' ' << i + 1 << ' ' << j + 1 << endl;
						done = true;
					}
				cnt1++;
			} else {
				bool done = false;
				for (int i = 0; !done && i < n; ++i)
				for (int j = 0; !done && j < n; ++j)
					if ((i + j) % 2 == 1 && v[i][j] == 0) {
						v[i][j] = 2;
						cout << 2 << ' ' << i + 1 << ' ' << j + 1 << endl;
						done = true;
					}
				cnt2++;
			}
		} else if (done1) {
			int c;
			if (x == 2)
				c = 3;
			else
				c = 2;

			bool done = false;
			for (int i = 0; !done && i < n; ++i)
			for (int j = 0; !done && j < n; ++j)
				if (v[i][j] == 0) {
					v[i][j] = c;
					cout << c << ' ' << i + 1 << ' ' << j + 1 << endl;
					done = true;
				}
		} else if (done2) {
			int c;
			if (x == 1)
				c = 3;
			else
				c = 1;

			bool done = false;
			for (int i = 0; !done && i < n; ++i)
			for (int j = 0; !done && j < n; ++j)
				if (v[i][j] == 0) {
					v[i][j] = c;
					cout << c << ' ' << i + 1 << ' ' << j + 1 << endl;
					done = true;
				}
		}
		if (cnt1 >= aim1)
			done1 = true;
		if (cnt2 >= aim2)
			done2 = true;
		// for (auto d : v) {
		// 	for (auto c : d)
		// 		cout << c << ' ';
		// 	cout << endl;
		// }
	}

	return 0;
}