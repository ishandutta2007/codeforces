#include <bits/stdc++.h>

using namespace std;

long long n, a, b, c, d, ans = 0;

bool Check (long long z) {
	return z >= 1 and z <= n;	
}

int main (void) {
	cin >> n >> a >> b >> c >> d;

	for (long long x = 1; x <= n; x++) {
		if (Check(x + b - c) and Check(x + a - d) and Check(x + a + b - c - d))
			ans += n;
	}
	
	cout << ans << endl;
	return 0;	
}