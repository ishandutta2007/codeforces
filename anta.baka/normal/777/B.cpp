#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> sh(10, 0), mo(10, 0);
	for(int i = 0; i < n; i++) {
		char dg;
		cin >> dg;
		sh[dg - '0']++;
	}
	for(int i = 0; i < n; i++) {
		char dg;
		cin >> dg;
		mo[dg - '0']++;
	}
	int ans1 = 0;
	int up = 0;
	for(int dg = 9; dg >= 0; dg--) {
		if(sh[dg] <= mo[dg]) {
			up += mo[dg] - sh[dg];
		} else {
			up -= sh[dg] - mo[dg];
			if(up < 0) {
				ans1 += -up;
				up = 0;
			}
		}
	}
	int ans2 = 0;
	up = 0;
	for(int dg = 9; dg >= 0; dg--) {
		if(sh[dg] <= up) {
			ans2 += sh[dg];
			up -= sh[dg];
		} else {
			ans2 += up;
			up = 0;
		}
		up += mo[dg];
	}
	cout << ans1 << "\n" << ans2;
}