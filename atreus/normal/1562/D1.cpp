#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;

int a[MAXN];

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '+')
			a[i + 1] = 1;
		else
			a[i + 1] = -1;
		
		if (i & 1)
			a[i + 1] *= -1;

		a[i + 1] += a[i];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		int x = a[r] - a[l - 1];
		if (x == 0)
			cout << 0 << '\n';
		else if (x & 1)
			cout << 1 << '\n';
		else
			cout << 2 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
}