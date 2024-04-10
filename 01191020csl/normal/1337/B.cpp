#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, m, n;
		cin >> x >> m >> n;
		while (m) {
			int x0 = x / 2 + 10;
			if (x0 >= x) break;
			x = x0, --m;
		}
		if (x <= n * 10) puts("YES");
		else puts("NO");
	}
}