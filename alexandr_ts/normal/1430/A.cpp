#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e14;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;



void solve() {
	int n;
	cin >> n;
	if (n % 3 == 0) {
		cout << n / 3 << " 0 0\n";
		return;
	}
	if (n % 3 == 1) {
		if (n < 7) {
			cout << "-1\n";
			return;
		}
		cout << (n - 7) / 3 << " 0 1\n";
		return;
	}

	if (n < 5) {
		cout << "-1\n";
		return;
	}
	cout << (n - 5) / 3 << " 1 0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();	
	}
}