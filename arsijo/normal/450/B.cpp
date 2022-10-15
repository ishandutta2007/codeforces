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

	ll x, y;
	cin >> x >> y;

	ll n;
	cin >> n;
	n %= 6;

	ll ans = 0;

	if(n == 1)
		ans = x;
	else if (n == 2)
		ans = y;
	else if (n == 3)
		ans = y - x;
	else if (n == 4)
		ans = -x;
	else if (n == 5)
		ans = -y;
	else
		ans = x - y;

	while(ans < 0)
		ans += pow(10, 9) + 7;
	cout << ans mod;

}