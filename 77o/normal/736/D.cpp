#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int N = 2001;

bitset<N * 2> a[N];

void gauss (int n) {
    for (int i = 0; i < n; i++) {
		int row = i;
		for (int j = i; j < n; j++) {
			if (a[j][i]) {
				row = j;
				break;
			}
		}
		swap(a[row], a[i]);
		for (int j = 0; j < n; j++) {
			if (j != i && a[j][i]) {
				a[j] ^= a[i];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> x(m), y(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		x[i]--;
		y[i]--;
		a[x[i]][y[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		a[i][i + n] = 1;
	}
	gauss(n);
	for (int i = 0; i < m; i++) {
		if (!a[y[i]][x[i] + n]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}