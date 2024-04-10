#include <bits/stdc++.h>

using namespace std;

int a, n, t[105], tot = 0;

int main (int argc, char const *argv[]) {
	cin >> n >> a;
	for (int i = 1; i <= n; ++i) cin >> t[i];

	tot = t[a] == 1;
	for (int i = 1; a - i >= 1 or a + i <= n; ++i) {
		if (a - i >= 1 and a + i <= n) {
			int sum = t[a - i] + t[a + i];
			if (sum == 2) tot += 2;
		} else if (a - i >= 1) {
			if (t[a - i] == 1) ++tot;
		} else if (a + i <= n) {
			if (t[a + i] == 1) ++tot;
		}
	}	

	cout << tot << endl;
	return 0;
}