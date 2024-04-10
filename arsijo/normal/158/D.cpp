/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("H.dat", "r", stdin); freopen("H.sol", "w", stdout);
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	long long sum = LONG_LONG_MIN;
	for (int i = 1; i * 3 <= n; i++) {
		if (n % i != 0 || n / i < 3)
			continue;
		long long res[i];
		memset(res, 0, sizeof(res));
		for(int j = 0; j < n; j++)
			res[j % i] += ar[j];
		for(int j = 0; j < i; j++)
			sum = max(sum, res[j]);

	}
	cout << sum;
}