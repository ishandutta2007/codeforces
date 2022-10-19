#include<bits/stdc++.h>

using namespace std;

bool a[32];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int m, n, x;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cout << 1 << endl;
		fflush(stdout);
		int u;
		cin >> u;
		if (u == 0) {
			return 0;
		}
		if (u == 1) a[i] = true;
		else a[i] = false;
	}
	int l = 2, r = m;
	int cnt = 0;
	while (1) {
		int mid = (l + r) / 2;
		cout << mid << endl;
		fflush(stdout);
		int u;
		cin >> u;
		if (u == 0) {
			return 0;
		}
		if (a[(cnt) % n + 1] == true) {
			if (u == 1) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		} else {
			if (u == 1) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		cnt++;
	}
	return 0;
}