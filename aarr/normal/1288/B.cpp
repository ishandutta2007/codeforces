#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long a, b;
		cin >> a >> b;
		b++;
		long long ans = 0;
		while (b > 0) {
			b /= 10;
			ans++;
		}
		ans--;
		
		cout << 1ll * a * ans << endl;
	}
	return 0;
}