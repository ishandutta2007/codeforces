#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int a[200005], b[200005], d[200005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ntest;
	cin >> ntest;
	while (ntest--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
		bool flagg = 0;
		bool flag2 = 0;
		for (int i = 1; i <= n; i++) {
			d[i] = b[i] - a[i];
			if (d[i] != 0) {
				flagg = 1;
			}
			if (d[i] < 0) {
				flag2 = 1;
			}
		}
		if (flagg == 0) {
			cout << "YES\n";
			continue;
		}
		if (flag2 == 1) {
			cout << "NO\n";
			continue;
		}
		int cnt = 0;
		d[n + 1] = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (d[i] != d[i - 1]) {
				cnt++;
			}
		}
		if (cnt <= 2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}