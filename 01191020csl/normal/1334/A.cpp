#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a = 0, b = 0;
		bool ans = 1;
		for (int i = 1; i <= n; i++) {
			int a0, b0;
			cin >> a0 >> b0;
			if (a0 < a || b0 < b || a - b > a0 - b0) ans = 0;
			a = a0, b = b0;
		}
		if (ans) puts("YES");
		else puts("NO");
	}
}