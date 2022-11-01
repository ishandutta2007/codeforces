#include <bits/stdc++.h>
#define endl '\n'
using namespace std;



int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long a, b, n, ans = 0;
		cin >> a >> b >> n;
		while (a <= n && b <= n) {
			if (a > b) {
				swap(a, b);
			}
			a += b;
			ans++;
		}
		cout << ans << '\n';
	}
	
	return 0;
}