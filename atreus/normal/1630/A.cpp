#include <bits/stdc++.h>
#define bit(n, k) ((n >> k) & 1)
typedef long long ll;
using namespace std;

const int maxn = 2e6 + 10;

int p[maxn];

void makepair(int a, int b) {
	p[a] = b;
	p[b] = a;
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		p[i] = n - 1 - i;
	if (k == 1) {
		makepair(0, n - 2);
		makepair(1, n - 1);
	}
	else if (k > 1 and k < n - 1) {
		int r = (k & -k);
		if (r == k) {
			makepair(k, n - 1);
			makepair(0, n - 1 - k);
		}
		else {
			int q = k - r;
			makepair(q, n - 1 - r);
			makepair(r, n - 1 - q);
		}
	}
	else if (k == n - 1) {
		if (n == 4) {
			cout << -1 << '\n';
			return;
		}
		makepair(n - 1, n - 2);
		makepair(1, 3);
		makepair(0, n - 4);
	}
	int t = 0;
	for (int i = 0; i < n; i++)
		if (p[i] > i) {
			cout << i << " " << p[i] << '\n';
			t += (i & p[i]);
		}
	assert(t == k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
}