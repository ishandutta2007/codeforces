#include<bits/stdc++.h>
using namespace std;
int a[101], b[101];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x, sum = 0;
		cin >> n >> x;
		for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
		sort(a + 1, a + n + 1);
		if (x == sum) {
			puts("NO");
			continue;
		}
		puts("YES");
		int flag = 0;
		for (int i = n; i > 1; i--) {
			if (x == a[i]) cout << a[1] << ' ', x -= a[1], flag = 1;
			cout << a[i] << ' ', x -= a[i];
		}
		if (!flag) cout << a[1];
		cout << endl;
	}
}