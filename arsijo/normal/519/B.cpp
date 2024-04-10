/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define ll long long
//#define x first
//#define y second
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

	sync;

	ll a, b, c, d;
	a = b = c = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d;
		a += d;
	}
	for (int i = 1; i < n; i++) {
		cin >> d;
		b += d;
	}
	for (int i = 2; i < n; i++) {
		cin >> d;
		c += d;
	}

	cout << a - b << endl << b - c;

}