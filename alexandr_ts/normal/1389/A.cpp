#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int M = 21;
const int N = 1e6 + 10;

void solve() {
	int l, r;
	cin >> l >> r;
	int x = l * 2;
	if (x <= r) {
		cout << l << " " << x << "\n";
	} else {
		cout << "-1 -1\n";
	}
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