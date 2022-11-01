#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

int a[N], d[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	fill(d, d + n + 6, INF);
	d[0] = 0;

	for (int i = 0; i < n; ++i) {
		int c1 = 0;
		if (a[i]) c1 = 1;
		d[i + 2] = min(d[i + 2], d[i] + c1);
		d[i + 3] = min(d[i + 3], d[i] + c1);

		int c2 = c1 + (!!a[i + 1]);
		d[i + 3] = min(d[i + 3], d[i] + c2);
		d[i + 4] = min(d[i + 4], d[i] + c2);
	}	
	cout << *min_element(d + n, d + n + 3) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();	
	}
}