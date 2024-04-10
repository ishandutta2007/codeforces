/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	int n;
	cin >> n;
	int ar1[n], ar2[n], a;
	memset(ar1, 0, sizeof(ar1));
	memset(ar2, 0, sizeof(ar2));
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a;
			ar1[i] += a;
			ar2[j] += a;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if (ar1[i] < ar2[j])
				ans++;



	cout << ans;
}