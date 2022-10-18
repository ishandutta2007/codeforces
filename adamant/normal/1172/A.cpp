#include <bits/stdc++.h>

using namespace std;

//#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	deque<int> a(n, 0), b(n, 0);
	set<int> have;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		have.insert(a[i]);
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	reverse(all(b));
	int j = 0;
	while(j + 1 < n && b[j + 1] == b[j] - 1 && b[j + 1] != 0) {
		j++;
	}
	if(b[j] == 1) {		
		int ans = n;
		for(int i = j + 1; i < n; i++) {
			if(b[i] != 0) {
				ans = min(ans, i + b[i] - (j + 2));
			}
		}
		if(ans == n) {
			cout << n - (j + 1) << endl;
			return 0;
		}
	}
		
	int ans = n;
	for(int i = 0; i < n; i++) {
		if(b[i] != 0) {
			ans = min(ans, i + b[i] - 1);
		}
	}
	cout << 2 * n - ans << endl;
	return 0;
}