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
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<vector<int>> v(n, vector<int> (n, -1));
	
	for (int i = 0; i < n; ++i) {
		int cx = i;
		int cy = i;

		int need = a[i] - 1;
		v[cx][cy] = a[i];

		while (need > 0) {
			if (cy - 1 >= 0 && v[cx][cy - 1] == -1) {
				cy--;
				v[cx][cy] = a[i];
			} else {
				cx++;
				if (cx >= n) {
					cout << "WTF!" << endl;
					for (int i = 0; i < n; ++i) {
						for (int j = 0; j <= i; ++j)
							cout << v[i][j] << ' ';
						cout << '\n';
					}
					return 1;
				}
				v[cx][cy] = a[i];
			}
			need--;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j)
			cout << v[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}