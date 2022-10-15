/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	for(int i = 0; i < 4; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (min(a, b) + min(c, d) <= n){
			cout << i + 1 << " " << min(a, b) << " " << n - min(a, b);
			return 0;
		}
	}
	cout << -1;

}