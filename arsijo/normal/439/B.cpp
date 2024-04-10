/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	int n, x;
	cin >> n >> x;
	long long ar[n];
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}
	sort(ar, ar + n);
	long long ans = 0;
	for(int i = 0; i < n; i++){
		ans += max(x - i, 1) * ar[i];
	}
	cout << ans;
}