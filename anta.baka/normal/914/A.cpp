#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int ans = INT_MIN;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		if(x < 0) { ans = max(ans, x); continue; }
		int y = sqrt(x + .0);
		if(y * y != x) ans = max(ans, x);
	}
	cout << ans;
}