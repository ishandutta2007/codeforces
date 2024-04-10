#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 1 << n;
		for (int i = 1; i < n / 2; i++) ans += 1 << i;
		for (int i = n / 2; i < n; i++) ans -= 1 << i;
		cout << ans << endl;
	}
}