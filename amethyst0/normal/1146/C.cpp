#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int ask(int l, int r, int v) {
	cout << 1 << ' ' << (r - l + 1 - ((l <= v && v <= r) ? 1 : 0)) << ' ';
	cout << v;

	for (int i = l; i <= r; i++) {
		if (i != v) {
			cout << ' ' << i;
		}
	}

	cout << endl;
	fflush(stdout);

	int d;

	cin >> d;
	if (d == -1) {
		throw 1;
	}

	return d;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;

		cin >> n;

		int l = 1;
		int r = n - 1;

		int dst = ask(l, r, n);

		while (l != r) {
			int m = (l + r) >> 1;

			int cur = ask(l, m, n);

			if (cur == dst) {
				r = m;
			}
			else {
				l = m + 1;
			}
		}
		
		int ans = ask(1, n, l);

		cout << "-1 " << ans << endl;
		fflush(stdout);
	}

	//system("pause");

	return 0;
}