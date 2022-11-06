#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int x, y, z;

bool jud(int team) {
	int x1 = x - team, y1 = y - team;
	return (x1 + y1 + z) >= team;
}

int main() {
	int T; cin >> T;
	while(T--) {
		int ans = 0;
		cin >> x >> y >> z;
		if(x > y) {
			int t = x;
			x = y; y = t;
		}
		int l = 0, r = x;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(jud(mid)) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}