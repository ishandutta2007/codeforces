#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int t, n, a[11];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, 10) a[i] = 0;
		rep(i, 1, n) {
			int b, d;
			cin >> b >> d;
			a[d] = max(a[d], b);
		}
		if (count(a + 1, a + 11, 0) > 0) {
			cout << "MOREPROBLEMS\n";
		}
		else {
			cout << accumulate(a + 1, a + 11, 0) << "\n";
		}
	}

	return 0;
}