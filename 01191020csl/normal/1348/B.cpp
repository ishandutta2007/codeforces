#include<bits/stdc++.h>
using namespace std;
int a[101];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		int p = unique(a + 1, a + n + 1) - a - 1;
		if (p > k) {
			puts("-1");
			continue;
		}
		while (p < k) a[++p] = 1;
		cout << n * p << endl;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= p; j++) cout << a[j] << ' ';
		cout << endl;
	}
}