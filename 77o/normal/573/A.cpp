#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int g = 0;
	for (int& i : a) {
		cin >> i;
		g = __gcd(g, i);
	}
	for (int i = 0; i < n; i++) {
		a[i] /= g;
		while (a[i] % 2 == 0) a[i] /= 2;
		while (a[i] % 3 == 0) a[i] /= 3;
		if (a[i] > 1) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}