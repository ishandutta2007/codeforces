#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 1e9 + 7;
const int N = 1e7 + 10;

int p[N];

void prec() {
	for (ll i = 2; i < N; ++i) {
		for (ll j = i * i; j < N; j += i) {
			if (!p[j]) {
				p[j] = i;
			}
		}
	}
}

int a[N], d1[N], d2[N];

void solve() {
	int n;
	cin >> n;
	prec();

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		d1[i] = d2[i] = -1;
		if (p[x] == 0) {
			continue;
		}

		ll d = p[x];
		while (x % (d * p[x]) == 0) {
			d *= p[x];
		}
		if (x == d) {
			continue;
		}
		d1[i] = d;
		d2[i] = x / d;
	}

	for (int i = 0; i < n; ++i) {
		cout << d1[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		cout << d2[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}