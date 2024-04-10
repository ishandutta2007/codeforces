#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		long long n;
		cin >> n;
		if (n % 2050 != 0) {
			puts("-1");
			continue;
		}
		n /= 2050;
		int ans = 0;
		while (n) ans += n%10, n /= 10;
		cout << ans << endl;
	}
}