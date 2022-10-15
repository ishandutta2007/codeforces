/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, x1, y1, x2, y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	r *= 2;
	double len = (double) sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	int ans = 0;
	while(len > 0){
		ans++;
		len -= r;
	}
	cout << ans;
}