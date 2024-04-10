#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ii pair
#define x first
#define y second


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ntest;
	cin >> ntest;
	while (ntest--) {
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		int ans = abs(a - b);
		ans = min(ans + x, n - 1);
		cout << ans << '\n';
	}
	return 0;
}