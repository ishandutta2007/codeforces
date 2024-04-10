#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, u, v;
		cin >> n >> u >> v;
		bool flag = 1, line = 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1 && abs(a[i]-a[i-1]) > 1) flag = 0;
			if (i > 1 && a[i] != a[i-1]) line = 0;
		}
		if (!flag) {
			puts("0");
			continue;
		}
		if (line) cout << v + min(u, v) << endl;
		else cout << min(u, v) << endl;
	}
}