/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

	int n;
	cin >> n;

	int ar[5];
	ms(ar);

	while (n--) {
		int a;
		cin >> a;
		ar[a]++;
	}

	int ans = 0;

	ans += ar[4];
	ar[4] = 0;

	ans += ar[2] / 2;
	ar[2] %= 2;

	int g = min(ar[1], ar[3]);
	ans += g;
	ar[1] -= g;
	ar[3] -= g;

	if (ar[3]) {
		ans += ar[3];
		ar[3] = 0;
	}

	if (ar[1] && ar[2]) {
		if (ar[1] == 1) {
			ar[1] = 0;
			ar[2] = 0;
			ans++;
		} else {
			ar[1] -= 2;
			ar[2] = 0;
			ans++;
		}
	}

	ans += (ar[1] / 4) + (ar[1] % 4 ? 1 : 0);

	for (int i = 2; i < 4; i++)
		if (ar[i])
			ans++;

	cout << ans;
}