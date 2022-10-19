#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (__gcd(a, b) == 1) cout << "Finite\n";
		else cout << "Infinite\n";
	}
	return 0;
}