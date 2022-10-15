/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

	int x, y;
	cin >> x >> y;

	if (x > 0 && y > 0) {
		cout << "0 " << (x + y) << " " << (x + y) << " 0";
	} else if (x < 0 && y < 0) {
		cout << (x + y) << " 0 0 " << (x + y);
	} else if (x > 0) {
		cout << "0 " << (y - x) << " " << (x - y) << " 0";
	} else {
		cout << (x - y) << " 0 0 " << (y - x);
	}

}