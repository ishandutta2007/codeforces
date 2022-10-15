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
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double
#define mod % 1000000007

int main() {

	int n;
	cin >> n;
	int ans = 1, g;
	cin >> g;
	for (int i = 2; i <= n; i++) {
		int a;
		cin >> a;
		if (g == a)
			ans = -1;
		if (a < g) {
			ans = i;
			g = a;
		}
	}

	if (ans == -1) {
		cout << "Still Rozdil";
	} else {
		cout << ans;
	}

}