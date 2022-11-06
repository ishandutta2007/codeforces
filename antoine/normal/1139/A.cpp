#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		if ((c - '0') % 2 == 0) {
			ans += i + 1;
		}
	}
	cout << ans;
	return 0;
}