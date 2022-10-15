/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar, ar + n);
	int m;
	cin >> m;
	long long ans = 0;
	for(int i = 0; i < min(n, m); i++){
		ans += ar[i];
	}
	if (m > n){
		ans -= (m - n) * d;
	}
	cout << ans;
}