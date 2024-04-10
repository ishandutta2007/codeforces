#include<bits/stdc++.h>
using namespace std;
bool checksq(int n) {
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (1ll * mid * mid > n) r = mid - 1;
		else l = mid;
	}
	return 1ll * l * l == n;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if ((n % 4 == 0 && checksq(n/4)) || (n % 2 == 0 && checksq(n / 2))) puts("YES");
		else puts("NO");
	}
}