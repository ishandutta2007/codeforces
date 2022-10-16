#include <bits/stdc++.h>

using namespace std;

int solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	if (count(a.begin(), a.end(), a[0]) == n) {
		cout << 1 << endl;
		for (int i = 0; i < n; ++i) {
			cout << 1 << " ";
		}
		cout << endl;
		return 0;
	}
	
	if (n % 2 == 0) {
		cout << 2 << endl;
		for (int i = 0; i < n; ++i) {
			cout << i % 2 + 1 << " ";
		}
		cout << endl;
		return 0;
	}
	
	for (int i = 0; i < n; ++i) {
		if (a[i] == a[(i + 1) % n]) {
			vector<int> ans(n);
			for (int j = 0, pos = i + 1; pos < n; ++pos, j ^= 1) {
				ans[pos] = j + 1;
			}
			for (int j = 0, pos = i; pos >= 0; --pos, j ^= 1) {
				ans[pos] = j + 1;
			}
			cout << 2 << endl;
			for (int pos = 0; pos < n; ++pos) {
				cout << ans[pos] << " ";
			}
			cout << endl;
			return 0;
		}
	}
	
	cout << 3 << endl;
	for (int i = 0; i < n - 1; ++i) {
		cout << i % 2 + 1 << " ";
	}
	cout << 3 << endl;
    return 0;    
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

int q;
cin >> q;
for (int qq = 0; qq < q; qq++) {
    solve();
}

	return 0;
}