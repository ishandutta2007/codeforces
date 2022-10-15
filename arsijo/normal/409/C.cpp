/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt","w",stdout);
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int ans = min(a, b);
	ans = min(ans, c / 2);
	ans = min(ans, d / 7);
	ans = min(ans, e / 4);
	cout << ans;
}